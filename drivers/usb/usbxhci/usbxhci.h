/*
 * PROJECT:         ReactOS xHCI Driver
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         Resource definitions
 * COPYRIGHT:       Copyright 2017 Rama Teja Gampa <ramateja.g@gmail.com>
 */

#pragma once

#include <ntddk.h>
#include <windef.h>
#include <stdio.h>
#include <hubbusif.h>
#include <usbbusif.h>
#include <usbdlib.h>
#include <drivers/usbport/usbmport.h>
#include "hardware.h"
#include "xhcispec.h"

extern USBPORT_REGISTRATION_PACKET RegPacket;

/* Transfer TRBs IDs ******************************************************************************/

#define NORMAL          1
#define SETUP_STAGE     2
#define DATA_STAGE      3
#define STATUS_STAGE    4
#define ISOCH           5
#define LINK            6  // BOTH TRNASFER AND COMMAND TRB TYPE
#define EVENT_DATA      7
#define NO_OP           8

/* Command TRB IDs ********************************************************************************/

#define ENABLE_SLOT_COMMAND             9
#define DISABLE_SLOT_COMMAND            10
#define ADDRESS_DEVICE_COMMAND          11
#define CONFIGURE_ENDPOINT_COMMAND      12
#define EVALUATE_CONTEXT_COMMAND        13
#define RESET_ENDPOINT_COMMAND          14
#define STOP_ENDPOINT_COMMAND           15
#define SET_TR_DEQUEUE_COMMAND          16
#define RESET_DEVICE_COMMAND            17
#define FORCE_EVENT_COMMMAND            18
#define NEGOTIATE_BANDWIDTH_COMMAND     19
#define SET_LATENCY_TOLERANCE_COMMAND   20
#define GET_PORT_BANDWIDTH_COMMAND      21
#define FORCE_HEADER_COMMAND            22
#define NO_OP_COMMAND                   23

/* Event TRB IDs **********************************************************************************/

#define TRANSFER_EVENT                  32
#define COMMAND_COMPLETION_EVENT        33
#define PORT_STATUS_CHANGE_EVENT        34
#define BANDWIDTH_RESET_REQUEST_EVENT   35
#define DOORBELL_EVENT                  36
#define HOST_CONTROLLER_EVENT           37
#define DEVICE_NOTIFICATION_EVENT       38
#define MF_INDEX_WARP_EVENT             39

/* TRB Completion Codes ***************************************************************************/

#define INVALID                     0
#define SUCCESS                     1
#define DATA_BUFFER_ERROR           2
#define BABBLLE_DETECTED_ERROR      3
#define USB_TRNASACTION_ERROR       4
#define TRB_ERROR                   5
#define STALL_ERROR                 6
#define RESOURCE_ERROR              7
#define BANDWIDTH_ERROR             8
#define NO_SLOTS_AVAILABLE_ERROR    9
#define INVALID_STREAM_TYPE_ERROR   10
#define SLOT_NOT_ENABLED_ERROR      11
#define ENDPOINT_NOT_ENABLED_ERROR  12
#define SHORT_PACKET                13
#define RING_UNDERRUN               14
#define RING_OVERRUN                15
#define VF_EVENT_RING_FULL_ERROR    16
#define PARAMETER_ERROR             17
#define BANDWIDTH_OVERRUN_ERROR     18
#define CONTEXT_STATE_ERROR         19
#define NO_PING_RESPONSE_ERROR      20
#define EVENT_RING_FULL_ERROR       21
#define INCOMPATIBLE_DEVICE_ERROR   22
#define MISSED_SERVICE_ERROR        23
#define COMMAND_RING_STOPPED        24
#define COMMAND_ABORTED             25
#define STOPPED                     26
#define STOPPED_LENGTH_INVALID      27
#define STOPPED_SHORT_PACKET        28
#define MAX_EXIT_LATENCY_ERROR      29
#define ISOCH_BUFFER_OVERRUN        31
#define EVENT_LOST_ERROR            32
#define UNDEFINED_ERROR             33
#define INVALID_STREAM_ID_ERROR     34
#define SECONDARY_BANDWIDTH_ERROR   35
#define SPLIT_TRNASACTION_ERROR     36

/* Roothub Functions ******************************************************************************/

VOID
NTAPI
XHCI_RH_GetRootHubData(
  IN PVOID xhciExtension,
  IN PVOID rootHubData);

MPSTATUS
NTAPI
XHCI_RH_GetStatus(
  IN PVOID xhciExtension,
  IN PUSHORT Status);

MPSTATUS
NTAPI
XHCI_RH_GetPortStatus(
  IN PVOID xhciExtension,
  IN USHORT Port,
  IN PUSB_PORT_STATUS_AND_CHANGE PortStatus);

MPSTATUS
NTAPI
XHCI_RH_GetHubStatus(
  IN PVOID xhciExtension,
  IN PUSB_HUB_STATUS_AND_CHANGE HubStatus);

MPSTATUS
NTAPI
XHCI_RH_SetFeaturePortReset(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_SetFeaturePortPower(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_SetFeaturePortEnable(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_SetFeaturePortSuspend(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortEnable(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortPower(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortSuspend(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortEnableChange(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortConnectChange(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortResetChange(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortSuspendChange(
  IN PVOID xhciExtension,
  IN USHORT Port);

MPSTATUS
NTAPI
XHCI_RH_ClearFeaturePortOvercurrentChange(
  IN PVOID xhciExtension,
  IN USHORT Port);

VOID
NTAPI
XHCI_RH_DisableIrq(
  IN PVOID xhciExtension);

VOID
NTAPI
XHCI_RH_EnableIrq(
  IN PVOID xhciExtension);
