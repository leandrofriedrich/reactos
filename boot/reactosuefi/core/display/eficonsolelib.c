/*
 * PROJECT:     ReactOS UEFI Bootloader
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI console header
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include <puefi.h>

VOID
EfiColSetCursor(UINT32 Col, UINT32 Row, EFI_SYSTEM_TABLE* SystemTable)
{
    SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, Col, Row);
}

VOID
EfiColPrint(CHAR16* str,  EFI_SYSTEM_TABLE* SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, str);
}

VOID
EfiClearScreen(EFI_SYSTEM_TABLE* SystemTable)
{
    // This clears the screen buffer, but does not reset it.
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
}

VOID
EfiSetColor(UINTN Attribute, EFI_SYSTEM_TABLE* SystemTable)
{
    // We set the color for the text output.
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, Attribute);
}
