/*
 * PROJECT:     ROSUEFI
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     UEFI core header file
 * COPYRIGHT:   Copyright 2021 Justin Miller <justinmiller100@gmail.com>
 */

#pragma once

/* C Headers */
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

/* NT Base Headers */
#include <ntifs.h>

/* NDK Headers */
#include <ntndk.h>

/* NT SafeInt Header */
#include <ntintsafe.h>

/* PE Headers */
#include <ntimage.h>

/* ACPI Headers */
#include <drivers/acpi/acpi.h>

/* UEFI Headers */
#include <uefi/uefigop.h>
#include <uefi/uefierror.h>
