
#ifndef _ARM64_KETYPES_H
#define _ARM64_KETYPES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// CPU Vendors
//
typedef enum
{
    CPU_UNKNOWN = 0,
} CPU_VENDORS;

//
// IPI Types
//
#define IPI_APC                 1
#define IPI_DPC                 2
#define IPI_FREEZE              4
#define IPI_PACKET_READY        6
#define IPI_SYNCH_REQUEST       16

//
// PRCB Flags
//
#define PRCB_MAJOR_VERSION      1
#define PRCB_BUILD_DEBUG        1
#define PRCB_BUILD_UNIPROCESSOR 2

//
// No LDTs on ARM64
//
#define LDT_ENTRY              ULONG

//
// HAL Variables
//
#define INITIAL_STALL_COUNT     100
#define MM_HAL_VA_START         0xFFC00000
#define MM_HAL_VA_END           0xFFFFFFFF

//
// Structure for CPUID info
//
typedef union _CPU_INFO
{
    ULONG Dummy;
} CPU_INFO, *PCPU_INFO;

/* TODO: REVERSE ME D: */
typedef struct _KTRAP_FRAME
{
    ULONG dummy;
} KTRAP_FRAME, *PKTRAP_FRAME;

#ifndef NTOS_MODE_USER

//
// Processor Region Control Block
// Based on Windows 10
//
typedef struct _KPRCB
{
    /* TODO: REVERSE ME D: */
    ULONG dummy;
} KPRCB, *PKPRCB;

//
// Processor Control Region
// Based on Windows 10
//
typedef struct _KIPCR
{
    ULONG dummy;
} KIPCR, *PKIPCR;

//
// Macro to get current KPRCB
//
FORCEINLINE
struct _KPRCB *
KeGetCurrentPrcb(VOID)
{  
    return 0;
}

//
// Just read it from the PCR
//
#define KeGetCurrentIrql()             KeGetPcr()->CurrentIrql
#define _KeGetCurrentThread()          KeGetCurrentPrcb()->CurrentThread
#define _KeGetPreviousMode()           KeGetCurrentPrcb()->CurrentThread->PreviousMode
#define _KeIsExecutingDpc()            (KeGetCurrentPrcb()->DpcRoutineActive != 0)
#define KeGetCurrentThread()           _KeGetCurrentThread()
#define KeGetPreviousMode()            _KeGetPreviousMode()
//#define KeGetDcacheFillSize()          PCR->DcacheFillSize

#endif // !NTOS_MODE_USER

#ifdef __cplusplus
}; // extern "C"
#endif

#endif // !_ARM64_KETYPES_H
