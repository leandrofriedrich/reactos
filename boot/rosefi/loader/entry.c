/*
 * PROJECT:     ROSUEFI
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI entry point
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include "include/uefiloader.h"

EFI_STATUS
RefiEntry(
    _In_ EFI_HANDLE ImageHandle,
    _In_ EFI_SYSTEM_TABLE *SystemTable)
{
    RefiClearScreen(SystemTable);
    RefiColPrint(L"ROSEFI entry point loaded!", SystemTable);
    RefiClearScreen(SystemTable);
    RefiSetColor(EFI_MAGENTA, SystemTable);
    RefiColPrint(L"Starting ReactOS from UEFI...", SystemTable);
    RefiSetColor(EFI_RED, SystemTable);
    RefiColPrint(L"Could not find registry hives", SystemTable);
    RefiSetColor(EFI_LIGHTGREEN, SystemTable);
    RefiColPrint(L"Hello ARM64 UEFI World from ReactOS!", SystemTable);


    for(;;)
    {

    }
    return 0;
}


VOID 
RefiStallProcessor(EFI_SYSTEM_TABLE* SystemTable, UINTN d)
{
    SystemTable->BootServices->Stall(d * 1000);
}
