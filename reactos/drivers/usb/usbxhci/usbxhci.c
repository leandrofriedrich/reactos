#include "usbxhci.h"

#include <debug.h>

#define NDEBUG_XHCI_TRACE
#include "dbg_xhci.h"

USBPORT_REGISTRATION_PACKET RegPacket;


MPSTATUS
NTAPI
XHCI_OpenEndpoint(IN PVOID xhciExtension,
                  IN PVOID endpointParameters,
                  IN PVOID xhciEndpoint)
{
    DPRINT1("XHCI_OpenEndpoint: function initiated\n");
    return MP_STATUS_SUCCESS;
}

MPSTATUS
NTAPI
XHCI_ReopenEndpoint(IN PVOID xhciExtension,
                    IN PVOID endpointParameters,
                    IN PVOID xhciEndpoint)
{
    DPRINT1("XHCI_ReopenEndpoint: function initiated\n");
    return MP_STATUS_SUCCESS;
}

VOID
NTAPI
XHCI_QueryEndpointRequirements(IN PVOID xhciExtension,
                               IN PVOID endpointParameters,
                               IN PULONG EndpointRequirements)
{
    DPRINT1("XHCI_QueryEndpointRequirements: function initiated\n");
}

VOID
NTAPI
XHCI_CloseEndpoint(IN PVOID xhciExtension,
                   IN PVOID xhciEndpoint,
                   IN BOOLEAN IsDoDisablePeriodic)
{
    DPRINT1("XHCI_CloseEndpoint: UNIMPLEMENTED. FIXME\n");
}

MPSTATUS
NTAPI
XHCI_InitializeResources(IN PXHCI_EXTENSION XhciExtension,
                        IN PVOID resourcesStartVA,
                        IN PVOID resourcesStartPA)
{
    DPRINT1("XHCI_InitializeResources: function initiated\n");
    PXHCI_HC_RESOURCES HcResourcesVA;
    PHYSICAL_ADDRESS HcResourcesPA;
    PULONG BaseIoAdress;
    PULONG OperationalRegs;
    
    
    PULONG  RunTimeRegisterBase;
    XHCI_INTERRUPTER_MANAGEMENT Iman;
    XHCI_INTERRUPTER_MODERATION Imod;
    XHCI_EVENT_RING_TABLE_SIZE erstz;
    XHCI_EVENT_RING_TABLE_BASE_ADDR erstba;
    XHCI_EVENT_RING_DEQUEUE_POINTER erstdp;
    XHCI_EVENT_RING_SEGMENT_TABLE EventRingSegTable;
    
    XHCI_COMMAND_RING_CONTROL CommandRingControlRegister;
    
    XHCI_DEVICE_CONTEXT_BASE_ADD_ARRAY_POINTER DCBAAPointer;
    unsigned long X, Y;
    
    DPRINT_XHCI("XHCI_InitializeResources: BaseVA - %p, BasePA - %p\n",
                resourcesStartVA,
                resourcesStartPA);
                
    HcResourcesVA = (PXHCI_HC_RESOURCES)resourcesStartVA;
    HcResourcesPA.QuadPart = (ULONG_PTR)resourcesStartPA;
    
    //DCBAA init
    DCBAAPointer.AsULONGLONG =  HcResourcesPA.QuadPart + FIELD_OFFSET(XHCI_HC_RESOURCES, DCBAA);
    
    BaseIoAdress = XhciExtension->BaseIoAdress;
    OperationalRegs = XhciExtension->OperationalRegs;
    
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_DCBAAP, DCBAAPointer.DCBAAPointerLo | DCBAAPointer.RsvdZ );
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_DCBAAP + 1, DCBAAPointer.DCBAAPointerHi);
    
    X = READ_REGISTER_ULONG(OperationalRegs + XHCI_DCBAAP) ;
    Y = READ_REGISTER_ULONG(OperationalRegs + XHCI_DCBAAP + 1) ;   
    DCBAAPointer.AsULONGLONG = Y|X ;
    ASSERT(DCBAAPointer.RsvdZ == 0);
    
    // command ring intialisation.
    
    HcResourcesVA->CommandRing.Segment[0].Link[0].AsULONG = 0;
    HcResourcesVA->CommandRing.Segment[0].Link[1].AsULONG = 0;
    HcResourcesVA->CommandRing.Segment[0].Link[2].AsULONG = 0;
    HcResourcesVA->CommandRing.Segment[0].Link[3].AsULONG = 0;
    
    HcResourcesVA->CommandRing.CREnquePointer=  &HcResourcesVA->CommandRing.Segment[0];
    HcResourcesVA->CommandRing.CRDequePointer= HcResourcesVA->CommandRing.CREnquePointer;
    
    CommandRingControlRegister.AsULONGLONG = HcResourcesPA.QuadPart + FIELD_OFFSET(XHCI_HC_RESOURCES, CommandRing.Segment);
    ASSERT(CommandRingControlRegister.RingCycleState == 0);
    ASSERT(CommandRingControlRegister.CommandStop == 0);
    ASSERT(CommandRingControlRegister.CommandAbort == 0);
    ASSERT(CommandRingControlRegister.CommandRingRunning == 0);
    ASSERT(CommandRingControlRegister.RsvdP == 0);
    
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_CRCR, CommandRingControlRegister.AsULONGLONG);
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_CRCR + 1, CommandRingControlRegister.CommandRingPointerHi);
    // end of command ring init
    
    //Primary Interrupter init
    RunTimeRegisterBase =  XhciExtension -> RunTimeRegisterBase;
    
    Iman.InterruptEnable = 1;
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_IMAN , Iman.AsULONG);
    
    // dont change imod now
    erstz.EventRingSegTableSize = 1;
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTSZ , erstz.AsULONG);
    
    erstba.AsULONGLONG = HcResourcesPA.QuadPart + FIELD_OFFSET(XHCI_HC_RESOURCES, EventRingSegTable);
    
    EventRingSegTable.RingSegmentBaseAddr = HcResourcesPA.QuadPart + FIELD_OFFSET(XHCI_HC_RESOURCES, EventRing);
    EventRingSegTable.RingSegmentSize = 16;
    HcResourcesVA->EventRingSegTable = EventRingSegTable;
    
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTBA, erstba.AsULONGLONG);
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTBA + 1, erstba.AsULONGLONG >> 32);
    // intially enque and deque are equal. 
    erstdp.AsULONGLONG = HcResourcesPA.QuadPart + FIELD_OFFSET(XHCI_HC_RESOURCES, EventRing);
    erstdp.DequeueERSTIndex =0;
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTDP, erstdp.AsULONGLONG);
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTDP + 1, erstdp.AsULONGLONG >> 32);
    
    //DbgBreakPoint();
    return MP_STATUS_SUCCESS;
}

