
/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/include/smp.h
 * PURPOSE:     Public Header File for SMP
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#pragma once

/* APIC specific functions inside apic/apicsmp.c */

BOOLEAN /* HalStartApplicationProcessor */
ApicStartApplicationProcessor(ULONG NTProcessorNumber, PHYSICAL_ADDRESS StartupLoc);

VOID
NTAPI /* HalRequestIpi (CONFIG_SMP) */
HalpRequestIpi(KAFFINITY TargetProcessors);
