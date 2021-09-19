/*
 * PROJECT:         ReactOS xHCI Driver
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         xHCI specification structs
 * COPYRIGHT:       Copyright 2017 Rama Teja Gampa <ramateja.g@gmail.com>
 */

#pragma once 

#include "usbxhci.h"

#define XHCI_FLAGS_CONTROLLER_SUSPEND 0x01

typedef struct  _XHCI_DEVICE_CONTEXT_BASE_ADD_ARRAY 
{
    PHYSICAL_ADDRESS ContextBaseAddr [256];
} XHCI_DEVICE_CONTEXT_BASE_ADD_ARRAY, *PXHCI_DEVICE_CONTEXT_BASE_ADD_ARRAY;


/* Link TRB ***************************************************************************************/

typedef union _XHCI_LINK_ADDR
{
    struct 
    {
        ULONGLONG RsvdZ1                     : 4;
        ULONGLONG RingSegmentPointerLo       : 28;
        ULONGLONG RingSegmentPointerHi       : 32;
    };
    ULONGLONG AsULONGLONG;
} XHCI_LINK_ADDR;

typedef struct _XHCI_LINK_TRB
{
    struct 
    {
        ULONG RsvdZ1                     : 4;
        ULONG RingSegmentPointerLo       : 28;
    };
    struct 
    {
        ULONG RingSegmentPointerHi       : 32;
    };
    struct 
    {
        ULONG RsvdZ2                     : 22;
        ULONG InterrupterTarget          : 10;
    };
    struct 
    {
        ULONG CycleBit                  : 1;
        ULONG ToggleCycle               : 1;
        ULONG RsvdZ3                    : 2;
        ULONG ChainBit                  : 1;
        ULONG InterruptOnCompletion     : 1;
        ULONG RsvdZ4                    : 4;
        ULONG TRBType                   : 6;
        ULONG RsvdZ5                    : 16;
    };
} XHCI_LINK_TRB;
C_ASSERT(sizeof(XHCI_LINK_TRB) == 16);

/* Generic TRB ************************************************************************************/

typedef struct _XHCI_GENERIC_TRB {
    ULONG Word0;
    ULONG Word1;
    ULONG Word2;
    ULONG Word3;
}XHCI_GENERIC_TRB, *PXHCI_GENERIC_TRB;
C_ASSERT(sizeof(XHCI_GENERIC_TRB) == 16);

/* Command TRB ************************************************************************************/

typedef struct _XHCI_COMMAND_NO_OP_TRB 
{
    ULONG RsvdZ1;
    ULONG RsvdZ2;
    ULONG RsvdZ3;
    struct
    {
        ULONG CycleBit                  : 1;
        ULONG RsvdZ4                    : 9;
        ULONG TRBType                   : 6;
        ULONG RsvdZ5                    : 16;
    };
} XHCI_COMMAND_NO_OP_TRB;
C_ASSERT(sizeof(XHCI_COMMAND_NO_OP_TRB) == 16);

typedef union _XHCI_COMMAND_TRB 
{
    XHCI_COMMAND_NO_OP_TRB NoOperation;
}XHCI_COMMAND_TRB, *PXHCI_COMMAND_TRB;
C_ASSERT(sizeof(XHCI_COMMAND_TRB) == 16);

/* Control Transfer Data Structures ***************************************************************/

typedef struct _XHCI_CONTROL_SETUP_TRB 
{
    struct 
    {
        ULONG bmRequestType             : 8;
        ULONG bRequest                  : 8;
        ULONG wValue                    : 16;
    };
    struct 
    {
        ULONG wIndex                    : 16;
        ULONG wLength                   : 16;
    };
    struct 
    {
        ULONG TRBTransferLength         : 17;
        ULONG RsvdZ                     : 5;
        ULONG InterrupterTarget         : 10;
    };
    struct 
    {
        ULONG CycleBit                  : 1;
        ULONG RsvdZ1                    : 4;
        ULONG InterruptOnCompletion     : 1;
        ULONG ImmediateData             : 1;
        ULONG RsvdZ2                    : 3;
        ULONG TRBType                   : 6;
        ULONG TransferType              : 2;
        ULONG RsvdZ3                    : 14;
    };
} XHCI_CONTROL_SETUP_TRB;
C_ASSERT(sizeof(XHCI_CONTROL_SETUP_TRB) == 16);

