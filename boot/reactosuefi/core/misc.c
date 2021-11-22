/*
 * PROJECT:     ReactOS UEFI Bootloader
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI Misc functions
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include <puefi.h>


BOOLEAN
EfiCheckCSM(EFI_BOOT_SERVICES* BootServices)
{
    EFI_STATUS EFIStatus;
    EFI_GUID EFIGuid = EFI_LEGACY_BIOS_PROTOCOL_GUID;
    EFI_HANDLE EFIHandle= NULL;
    UINTN count;

    EFIStatus = BootServices->LocateHandleBuffer(ByProtocol, &EFIGuid, NULL, &count, EFIHandle);
    if (EFI_ERROR == EFIStatus)
    {
        return FALSE;
    }

    if (count == 0)
    {
        EFIStatus = EFI_NOT_FOUND;
        BootServices->FreePool(EFIHandle);
        return FALSE;
    }

    else
    {
        return TRUE;
    }
}

VOID
HitAnyKey(EFI_SYSTEM_TABLE* SystemTable)
{
    // This clears the keyboard buffer.
    SystemTable->ConIn->Reset(SystemTable->ConIn, 1);

    // We setup the struct to take keyboard input.
    EFI_INPUT_KEY Key;

    // In a while loop to see if the keyboard has a key stroke in the buffer.
    while((SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key)) == EFI_NOT_READY);
}

VOID
ResetKeyboard(EFI_SYSTEM_TABLE* SystemTable)
{
    SystemTable->ConIn->Reset(SystemTable->ConIn, 1);
}

BOOLEAN 
GetKey(CHAR16 key, EFI_INPUT_KEY CheckKeystroke)
{
    if(CheckKeystroke.UnicodeChar == key)
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

EFI_STATUS 
CheckKey(EFI_SYSTEM_TABLE* SystemTable, EFI_INPUT_KEY CheckKeystroke)
{
    return SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &CheckKeystroke);
}

VOID 
Delay(UINTN d, EFI_SYSTEM_TABLE* SystemTable)
{
    // The Stall function is set is microseconds. So you have to convert
    // from microseconds ( µs ) to milliseconds ( ms ). EXAMPLE : 1ms = 1000µs.
    // The microsecond is the smallest unit of time measurement the EFI provides.
    SystemTable->BootServices->Stall(d * 1000);
}