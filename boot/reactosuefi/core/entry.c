/*
 * PROJECT:     ReactOS UEFI Bootloader
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI entry point
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include "include/uefi.h"

EFI_STATUS
EfiEntry (
    _In_ EFI_HANDLE ImageHandle,
    _In_ EFI_SYSTEM_TABLE *SystemTable
    )
{
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_BLUE);
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Starting ReactOS UEFI Loader...");

    while (1){};
    return EFI_SUCCESS;
}

/* 
 * ExitBootServices preperation (Section 2.3.2):
 *
 */
VOID
EfiExitBootServices()
{
}