typedef struct _XHCI_CONTROL_DATA_TRB 
{
    struct 
    {
        ULONG DataBufferPointerLo       : 32;
    };
    struct 
    {
        ULONG DataBufferPointerHi       : 32;
    };
    struct 
    {
        ULONG TRBTransferLength         : 17;
        ULONG TDSize                    : 5;
        ULONG InterrupterTarget         : 10;
    };
    struct 
    {
        ULONG CycleBit                  : 1;
        ULONG EvaluateNextTRB           : 1;
        ULONG InterruptOnShortPacket    : 1;
        ULONG NoSnoop                   : 1;
        ULONG ChainBit                  : 1;
        ULONG InterruptOnCompletion     : 1;
        ULONG ImmediateData             : 1;
        ULONG RsvdZ1                    : 2;
        ULONG TRBType                   : 6;
        ULONG Direction                 : 1;
        ULONG RsvdZ2                    : 15;
    };
} XHCI_CONTROL_DATA_TRB;
C_ASSERT(sizeof(XHCI_CONTROL_DATA_TRB) == 16);

typedef struct _XHCI_CONTROL_STATUS_TRB 
{
    struct 
    {
        ULONG RsvdZ1                    : 32;
    };
    struct 
    {
        ULONG RsvdZ2                    : 32;
    };
    struct 
    {
        ULONG RsvdZ                     : 22;
        ULONG InterrupterTarget         : 10;
    };
    struct 
    {
        ULONG CycleBit                  : 1;
        ULONG EvaluateNextTRB           : 1;
        ULONG ChainBit                  : 2;
        ULONG InterruptOnCompletion     : 1;
        ULONG RsvdZ3                    : 4;
        ULONG TRBType                   : 6;
        ULONG Direction                 : 1;
        ULONG RsvdZ4                    : 15;
    };
} XHCI_CONTROL_STATUS_TRB;
C_ASSERT(sizeof(XHCI_CONTROL_STATUS_TRB) == 16);

typedef union _XHCI_CONTROL_TRB 
{
    XHCI_CONTROL_SETUP_TRB  SetupTRB;
    XHCI_CONTROL_DATA_TRB   DataTRB;
    XHCI_CONTROL_STATUS_TRB StatusTRB;
    XHCI_GENERIC_TRB    GenericTRB;
} XHCI_CONTROL_TRB, *PXHCI_CONTROL_TRB;  
C_ASSERT(sizeof(XHCI_CONTROL_TRB) == 16);

/* Event Structs **********************************************************************************/

typedef struct _XHCI_EVENT_COMMAND_COMPLETION_TRB
{
    struct 
    {
        ULONG RsvdZ1                : 4;
        ULONG CommandTRBPointerLo   : 28;
    };
    ULONG CommandTRBPointerHi;
    struct 
    {
        ULONG CommandCompletionParam     : 24;
        ULONG CompletionCode             : 8;
    };
    struct 
    {
        ULONG CycleBit          : 1;
        ULONG RsvdZ2            : 9;
        ULONG TRBType           : 6;
        ULONG VFID              : 8;
        ULONG SlotID            : 8;
    };
} XHCI_EVENT_COMMAND_COMPLETION_TRB;
C_ASSERT(sizeof(XHCI_EVENT_COMMAND_COMPLETION_TRB) == 16);

typedef struct _XHCI_EVENT_PORT_STATUS_CHANGE_TRB
{
    struct 
    {
        ULONG RsvdZ1                : 24;
        ULONG PortID                : 8;
    };
    ULONG RsvdZ2;
    struct 
    {
        ULONG RsvdZ3                     : 24;
        ULONG CompletionCode             : 8;
    };
    struct 
    {
        ULONG CycleBit          : 1;
        ULONG RsvdZ4            : 9;
        ULONG TRBType           : 6;
        ULONG RsvdZ5            : 16;
    };
} XHCI_EVENT_PORT_STATUS_CHANGE_TRB;
C_ASSERT(sizeof(XHCI_EVENT_PORT_STATUS_CHANGE_TRB) == 16);

typedef struct _XHCI_EVENT_GENERIC_TRB
{
    ULONG Word0;
    ULONG Word1;
    ULONG Word2;
    struct 
    {
        ULONG CycleBit          : 1;
        ULONG RsvdZ1            : 9;
        ULONG TRBType           : 6;
        ULONG RsvdZ2            : 8;
        ULONG SlotID            : 8;
    };
}XHCI_EVENT_GENERIC_TRB;
C_ASSERT(sizeof(XHCI_EVENT_GENERIC_TRB) == 16);

