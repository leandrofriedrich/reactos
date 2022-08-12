/*
 * PROJECT:     ReactOS HAL
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     GIC definitions
 * COPYRIGHT:   Copyright 2022 Leandro Friedrich <email@leandrofriedrich.de>
 */

#define GICD_CTLR 0x000 /* distributor control register */ 
#define GICD_TYPER 0x004 /* Interrupt Controller Type Register */ 
#define GICD_IIDR 0x008 /* Distributor Implementer Identification Register */ 
#define GICD_IOGROUPRn 0x080 /* Interrupt Group Registers 0x084-0x0FC */
#define GICD_ISENABLERn 0x100 /* Interrupt Group Registers 0x17C */
#define GICD_ICENABLERn 0x180 /* Interrupt Clear-Enable Registers 0x1FC */
#define GICD_ISPENDRn 0x200 /* Interrupt Set-Pending Registers 0x27C */
#define GICD_ICPENDRn 0x280 /* Interrupt Clear-Pending Registers 0x2FC */
#define GICD_ISACTIVERn 0x300 /* Interrupt Set-Active Registers 0x37C (GICv2)*/
#define GICD_ICACTIVERn 0x380 /* Interrupt Clear-Active Registers */
#define GICD_IPRIORITYn 0x400 /* Interrupt Priority Registers 0x7F8 */
#define GICD_ITARGETSRn 0x800 /* Interrupt Processor Targets Registers 0x820-0xBF8 */
#define GICD_ICFGRN 0xC00 /* Interrupt Configuration Registers 0xCFC */
#define GICD_NSACRn 0xE00 /* Non-Secure Access Control Registers, optional */
#define GICD_SGIR 0xF00 /* Software Generated Interrupt Register */
#define GICD_CPENDSGIRn 0xF10 /* SGI Clear-Pending Registers 0xF1C */
#define GICD_SPENDSGIRn 0xF20 /* SGI Set-Pending Registers 0xF2C */

#define GICC_CTLR 0x0000 /* CPU Interface Control Register */
#define GICC_PMR 0x0004 /* Interrupt Priority Mask Register */
#define GICC_BPR 0x0008 /* Binary Point Register  */
#define GICC_IAR 0x000C /* Interrupt Acknowledge Register */
#define GICC_EOIR 0x0010 /* End of Interrupt Register */
#define GICC_RPR 0x0014 /* Highest Priority Pending Interrupt Register */
#define GICC_HPPIR 0x0018 /* Highest Priority Pending Interrupt Register */
#define GICC_ABPR 0x001C /* Aliased Binary Point Register */
#define GICC_AIAR 0x0020 /* Aliased Interrupt Acknowledge Register */
#define GICC_AEOIR 0x0024 /* Aliased End of Interrupt Register */
#define GICC_AHPPIR 0x0028 /* Aliased Highest Priority Pending Interrupt Register */
#define GICC_APRn 0x00D0 /* Active Priorities Registers 0x00DC */
#define GICC_NSAPRn 0x00E0 /* Non-secure Active Priorities Registers 0x00EC */
#define GICC_IIDR 0x00FC /* CPU Interface Identification Register */
#define GICC_DIR 0x1000 /* Deactivate Interrupt Register */

/* 4.3.1 GICv2 Specification */
typedef struct _GICD_CTLR_REGISTER
{
    ULONG Rsdvz1        : 31
    ULONG Enable        : 1
} GICD_CTLR_REGISTER, *PGICD_CTLR_REGISTER

/* 4.3.2 GICv2 Specification */
typedef struct _GICD_TYPER_REGISTER
{
    ULONG Rsdvz1         : 16
    ULONG LSPI		 : 5
    ULONG SecurityExtn	 : 1
    ULONG Rsdvz2         : 2
    ULONG CPUNumber	 : 3
    ULONG ITLinesNumber  : 4
} GICD_TYPER_REGISTER, *PGICD_TYPER_REGISTER

