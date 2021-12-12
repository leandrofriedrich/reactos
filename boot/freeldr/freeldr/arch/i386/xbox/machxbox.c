/*
 *  FreeLoader
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <freeldr.h>
#include <drivers/xbox/superio.h>

#include <debug.h>
DBG_DEFAULT_CHANNEL(HWDETECT);

#define MAX_XBOX_COM_PORTS    2

extern PVOID FrameBuffer;
extern ULONG FrameBufferSize;
extern void i386AcceptIrqs(void);
extern MACH_SET_PIC_IDT_OFFSETS MachSetPicIdtOffsets;
extern MACH_HANDLE_IRQ MachHandleIrq;

CROMWELL_PARAMETER_BLOCK * ParamBlock = (void *)CROMWELL_PARAM_BLOCK_OFFSET;
PCROMWELL_CALLBACK BiosCallback = NULL;

int XboxCalcParamChecksum(UCHAR * Data)
{
    UCHAR Checksum = 0;
    int i;

    for (i = 0; i < sizeof(CROMWELL_PARAMETER_BLOCK) - sizeof(int); i++, Data++)
        Checksum += *Data;
    return (signed char)(Checksum ^ 0x55);
}

VOID
XboxSetPicIdtOffsets(UCHAR Pic1IdtOffset, UCHAR Pic2IdtOffset)
{
    UCHAR Mask1, Mask2;

    Mask1 = READ_PORT_UCHAR(PIC1_DATA_PORT);
    Mask2 = READ_PORT_UCHAR(PIC2_DATA_PORT);

    WRITE_PORT_UCHAR(PIC1_CONTROL_PORT, ICW1_INIT | ICW1_ICW4);
    WRITE_PORT_UCHAR(PIC2_CONTROL_PORT, ICW1_INIT | ICW1_ICW4);
    WRITE_PORT_UCHAR(PIC1_DATA_PORT, Pic1IdtOffset);
    WRITE_PORT_UCHAR(PIC2_DATA_PORT, Pic2IdtOffset);
    WRITE_PORT_UCHAR(PIC1_DATA_PORT, 4);
    WRITE_PORT_UCHAR(PIC2_DATA_PORT, 2);
    WRITE_PORT_UCHAR(PIC1_DATA_PORT, ICW4_8086);
    WRITE_PORT_UCHAR(PIC2_DATA_PORT, ICW4_8086);

    WRITE_PORT_UCHAR(PIC1_DATA_PORT, Mask1);
    WRITE_PORT_UCHAR(PIC2_DATA_PORT, Mask2);
}

VOID
XboxHandleIrq(UCHAR Interrupt)
{
    USHORT SmcData;

    if (BiosCallback)
        BiosCallback(CROMWELL_CALLBACK_CALL_IRQ, (void *)(ULONG)Interrupt);

    if (Interrupt == 12)
    {
        /* SMC interrupt: Acknowledge EXTSMI# action (from PIC p6) */
        SmcData = READ_PORT_USHORT(0x8020);
        WRITE_PORT_USHORT(0x8020, SmcData | 0x200);
    }

    if (Interrupt >= 8)
    {
        WRITE_PORT_UCHAR(PIC2_CONTROL_PORT, PIC_EOI);
        WRITE_PORT_UCHAR(PIC1_CONTROL_PORT, PIC_SPECIFIC_EOI2);
    }
    else
    {
        WRITE_PORT_UCHAR(PIC1_CONTROL_PORT, PIC_EOI);
    }
}

BOOLEAN
XboxFindPciBios(PPCI_REGISTRY_INFO BusData)
{
    /* We emulate PCI BIOS here, there are 2 known working PCI buses on an original Xbox */

    BusData->NoBuses = 2;
    BusData->MajorRevision = 1;
    BusData->MinorRevision = 0;
    BusData->HardwareMechanism = 1;
    return TRUE;
}

extern
VOID
DetectSerialPointerPeripheral(PCONFIGURATION_COMPONENT_DATA ControllerKey, PUCHAR Base);

static
ULONG
XboxGetSerialPort(ULONG Index, PULONG Irq)
{
    /*
     * Xbox may have maximum two Serial COM ports
     * if the Super I/O chip is connected via LPC
     */
    static const UCHAR Device[MAX_XBOX_COM_PORTS] = {LPC_DEVICE_SERIAL_PORT_1, LPC_DEVICE_SERIAL_PORT_2};
    ULONG ComBase = 0;

    LpcEnterConfig();

    // Select serial device
    LpcWriteRegister(LPC_CONFIG_DEVICE_NUMBER, Device[Index]);

    // Check if selected device is active
    if (LpcReadRegister(LPC_CONFIG_DEVICE_ACTIVATE) == 1)
    {
        ComBase = LpcGetIoBase();
        *Irq = LpcGetIrqPrimary();
    }

    LpcExitConfig();

    return ComBase;
}

