#include "bootmgr.h"
/*++
 * @name EfiEntry
 *
 *     The EfiEntry routine implements the UEFI entrypoint for the application.
 *
 * @param  ImageHandle
 *         UEFI Image Handle for the current loaded application.
 *
 * @param  SystemTable
 *         Pointer to the UEFI System Table.
 *
 * @return EFI_SUCCESS if the image was loaded correctly, relevant error code
 *         otherwise.
 *
 *--*/
EFI_STATUS
EFIAPI
EfiEntry (
    _In_ EFI_HANDLE ImageHandle,
    _In_ EFI_SYSTEM_TABLE *SystemTable
    )
{
    /* Convert the NT status code to an EFI code */
    return 0;
}

