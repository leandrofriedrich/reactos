/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        ntoskrnl/ke/i386/mp.c
 * PURPOSE:     processor specific file to hold multiprocessor functions
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* INCLUDES *****************************************************************/

#include <ntoskrnl.h>
#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/

#define PHYSICAL_ADDRESS  LARGE_INTEGER
PHYSICAL_ADDRESS HighestPhysicalAddress;

/* FUNCTIONS *****************************************************************/
VOID
NTAPI
KeStartAllProcessors()
{
    BOOLEAN ProcessorsStarted = FALSE;
    ULONG ProcessorCount = 0;
    BOOLEAN Success = FALSE;
    KDESCRIPTOR GdtDesc, IdtDesc;
    __sgdt(&GdtDesc.Limit);
    __sidt(&IdtDesc.Limit);
    HighestPhysicalAddress.QuadPart = UINT64_MAX;

    /*  This setup process is executed uniquely per initalized AP */
    while(ProcessorsStarted == FALSE)
    {
        /* Increment the current processor count and attempt to allocate memory for its new setup */
        ProcessorCount++;
        SIZE_T APInfo = sizeof(KPCR) + sizeof(KTSS) + sizeof(ETHREAD) + GdtDesc.Limit + 1 + IdtDesc.Limit + 1; 
        PVOID PAPInfo = MmAllocateContiguousMemory(APInfo, HighestPhysicalAddress);
        if(!PAPInfo)
        {
            ASSERT("KeStartAllProcessors: Memory Allocation has failed");
        }

        RtlCopyMemory((PVOID)((ULONG_PTR)PAPInfo + sizeof(KPCR) + sizeof(KTSS)), (PVOID)GdtDesc.Base, GdtDesc.Limit + 1);
        RtlCopyMemory((PVOID)((ULONG_PTR)PAPInfo + sizeof(KPCR) + sizeof(KTSS) + GdtDesc.Limit + 1), (PVOID)IdtDesc.Base, IdtDesc.Limit + 1);

        KPROCESSOR_STATE ProcessorState;

        PKPCR pKPcr = (PKPCR)PAPInfo;
        PKTSS pKTss = (PKTSS)((ULONG_PTR)PAPInfo + sizeof(KPCR));
        PKTHREAD InitialThread = (PKTHREAD)((ULONG_PTR) PAPInfo + sizeof(KPCR) + sizeof(KTSS));

        /* Prep GDT and IDT based on BSPs */
        PKGDTENTRY pGdt = (PKGDTENTRY)((ULONG_PTR)PAPInfo + sizeof(KPCR) + sizeof(KTSS));
        PKIDTENTRY pIdt = (PKIDTENTRY)((ULONG_PTR)PAPInfo + sizeof(KPCR) + sizeof(KTSS) + GdtDesc.Limit + 1);
        ProcessorState.SpecialRegisters.Gdtr.Limit = GdtDesc.Limit;
        ProcessorState.SpecialRegisters.Gdtr.Base = (ULONG)((ULONG_PTR)PAPInfo + sizeof(KPCR) + sizeof(KTSS));
        ProcessorState.SpecialRegisters.Idtr.Limit = IdtDesc.Limit;
        ProcessorState.SpecialRegisters.Idtr.Base = (ULONG)((ULONG_PTR)PAPInfo + sizeof(KPCR) + sizeof(KTSS) + GdtDesc.Limit + 1);

        /* Prep Cr Regsters */
        ProcessorState.SpecialRegisters.Cr0 = __readcr0();
        ProcessorState.SpecialRegisters.Cr2 = __readcr2();
        ProcessorState.SpecialRegisters.Cr3 = __readcr3();
        ProcessorState.SpecialRegisters.Cr4 = __readcr4();

        /* Prep some stacks for the AP */
        PVOID KernelStack;
        PVOID DPCStack;

        KernelStack = MmCreateKernelStack(FALSE, 0);
        if (!KernelStack)
        {
            ASSERT("KeStartAllProcessors: MmCreateKernelStack has failed for an AP");
        }

        DPCStack = MmCreateKernelStack(FALSE, 0);
        if (!DPCStack)
        {
            MmDeleteKernelStack(KernelStack, FALSE);
        }

        /* Initalize a new PCR for the specific AP */
        KiInitializePcr(ProcessorCount,
                     (PKIPCR)pKPcr,
                     pIdt, 
                     pGdt, 
                     pKTss,
                     InitialThread,
                     (PVOID)DPCStack);

        /* Prep a new loadblock for AP */
        KeLoaderBlock->KernelStack = (ULONG_PTR)KernelStack;
        KeLoaderBlock->Prcb = (ULONG_PTR)pKPcr;
        KeLoaderBlock->Thread = (ULONG_PTR)InitialThread;

        /* Prepare Segment Registers */
        ProcessorState.ContextFrame.SegCs = KGDT_R0_CODE;
        ProcessorState.ContextFrame.SegSs = KGDT_R0_DATA;
        ProcessorState.ContextFrame.SegDs = KGDT_R0_DATA;
        ProcessorState.ContextFrame.SegEs = KGDT_R0_DATA; // This is vital for rep stosd.
        /* Clear GS */
        ProcessorState.ContextFrame.SegGs = 0;
        /* Set FS to PCR */
        ProcessorState.ContextFrame.SegFs = KGDT_R0_PCR;

        /* Load TSR */
        ProcessorState.SpecialRegisters.Tr = KGDT_TSS;
        
        /* Fully initalize AP's TSS */
        Ki386InitializeTss(pKTss, pIdt, pGdt);

        /* Save addresses so we can call KiSystemStartup with prepped values later */
        ProcessorState.ContextFrame.Ecx = (ULONG_PTR)PAPInfo;
        ProcessorState.ContextFrame.Eip = (ULONG_PTR)KiSystemStartup;

        /* Actually Start the AP */
        Success = HalStartNextProcessor(KeLoaderBlock, &ProcessorState);

        /* This isn't a bad failure, sometimes we just run out of processors to start */
        if(Success == FALSE)
        {
            /* Offset as we didn't sucessfully start a supposive AP */
            ProcessorCount += -1;
            /* This will not show the accurate number until MADT is in */
            //DPRINT1("KeStartAllProcessors has started %X extra processors \n", ProcessorCount);
            /* Clear memory and end the AP Startup process */
            MmFreeContiguousMemory(PAPInfo);
            MmDeleteKernelStack(KernelStack, FALSE);
            MmDeleteKernelStack(DPCStack, FALSE);
            ProcessorsStarted = TRUE;
            break;
        }
    }
} 
