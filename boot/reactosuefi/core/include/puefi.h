/*
 * PROJECT:     ReactOS UEFI Bootloader
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI core header file
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#pragma once

#include <reactosuefi.h>

VOID
EfiColSetCursor(UINT32 Col, UINT32 Row, EFI_SYSTEM_TABLE* SystemTable);

VOID
EfiColPrint(CHAR16* str,  EFI_SYSTEM_TABLE* SystemTable);

VOID
EfiClearScreen(EFI_SYSTEM_TABLE* SystemTable);

VOID
EfiSetColor(UINTN Attribute, EFI_SYSTEM_TABLE* SystemTable);

// This sets the color of the pixels ( Graphics Color )
EFI_GRAPHICS_OUTPUT_BLT_PIXEL
SetGraphicsColor(UINT32 color);

// This positions the pixel in the row and column ( X and Y )
VOID
SetPixel(UINT32 xPos, UINT32 yPos, EFI_GRAPHICS_OUTPUT_BLT_PIXEL GraphicsColor, EFI_GRAPHICS_OUTPUT_PROTOCOL* gop);

// This creates a filled box of pixels.
// NOTE : Call SetGraphicsColor prior to using this function.
VOID
CreateFilledBox(UINT32 xPos, UINT32 yPos, UINT32 w, UINT32 h, EFI_GRAPHICS_OUTPUT_BLT_PIXEL GraphicsColor, EFI_GRAPHICS_OUTPUT_PROTOCOL* gop);

BOOLEAN
EfiCheckCSM(EFI_BOOT_SERVICES* BootServices);

VOID
HitAnyKey(EFI_SYSTEM_TABLE* SystemTable);

VOID
ResetKeyboard(EFI_SYSTEM_TABLE* SystemTable);

BOOLEAN 
GetKey(CHAR16 key, EFI_INPUT_KEY CheckKeystroke);

EFI_STATUS 
CheckKey(EFI_SYSTEM_TABLE* SystemTable, EFI_INPUT_KEY CheckKeystroke);

VOID 
Delay(UINTN d, EFI_SYSTEM_TABLE* SystemTable);

VOID
EfiStartFileSystem(EFI_HANDLE ImageHandle,
                   EFI_SYSTEM_TABLE *SystemTable,
                   EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume);
VOID
EfiCheckSucess(EFI_STATUS Status, EFI_SYSTEM_TABLE *SystemTable);

EFI_FILE_PROTOCOL*
EfiOpenFile(CHAR16* FileName, EFI_SYSTEM_TABLE *SystemTable);
