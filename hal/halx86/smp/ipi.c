/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/smp/ipi.c
 * PURPOSE:     Source file for IPIs on the HAL side
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* INCLUDES ******************************************************************/

#include <hal.h>
#include <smp.h>
#include <apic.h>
#define NDEBUG
#include <debug.h>

/* FUNCTIONS *****************************************************************/

VOID
HalpRequestIpi(KAFFINITY TargetProcessors)
{
    DPRINT1("HalRequestIpi: is unimplemented.");
    __debugbreak();
}


BOOLEAN
HalpStartApplicationProcessor(ULONG NTProcessorNumber, PHYSICAL_ADDRESS APStubLocation)
{
    ULONG tmp, i, flags;

    /* save flags and disable interrupts */
    flags = __readeflags();
    _disable();

    /* INIT IPI */
    ApicWrite(APIC_ICR1, (NTProcessorNumber << 24));
    ApicWrite(APIC_ICR0, APIC_DM_INIT);

    /* Stall execution for a bit to give APIC time */
    KeStallExecutionProcessor(1000);
    
    /* Startup IPI */
    ApicWrite(APIC_ICR1, (NTProcessorNumber << 24));
    ApicWrite(APIC_ICR0, APIC_DM_STARTUP | ((APStubLocation.LowPart) >> 12));

    /* Wait for APIC to write and detect sucess status */
    for (i = 0; i < 10000; i++) 
    {
        tmp = ApicRead(APIC_ICR0);
        /* Check Delivery Status */
        if ((tmp & APIC_ICR0_DS) == 0)
            break;
        KeStallExecutionProcessor(10);
    }
    
    /* There's a few cases this can fail:
     * - APIC version not supporting anymore LAPICs
     * - No Application Processors at the number given
     * - Some failure in APIC read or writes
     * - Hardware not accepting the command for some other reason
     */
    if(i == 10000)
    {
        DPRINT("HalpStartApplicationProcessor: Could not start AP\n");
        __writeeflags(flags);
        return FALSE;
    }
    else
    {
        __writeeflags(flags);
        return TRUE;
    }
}
