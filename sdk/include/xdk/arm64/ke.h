$if (_WDMDDK_)
/* Kernel definitions for ARM64 */

NTSYSAPI
PKTHREAD
NTAPI
KeGetCurrentThread(VOID);

_Always_(_Post_satisfies_(return<=0))
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
_Kernel_float_saved_
_At_(*FloatSave, _Kernel_requires_resource_not_held_(FloatState) _Kernel_acquires_resource_(FloatState))

#define DbgRaiseAssertionFailure() __emit(0xdefc) /* Place holder based on arm32 for testing! */

$endif (_WDMDDK_)
$if (_NTDDK_)

#define ARM64_MAX_BREAKPOINTS 8
#define ARM64_MAX_WATCHPOINTS 2

typedef union NEON128 {
    struct {
        ULONGLONG Low;
        LONGLONG High;
    } DUMMYSTRUCTNAME;
    double D[2];
    float  S[4];
    USHORT H[8];
    UCHAR  B[16];
} NEON128, *PNEON128;
typedef NEON128 NEON128, *PNEON128;

typedef struct _CONTEXT {

    //
    // Control flags.
    //

    /* +0x000 */ UINT32 ContextFlags;

    //
    // Integer registers
    //

    /* +0x004 */ UINT32 Cpsr;       // NZVF + DAIF + CurrentEL + SPSel
    /* +0x008 */ union {
                    struct {
                        DWORD64 X0;
                        DWORD64 X1;
                        DWORD64 X2;
                        DWORD64 X3;
                        DWORD64 X4;
                        DWORD64 X5;
                        DWORD64 X6;
                        DWORD64 X7;
                        DWORD64 X8;
                        DWORD64 X9;
                        DWORD64 X10;
                        DWORD64 X11;
                        DWORD64 X12;
                        DWORD64 X13;
                        DWORD64 X14;
                        DWORD64 X15;
                        DWORD64 X16;
                        DWORD64 X17;
                        DWORD64 X18;
                        DWORD64 X19;
                        DWORD64 X20;
                        DWORD64 X21;
                        DWORD64 X22;
                        DWORD64 X23;
                        DWORD64 X24;
                        DWORD64 X25;
                        DWORD64 X26;
                        DWORD64 X27;
                        DWORD64 X28;
    /* +0x0f0 */        DWORD64 Fp;
    /* +0x0f8 */        DWORD64 Lr;
                    } DUMMYSTRUCTNAME;
                    DWORD64 X[31];
                 } DUMMYUNIONNAME;
    /* +0x100 */ DWORD64 Sp;
    /* +0x108 */ DWORD64 Pc;

    //
    // Floating Point/NEON Registers
    //

    /* +0x110 */ NEON128 V[32];
    /* +0x310 */ UINT32 Fpcr;
    /* +0x314 */ UINT32 Fpsr;

    //
    // Debug registers
    //

    /* +0x318 */ UINT32 Bcr[ARM64_MAX_BREAKPOINTS];
    /* +0x338 */ DWORD64 Bvr[ARM64_MAX_BREAKPOINTS];
    /* +0x378 */ UINT32 Wcr[ARM64_MAX_WATCHPOINTS];
    /* +0x380 */ DWORD64 Wvr[ARM64_MAX_WATCHPOINTS];
    /* +0x390 */

} _CONTEXT, *P_CONTEXT;
typedef _CONTEXT CONTEXT, *PCONTEXT;
$endif