extern
VOID
DetectSerialPorts(PCONFIGURATION_COMPONENT_DATA BusKey, GET_SERIAL_PORT MachGetSerialPort, ULONG Count);

VOID
XboxGetExtendedBIOSData(PULONG ExtendedBIOSDataArea, PULONG ExtendedBIOSDataSize)
{
    TRACE("XboxGetExtendedBIOSData(): UNIMPLEMENTED\n");
    *ExtendedBIOSDataArea = 0;
    *ExtendedBIOSDataSize = 0;
}

// NOTE: Similar to machpc.c!PcGetHarddiskConfigurationData(),
// but without extended geometry support.
static
PCM_PARTIAL_RESOURCE_LIST
XboxGetHarddiskConfigurationData(UCHAR DriveNumber, ULONG* pSize)
{
    PCM_PARTIAL_RESOURCE_LIST PartialResourceList;
    PCM_DISK_GEOMETRY_DEVICE_DATA DiskGeometry;
    //EXTENDED_GEOMETRY ExtGeometry;
    GEOMETRY Geometry;
    ULONG Size;

    //
    // Initialize returned size
    //
    *pSize = 0;

    /* Set 'Configuration Data' value */
    Size = sizeof(CM_PARTIAL_RESOURCE_LIST) +
           sizeof(CM_DISK_GEOMETRY_DEVICE_DATA);
    PartialResourceList = FrLdrHeapAlloc(Size, TAG_HW_RESOURCE_LIST);
    if (PartialResourceList == NULL)
    {
        ERR("Failed to allocate resource descriptor\n");
        return NULL;
    }

    RtlZeroMemory(PartialResourceList, Size);
    PartialResourceList->Version = 1;
    PartialResourceList->Revision = 1;
    PartialResourceList->Count = 1;
    PartialResourceList->PartialDescriptors[0].Type =
        CmResourceTypeDeviceSpecific;
//  PartialResourceList->PartialDescriptors[0].ShareDisposition =
//  PartialResourceList->PartialDescriptors[0].Flags =
    PartialResourceList->PartialDescriptors[0].u.DeviceSpecificData.DataSize =
        sizeof(CM_DISK_GEOMETRY_DEVICE_DATA);

    /* Get pointer to geometry data */
    DiskGeometry = (PVOID)(((ULONG_PTR)PartialResourceList) + sizeof(CM_PARTIAL_RESOURCE_LIST));

    /* Get the disk geometry */
    //ExtGeometry.Size = sizeof(EXTENDED_GEOMETRY);

    if (XboxDiskGetDriveGeometry(DriveNumber, &Geometry))
    {
        DiskGeometry->BytesPerSector = Geometry.BytesPerSector;
        DiskGeometry->NumberOfCylinders = Geometry.Cylinders;
        DiskGeometry->SectorsPerTrack = Geometry.Sectors;
        DiskGeometry->NumberOfHeads = Geometry.Heads;
    }
    else
    {
        ERR("Reading disk geometry failed\n");
        FrLdrHeapFree(PartialResourceList, TAG_HW_RESOURCE_LIST);
        return NULL;
    }
    TRACE("Disk %x: %u Cylinders  %u Heads  %u Sectors  %u Bytes\n",
          DriveNumber,
          DiskGeometry->NumberOfCylinders,
          DiskGeometry->NumberOfHeads,
          DiskGeometry->SectorsPerTrack,
          DiskGeometry->BytesPerSector);

    //
    // Return configuration data
    //
    *pSize = Size;
    return PartialResourceList;
}