MPSTATUS
NTAPI
XHCI_InitializeHardware(IN PXHCI_EXTENSION XhciExtension)
{
    DPRINT1("XHCI_InitializeHardware: function initiated\n");
    PULONG BaseIoAdress;
    PULONG OperationalRegs;
    
    
    XHCI_USB_COMMAND Command;
    XHCI_USB_STATUS Status;
    LARGE_INTEGER CurrentTime = {{0, 0}};
    LARGE_INTEGER LastTime = {{0, 0}};
    XHCI_HC_STRUCTURAL_PARAMS_1 StructuralParams_1;
    XHCI_CONFIGURE Config;
    
    DPRINT1("XHCI_InitializeHardware: ... \n");

    OperationalRegs = XhciExtension->OperationalRegs;
    BaseIoAdress = XhciExtension->BaseIoAdress;
   
    KeQuerySystemTime(&CurrentTime);
    CurrentTime.QuadPart += 100 * 10000; // 100 msec
    
    Status.AsULONG = READ_REGISTER_ULONG(OperationalRegs + XHCI_USBSTS);
    ASSERT(Status.ControllerNotReady != 1); // this is needed before writing anything to the operaational or doorbell registers

    Command.AsULONG = READ_REGISTER_ULONG(OperationalRegs + XHCI_USBCMD);
    Command.HCReset = 1;
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_USBCMD, Command.AsULONG);
    while(TRUE)
    {
        KeQuerySystemTime(&LastTime);
        
        Command.AsULONG = READ_REGISTER_ULONG(OperationalRegs + XHCI_USBCMD);
       
        if (Command.HCReset != 1)
        {
            break;
        }

        if (LastTime.QuadPart >= CurrentTime.QuadPart)
        {
            if (Command.HCReset == 1)
            {
                DPRINT1("XHCI_InitializeHardware: Software Reset failed!\n");
                return 7;
            }

            break;
        }
    }
    DPRINT("XHCI_InitializeHardware: Reset - OK\n");
    
    StructuralParams_1.AsULONG = READ_REGISTER_ULONG(BaseIoAdress + XHCI_HCSP1); // HCSPARAMS1 register

    XhciExtension->NumberOfPorts = StructuralParams_1.NumberOfPorts;
    
    Command.AsULONG = READ_REGISTER_ULONG(OperationalRegs + XHCI_USBCMD);
    Config.AsULONG = READ_REGISTER_ULONG(OperationalRegs + XHCI_CONFIG);
    ASSERT(Command.RunStop==0); //required before setting max device slots enabled.
    Config.MaxDeviceSlotsEnabled = 1; // max possible value is number of slots HCSPARAMS1
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_CONFIG, Config.AsULONG);
    
    return MP_STATUS_SUCCESS;
}

