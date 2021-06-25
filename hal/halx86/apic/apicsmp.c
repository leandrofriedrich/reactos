/*
 * PROJECT:     ReactOS HAL
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/apic/apicsmp.c
 * PURPOSE:     SMP specific APIC code
 * PROGRAMMERS: Copyright 2021 Timo Kreuzer (timo.kreuzer@reactos.org)
 * PROGRAMMERS: Copyright 2021 Justin Miller (justinmiller100@gmail.com)
 */

/* INCLUDES *******************************************************************/

#include <hal.h>
#include "apicp.h"
#include <smp.h>
#define NDEBUG
#include <debug.h>

/* INTERNAL FUNCTIONS *********************************************************/

/*!
    \param Vector - Specifies the interrupt vector to be delivered.

    \param MessageType - Specifies the message type sent to the CPU core
        interrupt handler. This can be one of the following values:
        APIC_MT_Fixed - Delivers an interrupt to the target local APIC
            specified in Destination field.
        APIC_MT_LowestPriority - Delivers an interrupt to the local APIC
            executing at the lowest priority of all local APICs.
        APIC_MT_SMI - Delivers an SMI interrupt to target local APIC(s).
        APIC_MT_RemoteRead - Delivers a read request to read an APIC register
            in the target local APIC specified in Destination field.
        APIC_MT_NMI - Delivers a non-maskable interrupt to the target local
            APIC specified in the Destination field. Vector is ignored.
        APIC_MT_INIT - Delivers an INIT request to the target local APIC(s)
            specified in the Destination field. TriggerMode must be
            APIC_TGM_Edge, Vector must be 0.
        APIC_MT_Startup - Delivers a start-up request (SIPI) to the target
            local APIC(s) specified in Destination field. Vector specifies
            the startup address.
        APIC_MT_ExtInt - Delivers an external interrupt to the target local
            APIC specified in Destination field. 

    \param TriggerMode - The trigger mode of the interrupt. Can be:
        APIC_TGM_Edge - The interrupt is edge triggered.
        APIC_TGM_Level - The interrupt is level triggered.

    \param DestinationShortHand - Specifies where to send the interrupt.
        APIC_DSH_Destination
        APIC_DSH_Self
        APIC_DSH_AllIncludingSelf
        APIC_DSH_AllExclusingSelf

    \see "AMD64 Architecture Programmer's Manual Volume 2 System Programming"
        Chapter 16 "Advanced Programmable Interrupt Controller (APIC)"
        16.5 "Interprocessor Interrupts (IPI)"

 */
FORCEINLINE
VOID
ApicRequestGlobalInterrupt(
    _In_ UCHAR DestinationProcessor,
    _In_ UCHAR Vector,
    _In_ APIC_MT MessageType,
    _In_ APIC_TGM TriggerMode,
    _In_ APIC_DSH DestinationShortHand)
{
    APIC_INTERRUPT_COMMAND_REGISTER Icr;

    /* Setup the command register */
    Icr.LongLong = 0;
    Icr.Vector = Vector;
    Icr.MessageType = MessageType;
    Icr.DestinationMode = APIC_DM_Physical;
    Icr.DeliveryStatus = 0;
    Icr.Level = 0;
    Icr.TriggerMode = TriggerMode;
    Icr.RemoteReadStatus = 0;
    Icr.DestinationShortHand = DestinationShortHand;
    Icr.Destination = DestinationProcessor;

    /* Write the low dword last to send the interrupt */
    ApicWrite(APIC_ICR1, Icr.Long1);
    ApicWrite(APIC_ICR0, Icr.Long0);
}

FORCEINLINE
ULONG
ApicReadRemoteRegister(
    _In_ UCHAR DestinationProcessor,
    _In_ APIC_REGISTER ApicRegister)
{
    APIC_INTERRUPT_COMMAND_REGISTER Icr;

    /* Request a remote read */
    ApicRequestGlobalInterrupt(DestinationProcessor,
                               (UCHAR)ApicRegister,
                               APIC_MT_RemoteRead,
                               APIC_TGM_Edge,
                               APIC_DSH_Destination);

    /* Wait until remote read is finished */
    do
    {
        _mm_pause();
        Icr.Long0 = ApicRead(APIC_ICR0);
    } while (Icr.RemoteReadStatus == APIC_RRS_Pending);

    ASSERT(Icr.RemoteReadStatus == APIC_RRS_Done);

    /* Return the value from the Remote Read Register */
    return ApicRead(APIC_RRR);
}


/* SMP SUPPORT FUNCTIONS ******************************************************/

VOID
NTAPI /* HalRequestIpi (CONFIG_SMP) */
HalpRequestIpi(KAFFINITY TargetProcessors)
{
    UNIMPLEMENTED;
    __debugbreak();
}

BOOLEAN /* HalStartApplicationProcessor */
ApicStartApplicationProcessor(ULONG NTProcessorNumber, PHYSICAL_ADDRESS StartupLoc)
{
    ULONG i, temp;
    /* 
     * There's a few cases this can fail:
     * - APIC version not supporting anymore LAPICs
     * - No Application Processors at the number given
     * - Some failure in APIC read or writes
     * - Hardware not accepting the command for some other reason
     */

    /* Init IPI */
    ApicRequestGlobalInterrupt(NTProcessorNumber, 0, 
        APIC_MT_INIT, APIC_TGM_Edge, APIC_DSH_Destination);

    /* Stall execution for a bit to give APIC time */
    KeStallExecutionProcessor(1000);

    /* Startup IPI */
    ApicRequestGlobalInterrupt(NTProcessorNumber, (StartupLoc.LowPart) >> 12, 
        APIC_MT_Startup, APIC_TGM_Edge, APIC_DSH_Destination);

    /* TODO: Test for IPI error */
    /* Wait up to 100ms for the APIC to become ready */
   for (i = 0; i < 10000; i++)
   {
      temp = ApicRead(APIC_ICR0);
      /* Check Delivery Status */
      if ((temp & (0x1 << 12)) == 0)
         break;
      KeStallExecutionProcessor(10);
   }

   if (i == 10000)
   {
      DPRINT1("Frick bro");
      return FALSE;
   }
    /* Hurray an AP has started sucessfully! */
    return TRUE;
    
}

VOID /* HalpStopAP */
ApicSoftlyStopApplicationProcessor(ULONG NTProcessorNumber)
{

}

VOID /* HalpStopAllAPs */
ApicHarshlyStopAllApplicationProcessors(VOID)
{

}