static VOID
DetectDisplayController(PCONFIGURATION_COMPONENT_DATA BusKey)
{
    CHAR Buffer[80];
    PCONFIGURATION_COMPONENT_DATA ControllerKey;
    PCM_PARTIAL_RESOURCE_LIST PartialResourceList;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptor;
    ULONG Size;

    if (FrameBufferSize == 0)
        return;

    strcpy(Buffer, "NV2A Framebuffer");

    Size = sizeof(CM_PARTIAL_RESOURCE_LIST);
    PartialResourceList = FrLdrHeapAlloc(Size, TAG_HW_RESOURCE_LIST);
    if (PartialResourceList == NULL)
    {
        ERR("Failed to allocate resource descriptor\n");
        return;
    }

    /* Initialize resource descriptor */
    RtlZeroMemory(PartialResourceList, Size);
    PartialResourceList->Version = 1;
    PartialResourceList->Revision = 1;
    PartialResourceList->Count = 1;

    /* Set Memory */
    PartialDescriptor = &PartialResourceList->PartialDescriptors[0];
    PartialDescriptor->Type = CmResourceTypeMemory;
    PartialDescriptor->ShareDisposition = CmResourceShareDeviceExclusive;
    PartialDescriptor->Flags = CM_RESOURCE_MEMORY_READ_WRITE;
    PartialDescriptor->u.Memory.Start.LowPart = (ULONG_PTR)FrameBuffer & 0x0FFFFFFF;
    PartialDescriptor->u.Memory.Length = FrameBufferSize;

    FldrCreateComponentKey(BusKey,
                           ControllerClass,
                           DisplayController,
                           0x0,
                           0x0,
                           0xFFFFFFFF,
                           Buffer,
                           PartialResourceList,
                           Size,
                           &ControllerKey);

    TRACE("Created key: DisplayController\\0\n");
}

static
VOID
DetectIsaBios(PCONFIGURATION_COMPONENT_DATA SystemKey, ULONG *BusNumber)
{
    PCM_PARTIAL_RESOURCE_LIST PartialResourceList;
    PCONFIGURATION_COMPONENT_DATA BusKey;
    ULONG Size;

    /* Set 'Configuration Data' value */
    Size = sizeof(CM_PARTIAL_RESOURCE_LIST) -
           sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR);
    PartialResourceList = FrLdrHeapAlloc(Size, TAG_HW_RESOURCE_LIST);
    if (PartialResourceList == NULL)
    {
        ERR("Failed to allocate resource descriptor\n");
        return;
    }

    /* Initialize resource descriptor */
    RtlZeroMemory(PartialResourceList, Size);
    PartialResourceList->Version = 1;
    PartialResourceList->Revision = 1;
    PartialResourceList->Count = 0;

    /* Create new bus key */
    FldrCreateComponentKey(SystemKey,
                           AdapterClass,
                           MultiFunctionAdapter,
                           0x0,
                           0x0,
                           0xFFFFFFFF,
                           "ISA",
                           PartialResourceList,
                           Size,
                           &BusKey);

    /* Increment bus number */
    (*BusNumber)++;

    /* Detect ISA/BIOS devices */
    DetectBiosDisks(SystemKey, BusKey);
    DetectSerialPorts(BusKey, XboxGetSerialPort, MAX_XBOX_COM_PORTS);
    DetectDisplayController(BusKey);

    /* FIXME: Detect more ISA devices */
}

static
UCHAR
XboxGetFloppyCount(VOID)
{
    /* On a PC we use CMOS/RTC I/O ports 0x70 and 0x71 to detect floppies.
     * However an Xbox CMOS memory range [0x10, 0x70) and [0x80, 0x100)
     * is filled with 0x55 0xAA 0x55 0xAA ... byte pattern which is used
     * to validate the date/time settings by Xbox OS.
     *
     * Technically it's possible to connect a floppy drive to Xbox, but
     * CMOS detection method should not be used here. */

    WARN("XboxGetFloppyCount() is UNIMPLEMENTED, returning 0\n");
    return 0;
}

PCONFIGURATION_COMPONENT_DATA
XboxHwDetect(VOID)
{
    PCONFIGURATION_COMPONENT_DATA SystemKey;
    ULONG BusNumber = 0;

    TRACE("DetectHardware()\n");

    /* Create the 'System' key */
    FldrCreateSystemKey(&SystemKey);
    FldrSetIdentifier(SystemKey, "Original Xbox (PC/AT like)");

    GetHarddiskConfigurationData = XboxGetHarddiskConfigurationData;
    FindPciBios = XboxFindPciBios;

    /* TODO: Build actual xbox's hardware configuration tree */
    DetectPciBios(SystemKey, &BusNumber);
    DetectIsaBios(SystemKey, &BusNumber);

    TRACE("DetectHardware() Done\n");
    return SystemKey;
}

VOID XboxHwIdle(VOID)
{
    /* UNIMPLEMENTED */
}


/******************************************************************************/

