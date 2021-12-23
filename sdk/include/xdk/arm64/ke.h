$if (_WDMDDK_)
<<<<<<< HEAD
/** Kernel definitions for ARM **/
=======
/** Kernel definitions for ARM (32bit, just here as place holder) **/
>>>>>>> e6cdca761459b758dcabfd0a819b1f88155ca5ca

/* Interrupt request levels */
#define PASSIVE_LEVEL           0
#define LOW_LEVEL               0
#define APC_LEVEL               1
#define DISPATCH_LEVEL          2
#define CLOCK_LEVEL             13
#define IPI_LEVEL               14
#define DRS_LEVEL               14
#define POWER_LEVEL             14
#define PROFILE_LEVEL           15
#define HIGH_LEVEL              15

#define KIP0PCRADDRESS          0xFFDFF000
#define KI_USER_SHARED_DATA     0xFFFF9000
#define SharedUserData          ((KUSER_SHARED_DATA * const)KI_USER_SHARED_DATA)

#define PAGE_SIZE               0x1000
#define PAGE_SHIFT              12L
#define DbgRaiseAssertionFailure() __emit(0xdefc)

NTSYSAPI
PKTHREAD
NTAPI
KeGetCurrentThread(VOID);


<<<<<<< HEAD
FORCEINLINE
PKPCR
KeGetPcr(
    VOID)
{
    return NULL;
}

FORCEINLINE
ULONG
NTAPI
KeGetCurrentProcessorIndex(VOID)
{
    return 0;
}

=======
>>>>>>> e6cdca761459b758dcabfd0a819b1f88155ca5ca
$endif (_WDMDDK_)
$if (_NTDDK_)
typedef struct _NEON128
{
    ULONGLONG Low;
    LONGLONG High;
} NEON128, *PNEON128;

#define ARM_MAX_BREAKPOINTS 8
#define ARM_MAX_WATCHPOINTS 1


#define DbgRaiseAssertionFailure() __emit(0xdefc)
typedef struct _CONTEXT
{
    /* The flags values within this flag control the contents of
       a CONTEXT record.

       If the context record is used as an input parameter, then
       for each portion of the context record controlled by a flag
       whose value is set, it is assumed that that portion of the
       context record contains valid context. If the context record
       is being used to modify a thread's context, then only that
       portion of the threads context will be modified.

       If the context record is used as an IN OUT parameter to capture
       the context of a thread, then only those portions of the thread's
       context corresponding to set flags will be returned.

       The context record is never used as an OUT only parameter. */
    ULONG ContextFlags;

    /* This section is specified/returned if the ContextFlags word contains
       the flag CONTEXT_INTEGER. */
<<<<<<< HEAD
    ULONG R0;
    ULONG R1;
    ULONG R2;
    ULONG R3;
    ULONG R4;
    ULONG R5;
    ULONG R6;
    ULONG R7;
    ULONG R8;
    ULONG R9;
    ULONG R10;
    ULONG R11;
    ULONG R12;

    ULONG Sp;
    ULONG Lr;
    ULONG Pc;
    ULONG Cpsr;

    /* Floating Point/NEON Registers */
    ULONG Fpscr;
    ULONG Padding;
    union
    {
        NEON128 Q[16];
        ULONGLONG D[32];
        ULONG S[32];
    } DUMMYUNIONNAME;

    /* Debug registers */
    ULONG Bvr[ARM_MAX_BREAKPOINTS];
    ULONG Bcr[ARM_MAX_BREAKPOINTS];
    ULONG Wvr[ARM_MAX_WATCHPOINTS];
    ULONG Wcr[ARM_MAX_WATCHPOINTS];

    ULONG Padding2[2];
=======
    ULONG x0;

    /* TODO: Implement me! */
>>>>>>> e6cdca761459b758dcabfd0a819b1f88155ca5ca
} CONTEXT;

$endif

