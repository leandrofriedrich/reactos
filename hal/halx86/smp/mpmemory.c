
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
#include "smpp.h"
#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/

/* Bootstub specific */
extern PVOID APEntry;
extern PVOID APEntryEnd;
extern PVOID APSpinup;
extern PVOID APSpinupEnd;

/* Pagetables specific */
#define MM_PAGE_SIZE     4096
#define MM_PAGE_SHIFT    12
#define SELFMAP_ENTRY    0x300

PFN_NUMBER TotalPagesInLookupTable = 0;
PHARDWARE_PTE PDE;

/* FUNCTIONS *****************************************************************/

VOID
HalpInitializeAPStub(PVOID APStubLocation)
{
    PVOID HalpSpinupLoc;
    //PVOID HalpAfterSpinupLoc;

    /* Prep the pointers to different spots in the AP bootstub */
    HalpSpinupLoc = (PVOID)((ULONG_PTR)APStubLocation + ((ULONG_PTR)&APEntryEnd  - (ULONG_PTR)&APEntry));
    /* HalpAfterSpinupLoc = (PVOID)((ULONG_PTR)APStubLocation + ((ULONG_PTR)&APEntryEnd - (ULONG_PTR)&APEntry) + 
        ((ULONG_PTR)&APSpinupEnd - (ULONG_PTR)&APSpinup)); */
    /* Copy over the bootstub for specific AP */
    RtlCopyMemory(APStubLocation, &APEntry,  ((ULONG_PTR)&APEntryEnd - (ULONG_PTR)&APEntry));
    RtlCopyMemory(HalpSpinupLoc, &APSpinup,  ((ULONG_PTR)&APSpinupEnd - (ULONG_PTR)&APSpinup));
    //RtlCopyMemory(HalpAfterSpinupLoc, NULL,  0x500); //This is just some memory after everything
}

VOID
HalpInitializeAPPageTables(PVOID APStubLocation)
{
   ULONG NumPageTables, TotalSize;
   PUCHAR Buffer;
   PVOID HalpAfterSpinupLoc;

   NumPageTables = TotalPagesInLookupTable >> 10;

   // Allocate memory block for all these things:
   // PDE, HAL mapping page table, physical mapping, kernel mapping
   TotalSize = (1 + 1 + NumPageTables * 2) * MM_PAGE_SIZE;

   HalpAfterSpinupLoc = (PVOID)((ULONG_PTR)APStubLocation + ((ULONG_PTR)&APEntryEnd - (ULONG_PTR)&APEntry) + 
        ((ULONG_PTR)&APSpinupEnd - (ULONG_PTR)&APSpinup));
   Buffer = (PUCHAR)HalpAfterSpinupLoc;
     // Zero all this memory block
   RtlZeroMemory(Buffer, TotalSize);

   // Set up pointers correctly now
   PDE = (PHARDWARE_PTE)Buffer;

   // Map the page directory at 0xC0000000 (maps itself)
   PDE[SELFMAP_ENTRY].PageFrameNumber = (ULONG)PDE >> MM_PAGE_SHIFT;
   PDE[SELFMAP_ENTRY].Valid = 1;
   PDE[SELFMAP_ENTRY].Write = 1;

   RtlCopyMemory(HalpAfterSpinupLoc, &PDE, (ULONG_PTR)TotalSize);
}