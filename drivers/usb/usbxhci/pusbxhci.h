/*
 * PROJECT:         ReactOS xHCI Driver
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         private xHCI functions and definitions
 * COPYRIGHT:       Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#pragma once

#include "usbxhci.h"

/* Private Functions ******************************************************************************/

MPSTATUS
NTAPI
PXHCI_ControllerWorkTest(IN PXHCI_EXTENSION XhciExtension,
                         IN PXHCI_HC_RESOURCES HcResourcesVA,
                         IN PVOID resourcesStartPA);

VOID
NTAPI
PXHCI_AssignSlot(IN PXHCI_EXTENSION xhciExtension);

VOID
NTAPI
PXHCI_InitSlot(IN PXHCI_EXTENSION xhciExtension, ULONG SlotID);

VOID
NTAPI
PXHCI_AssignAddress(IN PXHCI_EXTENSION xhciExtension);