typedef union _XHCI_EVENT_TRB 
{
    XHCI_EVENT_COMMAND_COMPLETION_TRB   CommandCompletionTRB;
    XHCI_EVENT_PORT_STATUS_CHANGE_TRB   PortStatusChangeTRB;
    XHCI_EVENT_GENERIC_TRB              EventGenericTRB;
}XHCI_EVENT_TRB, *PXHCI_EVENT_TRB;
C_ASSERT(sizeof(XHCI_EVENT_TRB) == 16);

// 6.5
typedef struct _XHCI_EVENT_RING_SEGMENT_TABLE
{
    ULONGLONG RingSegmentBaseAddr;
    struct 
    {
        ULONGLONG RingSegmentSize :  16;
        ULONGLONG RsvdZ           :  48;
    };
} XHCI_EVENT_RING_SEGMENT_TABLE;

/* Main Structs ***********************************************************************************/

typedef union _XHCI_TRB 
{
    XHCI_COMMAND_TRB    CommandTRB;
    XHCI_LINK_TRB       LinkTRB;
    XHCI_CONTROL_TRB    ControlTRB;
    XHCI_EVENT_TRB      EventTRB;
    XHCI_GENERIC_TRB    GenericTRB;
} XHCI_TRB, *PXHCI_TRB;
C_ASSERT(sizeof(XHCI_TRB) == 16);

typedef struct _XHCI_SEGMENT 
{
    XHCI_TRB XhciTrb[256];
    PVOID nextSegment;
}XHCI_SEGMENT, *PXHCI_SEGMENT;

typedef struct _XHCI_RING 
{
    XHCI_SEGMENT firstSeg;
    PXHCI_TRB dequeue_pointer;
    PXHCI_TRB enqueue_pointer;
    PXHCI_SEGMENT enqueue_segment;
    PXHCI_SEGMENT dequeue_segment;
    struct 
    {
        UCHAR ProducerCycleState : 1;
        UCHAR ConsumerCycleState : 1;
    };
} XHCI_RING, *PXHCI_RING;

typedef struct _XHCI_HC_RESOURCES 
{
    XHCI_DEVICE_CONTEXT_BASE_ADD_ARRAY DCBAA;
    DECLSPEC_ALIGN(16) XHCI_RING         EventRing ;
    DECLSPEC_ALIGN(64) XHCI_RING         CommandRing ;
    DECLSPEC_ALIGN(64) XHCI_EVENT_RING_SEGMENT_TABLE EventRingSegTable;
} XHCI_HC_RESOURCES, *PXHCI_HC_RESOURCES;
C_ASSERT (FIELD_OFFSET(XHCI_HC_RESOURCES,EventRing)% 16 == 0); 
C_ASSERT (FIELD_OFFSET(XHCI_HC_RESOURCES,CommandRing)% 64 == 0); 
C_ASSERT (FIELD_OFFSET(XHCI_HC_RESOURCES,EventRingSegTable)% 64 == 0);

typedef struct _XHCI_EXTENSION 
{
    ULONG Reserved;
    ULONG Flags;
    PULONG BaseIoAdress;
    PULONG OperationalRegs;
    PULONG RunTimeRegisterBase;
    PULONG DoorBellRegisterBase;
    UCHAR FrameLengthAdjustment;
    BOOLEAN IsStarted;
    USHORT HcSystemErrors;
    ULONG PortRoutingControl;
    USHORT NumberOfPorts; // HCSPARAMS1 => N_PORTS 
    USHORT PortPowerControl; // HCSPARAMS => Port Power Control (PPC)
    USHORT PageSize;
    USHORT MaxScratchPadBuffers;
    PMDL ScratchPadArrayMDL;
    PMDL ScratchPadBufferMDL;
    PXHCI_HC_RESOURCES HcResourcesVA;
    PHYSICAL_ADDRESS HcResourcesPA;
} XHCI_EXTENSION, *PXHCI_EXTENSION;


typedef struct _XHCI_ENDPOINT 
{
    ULONG Reserved;
} XHCI_ENDPOINT, *PXHCI_ENDPOINT;

typedef struct _XHCI_TRANSFER 
{
    ULONG Reserved;
} XHCI_TRANSFER, *PXHCI_TRANSFER;

// 6.6
typedef union _XHCI_SCRATCHPAD_BUFFER_ARRAY
{
    struct 
    {
        ULONGLONG RsvdZ1              :  12;
        ULONGLONG bufferBaseAddr      :  52;
    };
    ULONGLONG AsULONGLONG;
} XHCI_SCRATCHPAD_BUFFER_ARRAY, *PXHCI_SCRATCHPAD_BUFFER_ARRAY;
C_ASSERT(sizeof(XHCI_SCRATCHPAD_BUFFER_ARRAY) == 8);
