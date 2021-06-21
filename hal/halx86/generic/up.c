/*
 * PROJECT:     ReactOS Kernel
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * FILE:        hal/halx86/generic/up.c
 * PURPOSE:     Source file for processor functions when they're not in smp mode.
 * PROGRAMMERS:  Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#include <hal.h>
#include <smp.h>
#define NDEBUG
#include <debug.h>

BOOLEAN
HalpStartNextProcessor(PLOADER_PARAMETER_BLOCK APLoaderBlock, PKPROCESSOR_STATE APProcessorState)
{
    /* We always return FALSE on UP mode */
    return FALSE;
}

VOID
HalpRequestIpi(KAFFINITY TargetProcessors)
{
    DPRINT1("HalRequestIpi: Shouldn't be called on UP mode");
    __debugbreak();
}
