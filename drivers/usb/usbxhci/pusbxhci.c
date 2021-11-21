/*
 * PROJECT:         ReactOS xHCI Driver
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         Priate management functions of xHCI
 * COPYRIGHT:       Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include "pusbxhci.h"
//#define NDEBUG
#include <debug.h>
#define NDEBUG_XHCI_TRACE
#include "dbg_xhci.h"

VOID
NTAPI
PXHCI_AssignSlot(IN PXHCI_EXTENSION xhciExtension, ULONG PortID)
{
    /* 4.3.2 of the Intel xHCI spec */
    PXHCI_HC_RESOURCES HcResourcesVA;
    ULONG SlotID, CheckCompletion;
    PXHCI_EXTENSION XhciExtension;
    PXHCI_TRB dequeue_pointer;
    XHCI_EVENT_TRB eventTRB;
    XHCI_TRB Trb;

    SlotID = 0;
    CheckCompletion = INVALID;

    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    HcResourcesVA = XhciExtension -> HcResourcesVA;
    dequeue_pointer = HcResourcesVA-> EventRing.dequeue_pointer;
    eventTRB = (*dequeue_pointer).EventTRB;

    /* Send enable slot command properly */
    Trb.CommandTRB.NoOperation.RsvdZ1 = 0;
    Trb.CommandTRB.NoOperation.RsvdZ2 = 0;
    Trb.CommandTRB.NoOperation.RsvdZ3 = 0;
    Trb.CommandTRB.NoOperation.CycleBit = 1;
    Trb.CommandTRB.NoOperation.RsvdZ4 = 0;
    Trb.CommandTRB.NoOperation.TRBType = ENABLE_SLOT_COMMAND;
    Trb.CommandTRB.NoOperation.RsvdZ5 = 0;
    XHCI_SendCommand(Trb,XhciExtension);

    /* Check for completion and grab the Slot ID */
    DPRINT("PXHCI_AssignSlot: Assigning Slot.\n");
    while (!CheckCompletion)
    {
        SlotID = eventTRB.CommandCompletionTRB.SlotID;
        CheckCompletion = eventTRB.CommandCompletionTRB.CompletionCode;
        if(CheckCompletion == SUCCESS)
        {
            break;
        }
    }
    
    DPRINT("PXHCI_AssignSlot: The Slot ID assigned is %X\n", SlotID);
    PXHCI_InitSlot(xhciExtension, PortID, SlotID);
}

VOID
NTAPI
PXHCI_InitSlot(IN PXHCI_EXTENSION xhciExtension, ULONG PortID, ULONG SlotID)
{
    /* 4.3.3 of the Intel xHCI spec */
    PXHCI_INPUT_CONTROL_CONTEXT HcInputControlContext;
    XHCI_SLOT_CONTEXT HcSlotContext;
    PXHCI_EXTENSION XhciExtension;
    XHCI_ENDPOINT xHCIInputControlContext;
    PXHCI_DEVICE_CONTEXT xHCIDeviceContext;
    PHYSICAL_ADDRESS max;

    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    max.QuadPart = -1;

    HcInputControlContext = MmAllocateContiguousMemory(sizeof(XHCI_INPUT_CONTROL_CONTEXT), max);
    xHCIDeviceContext = MmAllocateContiguousMemory(sizeof(XHCI_DEVICE_CONTEXT), max);

    /* Zero out our instance of XHCI_INPUT_CONTROL_CONTEXT */
    RtlZeroMemory((PVOID)HcInputControlContext, sizeof(XHCI_INPUT_CONTROL_CONTEXT));

    /* Set A0 and A1 as per the spec */
    HcInputControlContext->A0 = 1;
    HcInputControlContext->A1 = 1;

    /* Route Strings are for high speed/thunderbolt devices,
        for now we don't have the stuff in our stack to achieve these
        defaulting to standard xHCI mode */
    HcSlotContext.RouteString = 0;
    HcSlotContext.ContextEntries = 1;
    HcSlotContext.ParentPortNumber = PortID;

    xHCIInputControlContext.EPType = 4;
    xHCIInputControlContext.MaxBurstSize = 0;
    //xHCIInputControlContext.TRDeqPtr = address
    xHCIInputControlContext.DCS = 1;
    xHCIInputControlContext.Interval = 0;
    xHCIInputControlContext.MaxPStreams = 0;
    xHCIInputControlContext.Mult = 0;
    xHCIInputControlContext.CErr = 3;

    RtlZeroMemory((PVOID)xHCIDeviceContext, sizeof(XHCI_DEVICE_CONTEXT));

    __debugbreak();
    /* After all data in Initalized; Go assign the address to the USB Device */
}

VOID
NTAPI
PXHCI_AssignAddress(IN PXHCI_EXTENSION xhciExtension, ULONG PortID)
{

}