/* 4.3.3 GICv2 Specification */
typedef struct _GICD_IIDR_REGISTER
{
    ULONG ProductID      : 8
    ULONG Rsdvz1	 : 4
    ULONG Variant	 : 4
    ULONG Revision       : 4
    ULONG Implementer    : 12
} GICD_TYPER_REGISTER, *PGICD_TYPER_REGISTER

/* 4.3.4 GICv2 Specification */
typedef struct _GICD_IGROUPRn_REGISTER
{
    ULONG GRPSTATUS_BITS : 32
} GICD_IGROUPRn_REGISTER, *PGICD_IGROUPRn_REGISTER

/* 4.3.5 GICv2 Specification */
typedef struct _GICD_ISENABLERn_REGISTER
{
    ULONG SETENABLE_BITS : 32
} GICD_ISENABLERn_REGISTER, *PGICD_ISENABLERn_REGISTER

/* 4.3.6 GICv2 Specification */
typedef struct _GICD_ICENABLERn_REGISTER
{
    ULONG CLRENABLE_BITS : 32
} GICD_ICENABLERn_REGISTER, *PGICD_ICENABLERn_REGISTER

/* 4.3.7 GICv2 Specification */
typedef struct _GICD_ISPENDRn_REGISTER
{
    ULONG SETPENDING_BITS : 32
} GICD_ISPENDRn_REGISTER, *PGICD_ISPENDRn_REGISTER

/* 4.3.8 GICv2 Specification */
typedef struct _GICD_ISPENDRn_REGISTER
{
    ULONG CLRPENDING_BITS : 32
} GICD_ICPENDRn_REGISTER, *PGICD_ICPENDRn_REGISTER

/* 4.3.9 GICv2 Specification */
typedef struct _GICD_ISACTIVERn_REGISTER
{
    ULONG SETACTIVE_BITS : 32
} GICD_ISACTIVERn_REGISTER, *PGICD_ISACTIVERn_REGISTER

/* 4.3.10 GICv2 Specification */
typedef struct _GICD_ICACTIVERn_REGISTER
{
    ULONG CLRACTIVE_BITS : 32
} GICD_ICACTIVERn_REGISTER, *PGICD_ISACTIVERn_REGISTER

/* 4.3.11 GICv2 Specification */
typedef struct _GICD_IPRIORITYRn_REGISTER
{
    ULONG Offset1        : 8
    ULONG Offset2        : 8
    ULONG Offset3        : 8
    ULONG Offset4        : 8
} GICD_IPRIORITYRn_REGISTER, *PGICD_IPRIORITYRn_REGISTER

/* 4.3.12 GICv2 Specification */
typedef struct _GICD_ITARGETSRn_REGISTER
{
    ULONG Offset1        : 8
    ULONG Offset2        : 8
    ULONG Offset3        : 8
    ULONG Offset4        : 8
} GICD_ITARGETSRn_REGISTER, *PGICD_ITARGETSRn_REGISTER

/* 4.3.13 GICv2 Specification - SKIPPED */

/* 4.3.14 GICv2 Specification - SKIPPED */


/* 4.3.15 GICv2 Specification */
typedef struct _GICD_ISGIR_REGISTER
{
    ULONG Rsdvz1         : 6
    ULONG TargetListFilter : 2
    ULONG CPUTargetList  : 8
    ULONG NSATT          : 1
    ULONG Rsdvz2	 : 11
    ULONG SGIINTID	 : 4
} GICD_SGIR_REGISTER, *PGICD_SGIR_REGISTER

/* 4.3.16 GICv2 Specification */
typedef struct _GICD_CPENDSGIRn_REGISTER
{
    ULONG SGI_CLRPEND1    : 8
    ULONG SGI_CLRPEND2    : 8
    ULONG SGI_CLRPEND3    : 8
    ULONG SGI_CLRPEND4    : 8
} GICD_CPENDSGIRn_REGISTER, *PGICD_CPENDSGIRn_REGISTER

