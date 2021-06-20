/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     Header file for public APIC management
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include <../apic/apic.h>

FORCEINLINE
ULONG
HalpApicRead(ULONG Offset)
{
    ApicRead(Offset);
}

FORCEINLINE
VOID
HalpApicWrite(ULONG Offset, ULONG Value)
{
    ApicWrite(Offset, Value);
}