MPSTATUS
NTAPI
XHCI_StartController(IN PVOID xhciExtension,
                     IN PUSBPORT_RESOURCES Resources)
{
    DPRINT1("XHCI_StartController: function initiated\n");
    PXHCI_EXTENSION XhciExtension;
    PULONG BaseIoAdress;
    PULONG OperationalRegs;
    PULONG  RunTimeRegisterBase;
    
    MPSTATUS MPStatus;
    XHCI_USB_COMMAND Command;
    XHCI_RT_REGISTER_SPACE_OFFSET RTSOffsetRegister;
    UCHAR CapabilityRegLength;
    UCHAR Fladj;

    

    if ((Resources->TypesResources & (USBPORT_RESOURCES_MEMORY | USBPORT_RESOURCES_INTERRUPT)) !=
                                     (USBPORT_RESOURCES_MEMORY | USBPORT_RESOURCES_INTERRUPT))
    {
        DPRINT1("XHCI_StartController: Resources->TypesResources - %x\n",
                Resources->TypesResources);

        return MP_STATUS_ERROR;
    }
    XhciExtension = (PXHCI_EXTENSION)xhciExtension;

    BaseIoAdress = (PULONG)Resources->ResourceBase;
    XhciExtension->BaseIoAdress = BaseIoAdress;

    CapabilityRegLength = (UCHAR)READ_REGISTER_ULONG(BaseIoAdress);
    OperationalRegs = (PULONG)((ULONG_PTR)BaseIoAdress + CapabilityRegLength);
    XhciExtension->OperationalRegs = OperationalRegs;
     
    RTSOffsetRegister.AsULONG = READ_REGISTER_ULONG(BaseIoAdress + XHCI_RTSOFF);
    RunTimeRegisterBase = BaseIoAdress + RTSOffsetRegister.AsULONG ;

    XhciExtension->RunTimeRegisterBase = RunTimeRegisterBase;
    
    DPRINT("XHCI_StartController: BaseIoAdress    - %p\n", BaseIoAdress);
    DPRINT("XHCI_StartController: OperationalRegs - %p\n", OperationalRegs);
    
    RegPacket.UsbPortReadWriteConfigSpace(XhciExtension,
                                          1,
                                          &Fladj,
                                          0x61,
                                          1);

    XhciExtension->FrameLengthAdjustment = Fladj;
    
    MPStatus = XHCI_InitializeHardware(XhciExtension);

    if (MPStatus)
    {
        DPRINT1("XHCI_StartController: Unsuccessful InitializeHardware()\n");
        return MPStatus;
    }

    MPStatus = XHCI_InitializeResources(XhciExtension,
                                       Resources->StartVA,
                                       Resources->StartPA);

    if (MPStatus)
    {
        DPRINT1("XHCI_StartController: Unsuccessful InitializeSchedule()\n");
        return MPStatus;
    }
    
    Command.RunStop =1;
    WRITE_REGISTER_ULONG (OperationalRegs + XHCI_USBCMD, Command.AsULONG );
    //DPRINT1("XHCI_StartController: UNIMPLEMENTED. FIXME\n");
    return MP_STATUS_SUCCESS;
}

VOID
NTAPI
XHCI_StopController(IN PVOID xhciExtension,
                    IN BOOLEAN IsDoDisableInterrupts)
{
    DPRINT1("XHCI_StopController: UNIMPLEMENTED. FIXME\n");
}

