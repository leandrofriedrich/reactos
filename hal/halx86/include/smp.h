
/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/include/smp.h
 * PURPOSE:     Public Header File for SMP
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* MADT information */
#pragma once

#define LOCAL_APIC_VERSION_MAX 0x1F
#define MAX_IOAPICS      64

/* APIC specific functions inside apic/apicsmp.c */

BOOLEAN /* HalStartApplicationProcessor */
ApicStartApplicationProcessor(ULONG NTProcessorNumber, PHYSICAL_ADDRESS StartupLoc);

VOID /* HalpStopAP */
ApicSoftlyStopApplicationProcessor(ULONG NTProcessorNumber);

VOID /* HalpStopAllAPs */
ApicHarshlyStopAllApplicationProcessors(VOID);

VOID
NTAPI
HalpRequestIpi(KAFFINITY TargetProcessors);
