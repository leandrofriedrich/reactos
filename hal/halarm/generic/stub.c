/*
 * PROJECT:         ReactOS HAL
 * LICENSE:         BSD - See COPYING.ARM in the top level directory
 * FILE:            hal/halarm/generic/halinit.c
 * PURPOSE:         HAL Entrypoint and Initialization
 * PROGRAMMERS:     ReactOS Portable Systems Group
 */

/* INCLUDES *******************************************************************/

#include <hal.h>
#define NDEBUG
#include <debug.h>

/*
 * @implemented
 */
CODE_SEG("INIT")
BOOLEAN
NTAPI
HalInitSystem(IN ULONG BootPhase,
              IN PLOADER_PARAMETER_BLOCK LoaderBlock)
{
    return FALSE;
}