VOID
NTAPI
XHCI_SuspendController(IN PVOID xhciExtension)
{
    PXHCI_EXTENSION XhciExtension;
    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    
    XhciExtension->Flags |= XHCI_FLAGS_CONTROLLER_SUSPEND;
    DPRINT1("XHCI_SuspendController: function initiated\n");
}

MPSTATUS
NTAPI
XHCI_ResumeController(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_ResumeController: function initiated\n");
    PXHCI_EXTENSION XhciExtension;
    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    
    XhciExtension->Flags &= ~XHCI_FLAGS_CONTROLLER_SUSPEND;
    return MP_STATUS_SUCCESS;
}

BOOLEAN
NTAPI
XHCI_HardwarePresent(IN PXHCI_EXTENSION xhciExtension,
                     IN BOOLEAN IsInvalidateController)
{
    DPRINT1("XHCI_HardwarePresent: function initiated\n");
    return TRUE;
}

BOOLEAN
NTAPI
XHCI_InterruptService(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_InterruptService: function initiated\n");
    XHCI_RT_REGISTER_SPACE_OFFSET RTSOffsetRegister;
    PULONG  RunTimeRegisterBase;
    XHCI_INTERRUPTER_MANAGEMENT Iman;
    PXHCI_EXTENSION XhciExtension;
    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    XHCI_EVENT_RING_DEQUEUE_POINTER erstdp;
    
    RunTimeRegisterBase = XhciExtension-> RunTimeRegisterBase;
    
    Iman.AsULONG = READ_REGISTER_ULONG(RunTimeRegisterBase + XHCI_IMAN);
    if (Iman.InterruptPending == 0)
    {
        return FALSE;
    }
    Iman.InterruptPending =1;
    
    WRITE_REGISTER_ULONG(RunTimeRegisterBase + XHCI_IMAN, Iman.AsULONG);
    DPRINT1("XHCI_InterruptService: Succesful Interupt\n");
    // changing the enque pointer
    erstdp.AsULONGLONG = READ_REGISTER_ULONG(RunTimeRegisterBase + XHCI_ERSTDP + 1)|READ_REGISTER_ULONG(RunTimeRegisterBase + XHCI_ERSTDP);
    erstdp.AsULONGLONG = erstdp.AsULONGLONG +2;
    erstdp.DequeueERSTIndex =0;
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTDP, erstdp.AsULONGLONG);
    WRITE_REGISTER_ULONG (RunTimeRegisterBase + XHCI_ERSTDP + 1, erstdp.AsULONGLONG >> 32);
    
    return TRUE;
}

VOID
NTAPI
XHCI_InterruptDpc(IN PVOID xhciExtension,
                  IN BOOLEAN IsDoEnableInterrupts)
{
    DPRINT1("XHCI_InterruptDpc: function initiated\n");
}

MPSTATUS
NTAPI
XHCI_SubmitTransfer(IN PVOID xhciExtension,
                    IN PVOID xhciEndpoint,
                    IN PVOID transferParameters,
                    IN PVOID xhciTransfer,
                    IN PVOID sgList)
{
    DPRINT1("XHCI_SubmitTransfer: function initiated\n");
    return MP_STATUS_SUCCESS;
}

MPSTATUS
NTAPI
XHCI_SubmitIsoTransfer(IN PVOID xhciExtension,
                       IN PVOID xhciEndpoint,
                       IN PVOID transferParameters,
                       IN PVOID xhciTransfer,
                       IN PVOID isoParameters)
{
    DPRINT1("XHCI_SubmitIsoTransfer: UNIMPLEMENTED. FIXME\n");
    return MP_STATUS_SUCCESS;
}

VOID
NTAPI
XHCI_AbortIsoTransfer(IN PXHCI_EXTENSION xhciExtension,
                      IN PXHCI_ENDPOINT xhciEndpoint,
                      IN PXHCI_TRANSFER xhciTransfer)
{
    DPRINT1("XHCI_AbortIsoTransfer: UNIMPLEMENTED. FIXME\n");
}

VOID
NTAPI
XHCI_AbortAsyncTransfer(IN PXHCI_EXTENSION xhciExtension,
                        IN PXHCI_ENDPOINT xhciEndpoint,
                        IN PXHCI_TRANSFER xhciTransfer)
{
    DPRINT1("XHCI_AbortAsyncTransfer: function initiated\n");
}

