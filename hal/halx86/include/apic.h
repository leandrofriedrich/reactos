/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     Header file for public APIC management
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

FORCEINLINE
ULONG
ApicRead(ULONG Offset)
{
    return READ_REGISTER_ULONG((PULONG)(APIC_BASE + Offset));
}

FORCEINLINE
VOID
ApicWrite(ULONG Offset, ULONG Value)
{
    WRITE_REGISTER_ULONG((PULONG)(APIC_BASE + Offset), Value);
}