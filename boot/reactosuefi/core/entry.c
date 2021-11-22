/*
 * PROJECT:     ReactOS UEFI Bootloader
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI entry point
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include <puefi.h>

struct EFI_GUID EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID    = {0x9042a9de, 0x23dc, 0x4a38, {0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a}};
struct EFI_GUID EFI_LOADED_IMAGE_PROTOCOL_GUID       = {0x5b1b31a1, 0x9562, 0x11d2, {0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
struct EFI_GUID EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID = {0x964e5b22, 0x6459, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
struct EFI_GUID EFI_DEVICE_PATH_PROTOCOL_GUID        = {0x09576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
struct EFI_GUID EFI_FILE_INFO_GUID                   = {0x09576e92, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};

unsigned short int* CheckStandardEFIError(unsigned long long s)
{
    switch(s)
    {
        case EFI_LOAD_ERROR:
        {
            return (unsigned short int*)L" Load Error\r\n";
        }
        case EFI_INVALID_PARAMETER:
        {
            return (unsigned short int*)L" Invalid Parameter\r\n";
        }
        case EFI_UNSUPPORTED:
        {
            return (unsigned short int*)L" Unsupported\r\n";
        }
        case EFI_BAD_BUFFER_SIZE:
        {
            return (unsigned short int*)L" Bad Buffer Size\r\n";
        }
        case EFI_BUFFER_TOO_SMALL:
        {
            return (unsigned short int*)L" Buffer Too Small\r\n";
        }
        case EFI_NOT_READY:
        {
            return (unsigned short int*)L" Not Ready\r\n";
        }
        case EFI_DEVICE_ERROR:
        {
            return (unsigned short int*)L" Device Error\r\n";
        }
        case EFI_WRITE_PROTECTED:
        {
            return (unsigned short int*)L" Write Protected\r\n";
        }
        case EFI_OUT_OF_RESOURCES:
        {
            return (unsigned short int*)L" Out Of Resources\r\n";
        }
        case EFI_VOLUME_CORRUPTED:
        {
            return (unsigned short int*)L" Volume Corrupted\r\n";
        }
        case EFI_VOLUME_FULL:
        {
            return (unsigned short int*)L" Volume Full\r\n";
        }
        case EFI_NO_MEDIA:
        {
            return (unsigned short int*)L" No Media\r\n";
        }
        case EFI_MEDIA_CHANGED:
        {
            return (unsigned short int*)L" Media Changed\r\n";
        }
        case EFI_NOT_FOUND:
        {
            return (unsigned short int*)L" File Not Found\r\n";
        }
        case EFI_ACCESS_DENIED:
        {
            return (unsigned short int*)L" Access Denied\r\n";
        }
        case EFI_NO_RESPONSE:
        {
            return (unsigned short int*)L" No Response\r\n";
        }
        case EFI_NO_MAPPING:
        {
            return (unsigned short int*)L" No Mapping\r\n";
        }
        case EFI_TIMEOUT:
        {
            return (unsigned short int*)L" Timeout\r\n";
        }
        case EFI_NOT_STARTED:
        {
            return (unsigned short int*)L" Not Started\r\n";
        }
        case EFI_ALREADY_STARTED:
        {
            return (unsigned short int*)L" Already Started\r\n";
        }
        case EFI_ABORTED:
        {
            return (unsigned short int*)L" Aborted\r\n";
        }
        case EFI_ICMP_ERROR:
        {
            return (unsigned short int*)L" ICMP Error\r\n";
        }
        case EFI_TFTP_ERROR:
        {
            return (unsigned short int*)L" TFTP Error\r\n";
        }
        case EFI_PROTOCOL_ERROR:
        {
            return (unsigned short int*)L" Protocol Error\r\n";
        }
        case EFI_INCOMPATIBLE_VERSION:
        {
            return (unsigned short int*)L" Incompatible Version\r\n";
        }
        case EFI_SECURITY_VIOLATION:
        {
            return (unsigned short int*)L" Security Violation\r\n";
        }
        case EFI_CRC_ERROR:
        {
            return (unsigned short int*)L" CRC Error\r\n";
        }
        case EFI_END_OF_MEDIA:
        {
            return (unsigned short int*)L" End Of Media\r\n";
        }
        case EFI_END_OF_FILE:
        {
            return (unsigned short int*)L" End Of File\r\n";
        }
        case EFI_INVALID_LANGUAGE:
        {
            return (unsigned short int*)L" Invalid Language\r\n";
        }
        case EFI_COMPROMISED_DATA:
        {
            return (unsigned short int*)L" Compromised Data\r\n";
        }
        case EFI_IP_ADDRESS_CONFLICT:
        {
            return (unsigned short int*)L" IP Address Conflict\r\n";
        }
        case EFI_HTTP_ERROR:
        {
            return (unsigned short int*)L" End Of File\r\n";
        }
        case EFI_WARN_UNKNOWN_GLYPH:
        {
            return (unsigned short int*)L" WARNING - Unknown Glyph\r\n";
        }
        case EFI_WARN_DELETE_FAILURE:
        {
            return (unsigned short int*)L" WARNING - Delete Failure\r\n";
        }
        case EFI_WARN_WRITE_FAILURE:
        {
            return (unsigned short int*)L" WARNING - Write Failure\r\n";
        }
        case EFI_WARN_BUFFER_TOO_SMALL:
        {
            return (unsigned short int*)L" WARNING - Buffer Too Small\r\n";
        }
        case EFI_WARN_STALE_DATA:
        {
            return (unsigned short int*)L" WARNING - Stale Data\r\n";
        }
        case EFI_WARN_FILE_SYSTEM:
        {
            return (unsigned short int*)L" WARNING - File System\r\n";
        }
        case EFI_WARN_RESET_REQUIRED:
        {
            return (unsigned short int*)L" WARNING - Reset Required\r\n";
        }
        case EFI_SUCCESS:
        {
            return (unsigned short int*)L" Successful\r\n";
        }
    }
    return (unsigned short int*)L" ERROR\r\n";
}


EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume;
EFI_FILE_PROTOCOL* efiload;
EFI_STATUS
EfiEntry (
    _In_ EFI_HANDLE ImageHandle,
    _In_ EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_BLUE);

    EfiClearScreen(SystemTable);
    EfiColPrint(L"Starting ReactOS UEFI Loader...", SystemTable);
    Delay(300, SystemTable);

    EFI_STATUS Status = SystemTable->BootServices->LocateProtocol(&EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, 0, (void**)&gop);

    Delay(8, SystemTable);
    EfiClearScreen(SystemTable);
    EfiStartFileSystem(ImageHandle, SystemTable, Volume);
    efiload = EfiOpenFile(L"efiload.txt", SystemTable);
    while (1){};
    return Status;
}

VOID
EfiStartFileSystem(EFI_HANDLE ImageHandle,
                   EFI_SYSTEM_TABLE *SystemTable,
                   EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume)
{
    EFI_STATUS Status; 
    EFI_LOADED_IMAGE_PROTOCOL *LoadedImage;
    EFI_DEVICE_PATH_PROTOCOL *DevicePath;
    Status = SystemTable->BootServices->HandleProtocol(ImageHandle, &EFI_LOADED_IMAGE_PROTOCOL_GUID, (void**)&LoadedImage);
    Status = SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_DEVICE_PATH_PROTOCOL_GUID, (void**)&DevicePath);
    Status = SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID, (void**)&Volume);
    EfiCheckSucess(Status, SystemTable);
    EfiColPrint(L"File System is ready",SystemTable);
}

EFI_FILE_PROTOCOL*
EfiOpenFile(CHAR16* FileName, EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_STATUS Status;
    EFI_FILE_PROTOCOL* RootFS;
    EFI_FILE_PROTOCOL* FileHandle = NULL;
    EfiSetColor(EFI_MAGENTA, SystemTable);
    Status = Volume->OpenVolume(Volume, &RootFS);
    EfiCheckSucess(Status, SystemTable);
    Status = RootFS->Open(RootFS, &FileHandle, FileName, 0x0000000000000001, 0);
    EfiCheckSucess(Status, SystemTable);
    return FileHandle;
}
VOID
EfiCheckSucess(EFI_STATUS Status, EFI_SYSTEM_TABLE *SystemTable)
{
    if (Status == 0)
    {
        EfiColPrint(L":D yay",SystemTable);
    }
    else
    {
        EfiColPrint(L"D: nuuuu",SystemTable);
    }
}
/* 
 * ExitBootServices preperation (Section 2.3.2):
 *
 */
VOID
EfiExitBootServices()
{

}