VOID
NTAPI
XHCI_AbortTransfer(IN PVOID xhciExtension,
                   IN PVOID xhciEndpoint,
                   IN PVOID xhciTransfer,
                   IN PULONG CompletedLength)
{
    DPRINT1("XHCI_AbortTransfer: function initiated\n");
}

ULONG
NTAPI
XHCI_GetEndpointState(IN PVOID xhciExtension,
                      IN PVOID xhciEndpoint)
{
    DPRINT1("XHCI_GetEndpointState: UNIMPLEMENTED. FIXME\n");
    return 0;
}

VOID
NTAPI
XHCI_SetEndpointState(IN PVOID xhciExtension,
                      IN PVOID xhciEndpoint,
                      IN ULONG EndpointState)
{
    DPRINT1("XHCI_SetEndpointState: function initiated\n");
}

VOID
NTAPI
XHCI_PollEndpoint(IN PVOID xhciExtension,
                  IN PVOID xhciEndpoint)
{
    DPRINT1("XHCI_PollEndpoint: function initiated\n");
}

VOID
NTAPI
XHCI_CheckController(IN PVOID xhciExtension)
{
    //RegPacket.UsbPortInvalidateController(xhciExtension, 2);
    DPRINT1("XHCI_CheckController: function initiated\n");
}

ULONG
NTAPI
XHCI_Get32BitFrameNumber(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_Get32BitFrameNumber: function initiated\n");
    return 0;
}

VOID
NTAPI
XHCI_InterruptNextSOF(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_InterruptNextSOF: function initiated\n");
}

VOID
NTAPI
XHCI_EnableInterrupts(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_EnableInterrupts: function initiated\n");
    PXHCI_EXTENSION XhciExtension;
    PULONG OperationalRegs;
    XHCI_USB_COMMAND usbCommand;
   
    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    OperationalRegs = XhciExtension->OperationalRegs;
    usbCommand.AsULONG =READ_REGISTER_ULONG (OperationalRegs + XHCI_USBCMD);
   
    usbCommand.InterrupterEnable = 1;
   
    WRITE_REGISTER_ULONG(OperationalRegs + XHCI_USBCMD,usbCommand.AsULONG );
     DPRINT1("XHCI_EnableInterrupts: Interrupts enabled\n");
}

VOID
NTAPI
XHCI_DisableInterrupts(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_DisableInterrupts: function initiated\n");
}

VOID
NTAPI
XHCI_PollController(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_PollController: function initiated\n");
    PXHCI_EXTENSION XhciExtension;
    PULONG OperationalRegs;
    //ULONG Port;
    //XHCI_PORT_STATUS_CONTROL PortSC;


    XhciExtension = (PXHCI_EXTENSION)xhciExtension;
    OperationalRegs = XhciExtension->OperationalRegs;

    if (!(XhciExtension->Flags & XHCI_FLAGS_CONTROLLER_SUSPEND))
    {
        RegPacket.UsbPortInvalidateRootHub(XhciExtension);
        return;
    }
    //RegPacket.UsbPortInvalidateRootHub(xhciExtension);
    
}

VOID
NTAPI
XHCI_SetEndpointDataToggle(IN PVOID xhciExtension,
                           IN PVOID xhciEndpoint,
                           IN ULONG DataToggle)
{
    DPRINT1("XHCI_SetEndpointDataToggle: function initiated\n");
}

ULONG
NTAPI
XHCI_GetEndpointStatus(IN PVOID xhciExtension,
                       IN PVOID xhciEndpoint)
{
    DPRINT1("XHCI_GetEndpointStatus: function initiated\n");
    return 0;
}

VOID
NTAPI
XHCI_SetEndpointStatus(IN PVOID xhciExtension,
                       IN PVOID xhciEndpoint,
                       IN ULONG EndpointStatus)
{
    DPRINT1("XHCI_SetEndpointStatus: function initiated\n");
}

MPSTATUS
NTAPI
XHCI_StartSendOnePacket(IN PVOID xhciExtension,
                        IN PVOID PacketParameters,
                        IN PVOID Data,
                        IN PULONG pDataLength,
                        IN PVOID BufferVA,
                        IN PVOID BufferPA,
                        IN ULONG BufferLength,
                        IN USBD_STATUS * pUSBDStatus)
{
    DPRINT1("XHCI_StartSendOnePacket: UNIMPLEMENTED. FIXME\n");
    return MP_STATUS_SUCCESS;
}

