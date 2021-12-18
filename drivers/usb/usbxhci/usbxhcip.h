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


/* Device Initalization *************************************************************************/

VOID
NTAPI
PXHCI_PortStatusChange(IN PXHCI_EXTENSION xhciExtension, IN ULONG PortID);

/* Transfer type functions ************************************************************************/

MPSTATUS
NTAPI
PXHCI_InitTransferBulk(PVOID xhciExtension);

MPSTATUS
NTAPI
PXHCI_InitTransferInterrupt(PVOID xhciExtension);

MPSTATUS
NTAPI
PXHCI_InitTransferIso(PVOID xhciExtension);

MPSTATUS
NTAPI
PXHCI_InitTransferControl(PVOID xhciExtension);
