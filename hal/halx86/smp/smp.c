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
#include "smpp.h"
#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/

extern PHYSICAL_ADDRESS HalpLowStubPhysicalAddress;
extern PVOID HalpLowStub;

/* HACK: this variable should be assigned by a Multi APIC table */
ULONG MaxAPCount = 8;
ULONG StartedProcessorCount = 1;

/* FUNCTIONS *****************************************************************/

BOOLEAN
NTAPI
HalStartNextProcessor(IN PLOADER_PARAMETER_BLOCK LoaderBlock,
                      IN PKPROCESSOR_STATE ProcessorState)
{
    if(MaxAPCount > StartedProcessorCount)
    {
        /* We only a create a new pagetable once */
        if(StartedProcessorCount == 1)
        {
            DPRINT1("HalpStartNextProcessor: Attempting to create a pagetable");
            HalpInitializeAPPageTables(HalpLowStub);
        }
        
        /* Start an AP */
        HalpInitializeAPStub(HalpLowStub);
        if(ApicStartApplicationProcessor(StartedProcessorCount, HalpLowStubPhysicalAddress) == FALSE)
        {
            return FALSE;
        }

        StartedProcessorCount++;
        return TRUE;
    }
    else
    {
        DPRINT1("HalStartNextProcessor: Currently Started Processor Count: %X\n", StartedProcessorCount);
        return FALSE;
    }
}