MPSTATUS
NTAPI
XHCI_EndSendOnePacket(IN PVOID xhciExtension,
                      IN PVOID PacketParameters,
                      IN PVOID Data,
                      IN PULONG pDataLength,
                      IN PVOID BufferVA,
                      IN PVOID BufferPA,
                      IN ULONG BufferLength,
                      IN USBD_STATUS * pUSBDStatus)
{
    DPRINT1("XHCI_EndSendOnePacket: UNIMPLEMENTED. FIXME\n");
    return MP_STATUS_SUCCESS;
}

MPSTATUS
NTAPI
XHCI_PassThru(IN PVOID xhciExtension,
              IN PVOID passThruParameters,
              IN ULONG ParameterLength,
              IN PVOID pParameters)
{
    DPRINT1("XHCI_PassThru: UNIMPLEMENTED. FIXME\n");
    return MP_STATUS_SUCCESS;
}

VOID
NTAPI
XHCI_RebalanceEndpoint(IN PVOID ohciExtension,
                       IN PVOID endpointParameters,
                       IN PVOID ohciEndpoint)
{
    DPRINT1("XHCI_RebalanceEndpoint: UNIMPLEMENTED. FIXME\n");
}

VOID
NTAPI
XHCI_FlushInterrupts(IN PVOID xhciExtension)
{
    DPRINT1("XHCI_FlushInterrupts: function initiated\n");
}

MPSTATUS
NTAPI
XHCI_RH_ChirpRootPort(IN PVOID xhciExtension,
                      IN USHORT Port)
{
    DPRINT1("XHCI_RH_ChirpRootPort: UNIMPLEMENTED. FIXME\n");
    return MP_STATUS_SUCCESS;
}

VOID
NTAPI
XHCI_TakePortControl(IN PVOID ohciExtension)
{
    DPRINT1("XHCI_TakePortControl: UNIMPLEMENTED. FIXME\n");
}

VOID
NTAPI
XHCI_Unload(PDRIVER_OBJECT DriverObject)
{
    DPRINT1("XHCI_Unload: UNIMPLEMENTED. FIXME\n");
}

