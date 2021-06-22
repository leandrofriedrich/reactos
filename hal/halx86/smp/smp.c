/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/smp/smp.c
 * PURPOSE:     Core source file for SMP management
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* INCLUDES ******************************************************************/

#include <hal.h>
#include <smp.h>
#include <apic.h>
#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/

extern PHYSICAL_ADDRESS HalpLowStubPhysicalAddress;
extern PVOID HalpLowStub;

/* Tiny bit of a hack to limit the cpu count until we develop the HAL further */
ULONG MAXAPCount = 8;
ULONG APCountStarted = 1;

/* FUNCTIONS *****************************************************************/

BOOLEAN
HalpStartNextProcessor(PLOADER_PARAMETER_BLOCK APLoaderBlock, PKPROCESSOR_STATE APProcessorState)
{
    if(MAXAPCount > APCountStarted)
    {
        /* We only a create a new pagetable once */
        if(APCountStarted == 1)
        {
            DPRINT1("HalpStartNextProcessor: Attempting to create a pagetable");
            HalpInitializeAPPageTables(HalpLowStub);
        }
        
        /* Start an AP */
        HalpInitializeAPStub(HalpLowStub);
        if(HalpStartApplicationProcessor(APCountStarted, HalpLowStubPhysicalAddress) == FALSE)
        {
            return FALSE;
        }

        APCountStarted++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
