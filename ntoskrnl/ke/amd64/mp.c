/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        ntoskrnl/ke/amd64/mp.c
 * PURPOSE:     processor specific file to hold multiprocessor functions
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* INCLUDES *****************************************************************/

#include <ntoskrnl.h>
#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/
/* FUNCTIONS *****************************************************************/
VOID
NTAPI
KeStartAllProcessors()
{
    /* This function is still unimplemented for x64, this is just a place holder to get APs going */
    BOOLEAN ProcessorsStarted = FALSE;
    ULONG ProcessorCount = 0;
    BOOLEAN Success = FALSE;

    while(ProcessorsStarted == FALSE)
    {
        Success = HalStartNextProcessor(NULL, NULL);
        /* This isn't a bad failure, sometimes we just run out of processors to start */
        if(Success == FALSE)
        {
            /* Offset as we didn't sucessfully start a supposive AP */
            ProcessorCount += -1;
            /* This will not show the accurate number until MADT is in */
            //DPRINT1("KeStartAllProcessors has started %X extra processors \n", ProcessorCount);
            /* Clear memory and end the AP Startup process */
            ProcessorsStarted = TRUE;
            break;
        }
    }
} 