NTSTATUS
NTAPI
DriverEntry(IN PDRIVER_OBJECT DriverObject,
            IN PUNICODE_STRING RegistryPath)
{
    DPRINT("DriverEntry: DriverObject - %p, RegistryPath - %wZ\n",
           DriverObject,
           RegistryPath);
    if (USBPORT_GetHciMn() != USBPORT_HCI_MN) // Don't know the purpose
    {
        return STATUS_INSUFFICIENT_RESOURCES;
    }
    
    RtlZeroMemory(&RegPacket, sizeof(USBPORT_REGISTRATION_PACKET));
    
    RegPacket.MiniPortVersion = USB_MINIPORT_VERSION_XHCI;

    RegPacket.MiniPortFlags = USB_MINIPORT_FLAGS_INTERRUPT |
                              USB_MINIPORT_FLAGS_MEMORY_IO |
                              USB_MINIPORT_FLAGS_USB2 |
                              USB_MINIPORT_FLAGS_POLLING |
                              USB_MINIPORT_FLAGS_WAKE_SUPPORT;

    RegPacket.MiniPortBusBandwidth = 400000;

    RegPacket.MiniPortExtensionSize = sizeof(XHCI_EXTENSION);
    RegPacket.MiniPortEndpointSize = sizeof(XHCI_ENDPOINT);
    RegPacket.MiniPortTransferSize = sizeof(XHCI_TRANSFER);
    RegPacket.MiniPortResourcesSize = sizeof(XHCI_HC_RESOURCES);
    
    RegPacket.OpenEndpoint = XHCI_OpenEndpoint;
    RegPacket.ReopenEndpoint = XHCI_ReopenEndpoint;
    RegPacket.QueryEndpointRequirements = XHCI_QueryEndpointRequirements;
    RegPacket.CloseEndpoint = XHCI_CloseEndpoint;
    RegPacket.StartController = XHCI_StartController;
    RegPacket.StopController = XHCI_StopController;
    RegPacket.SuspendController = XHCI_SuspendController;
    RegPacket.ResumeController = XHCI_ResumeController;
    RegPacket.InterruptService = XHCI_InterruptService;
    RegPacket.InterruptDpc = XHCI_InterruptDpc;
    RegPacket.SubmitTransfer = XHCI_SubmitTransfer;
    RegPacket.SubmitIsoTransfer = XHCI_SubmitIsoTransfer;
    RegPacket.AbortTransfer = XHCI_AbortTransfer;
    RegPacket.GetEndpointState = XHCI_GetEndpointState;
    RegPacket.SetEndpointState = XHCI_SetEndpointState;
    RegPacket.PollEndpoint = XHCI_PollEndpoint;
    RegPacket.CheckController = XHCI_CheckController;
    RegPacket.Get32BitFrameNumber = XHCI_Get32BitFrameNumber;
    RegPacket.InterruptNextSOF = XHCI_InterruptNextSOF;
    RegPacket.EnableInterrupts = XHCI_EnableInterrupts;
    RegPacket.DisableInterrupts = XHCI_DisableInterrupts;
    RegPacket.PollController = XHCI_PollController;
    RegPacket.SetEndpointDataToggle = XHCI_SetEndpointDataToggle;
    RegPacket.GetEndpointStatus = XHCI_GetEndpointStatus;
    RegPacket.SetEndpointStatus = XHCI_SetEndpointStatus;
    RegPacket.RH_GetRootHubData = XHCI_RH_GetRootHubData;
    RegPacket.RH_GetStatus = XHCI_RH_GetStatus;
    RegPacket.RH_GetPortStatus = XHCI_RH_GetPortStatus;
    RegPacket.RH_GetHubStatus = XHCI_RH_GetHubStatus;
    RegPacket.RH_SetFeaturePortReset = XHCI_RH_SetFeaturePortReset;
    RegPacket.RH_SetFeaturePortPower = XHCI_RH_SetFeaturePortPower;
    RegPacket.RH_SetFeaturePortEnable = XHCI_RH_SetFeaturePortEnable;
    RegPacket.RH_SetFeaturePortSuspend = XHCI_RH_SetFeaturePortSuspend;
    RegPacket.RH_ClearFeaturePortEnable = XHCI_RH_ClearFeaturePortEnable;
    RegPacket.RH_ClearFeaturePortPower = XHCI_RH_ClearFeaturePortPower;
    RegPacket.RH_ClearFeaturePortSuspend = XHCI_RH_ClearFeaturePortSuspend;
    RegPacket.RH_ClearFeaturePortEnableChange = XHCI_RH_ClearFeaturePortEnableChange;
    RegPacket.RH_ClearFeaturePortConnectChange = XHCI_RH_ClearFeaturePortConnectChange;
    RegPacket.RH_ClearFeaturePortResetChange = XHCI_RH_ClearFeaturePortResetChange;
    RegPacket.RH_ClearFeaturePortSuspendChange = XHCI_RH_ClearFeaturePortSuspendChange;
    RegPacket.RH_ClearFeaturePortOvercurrentChange = XHCI_RH_ClearFeaturePortOvercurrentChange;
    RegPacket.RH_DisableIrq = XHCI_RH_DisableIrq;
    RegPacket.RH_EnableIrq = XHCI_RH_EnableIrq;
    RegPacket.StartSendOnePacket = XHCI_StartSendOnePacket;
    RegPacket.EndSendOnePacket = XHCI_EndSendOnePacket;
    RegPacket.PassThru = XHCI_PassThru;
    RegPacket.RebalanceEndpoint = XHCI_RebalanceEndpoint;
    RegPacket.FlushInterrupts = XHCI_FlushInterrupts;
    RegPacket.RH_ChirpRootPort = XHCI_RH_ChirpRootPort;
    RegPacket.TakePortControl = XHCI_TakePortControl;
    
    DPRINT1("XHCI_DriverEntry: before driver unload. FIXME\n");
    DriverObject->DriverUnload = XHCI_Unload;
    
    DPRINT1("XHCI_DriverEntry: after driver unload, before usbport_reg call. FIXME\n");
    //DbgBreakPoint();
    return USBPORT_RegisterUSBPortDriver(DriverObject, 200, &RegPacket); // 200- is version for usb 2... 
   // return STATUS_SUCCESS;
}