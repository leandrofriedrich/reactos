/*
 * PROJECT:     ReactOS kernel-mode tests
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     Kernel-Mode Test Suite Struct alignment tests
 * COPYRIGHT:   Copyright 2018 Mark Jansen (mark.jansen@reactos.org)
 */

#include <kmt_test.h>

// When searching for the correct offset,
// this will generate a compile-time error including the offset:
// char (*__kaboom1)[FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.EaLength)] = 1;
// Taken from https://stackoverflow.com/a/35261673

#if !defined(_AMD64_)

//plzstop(sizeof(IO_STACK_LOCATION) == 36);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, MajorFunction) == 0);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, MinorFunction) == 1);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Flags) == 2);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Control) == 3);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.SecurityContext) == 4);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.Options) == 8);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.FileAttributes) == 12);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.ShareAccess) == 14);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.EaLength) == 16);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.WhichSpace) == 4);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.Buffer) == 8);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.Offset) == 12);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.Length) == 16);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.Length) == 4);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.FileInformationClass) == 8);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.FileObject) == 12);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.ReplaceIfExists) == 16);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.AdvanceOnly) == 17);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.ClusterCount) == 16);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.DeleteHandle) == 16);

#else

//plzstop(sizeof(IO_STACK_LOCATION) == 72);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, MajorFunction) == 0);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, MinorFunction) == 1);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Flags) == 2);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Control) == 3);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.SecurityContext) == 8);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.Options) == 16);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.FileAttributes) == 24);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.ShareAccess) == 26);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.Create.EaLength) == 32);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.WhichSpace) == 8);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.Buffer) == 16);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.Offset) == 24);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.ReadWriteConfig.Length) == 32);

//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.Length) == 8);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.FileInformationClass) == 16);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.FileObject) == 24);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.ReplaceIfExists) == 32);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.AdvanceOnly) == 33);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.ClusterCount) == 32);
//plzstop(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.SetFile.DeleteHandle) == 32);

#endif
