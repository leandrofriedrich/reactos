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