VOID
MachInit(const char *CmdLine)
{
    PCI_TYPE1_CFG_BITS PciCfg1;
    ULONG PciId;

    /* Check for Xbox by identifying device at PCI 0:0:0, if it's
     * 0x10DE/0x02A5 then we're running on an Xbox */

    /* Select Host to PCI bridge */
    PciCfg1.u.bits.Enable = 1;
    PciCfg1.u.bits.BusNumber = 0;
    PciCfg1.u.bits.DeviceNumber = 0;
    PciCfg1.u.bits.FunctionNumber = 0;
    /* Select register VendorID & DeviceID */
    PciCfg1.u.bits.RegisterNumber = 0x00;
    PciCfg1.u.bits.Reserved = 0;

    WRITE_PORT_ULONG(PCI_TYPE1_ADDRESS_PORT, PciCfg1.u.AsULONG);
    PciId = READ_PORT_ULONG((PULONG)PCI_TYPE1_DATA_PORT);
    if (PciId != 0x02A510DE)
    {
        ERR("This is not an original Xbox!\n");

        /* Disable and halt the CPU */
        _disable();
        __halt();

        while (TRUE)
            NOTHING;
    }

    /* Set LEDs to red before anything is initialized */
    XboxSetLED("rrrr");

    /* Cromwell callback */
    if (ParamBlock->Signature == CROMWELL_PARAM_BLOCK_SIGNATURE &&
        ParamBlock->Checksum == XboxCalcParamChecksum((UCHAR *)ParamBlock))
    {
        BiosCallback = ParamBlock->BiosCallback;
    }
    if (BiosCallback)
    {
        MachSetPicIdtOffsets = XboxSetPicIdtOffsets;
        MachHandleIrq = XboxHandleIrq;
        i386AcceptIrqs();
        if (!BiosCallback(CROMWELL_CALLBACK_START_SERVICE, NULL))
        {
            ERR("Failed to initialize Cromwell boot services\n");
            BiosCallback = NULL;
        }
    }

    /* Setup vtbl */
    RtlZeroMemory(&MachVtbl, sizeof(MachVtbl));
    MachVtbl.ConsPutChar = XboxConsPutChar;
    MachVtbl.ConsKbHit = XboxConsKbHit;
    MachVtbl.ConsGetCh = XboxConsGetCh;
    MachVtbl.VideoClearScreen = XboxVideoClearScreen;
    MachVtbl.VideoSetDisplayMode = XboxVideoSetDisplayMode;
    MachVtbl.VideoGetDisplaySize = XboxVideoGetDisplaySize;
    MachVtbl.VideoGetBufferSize = XboxVideoGetBufferSize;
    MachVtbl.VideoGetFontsFromFirmware = XboxVideoGetFontsFromFirmware;
    MachVtbl.VideoSetTextCursorPosition = XboxVideoSetTextCursorPosition;
    MachVtbl.VideoHideShowTextCursor = XboxVideoHideShowTextCursor;
    MachVtbl.VideoPutChar = XboxVideoPutChar;
    MachVtbl.VideoCopyOffScreenBufferToVRAM = XboxVideoCopyOffScreenBufferToVRAM;
    MachVtbl.VideoIsPaletteFixed = XboxVideoIsPaletteFixed;
    MachVtbl.VideoSetPaletteColor = XboxVideoSetPaletteColor;
    MachVtbl.VideoGetPaletteColor = XboxVideoGetPaletteColor;
    MachVtbl.VideoSync = XboxVideoSync;
    MachVtbl.Beep = PcBeep;
    MachVtbl.PrepareForReactOS = XboxPrepareForReactOS;
    MachVtbl.GetMemoryMap = XboxMemGetMemoryMap;
    MachVtbl.GetExtendedBIOSData = XboxGetExtendedBIOSData;
    MachVtbl.GetFloppyCount = XboxGetFloppyCount;
    MachVtbl.DiskReadLogicalSectors = XboxDiskReadLogicalSectors;
    MachVtbl.DiskGetDriveGeometry = XboxDiskGetDriveGeometry;
    MachVtbl.DiskGetCacheableBlockCount = XboxDiskGetCacheableBlockCount;
    MachVtbl.GetTime = XboxGetTime;
    MachVtbl.InitializeBootDevices = PcInitializeBootDevices;
    MachVtbl.HwDetect = XboxHwDetect;
    MachVtbl.HwIdle = XboxHwIdle;

    /* Initialize our stuff */
    XboxMemInit();
    XboxVideoInit();

    /* Set LEDs to orange after init */
    XboxSetLED("oooo");

    HalpCalibrateStallExecution();
}

VOID
XboxPrepareForReactOS(VOID)
{
    /* On Xbox, prepare video and disk support */
    XboxVideoPrepareForReactOS();
    XboxDiskInit(FALSE);
    DiskStopFloppyMotor();

    /* Turn off debug messages to screen */
    DebugDisableScreenPort();
}

/* EOF */