/* 4.3.17 GICv2 Specification */
typedef struct _GICD_SPENDSGIRn_REGISTER
{
    ULONG SGI_SETPEND1    : 8
    ULONG SGI_SETPEND2    : 8
    ULONG SGI_SETPEND3    : 8
    ULONG SGI_SETPEND4    : 8
} GICD_SPENDSGIRn_REGISTER, *PGICD_SPENDSGIRn_REGISTER


/* 4.4.1 GICv2 Specification */
typedef struct _GICC_CTLR_REGISTER
{
    ULONG Rsdvz1       : 31
    ULONG Enable        : 1
} GICC_CTLR_REGISTER, *PGICC_CTLR_REGISTER

/* 4.4.2 GICv2 Specification */
typedef struct _GICC_PMR_REGISTER
{
    ULONG Priority     : 24
    ULONG Rsdvz1       : 8
} GICC_PMR_REGISTER, *PGICC_PMR_REGISTER

/* 4.4.3 GICv2 Specification */
typedef struct _GICC_BPR_REGISTER
{
    ULONG Rsdvz1       : 29
    ULONG BinaryPoint  : 3
} GICC_BPR_REGISTER, *PGICC_BPR_REGISTER

/* 4.4.4 GICv2 Specification */
typedef struct _GICC_IAR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG InterruptID  : 10
} GICC_IAR_REGISTER, *PGICC_IAR_REGISTER

/* 4.4.5 GICv2 Specification */
typedef struct _GICC_EOIR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG EOIINTID     : 10
} GICC_EOIR_REGISTER, *PGICC_EOIR_REGISTER

/* 4.4.6 GICv2 Specification */
typedef struct _GICC_RPR_REGISTER
{
    ULONG Rsdvz1       : 24
    ULONG Priority     : 8
} GICC_RPR_REGISTER, *PGICC_RPR_REGISTER

/* 4.4.7 GICv2 Specification */
typedef struct _GICC_HPPIR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG PENDINTID    : 10
} GICC_ABPR_REGISTER, *PGICC_ABPR_REGISTER

/* 4.4.8 GICv2 Specification */
typedef struct _GICC_ABPR_REGISTER
{
    ULONG Rsdvz1       : 29
    ULONG BinaryPoint  : 3
} GICC_ABPR_REGISTER, *PGICC_ABPR_REGISTER

/* 4.4.9 GICv2 Specification */
typedef struct _GICC_AIAR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG InterruptID  : 10
} GICC_AIAR_REGISTER, *PGICC_AIAR_REGISTER

/* 4.4.10 GICv2 Specification */
typedef struct _GICC_AEOIR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG InterruptID  : 10
} GICC_AEOIR_REGISTER, *PGICC_AEOIR_REGISTER

/* 4.4.11 GICv2 Specification */
typedef struct _GICC_AHPPIR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG PENDINTID    : 10
} GICC_AHPPIR_REGISTER, *PGICC_AHPPIR_REGISTER

/* 4.4.12 GICv2 Specification - SKIPPED*/

/* 4.4.13 GICv2 Specification - SKIPPED*/

/* 4.4.14 GICv2 Specification */
typedef struct _GICC_IIDR_REGISTER
{
    ULONG ProductID    : 12
    ULONG ARCH_VERSION : 4
    ULONG Revision     : 4
    ULONG Implementer  : 12
} GICC_IIDR_REGISTER, *PGICC_IIDR_REGISTER

/* 4.4.15 GICv2 Specification */
typedef struct _GICC_DIR_REGISTER
{
    ULONG Rsdvz1       : 19
    ULONG CPUID        : 3
    ULONG InterruptID  : 10
} GICC_DIR_REGISTER, *PGICC_DIR_REGISTER
