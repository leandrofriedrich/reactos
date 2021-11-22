/*
 * PROJECT:     ReactOS UEFI Bootloader
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI Misc functions
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include "include/uefi.h"

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
