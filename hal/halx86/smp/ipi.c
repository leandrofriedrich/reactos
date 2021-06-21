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

