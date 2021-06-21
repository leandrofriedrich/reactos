/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/smp/mp.c
 * PURPOSE:     Source file for private memory functions specific to SMP
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* INCLUDES ******************************************************************/

#include <hal.h>
#include <smp.h>
#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/

extern PVOID APEntry;
extern PVOID APEntryEnd;
extern PVOID APSpinup;
extern PVOID APSpinupEnd;

/* FUNCTIONS *****************************************************************/

VOID
HalpInitializeAPStub(PVOID APStubLocation)
{
    PVOID HalpSpinupLoc;
    PVOID HalpAfterSpinupLoc;

    /* Prep the pointers to different spots in the AP bootstub */
    HalpSpinupLoc = (PVOID)((ULONG_PTR)APStubLocation + ((ULONG_PTR)&APEntryEnd  - (ULONG_PTR)&APEntry));
    HalpAfterSpinupLoc = (PVOID)((ULONG_PTR)APStubLocation + ((ULONG_PTR)&APEntryEnd - (ULONG_PTR)&APEntry) + 
        ((ULONG_PTR)&APSpinupEnd - (ULONG_PTR)&APSpinup) + 0x500);
    
    /* Copy over the bootstub for specific AP */
    RtlCopyMemory(APStubLocation, &APEntry,  ((ULONG_PTR)&APEntryEnd - (ULONG_PTR)&APEntry));
    RtlCopyMemory(HalpSpinupLoc, &APSpinup,  ((ULONG_PTR)&APSpinupEnd - (ULONG_PTR)&APSpinup) + 0x500);
}