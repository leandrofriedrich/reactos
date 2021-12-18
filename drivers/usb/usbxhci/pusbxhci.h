/*
 * PROJECT:         ReactOS xHCI Driver
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         private xHCI functions and definitions
 * COPYRIGHT:       Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#pragma once

#include "usbxhci.h"

/* Private Functions ******************************************************************************/

VOID
NTAPI
PXHCI_PortStatusChange(IN PXHCI_EXTENSION xhciExtension, IN ULONG PortID);

VOID
NTAPI
PXHCI_AssignSlot(IN PXHCI_EXTENSION xhciExtension, ULONG PortID);

VOID
NTAPI
PXHCI_InitSlot(IN PXHCI_EXTENSION xhciExtension, ULONG PortID, ULONG SlotID);

VOID
NTAPI
PXHCI_AssignAddress(IN PXHCI_EXTENSION xhciExtension, ULONG PortID);

VOID
NTAPI
PXHCI_ConfigureDevice(IN PXHCI_EXTENSION xhciExtension, ULONG PortID);
