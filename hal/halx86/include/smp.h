
/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/include/smp.h
 * PURPOSE:     Header File for SMP
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

/* MADT information */
#pragma once

#define LOCAL_APIC_VERSION_MAX 0x1F
#define MAX_IOAPICS      64

/* APIC specific functions inside apic/apicsmp.c */
FORCEINLINE
VOID
ApicRequestGlobalInterrupt(
    _In_ UCHAR DestinationProcessor,
    _In_ UCHAR Vector,
    _In_ APIC_MT MessageType,
    _In_ APIC_TGM TriggerMode,
    _In_ APIC_DSH DestinationShortHand);

FORCEINLINE
ULONG
ApicReadRemoteRegister(
    _In_ UCHAR DestinationProcessor,
    _In_ APIC_REGISTER ApicRegister);

VOID
NTAPI
HalpRequestIpi(KAFFINITY TargetProcessors);
