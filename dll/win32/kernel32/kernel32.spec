@ stdcall -version=0x600+ AcquireSRWLockExclusive(ptr) ntdll_vista.RtlAcquireSRWLockExclusive
@ stdcall -version=0x600+ AcquireSRWLockShared(ptr) ntdll_vista.RtlAcquireSRWLockShared
@ stdcall ActivateActCtx(ptr ptr)
@ stdcall AddAtomA(str)
@ stdcall AddAtomW(wstr)
@ stdcall AddConsoleAliasA(str str str) ;check
@ stdcall AddConsoleAliasW(wstr wstr wstr) ;check
@ stdcall AddLocalAlternateComputerNameA(str ptr)
@ stdcall AddLocalAlternateComputerNameW(wstr ptr)
@ stdcall AddRefActCtx(ptr)
@ stdcall -stub -version=0x600+ AddSIDToBoundaryDescriptor(ptr ptr)
@ stdcall -stub -version=0x600+ AddSecureMemoryCacheCallback(ptr)
@ stdcall AddVectoredContinueHandler(long ptr) ntdll.RtlAddVectoredContinueHandler
@ stdcall AddVectoredExceptionHandler(long ptr) ntdll.RtlAddVectoredExceptionHandler
@ stdcall -stub -version=0x600+ AdjustCalendarDate(ptr long long)
@ stdcall AllocConsole()
@ stdcall AllocateUserPhysicalPages(long ptr ptr)
@ stdcall -stub -version=0x600+ AllocateUserPhysicalPagesNuma(ptr ptr ptr long)
@ stdcall -stub -version=0x600+ ApplicationRecoveryFinished(long)
@ stdcall -stub -version=0x600+ ApplicationRecoveryInProgress(ptr)
@ stdcall AreFileApisANSI()
@ stdcall AssignProcessToJobObject(ptr ptr)
@ stdcall AttachConsole(long)
@ stdcall BackupRead(ptr ptr long ptr long long ptr)
@ stdcall BackupSeek(ptr long long ptr ptr ptr)
@ stdcall BackupWrite(ptr ptr long ptr long long ptr)
@ stdcall BaseCheckAppcompatCache(long long long ptr)
@ stdcall BaseCheckRunApp(long ptr long long long long long long long long)
@ stdcall BaseCleanupAppcompatCacheSupport(ptr)
@ stdcall BaseDumpAppcompatCache()
@ stdcall BaseFlushAppcompatCache()
@ stub -version=0x600+ BaseGenerateAppCompatData
@ stdcall -version=0x601+ BaseGetNamedObjectDirectory(ptr)
@ stdcall BaseInitAppcompatCacheSupport()
@ stdcall BaseIsAppcompatInfrastructureDisabled() IsShimInfrastructureDisabled
@ stdcall -version=0x501-0x502 BaseProcessInitPostImport()
;@ stdcall -version=0x502 -arch=x86_64 BaseProcessStart()
@ stdcall BaseQueryModuleData(str str ptr ptr ptr) ;check
@ stub -version=0x600+ BaseThreadInitThunk
;@ stdcall -version=0x502 -arch=x86_64 BaseThreadStart()
@ stdcall BaseUpdateAppcompatCache(long long long)
@ stdcall BasepCheckBadapp(long ptr long long long long long long long)
@ stdcall BasepCheckWinSaferRestrictions(long long long long long long)
@ stdcall BasepFreeAppCompatData(ptr ptr)
@ stdcall Beep(long long)
@ stdcall BeginUpdateResourceA(str long)
@ stdcall BeginUpdateResourceW(wstr long)
@ stdcall BindIoCompletionCallback(long ptr long)
@ stdcall BuildCommDCBA(str ptr)
@ stdcall BuildCommDCBAndTimeoutsA(str ptr ptr)
@ stdcall BuildCommDCBAndTimeoutsW(wstr ptr ptr)
@ stdcall BuildCommDCBW(wstr ptr)
@ stdcall CallNamedPipeA(str ptr long ptr long ptr long)
@ stdcall CallNamedPipeW(wstr ptr long ptr long ptr long)
@ stdcall -version=0x600+ CallbackMayRunLong(ptr)
@ stdcall CancelDeviceWakeupRequest(long)
@ stdcall CancelIo(long)
@ stdcall -stub -version=0x600+ CancelIoEx(ptr ptr)
@ stdcall -stub -version=0x600+ CancelSynchronousIo(ptr)
@ stdcall -stub -version=0x600+ CancelThreadpoolIo(ptr)
@ stdcall CancelTimerQueueTimer(long long)
@ stdcall CancelWaitableTimer(long)
@ stdcall ChangeTimerQueueTimer(ptr ptr long long)
@ stdcall -stub -version=0x600+ CheckElevation(ptr ptr ptr ptr ptr)
@ stdcall -stub -version=0x600+ CheckElevationEnabled(ptr)
@ stub -version=0x600+ CheckForReadOnlyResource
@ stdcall CheckNameLegalDOS8Dot3A(str str long long long)
@ stdcall CheckNameLegalDOS8Dot3W(wstr str long long long)
@ stdcall CheckRemoteDebuggerPresent(long ptr)
@ stdcall ClearCommBreak(long)
@ stdcall ClearCommError(long ptr ptr)
@ stdcall CloseConsoleHandle(long)
@ stdcall CloseHandle(long)
@ stdcall -stub -version=0x600+ ClosePrivateNamespace(ptr long)
@ stdcall CloseProfileUserMapping()
@ stdcall -version=0x600+ CloseThreadpool(ptr) ntdll_vista.TpReleasePool
@ stdcall -version=0x600+ CloseThreadpoolCleanupGroup(ptr) ntdll_vista.TpReleaseCleanupGroup
@ stdcall -version=0x600+ CloseThreadpoolCleanupGroupMembers(ptr long ptr) ntdll_vista.TpReleaseCleanupGroupMembers
@ stdcall -version=0x600+ CloseThreadpoolIo(ptr)  ; really, not event stub in wine?
@ stdcall -version=0x600+ CloseThreadpoolTimer(ptr) ntdll_vista.TpReleaseTimer
@ stdcall -version=0x600+ CloseThreadpoolWait(ptr) ntdll_vista.TpReleaseWait
@ stdcall -version=0x600+ CloseThreadpoolWork(ptr) ntdll_vista.TpReleaseWork
@ stdcall CmdBatNotification(long)
@ stdcall CommConfigDialogA(str long ptr)
@ stdcall CommConfigDialogW(wstr long ptr)
@ stdcall -stub -version=0x600+ CompareCalendarDates(ptr ptr ptr)
@ stdcall CompareFileTime(ptr ptr)
@ stdcall CompareStringA(long long str long str long)
@ stdcall -version=0x600+ CompareStringEx(wstr long wstr long wstr long ptr ptr ptr)
@ stdcall -version=0x600+ CompareStringOrdinal(wstr long wstr long long) kernel32_vista.CompareStringOrdinal
@ stdcall CompareStringW(long long wstr long wstr long)
@ stdcall ConnectNamedPipe(long ptr)
;@ stdcall -arch=x86_64 ConsoleIMERoutine()
@ stdcall ConsoleMenuControl(long long long)
@ stdcall ContinueDebugEvent(long long long)
@ stdcall -stub -version=0x600+ ConvertCalDateTimeToSystemTime(ptr ptr)
@ stdcall ConvertDefaultLocale (long)
@ stdcall ConvertFiberToThread()
@ stdcall -stub -version=0x600+ ConvertNLSDayOfWeekToWin32DayOfWeek(long)
@ stdcall -stub -version=0x600+ ConvertSystemTimeToCalDateTime(ptr long ptr)
@ stdcall ConvertThreadToFiber(ptr)
@ stdcall ConvertThreadToFiberEx(ptr long)
@ stdcall CopyFileA(str str long)
@ stdcall CopyFileExA (str str ptr ptr ptr long)
@ stdcall CopyFileExW (wstr wstr ptr ptr ptr long)
@ stdcall -stub -version=0x600+ CopyFileTransactedA(str str ptr ptr ptr long ptr)
@ stdcall -stub -version=0x600+ CopyFileTransactedW(wstr wstr ptr ptr ptr long ptr)
@ stdcall CopyFileW(wstr wstr long)
@ stdcall CopyLZFile(long long) LZCopy
@ stdcall CreateActCtxA(ptr)
@ stdcall CreateActCtxW(ptr)
@ stdcall -stub -version=0x600+ CreateBoundaryDescriptorA(str long)
@ stdcall -stub -version=0x600+ CreateBoundaryDescriptorW(wstr long)
@ stdcall CreateConsoleScreenBuffer(long long ptr long ptr)
@ stdcall CreateDirectoryA(str ptr)
@ stdcall CreateDirectoryExA(str str ptr)
@ stdcall CreateDirectoryExW(wstr wstr ptr)
@ stdcall -stub -version=0x600+ CreateDirectoryTransactedA(str str ptr ptr)
@ stdcall -stub -version=0x600+ CreateDirectoryTransactedW(wstr wstr ptr ptr)
@ stdcall CreateDirectoryW(wstr ptr)
@ stdcall CreateEventA(ptr long long str)
@ stdcall -version=0x600+ CreateEventExA(ptr str long long)
@ stdcall -version=0x600+ CreateEventExW(ptr wstr long long)
@ stdcall CreateEventW(ptr long long wstr)
@ stdcall CreateFiber(long ptr ptr)
@ stdcall CreateFiberEx(long long long ptr ptr)
@ stdcall CreateFileA(str long long ptr long long long)
@ stdcall CreateFileMappingA(long ptr long long long str)
@ stdcall -stub -version=0x600+ CreateFileMappingNumaA(ptr ptr long long long str long)
@ stdcall -stub -version=0x600+ CreateFileMappingNumaW(ptr ptr long long long wstr long)
@ stdcall CreateFileMappingW(long ptr long long long wstr)
@ stdcall -stub -version=0x600+ CreateFileTransactedA(str long long ptr long long ptr ptr ptr ptr)
@ stdcall -stub -version=0x600+ CreateFileTransactedW(wstr long long ptr long long ptr ptr ptr ptr)
@ stdcall CreateFileW(wstr long long ptr long long long)
@ stdcall CreateHardLinkA(str str ptr)
@ stdcall -stub -version=0x600+ CreateHardLinkTransactedA(str str ptr ptr)
@ stdcall -stub -version=0x600+ CreateHardLinkTransactedW(wstr wstr ptr ptr)
@ stdcall CreateHardLinkW(wstr wstr ptr)
@ stdcall CreateIoCompletionPort(long long long long)
@ stdcall CreateJobObjectA(ptr str)
@ stdcall CreateJobObjectW(ptr wstr)
@ stdcall CreateJobSet(long ptr long)
@ stdcall CreateMailslotA(ptr long long ptr)
@ stdcall CreateMailslotW(ptr long long ptr)
@ stdcall CreateMemoryResourceNotification(long)
@ stdcall CreateMutexA(ptr long str)
@ stdcall -version=0x600+ CreateMutexExA(ptr str long long)
@ stdcall -version=0x600+ CreateMutexExW(ptr wstr long long)
@ stdcall CreateMutexW(ptr long wstr)
@ stdcall CreateNamedPipeA(str long long long long long long ptr)
@ stdcall CreateNamedPipeW(wstr long long long long long long ptr)
@ stdcall -version=0x501-0x502 CreateNlsSecurityDescriptor(ptr long long)
@ stdcall CreatePipe(ptr ptr ptr long)
@ stdcall -stub -version=0x600+ CreatePrivateNamespaceA(ptr ptr str)
@ stdcall -stub -version=0x600+ CreatePrivateNamespaceW(ptr ptr wstr)
@ stdcall CreateProcessA(str str ptr ptr long long ptr str ptr ptr)
@ stdcall CreateProcessInternalA(ptr str str ptr ptr long long ptr str ptr ptr long)
@ stdcall CreateProcessInternalW(ptr wstr wstr ptr ptr long long ptr wstr ptr ptr long)
@ stdcall CreateProcessW(wstr wstr ptr ptr long long ptr wstr ptr ptr)
@ stdcall CreateRemoteThread(long ptr long ptr long long ptr)
@ stdcall CreateSemaphoreA(ptr long long str)
@ stdcall -version=0x600+ CreateSemaphoreExA(ptr long long str long long)
@ stdcall -version=0x600+ CreateSemaphoreExW(ptr long long wstr long long)
@ stdcall CreateSemaphoreW(ptr long long wstr)
@ stdcall -i386 CreateSocketHandle()
@ stdcall -version=0x600+ CreateSymbolicLinkA(str str long) kernel32_vista.CreateSymbolicLinkA
@ stdcall -stub -version=0x600+ CreateSymbolicLinkTransactedA(str str long ptr)
@ stdcall -stub -version=0x600+ CreateSymbolicLinkTransactedW(wstr wstr long ptr)
@ stdcall -version=0x600+ CreateSymbolicLinkW(wstr wstr long) kernel32_vista.CreateSymbolicLinkW
@ stdcall CreateTapePartition(long long long long)
@ stdcall CreateThread(ptr long ptr long long ptr)
@ stdcall -version=0x600+ CreateThreadpool(ptr)
@ stdcall -version=0x600+ CreateThreadpoolCleanupGroup()
@ stdcall -version=0x600+ CreateThreadpoolIo(ptr ptr ptr ptr)
@ stdcall -version=0x600+ CreateThreadpoolTimer(ptr ptr ptr)
@ stdcall -version=0x600+ CreateThreadpoolWait(ptr ptr ptr)
@ stdcall -version=0x600+ CreateThreadpoolWork(ptr ptr ptr)
@ stdcall CreateTimerQueue ()
@ stdcall CreateTimerQueueTimer(ptr long ptr ptr long long long)
@ stdcall CreateToolhelp32Snapshot(long long)
@ stdcall CreateWaitableTimerA(ptr long str)
@ stdcall -stub -version=0x600+ CreateWaitableTimerExA(ptr str long long)
@ stdcall -stub -version=0x600+ CreateWaitableTimerExW(ptr wstr long long)
@ stdcall CreateWaitableTimerW(ptr long wstr)
;@ stdcall -arch=x86_64 CtrlRoutine()
@ stdcall DeactivateActCtx(long ptr)
@ stdcall DebugActiveProcess(long)
@ stdcall DebugActiveProcessStop(long)
@ stdcall DebugBreak() ntdll.DbgBreakPoint
@ stdcall DebugBreakProcess(long)
@ stdcall DebugSetProcessKillOnExit(long)
@ stdcall DecodePointer(ptr) ntdll.RtlDecodePointer
@ stdcall DecodeSystemPointer(ptr) ntdll.RtlDecodeSystemPointer
@ stdcall DefineDosDeviceA(long str str)
@ stdcall DefineDosDeviceW(long wstr wstr)
@ stdcall DelayLoadFailureHook(str str)
@ stdcall DeleteAtom(long)
@ stdcall -stub -version=0x600+ DeleteBoundaryDescriptor(ptr)
@ stdcall DeleteCriticalSection(ptr) ntdll.RtlDeleteCriticalSection
@ stdcall DeleteFiber(ptr)
@ stdcall DeleteFileA(str)
@ stdcall -stub -version=0x600+ DeleteFileTransactedA(str ptr)
@ stdcall -stub -version=0x600+ DeleteFileTransactedW(wstr ptr)
@ stdcall DeleteFileW(wstr)
@ stdcall -stub -version=0x600+ DeleteProcThreadAttributeList(ptr)
@ stdcall DeleteTimerQueue(long)
@ stdcall DeleteTimerQueueEx (long long)
@ stdcall DeleteTimerQueueTimer(long long long)
@ stdcall DeleteVolumeMountPointA(str) ;check
@ stdcall DeleteVolumeMountPointW(wstr) ;check
@ stdcall DeviceIoControl(long long ptr long ptr long ptr ptr)
@ stdcall DisableThreadLibraryCalls(long)
@ stdcall -version=0x600+ DisassociateCurrentThreadFromCallback(ptr) ntdll_vista.TpDisassociateCallback
@ stdcall DisconnectNamedPipe(long)
@ stdcall DnsHostnameToComputerNameA (str ptr ptr)
@ stdcall DnsHostnameToComputerNameW (wstr ptr ptr)
@ stdcall DosDateTimeToFileTime(long long ptr)
@ stdcall DosPathToSessionPathA(long str str)
@ stdcall DosPathToSessionPathW(long wstr wstr)
@ stdcall DuplicateConsoleHandle(long long long long)
@ stdcall DuplicateHandle(long long long ptr long long long)
@ stdcall EncodePointer(ptr) ntdll.RtlEncodePointer
@ stdcall EncodeSystemPointer(ptr) ntdll.RtlEncodeSystemPointer
@ stdcall EndUpdateResourceA(long long)
@ stdcall EndUpdateResourceW(long long)
@ stdcall EnterCriticalSection(ptr) ntdll.RtlEnterCriticalSection
@ stdcall EnumCalendarInfoA(ptr long long long)
@ stdcall EnumCalendarInfoExA(ptr long long long)
@ stdcall -version=0x600+ EnumCalendarInfoExEx(ptr wstr long wstr long long)
@ stdcall EnumCalendarInfoExW(ptr long long long)
@ stdcall EnumCalendarInfoW(ptr long long long)
@ stdcall EnumDateFormatsA(ptr long long)
@ stdcall EnumDateFormatsExA(ptr long long)
@ stdcall -version=0x600+ EnumDateFormatsExEx(ptr wstr long long)
@ stdcall EnumDateFormatsExW(ptr long long)
@ stdcall EnumDateFormatsW(ptr long long)
@ stdcall EnumLanguageGroupLocalesA(ptr long long ptr)
@ stdcall EnumLanguageGroupLocalesW(ptr long long ptr)
@ stdcall EnumResourceLanguagesA(long str str ptr long)
@ stdcall -stub -version=0x600+ EnumResourceLanguagesExA(ptr str str ptr ptr long long)
@ stdcall -stub -version=0x600+ EnumResourceLanguagesExW(ptr wstr wstr ptr ptr long long)
@ stdcall EnumResourceLanguagesW(long wstr wstr ptr long)
@ stdcall EnumResourceNamesA(long str ptr long)
@ stdcall -stub -version=0x600+ EnumResourceNamesExA(ptr str ptr ptr long long)
@ stdcall -stub -version=0x600+ EnumResourceNamesExW(ptr wstr ptr ptr long long)
@ stdcall EnumResourceNamesW(long wstr ptr long)
@ stdcall EnumResourceTypesA(long ptr long)
@ stdcall -stub -version=0x600+ EnumResourceTypesExA(ptr ptr ptr long long)
@ stdcall -stub -version=0x600+ EnumResourceTypesExW(ptr ptr ptr long long)
@ stdcall EnumResourceTypesW(long ptr long)
@ stdcall EnumSystemCodePagesA(ptr long)
@ stdcall EnumSystemCodePagesW(ptr long)
@ stdcall EnumSystemFirmwareTables(long ptr long)
@ stdcall EnumSystemGeoID(long long ptr)
@ stdcall EnumSystemLanguageGroupsA(ptr long ptr)
@ stdcall EnumSystemLanguageGroupsW(ptr long ptr)
@ stdcall EnumSystemLocalesA(ptr long)
@ stdcall -version=0x600+ EnumSystemLocalesEx(ptr long long ptr)
@ stdcall EnumSystemLocalesW(ptr long)
@ stdcall EnumTimeFormatsA(ptr long long)
@ stdcall -version=0x600+ EnumTimeFormatsEx(ptr wstr long long)
@ stdcall EnumTimeFormatsW(ptr long long)
@ stdcall EnumUILanguagesA(ptr long long)
@ stdcall EnumUILanguagesW(ptr long long)
@ stdcall EnumerateLocalComputerNamesA(ptr long str ptr)
@ stdcall EnumerateLocalComputerNamesW(ptr long wstr ptr)
@ stdcall EraseTape(ptr long long)
@ stdcall EscapeCommFunction(long long)
@ stdcall ExitProcess(long) ; FIXME: ntdll.RtlExitUserProcess
@ stdcall ExitThread(long) ; FIXME: ntdll.RtlExitUserThread
@ stdcall ExitVDM(long long)
@ stdcall ExpandEnvironmentStringsA(str ptr long)
@ stdcall ExpandEnvironmentStringsW(wstr ptr long)
@ stdcall ExpungeConsoleCommandHistoryA(long)
@ stdcall ExpungeConsoleCommandHistoryW(long)
@ stdcall FatalAppExitA(long str)
@ stdcall FatalAppExitW(long wstr)
@ stdcall FatalExit(long)
@ stdcall FileTimeToDosDateTime(ptr ptr ptr)
@ stdcall FileTimeToLocalFileTime(ptr ptr)
@ stdcall FileTimeToSystemTime(ptr ptr)
@ stdcall FillConsoleOutputAttribute(long long long long ptr)
@ stdcall FillConsoleOutputCharacterA(long long long long ptr)
@ stdcall FillConsoleOutputCharacterW(long long long long ptr)
@ stdcall FindActCtxSectionGuid(long ptr long ptr ptr)
@ stdcall FindActCtxSectionStringA(long ptr long str ptr)
@ stdcall FindActCtxSectionStringW(long ptr long wstr ptr)
@ stdcall FindAtomA(str)
@ stdcall FindAtomW(wstr)
@ stdcall FindClose(long)
@ stdcall FindCloseChangeNotification(long)
@ stdcall FindFirstChangeNotificationA(str long long)
@ stdcall FindFirstChangeNotificationW(wstr long long)
@ stdcall FindFirstFileA(str ptr)
@ stdcall FindFirstFileExA(str long ptr long ptr long)
@ stdcall FindFirstFileExW(wstr long ptr long ptr long)
@ stub -version=0x600+ FindFirstFileNameTransactedW
@ stdcall -stub -version=0x600+ FindFirstFileNameW(wstr long ptr wstr)
@ stub -version=0x600+ FindFirstFileTransactedA
@ stub -version=0x600+ FindFirstFileTransactedW
@ stdcall FindFirstFileW(wstr ptr)
@ stub -version=0x600+ FindFirstStreamTransactedW
@ stdcall FindFirstStreamW(wstr ptr ptr long)
@ stdcall FindFirstVolumeA(ptr long)
@ stdcall FindFirstVolumeMountPointA(str ptr long)
@ stdcall FindFirstVolumeMountPointW(wstr ptr long)
@ stdcall FindFirstVolumeW(ptr long)
@ stdcall -stub -version=0x600+ FindNLSString(long long wstr long wstr long ptr)
@ stdcall -stub -version=0x600+ FindNLSStringEx(wstr long wstr long wstr long ptr ptr ptr long)
@ stdcall FindNextChangeNotification(long)
@ stdcall FindNextFileA(long ptr)
@ stdcall -stub -version=0x600+ FindNextFileNameW(ptr ptr)
@ stdcall FindNextFileW(long ptr)
@ stdcall FindNextStreamW(ptr ptr)
@ stdcall FindNextVolumeA(long ptr long)
@ stdcall FindNextVolumeMountPointA(long str long)
@ stdcall FindNextVolumeMountPointW(long wstr long)
@ stdcall FindNextVolumeW(long ptr long)
@ stdcall FindResourceA(long str str)
@ stdcall FindResourceExA(long str str long)
@ stdcall FindResourceExW(long wstr wstr long)
@ stdcall FindResourceW(long wstr wstr)
@ stdcall FindVolumeClose(ptr)
@ stdcall FindVolumeMountPointClose(ptr)
@ stdcall FlsAlloc(ptr)
@ stdcall FlsFree(long)
@ stdcall FlsGetValue(long)
@ stdcall FlsSetValue(long ptr)
@ stdcall FlushConsoleInputBuffer(long)
@ stdcall FlushFileBuffers(long)
@ stdcall FlushInstructionCache(long long long)
@ stdcall -stub -version=0x600+ FlushProcessWriteBuffers()
@ stdcall FlushViewOfFile(ptr long)
@ stdcall FoldStringA(long str long ptr long)
@ stdcall FoldStringW(long wstr long ptr long)
@ stdcall FormatMessageA(long ptr long long ptr long ptr)
@ stdcall FormatMessageW(long ptr long long ptr long ptr)
@ stdcall FreeConsole()
@ stdcall FreeEnvironmentStringsA(ptr)
@ stdcall FreeEnvironmentStringsW(ptr)
@ stdcall FreeLibrary(long)
@ stdcall FreeLibraryAndExitThread(long long)
@ stdcall -stub -version=0x600+ FreeLibraryWhenCallbackReturns(ptr ptr)
@ stdcall FreeResource(long)
@ stdcall FreeUserPhysicalPages(long long long)
@ stdcall GenerateConsoleCtrlEvent(long long)
@ stdcall GetACP()
@ stdcall -version=0x600+ GetActiveProcessorCount(long)
@ stdcall -version=0x600+ GetApplicationRecoveryCallback(ptr ptr ptr ptr ptr) kernel32_vista.GetApplicationRecoveryCallback
@ stdcall -stub -version=0x600+ GetApplicationRestartSettings(ptr wstr ptr ptr)
@ stdcall GetAtomNameA(long ptr long)
@ stdcall GetAtomNameW(long ptr long)
@ stdcall GetBinaryType(str ptr) GetBinaryTypeA
@ stdcall GetBinaryTypeA(str ptr)
@ stdcall GetBinaryTypeW(wstr ptr)
@ stdcall -version=0x501-0x600 GetCPFileNameFromRegistry(long wstr long)
@ stdcall GetCPInfo(long ptr)
@ stdcall GetCPInfoExA(long long ptr)
@ stdcall GetCPInfoExW(long long ptr)
@ stub -version=0x600+ GetCalendarDateFormat
@ stub -version=0x600+ GetCalendarDateFormatEx
@ stub -version=0x600+ GetCalendarDaysInMonth
@ stub -version=0x600+ GetCalendarDifferenceInDays
@ stdcall GetCalendarInfoA(long long long ptr long ptr)
@ stdcall -version=0x600+ GetCalendarInfoEx(wstr long wstr long wstr long ptr)
@ stdcall GetCalendarInfoW(long long long ptr long ptr)
@ stub -version=0x600+ GetCalendarMonthsInYear
@ stub -version=0x600+ GetCalendarSupportedDateRange
@ stub -version=0x600+ GetCalendarWeekNumber
@ stdcall GetComPlusPackageInstallStatus()
@ stdcall GetCommConfig(long ptr long)
@ stdcall GetCommMask(long ptr)
@ stdcall GetCommModemStatus(long ptr)
@ stdcall GetCommProperties(long ptr)
@ stdcall GetCommState(long ptr)
@ stdcall GetCommTimeouts(long ptr)
@ stdcall GetCommandLineA()
@ stdcall GetCommandLineW()
@ stdcall GetCompressedFileSizeA(long ptr)
@ stub -version=0x600+ GetCompressedFileSizeTransactedA
@ stub -version=0x600+ GetCompressedFileSizeTransactedW
@ stdcall GetCompressedFileSizeW(long ptr)
@ stdcall GetComputerNameA(ptr ptr)
@ stdcall GetComputerNameExA(long ptr ptr)
@ stdcall GetComputerNameExW(long ptr ptr)
@ stdcall GetComputerNameW(ptr ptr)
@ stdcall GetConsoleAliasA(str str long str)
@ stdcall GetConsoleAliasExesA(str long)
@ stdcall GetConsoleAliasExesLengthA()
@ stdcall GetConsoleAliasExesLengthW()
@ stdcall GetConsoleAliasExesW(wstr long)
@ stdcall GetConsoleAliasW(wstr ptr long wstr)
@ stdcall GetConsoleAliasesA(str long str)
@ stdcall GetConsoleAliasesLengthA(str)
@ stdcall GetConsoleAliasesLengthW(wstr)
@ stdcall GetConsoleAliasesW(wstr long wstr)
@ stdcall GetConsoleCP()
@ stdcall GetConsoleCharType(long long ptr)
@ stdcall GetConsoleCommandHistoryA(long long long)
@ stdcall GetConsoleCommandHistoryLengthA(long)
@ stdcall GetConsoleCommandHistoryLengthW(long)
@ stdcall GetConsoleCommandHistoryW(long long long)
@ stdcall GetConsoleCursorInfo(long ptr)
@ stdcall GetConsoleCursorMode(long ptr ptr)
@ stdcall GetConsoleDisplayMode(ptr)
@ stdcall GetConsoleFontInfo(long long long ptr)
@ stdcall GetConsoleFontSize(long long)
@ stdcall GetConsoleHardwareState(long long ptr)
@ stdcall -version=0x600+ GetConsoleHistoryInfo(ptr)
@ stdcall GetConsoleInputExeNameA(long ptr)
@ stdcall GetConsoleInputExeNameW(long ptr)
@ stdcall GetConsoleInputWaitHandle()
@ stdcall GetConsoleKeyboardLayoutNameA(ptr)
@ stdcall GetConsoleKeyboardLayoutNameW(ptr)
@ stdcall GetConsoleMode(long ptr)
@ stdcall GetConsoleNlsMode(long ptr)
@ stdcall -version=0x600+ GetConsoleOriginalTitleA(str long)
@ stdcall -version=0x600+ GetConsoleOriginalTitleW(wstr long)
@ stdcall GetConsoleOutputCP()
@ stdcall GetConsoleProcessList(ptr long) ; missing in XP SP3
@ stdcall GetConsoleScreenBufferInfo(long ptr)
@ stdcall -version=0x600+ GetConsoleScreenBufferInfoEx(ptr ptr)
@ stdcall GetConsoleSelectionInfo(ptr)
@ stdcall GetConsoleTitleA(ptr long)
@ stdcall GetConsoleTitleW(ptr long)
@ stdcall GetConsoleWindow()
@ stdcall GetCurrencyFormatA(long long str ptr str long)
@ stdcall -version=0x600+ GetCurrencyFormatEx(wstr long wstr ptr wstr long)
@ stdcall GetCurrencyFormatW(long long str ptr str long)
@ stdcall GetCurrentActCtx(ptr)
@ stdcall GetCurrentConsoleFont(long long ptr)
@ stdcall -version=0x600+ GetCurrentConsoleFontEx(ptr long ptr)
@ stdcall GetCurrentDirectoryA(long ptr)
@ stdcall GetCurrentDirectoryW(long ptr)
@ stdcall -version=0x602+ GetCurrentPackageId(ptr ptr)
@ stdcall -norelay GetCurrentProcess()
@ stdcall -norelay GetCurrentProcessId()
@ stdcall GetCurrentProcessorNumber() ntdll.RtlGetCurrentProcessorNumber
@ stdcall -version=0x601+ GetCurrentProcessorNumberEx(ptr) ntdll.RtlGetCurrentProcessorNumberEx
@ stdcall -norelay GetCurrentThread()
@ stdcall -norelay GetCurrentThreadId()
@ stdcall GetDateFormatA(long long ptr str ptr long)
@ stdcall -version=0x600+ GetDateFormatEx(wstr long ptr wstr wstr long wstr)
@ stdcall GetDateFormatW(long long ptr wstr ptr long)
@ stdcall GetDefaultCommConfigA(str ptr long)
@ stdcall GetDefaultCommConfigW(wstr ptr long)
@ stdcall -version=0x501-0x502 GetDefaultSortkeySize(ptr)
@ stdcall GetDevicePowerState(long ptr)
@ stdcall GetDiskFreeSpaceA(str ptr ptr ptr ptr)
@ stdcall GetDiskFreeSpaceExA (str ptr ptr ptr)
@ stdcall GetDiskFreeSpaceExW (wstr ptr ptr ptr)
@ stdcall GetDiskFreeSpaceW(wstr ptr ptr ptr ptr)
@ stdcall GetDllDirectoryA(long ptr)
@ stdcall GetDllDirectoryW(long ptr)
@ stdcall GetDriveTypeA(str)
@ stdcall GetDriveTypeW(wstr)
@ stdcall -stub -version=0x600+ GetDurationFormat(long long ptr long long wstr wstr long)
@ stdcall -stub -version=0x600+ GetDurationFormatEx(wstr long ptr long long wstr wstr long)
@ stdcall -stub -version=0x600+ GetDynamicTimeZoneInformation(ptr)
@ stdcall GetEnvironmentStrings()
@ stdcall GetEnvironmentStringsA() GetEnvironmentStrings
@ stdcall GetEnvironmentStringsW()
@ stdcall GetEnvironmentVariableA(str ptr long)
@ stdcall GetEnvironmentVariableW(wstr ptr long)
@ stdcall -version=0x600+ GetErrorMode()
@ stdcall GetExitCodeProcess(long ptr)
@ stdcall GetExitCodeThread(long ptr)
@ stdcall GetExpandedNameA(str ptr)
@ stdcall GetExpandedNameW(wstr ptr)
@ stdcall GetFileAttributesA(str)
@ stdcall GetFileAttributesExA(str long ptr)
@ stdcall GetFileAttributesExW(wstr long ptr)
@ stub -version=0x600+ GetFileAttributesTransactedA
@ stub -version=0x600+ GetFileAttributesTransactedW
@ stdcall GetFileAttributesW(wstr)
@ stdcall -stub -version=0x600+ GetFileBandwidthReservation(ptr ptr ptr ptr ptr ptr ptr)
@ stdcall GetFileInformationByHandle(long ptr)
@ stdcall -version=0x600+ GetFileMUIInfo(long wstr ptr ptr) kernel32_vista.GetFileMUIInfo
@ stdcall -version=0x600+ GetFileInformationByHandleEx(long long ptr long)
@ stdcall -version=0x600+ GetFileMUIPath(long wstr wstr ptr wstr ptr ptr) kernel32_vista.GetFileMUIPath
@ stdcall GetFileSize(long ptr)
@ stdcall GetFileSizeEx(long ptr)
@ stdcall GetFileTime(long ptr ptr ptr)
@ stdcall GetFileType(long)
@ stdcall -version=0x600+ GetFinalPathNameByHandleA(ptr str long long) kernel32_vista.GetFinalPathNameByHandleA
@ stdcall -version=0x600+ GetFinalPathNameByHandleW(ptr wstr long long) kernel32_vista.GetFinalPathNameByHandleW
@ stdcall GetFirmwareEnvironmentVariableA(str str ptr long)
@ stdcall GetFirmwareEnvironmentVariableW(wstr wstr ptr long)
@ stdcall GetFullPathNameA(str long ptr ptr)
@ stub -version=0x600+ GetFullPathNameTransactedA
@ stub -version=0x600+ GetFullPathNameTransactedW
@ stdcall GetFullPathNameW(wstr long ptr ptr)
@ stdcall GetGeoInfoA(long long ptr long long)
@ stdcall GetGeoInfoW(long long ptr long long)
@ stdcall -i386 GetHandleContext(long) ; missing on x64
@ stdcall GetHandleInformation(long ptr)
@ stdcall GetLargePageMinimum()
@ stdcall GetLargestConsoleWindowSize(long)
@ stdcall GetLastError() ntdll.RtlGetLastWin32Error
@ stdcall -version=0x500-0x502 GetLinguistLangSize(ptr)
@ stdcall GetLocalTime(ptr)
@ stdcall GetLocaleInfoA(long long ptr long)
@ stdcall -version=0x600+ GetLocaleInfoEx(wstr long ptr long)
@ stdcall GetLocaleInfoW(long long ptr long)
@ stdcall -version=0x600+ IsValidLocaleName(wstr)
@ stdcall GetLogicalDriveStringsA(long ptr)
@ stdcall GetLogicalDriveStringsW(long ptr)
@ stdcall GetLogicalDrives()
@ stdcall GetLogicalProcessorInformation(ptr ptr)
@ stdcall GetLongPathNameA (str long long)
@ stub -version=0x600+ GetLongPathNameTransactedA
@ stub -version=0x600+ GetLongPathNameTransactedW
@ stdcall GetLongPathNameW (wstr long long)
@ stdcall GetMailslotInfo(long ptr ptr ptr ptr)
@ stdcall GetModuleFileNameA(long ptr long)
@ stdcall GetModuleFileNameW(long ptr long)
@ stdcall GetModuleHandleA(str)
@ stdcall GetModuleHandleExA(long ptr ptr)
@ stdcall GetModuleHandleExW(long ptr ptr)
@ stdcall GetModuleHandleW(wstr)
@ stdcall GetNLSVersion(long long ptr)
@ stdcall GetNLSVersionEx(long wstr ptr)
@ stub -version=0x600+ GetNamedPipeAttribute
@ stdcall -stub -version=0x600+ GetNamedPipeClientComputerNameA(ptr str long)
@ stdcall -stub -version=0x600+ GetNamedPipeClientComputerNameW(ptr wstr long)
@ stdcall -stub -version=0x600+ GetNamedPipeClientProcessId(ptr ptr)
@ stdcall -stub -version=0x600+ GetNamedPipeClientSessionId(ptr ptr)
@ stdcall GetNamedPipeHandleStateA(long ptr ptr ptr ptr str long)
@ stdcall GetNamedPipeHandleStateW(long ptr ptr ptr ptr wstr long)
@ stdcall GetNamedPipeInfo(long ptr ptr ptr ptr)
@ stdcall -stub -version=0x600+ GetNamedPipeServerProcessId(ptr ptr)
@ stdcall -stub -version=0x600+ GetNamedPipeServerSessionId(ptr ptr)
@ stdcall GetNativeSystemInfo(ptr)
@ stdcall GetNextVDMCommand(long)
@ stdcall -version=0x500-0x502 GetNlsSectionName(long long long str str long)
@ stdcall GetNumaAvailableMemoryNode(long ptr)
@ stdcall GetNumaHighestNodeNumber(ptr)
@ stdcall GetNumaNodeProcessorMask(long ptr)
@ stdcall GetNumaProcessorNode(long ptr)
@ stdcall -stub -version=0x600+ GetNumaProximityNode(long ptr)
@ stdcall GetNumberFormatA(long long str ptr ptr long)
@ stdcall -version=0x600+ GetNumberFormatEx(wstr long wstr ptr wstr long)
@ stdcall GetNumberFormatW(long long wstr ptr ptr long)
@ stdcall GetNumberOfConsoleFonts()
@ stdcall GetNumberOfConsoleInputEvents(long ptr)
@ stdcall GetNumberOfConsoleMouseButtons(ptr)
@ stdcall GetOEMCP()
@ stdcall GetOverlappedResult(long ptr ptr long)
@ stdcall -version=0x600+ GetPhysicallyInstalledSystemMemory(ptr)
@ stdcall GetPriorityClass(long)
@ stdcall GetPrivateProfileIntA(str str long str)
@ stdcall GetPrivateProfileIntW(wstr wstr long wstr)
@ stdcall GetPrivateProfileSectionA(str ptr long str)
@ stdcall GetPrivateProfileSectionNamesA(ptr long str)
@ stdcall GetPrivateProfileSectionNamesW(ptr long wstr)
@ stdcall GetPrivateProfileSectionW(wstr ptr long wstr)
@ stdcall GetPrivateProfileStringA(str str str ptr long str)
@ stdcall GetPrivateProfileStringW(wstr wstr wstr ptr long wstr)
@ stdcall GetPrivateProfileStructA (str str ptr long str)
@ stdcall GetPrivateProfileStructW(wstr wstr ptr long wstr)
@ stdcall GetProcAddress(long str)
@ stdcall GetProcessAffinityMask(long ptr ptr)
@ stdcall -stub -version=0x600+ GetProcessDEPPolicy(ptr ptr ptr)
@ stdcall GetProcessHandleCount(long ptr)
@ stdcall -norelay GetProcessHeap()
@ stdcall GetProcessHeaps(long ptr)
@ stdcall GetProcessId(long)
@ stdcall GetProcessIdOfThread(ptr)
@ stdcall GetProcessIoCounters(long ptr)
@ stdcall GetProcessPriorityBoost(long ptr)
@ stdcall GetProcessShutdownParameters(ptr ptr)
@ stdcall GetProcessTimes(long ptr ptr ptr ptr)
@ stdcall GetProcessVersion(long)
@ stdcall GetProcessWorkingSetSize(long ptr ptr)
@ stdcall GetProcessWorkingSetSizeEx(long ptr ptr long)
@ stdcall -version=0x600+ GetProductInfo() ntdll.RtlGetProductInfo
@ stdcall GetProfileIntA(str str long)
@ stdcall GetProfileIntW(wstr wstr long)
@ stdcall GetProfileSectionA(str ptr long)
@ stdcall GetProfileSectionW(wstr ptr long)
@ stdcall GetProfileStringA(str str str ptr long)
@ stdcall GetProfileStringW(wstr wstr wstr ptr long)
@ stdcall GetQueuedCompletionStatus(long ptr ptr ptr long)
@ stdcall -version=0x600+ GetQueuedCompletionStatusEx(ptr ptr long ptr long long) kernel32_vista.GetQueuedCompletionStatusEx
@ stdcall GetShortPathNameA(str ptr long)
@ stdcall GetShortPathNameW(wstr ptr long)
@ stdcall GetStartupInfoA(ptr)
@ stdcall GetStartupInfoW(ptr)
@ stdcall GetStdHandle(long)
@ stdcall -stub -version=0x600+ GetStringScripts(long wstr long wstr long)
@ stdcall GetStringTypeA(long long str long ptr)
@ stdcall GetStringTypeExA(long long str long ptr)
@ stdcall GetStringTypeExW(long long wstr long ptr)
@ stdcall GetStringTypeW(long wstr long ptr)
@ stdcall -version=0x600+ GetSystemDEPPolicy()
@ stdcall GetSystemDefaultLCID()
@ stdcall GetSystemDefaultLangID()
@ stdcall -version=0x600+ GetSystemDefaultLocaleName(wstr long)
@ stdcall GetSystemDefaultUILanguage()
@ stdcall GetSystemDirectoryA(ptr long)
@ stdcall GetSystemDirectoryW(ptr long)
@ stdcall GetSystemFileCacheSize(ptr ptr ptr)
@ stdcall GetSystemFirmwareTable(long long ptr long)
@ stdcall GetSystemInfo(ptr)
@ stdcall GetSystemPowerStatus(ptr)
@ stdcall -version=0x600+ GetSystemPreferredUILanguages(long ptr ptr ptr)
@ stdcall GetSystemRegistryQuota(ptr ptr)
@ stdcall GetSystemTime(ptr)
@ stdcall GetSystemTimeAdjustment(ptr ptr ptr)
@ stdcall GetSystemTimeAsFileTime(ptr)
@ stdcall -version=0x602+ GetSystemTimePreciseAsFileTime(ptr)
@ stdcall GetSystemTimes(ptr ptr ptr)
@ stdcall GetSystemWindowsDirectoryA(ptr long)
@ stdcall GetSystemWindowsDirectoryW(ptr long)
@ stdcall GetSystemWow64DirectoryA(ptr long)
@ stdcall GetSystemWow64DirectoryW(ptr long)
@ stdcall GetTapeParameters(ptr long ptr ptr)
@ stdcall GetTapePosition(ptr long ptr ptr ptr)
@ stdcall GetTapeStatus(ptr)
@ stdcall GetTempFileNameA(str str long ptr)
@ stdcall GetTempFileNameW(wstr wstr long ptr)
@ stdcall GetTempPathA(long ptr)
@ stdcall GetTempPathW(long ptr)
@ stdcall GetThreadContext(long ptr)
@ stub -version=0x600+ GetThreadErrorMode
@ stdcall GetThreadIOPendingFlag(long ptr)
@ stdcall GetThreadId(ptr)
@ stdcall GetThreadLocale()
@ stdcall -version=0x600+ GetThreadPreferredUILanguages(long ptr ptr ptr)
@ stdcall GetThreadPriority(long)
@ stdcall GetThreadPriorityBoost(long ptr)
@ stdcall GetThreadSelectorEntry(long long ptr)
@ stdcall GetThreadTimes(long ptr ptr ptr ptr)
@ stdcall -version=0x600+ GetThreadUILanguage() kernel32_vista.GetThreadUILanguage
@ stdcall GetTickCount()
@ stdcall -version=0x600+ GetTickCount64() kernel32_vista.GetTickCount64
@ stdcall GetTimeFormatA(long long ptr str ptr long)
@ stdcall -version=0x600+ GetTimeFormatEx(wstr long ptr wstr wstr long)
@ stdcall GetTimeFormatW(long long ptr wstr ptr long)
@ stdcall GetTimeZoneInformation(ptr)
@ stdcall -stub -version=0x600+ GetTimeZoneInformationForYear(long ptr ptr)
@ stdcall -version=0x600+ GetUILanguageInfo(long ptr ptr ptr ptr) kernel32_vista.GetUILanguageInfo
@ stdcall GetUserDefaultLCID()
@ stdcall GetUserDefaultLangID()
@ stdcall -version=0x600+ GetUserDefaultLocaleName(wstr long)
@ stdcall GetUserDefaultUILanguage()
@ stdcall GetUserGeoID(long)
@ stdcall -version=0x600+ GetUserPreferredUILanguages(long ptr ptr ptr)
@ stdcall GetVDMCurrentDirectories(long long)
@ stdcall GetVersion()
@ stdcall GetVersionExA(ptr)
@ stdcall GetVersionExW(ptr)
@ stdcall GetVolumeInformationA(str ptr long ptr ptr ptr ptr long)
@ stdcall -stub -version=0x600+ GetVolumeInformationByHandleW(ptr wstr long ptr ptr ptr wstr long)
@ stdcall GetVolumeInformationW(wstr ptr long ptr ptr ptr ptr long)
@ stdcall GetVolumeNameForVolumeMountPointA(str ptr long)
@ stdcall GetVolumeNameForVolumeMountPointW(wstr ptr long)
@ stdcall GetVolumePathNameA(str ptr long)
@ stdcall GetVolumePathNameW(wstr ptr long)
@ stdcall GetVolumePathNamesForVolumeNameA(str str long ptr)
@ stdcall GetVolumePathNamesForVolumeNameW(wstr wstr long ptr)
@ stdcall GetWindowsDirectoryA(ptr long)
@ stdcall GetWindowsDirectoryW(ptr long)
@ stdcall GetWriteWatch(long ptr long ptr ptr ptr)
@ stdcall GlobalAddAtomA(str)
@ stdcall GlobalAddAtomW(wstr)
@ stdcall GlobalAlloc(long long)
@ stdcall GlobalCompact(long)
@ stdcall GlobalDeleteAtom(long)
@ stdcall GlobalFindAtomA(str)
@ stdcall GlobalFindAtomW(wstr)
@ stdcall GlobalFix(long)
@ stdcall GlobalFlags(long)
@ stdcall GlobalFree(long)
@ stdcall GlobalGetAtomNameA(long ptr long)
@ stdcall GlobalGetAtomNameW(long ptr long)
@ stdcall GlobalHandle(ptr)
@ stdcall GlobalLock(long)
@ stdcall GlobalMemoryStatus(ptr)
@ stdcall GlobalMemoryStatusEx(ptr)
@ stdcall GlobalReAlloc(long long long)
@ stdcall GlobalSize(long)
@ stdcall GlobalUnWire(long)
@ stdcall GlobalUnfix(long)
@ stdcall GlobalUnlock(long)
@ stdcall GlobalWire(long)
@ stdcall Heap32First(ptr long long)
@ stdcall Heap32ListFirst(long ptr)
@ stdcall Heap32ListNext(long ptr)
@ stdcall Heap32Next(ptr)
@ stdcall HeapAlloc(long long long) ntdll.RtlAllocateHeap
@ stdcall HeapCompact(long long)
@ stdcall HeapCreate(long long long)
@ stdcall -version=0x351-0x502 HeapCreateTagsW(long long wstr wstr)
@ stdcall HeapDestroy(long)
@ stdcall -version=0x351-0x502 HeapExtend(long long ptr long)
@ stdcall HeapFree(long long long) ntdll.RtlFreeHeap
@ stdcall HeapLock(long)
@ stdcall HeapQueryInformation(long long ptr long ptr)
@ stdcall -version=0x351-0x502 HeapQueryTagW(long long long long ptr)
@ stdcall HeapReAlloc(long long ptr long) ntdll.RtlReAllocateHeap
@ stdcall HeapSetInformation(ptr long ptr long)
@ stdcall HeapSize(long long ptr) ntdll.RtlSizeHeap
@ stdcall HeapSummary(long long ptr)
@ stdcall HeapUnlock(long)
@ stdcall -version=0x351-0x502 HeapUsage(long long long long ptr)
@ stdcall HeapValidate(long long ptr)
@ stdcall HeapWalk(long ptr)
@ stdcall -stub -version=0x600+ IdnToAscii(long wstr long wstr long)
@ stdcall -stub -version=0x600+ IdnToNameprepUnicode(long wstr long wstr long)
@ stdcall -stub -version=0x600+ IdnToUnicode(long wstr long wstr long)
@ stdcall InitAtomTable(long)
@ stdcall -version=0x600+ InitOnceBeginInitialize(ptr long ptr ptr) kernel32_vista.InitOnceBeginInitialize
@ stdcall -version=0x600+ InitOnceComplete(ptr long ptr) kernel32_vista.InitOnceComplete
@ stdcall -version=0x600+ InitOnceExecuteOnce(ptr ptr ptr ptr) kernel32_vista.InitOnceExecuteOnce
@ stdcall -stub -version=0x600+ InitOnceInitialize(ptr)
@ stdcall -version=0x600+ InitializeConditionVariable(ptr)  kernel32_vista.InitializeConditionVariable
@ stdcall InitializeCriticalSection(ptr)
@ stdcall InitializeCriticalSectionAndSpinCount(ptr long)
@ stdcall -version=0x600+ InitializeCriticalSectionEx(ptr long long) kernel32_vista.InitializeCriticalSectionEx
@ stdcall -stub -version=0x600+ InitializeProcThreadAttributeList(ptr long long ptr)
@ stdcall InitializeSListHead(ptr) ntdll.RtlInitializeSListHead
@ stdcall -version=0x600+ InitializeSRWLock(ptr) ntdll_vista.RtlInitializeSRWLock
@ stdcall -arch=i386 -ret64 InterlockedCompareExchange64(ptr double double) ntdll.RtlInterlockedCompareExchange64
@ stdcall -arch=i386 InterlockedCompareExchange (ptr long long)
@ stdcall -arch=i386 InterlockedDecrement(ptr)
@ stdcall -arch=i386 InterlockedExchange(ptr long)
@ stdcall -arch=i386 InterlockedExchangeAdd(ptr long)
@ stdcall InterlockedFlushSList(ptr) ntdll.RtlInterlockedFlushSList
@ stdcall -arch=i386 InterlockedIncrement(ptr)
@ stdcall InterlockedPopEntrySList(ptr) ntdll.RtlInterlockedPopEntrySList
@ stdcall InterlockedPushEntrySList(ptr ptr) ntdll.RtlInterlockedPushEntrySList
@ stdcall -stub -version=0x600+ InterlockedPushListSList(ptr ptr ptr long)
@ stdcall InvalidateConsoleDIBits(long long)
@ stdcall IsBadCodePtr(ptr)
@ stdcall IsBadHugeReadPtr(ptr long)
@ stdcall IsBadHugeWritePtr(ptr long)
@ stdcall IsBadReadPtr(ptr long)
@ stdcall IsBadStringPtrA(ptr long)
@ stdcall IsBadStringPtrW(ptr long)
@ stdcall IsBadWritePtr(ptr long)
@ stub -version=0x600+ IsCalendarLeapDay
@ stub -version=0x600+ IsCalendarLeapMonth
@ stub -version=0x600+ IsCalendarLeapYear
@ stdcall IsDBCSLeadByte(long)
@ stdcall IsDBCSLeadByteEx(long long)
@ stdcall IsDebuggerPresent()
@ stdcall IsNLSDefinedString(long long ptr long long)
@ stdcall -stub -version=0x600+ IsNormalizedString(long wstr long)
@ stdcall IsProcessInJob(long long ptr)
@ stdcall IsProcessorFeaturePresent(long)
@ stdcall IsSystemResumeAutomatic()
@ stdcall -version=0x600+ IsThreadAFiber()
@ stdcall -version=0x600+ IsThreadpoolTimerSet(ptr) ntdll_vista.TpIsTimerSet
@ stdcall IsTimeZoneRedirectionEnabled()
@ stub -version=0x600+ IsValidCalDateTime
@ stdcall IsValidCodePage(long)
@ stdcall IsValidLanguageGroup(long long)
@ stdcall IsValidLocale(long long)
@ stdcall -version=0x501-0x502 IsValidUILanguage(long)
@ stdcall IsWow64Process(ptr ptr)
@ stdcall -version=0x600+ LCIDToLocaleName(long wstr long long)
@ stdcall LCMapStringA(long long str long ptr long)
@ stdcall -version=0x600+ LCMapStringEx(long long wstr long ptr long ptr ptr long)
@ stdcall LCMapStringW(long long wstr long ptr long)
@ stdcall LZClose(long)
@ stdcall LZCloseFile(long)
@ stdcall LZCopy(long long)
@ stdcall LZCreateFileW(ptr long long long ptr)
@ stdcall LZDone()
@ stdcall LZInit(long)
@ stdcall LZOpenFileA(str ptr long)
@ stdcall LZOpenFileW(wstr ptr long)
@ stdcall LZRead(long str long)
@ stdcall LZSeek(long long long)
@ stdcall LZStart()
@ stdcall LeaveCriticalSection(ptr) ntdll.RtlLeaveCriticalSection
@ stdcall -stub -version=0x600+ LeaveCriticalSectionWhenCallbackReturns(ptr ptr)
@ stdcall -stub -version=0x601+ LoadAppInitDlls()
@ stdcall LoadLibraryA(str)
@ stdcall LoadLibraryExA( str long long)
@ stdcall LoadLibraryExW(wstr long long)
@ stdcall LoadLibraryW(wstr)
@ stdcall LoadModule(str ptr)
@ stdcall LoadResource(long long)
@ stdcall -stub -version=0x600+ LoadStringBaseExW()
@ stdcall -stub -version=0x600+ LoadStringBaseW()
@ stdcall LocalAlloc(long long)
@ stdcall LocalCompact(long)
@ stdcall LocalFileTimeToFileTime(ptr ptr)
@ stdcall LocalFlags(long)
@ stdcall LocalFree(long)
@ stdcall LocalHandle(ptr)
@ stdcall LocalLock(long)
@ stdcall LocalReAlloc(long long long)
@ stdcall LocalShrink(long long)
@ stdcall LocalSize(long)
@ stdcall LocalUnlock(long)
@ stdcall -version=0x600+ LocaleNameToLCID(wstr long)
@ stdcall LockFile(long long long long long)
@ stdcall LockFileEx(long long long long long ptr)
@ stdcall LockResource(long)
@ stdcall MapUserPhysicalPages(ptr long ptr)
@ stdcall MapUserPhysicalPagesScatter(ptr long ptr)
@ stdcall MapViewOfFile(long long long long long)
@ stdcall MapViewOfFileEx(long long long long long ptr)
@ stdcall -stub -version=0x600+ MapViewOfFileExNuma(ptr long long long long ptr long)
@ stdcall Module32First(long ptr)
@ stdcall Module32FirstW(long ptr)
@ stdcall Module32Next(long ptr)
@ stdcall Module32NextW(long ptr)
@ stdcall MoveFileA(str str)
@ stdcall MoveFileExA(str str long)
@ stdcall MoveFileExW(wstr wstr long)
@ stdcall -stub -version=0x600+ MoveFileTransactedA(str str ptr ptr long ptr)
@ stdcall -stub -version=0x600+ MoveFileTransactedW(wstr wstr ptr ptr long ptr)
@ stdcall MoveFileW(wstr wstr)
@ stdcall MoveFileWithProgressA(str str ptr ptr long)
@ stdcall MoveFileWithProgressW(wstr wstr ptr ptr long)
@ stdcall MulDiv(long long long)
@ stdcall MultiByteToWideChar(long long str long ptr long)
@ stdcall NeedCurrentDirectoryForExePathA(str)
@ stdcall NeedCurrentDirectoryForExePathW(wstr)
@ stub -version=0x600+ NlsCheckPolicy
@ stdcall -version=0x500-0x600 NlsConvertIntegerToString(long long long wstr long)
@ stub -version=0x600+ NlsEventDataDescCreate
@ stdcall NlsGetCacheUpdateCount()
@ stdcall -version=0x500-0x502 NlsResetProcessLocale()
@ stub -version=0x600+ NlsUpdateLocale
@ stub -version=0x600+ NlsUpdateSystemLocale
@ stub -version=0x600+ NlsWriteEtwEvent
@ stdcall -stub -version=0x600+ NormalizeString(long wstr long wstr long)
@ stdcall -stub -version=0x600+ NotifyUILanguageChange(long wstr wstr long ptr)
@ stdcall OpenConsoleW(wstr long long long)
@ stdcall -version=0x500-0x502 OpenDataFile(long long)
@ stdcall OpenEventA(long long str)
@ stdcall OpenEventW(long long wstr)
@ stdcall OpenFile(str ptr long)
@ stdcall -version=0x600+ OpenFileById(ptr ptr long long ptr long) kernel32_vista.OpenFileById
@ stdcall OpenFileMappingA(long long str)
@ stdcall OpenFileMappingW(long long wstr)
@ stdcall OpenJobObjectA(long long str)
@ stdcall OpenJobObjectW(long long wstr)
@ stdcall OpenMutexA(long long str)
@ stdcall OpenMutexW(long long wstr)
@ stdcall -stub -version=0x600+ OpenPrivateNamespaceA(ptr str)
@ stdcall -stub -version=0x600+ OpenPrivateNamespaceW(ptr wstr)
@ stdcall OpenProcess(long long long)
@ stdcall OpenProfileUserMapping()
@ stdcall OpenSemaphoreA(long long str)
@ stdcall OpenSemaphoreW(long long wstr)
@ stdcall OpenThread(long long long)
@ stdcall OpenWaitableTimerA(long long str)
@ stdcall OpenWaitableTimerW(long long wstr)
@ stdcall OutputDebugStringA(str)
@ stdcall OutputDebugStringW(wstr)
@ stdcall PeekConsoleInputA(ptr ptr long ptr)
@ stdcall PeekConsoleInputW(ptr ptr long ptr)
@ stdcall PeekNamedPipe(long ptr long ptr ptr ptr)
@ stdcall PostQueuedCompletionStatus(long long ptr ptr)
@ stdcall PrepareTape(ptr long long)
@ stdcall PrivCopyFileExW(wstr wstr ptr ptr long long)
@ stdcall PrivMoveFileIdentityW(long long long)
@ stdcall Process32First (ptr ptr)
@ stdcall Process32FirstW (ptr ptr)
@ stdcall Process32Next (ptr ptr)
@ stdcall Process32NextW (ptr ptr)
@ stdcall ProcessIdToSessionId(long ptr)
@ stdcall PulseEvent(long)
@ stdcall PurgeComm(long long)
@ stub -version=0x600+ QueryActCtxSettingsW
@ stdcall QueryActCtxW(long ptr ptr long ptr long ptr)
@ stdcall QueryDepthSList(ptr) ntdll.RtlQueryDepthSList
@ stdcall QueryDosDeviceA(str ptr long)
@ stdcall QueryDosDeviceW(wstr ptr long)
@ stdcall -version=0x600+ QueryFullProcessImageNameA(ptr long wstr ptr) kernel32_vista.QueryFullProcessImageNameA
@ stdcall -version=0x600+ QueryFullProcessImageNameW(ptr long str ptr) kernel32_vista.QueryFullProcessImageNameW
@ stdcall -stub -version=0x600+ QueryIdleProcessorCycleTime(ptr ptr)
@ stdcall QueryInformationJobObject(long long ptr long ptr)
@ stdcall QueryMemoryResourceNotification(ptr ptr)
@ stdcall QueryPerformanceCounter(ptr)
@ stdcall QueryPerformanceFrequency(ptr)
@ stdcall -stub -version=0x600+ QueryProcessAffinityUpdateMode(ptr ptr)
@ stdcall -version=0x600+ QueryProcessCycleTime(long ptr)
@ stdcall -version=0x600+ QueryThreadCycleTime(long ptr)
@ stdcall -version=0x600+ QueryUnbiasedInterruptTime(ptr)
@ stdcall QueueUserAPC(ptr long long)
@ stdcall QueueUserWorkItem(ptr ptr long)
@ stdcall -norelay RaiseException(long long long ptr)
@ stdcall -stub RaiseFailFastException(ptr ptr long)
@ stdcall ReOpenFile(ptr long long long)
@ stdcall ReadConsoleA(long ptr long ptr ptr)
@ stdcall ReadConsoleInputA(long ptr long ptr)
@ stdcall ReadConsoleInputExA(long ptr long ptr long)
@ stdcall ReadConsoleInputExW(long ptr long ptr long)
@ stdcall ReadConsoleInputW(long ptr long ptr)
@ stdcall ReadConsoleOutputA(long ptr long long ptr)
@ stdcall ReadConsoleOutputAttribute(long ptr long long ptr)
@ stdcall ReadConsoleOutputCharacterA(long ptr long long ptr)
@ stdcall ReadConsoleOutputCharacterW(long ptr long long ptr)
@ stdcall ReadConsoleOutputW(long ptr long long ptr)
@ stdcall ReadConsoleW(long ptr long ptr ptr)
@ stdcall ReadDirectoryChangesW(long ptr long long long ptr ptr ptr)
@ stdcall ReadFile(long ptr long ptr ptr)
@ stdcall ReadFileEx(long ptr long ptr ptr)
@ stdcall ReadFileScatter(long ptr long ptr ptr)
@ stdcall ReadProcessMemory(long ptr ptr long ptr)
@ stdcall -version=0x600+ RegCloseKey(long)
@ stdcall -version=0x600+ RegCreateKeyExA(long str long ptr long long ptr ptr ptr)
@ stdcall -version=0x600+ RegCreateKeyExW(long wstr long ptr long long ptr ptr ptr)
@ stdcall -version=0x600+ RegDeleteKeyExA(long str long long)
@ stdcall -version=0x600+ RegDeleteKeyExW(long wstr long long)
@ stdcall -version=0x600+ RegDeleteKeyValueA(ptr str str)
@ stdcall -version=0x600+ RegDeleteKeyValueW(ptr wstr wstr)
@ stdcall -version=0x600+ RegDeleteTreeA(ptr str)
@ stdcall -version=0x600+ RegDeleteTreeW(ptr wstr)
@ stdcall -version=0x600+ RegDeleteValueA(long str)
@ stdcall -version=0x600+ RegDeleteValueW(long wstr)
@ stdcall -version=0x600+ RegDisablePredefinedCacheEx()
@ stdcall -version=0x600+ RegEnumKeyExA(long long ptr ptr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegEnumKeyExW(long long ptr ptr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegEnumValueA(long long ptr ptr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegEnumValueW(long long ptr ptr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegFlushKey(long)
@ stdcall -version=0x600+ RegGetKeySecurity(long long ptr ptr)
@ stdcall -version=0x600+ RegGetValueA(long str str long ptr ptr ptr)
@ stdcall -version=0x600+ RegGetValueW(long wstr wstr long ptr ptr ptr)
@ stdcall -version=0x600+ RegisterApplicationRecoveryCallback(ptr ptr long long) kernel32_vista.RegisterApplicationRecoveryCallback
@ stdcall -version=0x600+ RegisterApplicationRestart(wstr long) kernel32_vista.RegisterApplicationRestart
@ stdcall RegisterConsoleIME(ptr ptr)
@ stdcall RegisterConsoleOS2(long)
@ stdcall RegisterConsoleVDM(long long long long long long long long long long long)
@ stdcall RegisterWaitForInputIdle(ptr)
@ stdcall RegisterWaitForSingleObject(ptr long ptr ptr long long)
@ stdcall RegisterWaitForSingleObjectEx(long ptr ptr long long)
@ stdcall RegisterWowBaseHandlers(long)
@ stdcall RegisterWowExec(long)
@ stdcall -version=0x600+ RegLoadKeyA(long str str)
@ stdcall -version=0x600+ RegLoadKeyW(long wstr wstr)
@ stdcall -stub -version=0x600+ RegLoadMUIStringA(long str str long ptr long str)
@ stdcall -stub -version=0x600+ RegLoadMUIStringW(long wstr wstr long ptr long wstr)
@ stdcall -version=0x600+ RegNotifyChangeKeyValue(long long long long long)
@ stdcall -version=0x600+ RegOpenCurrentUser(long ptr)
@ stdcall -version=0x600+ RegOpenKeyExA(long str long long ptr)
@ stdcall -version=0x600+ RegOpenKeyExW(long wstr long long ptr)
@ stdcall -version=0x600+ RegOpenUserClassesRoot(ptr long long ptr)
@ stdcall -version=0x600+ RegQueryInfoKeyA(long ptr ptr ptr ptr ptr ptr ptr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegQueryInfoKeyW(long ptr ptr ptr ptr ptr ptr ptr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegQueryValueExA(long str ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegQueryValueExW(long wstr ptr ptr ptr ptr)
@ stdcall -version=0x600+ RegRestoreKeyA(long str long)
@ stdcall -version=0x600+ RegRestoreKeyW(long wstr long)
@ stdcall -version=0x600+ RegSaveKeyExA(long str ptr long)
@ stdcall -version=0x600+ RegSaveKeyExW(long str ptr long)
@ stdcall -version=0x600+ RegSetKeySecurity(long long ptr)
@ stdcall -version=0x600+ RegSetValueExA(long str long long ptr long)
@ stdcall -version=0x600+ RegSetValueExW(long wstr long long ptr long)
@ stdcall -version=0x600+ RegUnLoadKeyA(long str)
@ stdcall -version=0x600+ RegUnLoadKeyW(long wstr)
@ stdcall ReleaseActCtx(ptr)
@ stdcall ReleaseMutex(long)
@ stdcall -version=0x600+ ReleaseMutexWhenCallbackReturns(ptr ptr) ntdll_vista.TpCallbackReleaseMutexOnCompletion
@ stdcall -version=0x600+ ReleaseSRWLockExclusive(ptr) ntdll_vista.RtlReleaseSRWLockExclusive
@ stdcall -version=0x600+ ReleaseSRWLockShared(ptr) ntdll_vista.RtlReleaseSRWLockShared
@ stdcall ReleaseSemaphore(long long ptr)
@ stdcall -version=0x600+ ReleaseSemaphoreWhenCallbackReturns(ptr ptr) ntdll_vista.TpCallbackReleaseSemaphoreOnCompletion
@ stdcall RemoveDirectoryA(str)
@ stdcall -stub -version=0x600+ RemoveDirectoryTransactedA(str ptr)
@ stdcall -stub -version=0x600+ RemoveDirectoryTransactedW(wstr ptr)
@ stdcall RemoveDirectoryW(wstr)
@ stdcall RemoveLocalAlternateComputerNameA(str long)
@ stdcall RemoveLocalAlternateComputerNameW(wstr long)
@ stdcall -stub -version=0x600+ RemoveSecureMemoryCacheCallback(ptr)
@ stdcall RemoveVectoredContinueHandler(ptr) ntdll.RtlRemoveVectoredContinueHandler
@ stdcall RemoveVectoredExceptionHandler(ptr) ntdll.RtlRemoveVectoredExceptionHandler
@ stdcall ReplaceFile(wstr wstr wstr long ptr ptr) ReplaceFileW
@ stdcall ReplaceFileA(str str str long ptr ptr)
@ stdcall ReplaceFileW(wstr wstr wstr long ptr ptr)
@ stub -version=0x600+ ReplacePartitionUnit
@ stdcall RequestDeviceWakeup(long)
@ stdcall RequestWakeupLatency(long)
@ stdcall ResetEvent(long)
@ stdcall ResetWriteWatch(ptr long)
@ stdcall -stub -version=0x600+ ResolveDelayLoadedAPI(ptr ptr ptr ptr ptr long)
@ stdcall RestoreLastError(long) ntdll.RtlRestoreLastWin32Error
@ stdcall ResumeThread(long)
@ stdcall -version=0x600+ ResolveLocaleName(wstr wstr long) kernel32_vista.ResolveLocaleName
@ stdcall -arch=x86_64 RtlAddFunctionTable(ptr long long) ntdll.RtlAddFunctionTable
@ stdcall -register RtlCaptureContext(ptr) ntdll.RtlCaptureContext
@ stdcall RtlCaptureStackBackTrace(long long ptr ptr) ntdll.RtlCaptureStackBackTrace
@ stdcall -arch=x86_64 RtlCompareMemory(ptr ptr ptr) ntdll.RtlCompareMemory
@ stdcall -arch=x86_64 RtlCopyMemory(ptr ptr ptr) ntdll.memcpy
@ stdcall -arch=x86_64 RtlDeleteFunctionTable(ptr) ntdll.RtlDeleteFunctionTable
@ stdcall RtlFillMemory(ptr long long) ntdll.RtlFillMemory
@ stdcall -arch=x86_64 RtlInstallFunctionTableCallback(double double long ptr ptr ptr) ntdll.RtlInstallFunctionTableCallback
@ stdcall -arch=x86_64 RtlLookupFunctionEntry(ptr ptr ptr) ntdll.RtlLookupFunctionEntry
@ stdcall RtlMoveMemory(ptr ptr long) ntdll.RtlMoveMemory
@ stdcall -arch=x86_64 RtlPcToFileHeader(ptr ptr) ntdll.RtlPcToFileHeader
@ stdcall -arch=x86_64 RtlRaiseException(ptr) ntdll.RtlRaiseException
@ stdcall -arch=x86_64 RtlRestoreContext(ptr ptr) ntdll.RtlRestoreContext
@ stdcall RtlUnwind(ptr ptr ptr ptr) ntdll.RtlUnwind
@ stdcall -arch=x86_64 RtlUnwindEx(ptr ptr ptr ptr ptr ptr) ntdll.RtlUnwindEx
@ stdcall -arch=x86_64 RtlVirtualUnwind(ptr ptr ptr long) ntdll.RtlVirtualUnwind
@ stdcall RtlZeroMemory(ptr long) ntdll.RtlZeroMemory
@ stdcall ScrollConsoleScreenBufferA(long ptr ptr ptr ptr)
@ stdcall ScrollConsoleScreenBufferW(long ptr ptr ptr ptr)
@ stdcall SearchPathA(str str str long ptr ptr)
@ stdcall SearchPathW(wstr wstr wstr long ptr ptr)
@ stdcall -version=0x500-0x502 SetCPGlobal(long)
@ stdcall SetCalendarInfoA(long long long str)
@ stdcall SetCalendarInfoW(long long long wstr)
@ stdcall SetClientTimeZoneInformation(ptr)
@ stdcall SetComPlusPackageInstallStatus(ptr)
@ stdcall SetCommBreak(long)
@ stdcall SetCommConfig(long ptr long)
@ stdcall SetCommMask(long ptr)
@ stdcall SetCommState(long ptr)
@ stdcall SetCommTimeouts(long ptr)
@ stdcall SetComputerNameA(str)
@ stdcall SetComputerNameExA(long str)
@ stdcall SetComputerNameExW(long wstr)
@ stdcall SetComputerNameW(wstr)
@ stdcall SetConsoleActiveScreenBuffer(long)
@ stdcall SetConsoleCP(long)
@ stdcall -version=0x351-0x502 SetConsoleCommandHistoryMode(long)
@ stdcall SetConsoleCtrlHandler(ptr long)
@ stdcall SetConsoleCursor(long long)
@ stdcall SetConsoleCursorInfo(long ptr)
@ stdcall SetConsoleCursorMode(long long long)
@ stdcall SetConsoleCursorPosition(long long)
@ stdcall SetConsoleDisplayMode(long long ptr)
@ stdcall SetConsoleFont(long long)
@ stdcall SetConsoleHardwareState(long long long)
@ stdcall -version=0x600+ SetConsoleHistoryInfo(ptr)
@ stdcall SetConsoleIcon(ptr)
@ stdcall SetConsoleInputExeNameA(ptr)
@ stdcall SetConsoleInputExeNameW(ptr)
@ stdcall SetConsoleKeyShortcuts(long long long long)
@ stdcall SetConsoleLocalEUDC(long long long long)
@ stdcall SetConsoleMaximumWindowSize(long long)
@ stdcall SetConsoleMenuClose(long)
@ stdcall SetConsoleMode(long long)
@ stdcall SetConsoleNlsMode(long long)
@ stdcall SetConsoleNumberOfCommandsA(long long)
@ stdcall SetConsoleNumberOfCommandsW(long long)
@ stdcall SetConsoleOS2OemFormat(long)
@ stdcall SetConsoleOutputCP(long)
@ stdcall SetConsolePalette(long long long)
@ stdcall -version=0x600+ SetConsoleScreenBufferInfoEx(ptr ptr)
@ stdcall SetConsoleScreenBufferSize(long long)
@ stdcall SetConsoleTextAttribute(long long)
@ stdcall SetConsoleTitleA(str)
@ stdcall SetConsoleTitleW(wstr)
@ stdcall SetConsoleWindowInfo(long long ptr)
@ stdcall SetCriticalSectionSpinCount(ptr long) ntdll.RtlSetCriticalSectionSpinCount
@ stdcall -stub -version=0x600+ SetCurrentConsoleFontEx(ptr long ptr)
@ stdcall SetCurrentDirectoryA(str)
@ stdcall SetCurrentDirectoryW(wstr)
@ stdcall SetDefaultCommConfigA(str ptr long)
@ stdcall SetDefaultCommConfigW(wstr ptr long)
@ stdcall -version=0x600+ SetDefaultDllDirectories(long)
@ stdcall SetDllDirectoryA(str)
@ stdcall SetDllDirectoryW(wstr)
@ stdcall -stub -version=0x600+ SetDynamicTimeZoneInformation(ptr)
@ stdcall SetEndOfFile(long)
@ stdcall SetEnvironmentStringsA(ptr)
@ stdcall SetEnvironmentStringsW(ptr)
@ stdcall SetEnvironmentVariableA(str str)
@ stdcall SetEnvironmentVariableW(wstr wstr)
@ stdcall SetErrorMode(long)
@ stdcall SetEvent(long)
@ stdcall -version=0x600+ SetEventWhenCallbackReturns(ptr ptr) ntdll_vista.TpCallbackSetEventOnCompletion
@ stdcall SetFileApisToANSI()
@ stdcall SetFileApisToOEM()
@ stdcall SetFileAttributesA(str long)
@ stdcall -stub -version=0x600+ SetFileAttributesTransactedA(str long ptr)
@ stdcall -stub -version=0x600+ SetFileAttributesTransactedW(wstr long ptr)
@ stdcall SetFileAttributesW(wstr long)
@ stdcall -version=0x600+ SetFileBandwidthReservation(ptr long long long ptr ptr) kernel32_vista.SetFileBandwidthReservation
@ stdcall SetFileCompletionNotificationModes(ptr long)
@ stdcall -version=0x600+ SetFileInformationByHandle(long long ptr long)
@ stdcall -stub -version=0x600+ SetFileIoOverlappedRange(ptr ptr long)
@ stdcall SetFilePointer(long long ptr long)
@ stdcall SetFilePointerEx(long double ptr long)
@ stdcall SetFileShortNameA(long str)
@ stdcall SetFileShortNameW(long wstr)
@ stdcall SetFileTime(long ptr ptr ptr)
@ stdcall SetFileValidData(long double)
@ stdcall SetFirmwareEnvironmentVariableA(str str ptr long)
@ stdcall SetFirmwareEnvironmentVariableW(wstr wstr ptr long)
@ stdcall -i386 SetHandleContext(long long)
@ stdcall SetHandleCount(long)
@ stdcall SetHandleInformation(long long long)
@ stdcall SetInformationJobObject(long long ptr long)
@ stdcall SetLastConsoleEventActive() ; missing in XP SP3
@ stdcall SetLastError(long) ntdll.RtlSetLastWin32Error
@ stdcall SetLocalPrimaryComputerNameA(long long) ; missing in XP SP3
@ stdcall SetLocalPrimaryComputerNameW(long long) ; missing in XP SP3
@ stdcall SetLocalTime(ptr)
@ stdcall SetLocaleInfoA(long long str)
@ stdcall SetLocaleInfoW(long long wstr)
@ stdcall SetMailslotInfo(long long)
@ stdcall SetMessageWaitingIndicator(ptr long)
@ stub -version=0x600+ SetNamedPipeAttribute
@ stdcall SetNamedPipeHandleState(long ptr ptr ptr)
@ stdcall SetPriorityClass(long long)
@ stdcall SetProcessAffinityMask(long long)
@ stdcall -stub -version=0x600+ SetProcessAffinityUpdateMode(ptr long)
@ stdcall -version=0x600+ SetProcessDEPPolicy(long)
@ stdcall SetProcessPriorityBoost(long long)
@ stdcall SetProcessShutdownParameters(long long)
@ stdcall SetProcessWorkingSetSize(long long long)
@ stdcall SetProcessWorkingSetSizeEx(long long long long)
@ stdcall  -version=0x601+ SetSearchPathMode(long)
@ stdcall SetStdHandle(long long)
@ stub -version=0x600+ SetStdHandleEx
@ stdcall SetSystemFileCacheSize(long long long)
@ stdcall SetSystemPowerState(long long)
@ stdcall SetSystemTime(ptr)
@ stdcall SetSystemTimeAdjustment(long long)
@ stdcall SetTapeParameters(ptr long ptr)
@ stdcall SetTapePosition(ptr long long long long long)
@ stdcall SetTermsrvAppInstallMode(long)
@ stdcall SetThreadAffinityMask(long long)
@ stdcall -stub SetThreadGroupAffinity(long long long)
@ stdcall SetThreadContext(long ptr)
@ stdcall -version=0x601+ SetThreadErrorMode(long long)
@ stdcall SetThreadExecutionState(long)
@ stdcall SetThreadIdealProcessor(long long)
@ stdcall -stub SetThreadIdealProcessorEx(ptr ptr ptr)
@ stdcall -stub GetThreadIdealProcessorEx(ptr ptr)
@ stdcall SetThreadLocale(long)
@ stdcall -version=0x600+ SetThreadPreferredUILanguages(long ptr ptr)
@ stdcall SetThreadPriority(long long)
@ stdcall SetThreadPriorityBoost(long long)
@ stdcall SetThreadStackGuarantee(ptr)
@ stdcall SetThreadUILanguage(long)
@ stdcall -version=0x600+ SetThreadpoolThreadMaximum(ptr long) ntdll_vista.TpSetPoolMaxThreads
@ stdcall -version=0x600+ SetThreadpoolThreadMinimum(ptr long) ntdll_vista.TpSetPoolMinThreads
@ stdcall -version=0x600+ SetThreadpoolTimer(ptr ptr long long)
@ stdcall -version=0x600+ SetThreadpoolWait(ptr ptr ptr)
@ stdcall SetTimeZoneInformation(ptr)
@ stdcall SetTimerQueueTimer(long ptr ptr long long long)
@ stdcall SetUnhandledExceptionFilter(ptr)
@ stdcall SetUserGeoID(long)
@ stdcall SetVDMCurrentDirectories(long long)
@ stdcall SetVolumeLabelA(str str)
@ stdcall SetVolumeLabelW(wstr wstr)
@ stdcall SetVolumeMountPointA(str str)
@ stdcall SetVolumeMountPointW(wstr wstr)
@ stdcall SetWaitableTimer(long ptr long ptr ptr long)
@ stdcall -version=0x601+ SetWaitableTimerEx(long ptr long ptr ptr ptr long)
@ stdcall SetupComm(long long long)
@ stdcall ShowConsoleCursor(long long)
@ stdcall SignalObjectAndWait(long long long long)
@ stdcall SizeofResource(long long)
@ stdcall Sleep(long)
@ stdcall -version=0x600+ SleepConditionVariableCS(ptr ptr long) kernel32_vista.SleepConditionVariableCS
@ stdcall -version=0x600+ SleepConditionVariableSRW(ptr ptr long long) kernel32_vista.SleepConditionVariableSRW
@ stdcall SleepEx(long long)
@ stdcall -stub -version=0x600+ StartThreadpoolIo(ptr)
@ stdcall -version=0x600+ SubmitThreadpoolWork(ptr) ntdll.TpPostWork
@ stdcall SuspendThread(long)
@ stdcall SwitchToFiber(ptr)
@ stdcall SwitchToThread()
@ stdcall SystemTimeToFileTime(ptr ptr)
@ stdcall SystemTimeToTzSpecificLocalTime (ptr ptr ptr)
@ stdcall TerminateJobObject(ptr long)
@ stdcall TerminateProcess(ptr long)
@ stdcall TerminateThread(ptr long)
@ stdcall TermsrvAppInstallMode()
@ stdcall Thread32First(long ptr)
@ stdcall Thread32Next(long ptr)
@ stdcall TlsAlloc()
@ stdcall TlsFree(long)
@ stdcall -norelay TlsGetValue(long)
@ stdcall -norelay TlsSetValue(long ptr)
@ stdcall Toolhelp32ReadProcessMemory(long ptr ptr long ptr)
@ stdcall TransactNamedPipe(long ptr long ptr long ptr ptr)
@ stdcall TransmitCommChar(long long)
@ stdcall -version=0x600+ TryAcquireSRWLockExclusive(ptr) ntdll_vista.RtlTryAcquireSRWLockExclusive
@ stdcall -version=0x600+ TryAcquireSRWLockShared(ptr) ntdll_vista.RtlTryAcquireSRWLockShared
@ stdcall TryEnterCriticalSection(ptr) ntdll.RtlTryEnterCriticalSection
@ stdcall -version=0x600+ TrySubmitThreadpoolCallback(ptr ptr ptr)
@ stdcall TzSpecificLocalTimeToSystemTime(ptr ptr ptr)
@ stdcall UTRegister(long str str str ptr ptr ptr)
@ stdcall UTUnRegister(long)
@ stdcall UnhandledExceptionFilter(ptr)
@ stdcall UnlockFile(long long long long long)
@ stdcall UnlockFileEx(long long long long ptr)
@ stdcall UnmapViewOfFile(ptr)
@ stdcall -stub -version=0x600+ UnregisterApplicationRecoveryCallback()
@ stdcall -stub -version=0x600+ UnregisterApplicationRestart()
@ stdcall UnregisterConsoleIME()
@ stdcall UnregisterWait(long)
@ stdcall UnregisterWaitEx(long long)
@ stdcall -stub -version=0x600+ UpdateCalendarDayOfWeek(ptr)
@ stdcall -stub -version=0x600+ UpdateProcThreadAttribute(ptr long ptr ptr long ptr ptr)
@ stdcall UpdateResourceA(long str str long ptr long)
@ stdcall UpdateResourceW(long wstr wstr long ptr long)
@ stdcall VDMConsoleOperation(long long)
@ stdcall VDMOperationStarted(long)
@ stdcall -version=0x500-0x502 ValidateLCType(long long ptr ptr)
@ stdcall -version=0x500-0x502 ValidateLocale(long)
@ stdcall VerLanguageNameA(long str long)
@ stdcall VerLanguageNameW(long wstr long)
@ stdcall -ret64 VerSetConditionMask(long long long long) ntdll.VerSetConditionMask
@ stdcall VerifyConsoleIoHandle(long)
@ stdcall -stub -version=0x600+ VerifyScripts(long wstr long wstr long)
@ stdcall VerifyVersionInfoA(long long double)
@ stdcall VerifyVersionInfoW(long long double)
@ stdcall VirtualAlloc(ptr long long long)
@ stdcall VirtualAllocEx(long ptr long long long)
@ stdcall -stub -version=0x600+ VirtualAllocExNuma(ptr ptr long long long long)
@ stdcall VirtualFree(ptr long long)
@ stdcall VirtualFreeEx(long ptr long long)
@ stdcall VirtualLock(ptr long)
@ stdcall VirtualProtect(ptr long long ptr)
@ stdcall VirtualProtectEx(long ptr long long ptr)
@ stdcall VirtualQuery(ptr ptr long)
@ stdcall VirtualQueryEx(long ptr ptr long)
@ stdcall VirtualUnlock(ptr long)
@ stdcall WTSGetActiveConsoleSessionId()
@ stdcall WaitCommEvent(long ptr ptr)
@ stdcall WaitForDebugEvent(ptr long)
@ stdcall WaitForMultipleObjects(long ptr long long)
@ stdcall WaitForMultipleObjectsEx(long ptr long long long)
@ stdcall WaitForSingleObject(long long)
@ stdcall WaitForSingleObjectEx(long long long)
@ stdcall -stub -version=0x600+ WaitForThreadpoolIoCallbacks(ptr long)
@ stdcall -version=0x600+ WaitForThreadpoolTimerCallbacks(ptr long) ntdll_vista.TpWaitForTimer
@ stdcall -version=0x600+ WaitForThreadpoolWaitCallbacks(ptr long) ntdll_vista.TpWaitForWait
@ stdcall -version=0x600+ WaitForThreadpoolWorkCallbacks(ptr long) ntdll_vista.TpWaitForWork
@ stdcall WaitNamedPipeA (str long)
@ stdcall WaitNamedPipeW (wstr long)
@ stdcall -version=0x600+ WakeAllConditionVariable(ptr) kernel32_vista.WakeAllConditionVariable
@ stdcall -version=0x600+ WakeConditionVariable(ptr) kernel32_vista.WakeConditionVariable
@ stdcall -stub -version=0x600+ WerGetFlags(ptr ptr)
@ stdcall -stub -version=0x600+ WerRegisterFile(wstr long long)
@ stdcall -version=0x600+ WerRegisterMemoryBlock(ptr long)
@ stub -version=0x600+ WerRegisterRuntimeExceptionModule
@ stdcall -stub -version=0x600+ WerSetFlags(long)
@ stdcall -stub -version=0x600+ WerUnregisterFile(wstr)
@ stdcall -stub -version=0x600+ WerUnregisterMemoryBlock(ptr)
@ stub -version=0x601+ WerUnregisterRuntimeExceptionModule
@ stub -version=0x600+ WerpCleanupMessageMapping
@ stub -version=0x600+ WerpInitiateRemoteRecovery
@ stub -version=0x600+ WerpNotifyLoadStringResource
@ stub -version=0x600+ WerpNotifyLoadStringResourceEx
@ stub -version=0x600+ WerpNotifyUseStringResource
@ stub -version=0x600+ WerpStringLookup
@ stdcall WideCharToMultiByte(long long wstr long ptr long ptr ptr)
@ stdcall WinExec(str long)
@ stdcall Wow64DisableWow64FsRedirection(ptr)
@ stdcall Wow64EnableWow64FsRedirection(long)
@ stdcall -stub -version=0x600+ Wow64GetThreadContext(ptr ptr)
@ stdcall Wow64RevertWow64FsRedirection(ptr)
@ stdcall -stub -version=0x600+ Wow64SetThreadContext(ptr ptr)
@ stdcall -stub -version=0x600+ Wow64SuspendThread(ptr)
@ stdcall WriteConsoleA(long ptr long ptr ptr)
@ stdcall WriteConsoleInputA(long ptr long ptr)
@ stdcall WriteConsoleInputVDMA(long long long long)
@ stdcall WriteConsoleInputVDMW(long long long long)
@ stdcall WriteConsoleInputW(long ptr long ptr)
@ stdcall WriteConsoleOutputA(long ptr long long ptr)
@ stdcall WriteConsoleOutputAttribute(long ptr long long ptr)
@ stdcall WriteConsoleOutputCharacterA(long ptr long long ptr)
@ stdcall WriteConsoleOutputCharacterW(long ptr long long ptr)
@ stdcall WriteConsoleOutputW(long ptr long long ptr)
@ stdcall WriteConsoleW(long ptr long ptr ptr)
@ stdcall WriteFile(long ptr long ptr ptr)
@ stdcall WriteFileEx(long ptr long ptr ptr)
@ stdcall WriteFileGather(long ptr long ptr ptr)
@ stdcall WritePrivateProfileSectionA(str str str)
@ stdcall WritePrivateProfileSectionW(wstr wstr wstr)
@ stdcall WritePrivateProfileStringA(str str str str)
@ stdcall WritePrivateProfileStringW(wstr wstr wstr wstr)
@ stdcall WritePrivateProfileStructA (str str ptr long str)
@ stdcall WritePrivateProfileStructW(wstr wstr ptr long wstr)
@ stdcall WriteProcessMemory(long ptr ptr long ptr)
@ stdcall WriteProfileSectionA(str str)
@ stdcall WriteProfileSectionW(str str)
@ stdcall WriteProfileStringA(str str str)
@ stdcall WriteProfileStringW(wstr wstr wstr)
@ stdcall WriteTapemark(ptr long long long)
@ stdcall ZombifyActCtx(ptr)
@ stdcall -arch=x86_64 __C_specific_handler() ntdll.__C_specific_handler
@ stdcall -arch=x86_64 __chkstk() ntdll.__chkstk
;@ stdcall -arch=x86_64 __misaligned_access() ntdll.__misaligned_access
@ stdcall _hread(long ptr long)
@ stdcall _hwrite(long ptr long)
@ stdcall _lclose(long)
@ stdcall _lcreat(str long)
@ stdcall _llseek(long long long)
@ stdcall -arch=x86_64 _local_unwind() ntdll._local_unwind
@ stdcall _lopen(str long)
@ stdcall _lread(long ptr long) _hread
@ stdcall _lwrite(long ptr long) _hwrite
@ stdcall lstrcat(str str) lstrcatA
@ stdcall lstrcatA(str str)
@ stdcall lstrcatW(wstr wstr)
@ stdcall lstrcmp(str str) lstrcmpA
@ stdcall lstrcmpA(str str)
@ stdcall lstrcmpW(wstr wstr)
@ stdcall lstrcmpi(str str) lstrcmpiA
@ stdcall lstrcmpiA(str str)
@ stdcall lstrcmpiW(wstr wstr)
@ stdcall lstrcpy(ptr str) lstrcpyA
@ stdcall lstrcpyA(ptr str)
@ stdcall lstrcpyW(ptr wstr)
@ stdcall lstrcpyn(ptr str long) lstrcpynA
@ stdcall lstrcpynA(ptr str long)
@ stdcall lstrcpynW(ptr wstr long)
@ stdcall lstrlen(str) lstrlenA
@ stdcall lstrlenA(str)
@ stdcall lstrlenW(wstr)
;@ stdcall -arch=x86_64 uaw_lstrcmpW(wstr wstr)
;@ stdcall -arch=x86_64 uaw_lstrcmpiW(wstr wstr)
;@ stdcall -arch=x86_64 uaw_lstrlenW(wstr)
;@ stdcall -arch=x86_64 uaw_wcschr(wstr long)
;@ stdcall -arch=x86_64 uaw_wcscpy(ptr wstr)
;@ stdcall -arch=x86_64 uaw_wcsicmp(wstr wstr)
;@ stdcall -arch=x86_64 uaw_wcslen(wstr)
;@ stdcall -arch=x86_64 uaw_wcsrchr(wstr long)
@ stdcall -version=0x600+ K32EmptyWorkingSet(long)
@ stdcall -version=0x600+ K32EnumDeviceDrivers(ptr long ptr)
@ stdcall -stub -version=0x600+ K32EnumPageFilesA(ptr ptr)
@ stdcall -stub -version=0x600+ K32EnumPageFilesW(ptr ptr)
@ stdcall -version=0x600+ K32EnumProcessModules(long ptr long ptr)
@ stdcall -version=0x600+ K32EnumProcessModulesEx(long ptr long ptr long)
@ stdcall -version=0x600+ K32EnumProcesses(ptr long ptr)
@ stdcall -version=0x600+ K32GetDeviceDriverBaseNameA(ptr ptr long)
@ stdcall -version=0x600+ K32GetDeviceDriverBaseNameW(ptr ptr long)
@ stdcall -version=0x600+ K32GetDeviceDriverFileNameA(ptr ptr long)
@ stdcall -version=0x600+ K32GetDeviceDriverFileNameW(ptr ptr long)
@ stdcall -stub -version=0x600+ K32GetMappedFileNameW(long ptr ptr long)
@ stdcall -version=0x600+ K32GetModuleBaseNameA(long long ptr long)
@ stdcall -version=0x600+ K32GetModuleBaseNameW(long long ptr long)
@ stdcall -version=0x600+ K32GetModuleFileNameExA(long long ptr long)
@ stdcall -version=0x600+ K32GetModuleFileNameExW(long long ptr long)
@ stdcall -version=0x600+ K32GetModuleInformation(long long ptr long)
@ stdcall -version=0x601+ K32GetPerformanceInfo(ptr long)
@ stdcall -stub -version=0x601+ K32GetProcessImageFileNameW(ptr wstr long)
@ stdcall -version=0x600+ K32GetProcessMemoryInfo(ptr ptr long)
@ stdcall -stub -version=0x600+ K32QueryWorkingSet(ptr ptr long)
@ stdcall -stub -version=0x600+ K32QueryWorkingSetEx(ptr ptr long)
@ stdcall -version=0x600+ PowerClearRequest(long long)
@ stdcall -version=0x600+ PowerCreateRequest(ptr)
@ stdcall -version=0x600+ PowerSetRequest(long long)

;NT6.0 stuff
@ stub -version=0x600+ GetDurationFormatW
@ stub -version=0x602+ ActivateActCtxWorker	
@ stub -version=0x602+ AddRefActCtxWorker	
@ stub -version=0x602+ AppContainerDeriveSidFromMoniker	
@ stub -version=0x602+ AppContainerFreeMemory	
@ stub -version=0x602+ AppContainerLookupDisplayName	
@ stub -version=0x602+ AppContainerLookupMoniker	
@ stub -version=0x602+ AppContainerRegisterSid	
@ stub -version=0x602+ AppContainerUnregisterSid	
@ stub -version=0x602+ AppXFreeMemory	
@ stub -version=0x602+ AppXGetApplicationData	
@ stub -version=0x602+ AppXGetDevelopmentMode	
@ stub -version=0x602+ AppXGetOSMaxVersionTested	
@ stub -version=0x602+ AppXGetPackageCapabilities	
@ stub -version=0x602+ AppXGetPackageSid	
@ stub -version=0x602+ AppXGetPackageState	
@ stub -version=0x602+ AppXLookupDisplayName	
@ stub -version=0x602+ AppXLookupMoniker	
@ stub -version=0x602+ AppXSetPackageState	
@ stub -version=0x602+ BaseCheckAppcompatCacheExWorker	
@ stub -version=0x602+ BaseCheckAppcompatCacheWorker	
@ stub -version=0x602+ BaseCheckElevation	
@ stub -version=0x602+ BaseCleanupAppcompatCacheSupportWorker	
;@ stub -version=0x602+ BaseDestroyVDMEnvironment	
@ stub -version=0x602+ BaseDumpAppcompatCacheWorker	
@ stub -version=0x602+ BaseElevationPostProcessing	
@ stub -version=0x602+ BaseFlushAppcompatCacheWorker	
@ stub -version=0x602+ BaseInitAppcompatCacheSupportWorker	
@ stub -version=0x602+ BaseIsAppcompatInfrastructureDisabledWorker	
;@ stub -version=0x602+ BaseIsDosApplication	
@ stub -version=0x602+ BaseUpdateAppcompatCacheWorker	
;@ stub -version=0x602+ BaseUpdateVDMEntry	
@ stub -version=0x602+ BaseWriteErrorElevationRequiredEvent	
@ stub -version=0x602+ BasepAppCompatHookDLL	
@ stub -version=0x602+ BasepAppContainerEnvironmentExtension	
@ stub -version=0x602+ BasepAppXExtension	
;@ stub -version=0x602+ BasepCheckWebBladeHashes	
@ stub -version=0x602+ BasepConstructSxsCreateProcessMessage	
@ stub -version=0x602+ BasepCopyEncryption	
@ stub -version=0x602+ BasepGetAppCompatData	
;@ stub -version=0x602+ BasepGetComputerNameFromNtPath	
@ stub -version=0x602+ BasepGetExeArchType	
;@ stub -version=0x602+ BasepIsProcessAllowed	
@ stub -version=0x602+ BasepNotifyLoadStringResource	
@ stub -version=0x602+ BasepPostSuccessAppXExtension	
@ stub -version=0x602+ BasepProcessInvalidImage	
@ stub -version=0x602+ BasepQueryAppCompat	
@ stub -version=0x602+ BasepReleaseAppXContext	
@ stub -version=0x602+ BasepReleaseSxsCreateProcessUtilityStruct	
@ stub -version=0x602+ BasepReportFault	
@ stub -version=0x602+ BasepSetFileEncryptionCompression	
@ stub -version=0x602+ CallbackDetectedUnrecoverableError	
@ stub -version=0x602+ CheckAllowDecryptedRemoteDestinationPolicy	
@ stub -version=0x602+ CheckForReadOnlyResourceFilter	
@ stub -version=0x602+ CheckTokenCapability	
@ stub -version=0x602+ CheckTokenMembershipEx	
@ stub -version=0x602+ ClosePackageInfo	
@ stub -version=0x602+ CloseState	
@ stub -version=0x602+ CloseStateAtom	
@ stub -version=0x602+ CloseStateContainer	
@ stub -version=0x602+ CommitStateAtom	
@ stub -version=0x602+ CommitStateAtomDeprecated	
@ stub -version=0x602+ CopyContext	
@ stub -version=0x602+ CopyFile2	
@ stub -version=0x602+ CreateActCtxWWorker	
@ stub -version=0x602+ CreateFile2	
@ stub -version=0x602+ CreateStateAtom	
@ stub -version=0x602+ CreateStateAtomDeprecated	
@ stub -version=0x602+ CreateStateContainer	
@ stub -version=0x602+ CreateStateSubcontainer	
@ stub -version=0x602+ DeactivateActCtxWorker	
@ stub -version=0x602+ DeleteStateAtomValue	
@ stub -version=0x602+ DeleteStateContainer	
@ stub -version=0x602+ DeleteStateContainerAtom	
@ stub -version=0x602+ DeleteStateContainerValue	
@ stub -version=0x602+ DuplicateEncryptionInfoFileExt	
@ stub -version=0x602+ DuplicateStateContainerHandle	
@ stub -version=0x602+ EnumerateStateAtomValues	
@ stub -version=0x602+ EnumerateStateContainerItems	
@ stub -version=0x602+ EnumerateStateContainerItemsDeprecated	
@ stub -version=0x602+ FindActCtxSectionGuidWorker	
@ stub -version=0x602+ FindActCtxSectionStringWWorker	
@ stub -version=0x602+ GetAppContainerAce	
@ stub -version=0x602+ GetAppContainerNamedObjectPath	
@ stub -version=0x602+ GetApplicationRecoveryCallbackWorker	
@ stub -version=0x602+ GetApplicationRestartSettingsWorker	
@ stub -version=0x602+ GetCurrentActCtxWorker	
@ stub -version=0x602+ GetCurrentPackageFamilyMonikerW	
@ stub -version=0x602+ GetCurrentPackageFamilyName	
@ stub -version=0x602+ GetCurrentPackageFamilyNameW	
@ stub -version=0x602+ GetCurrentPackageFullName	
@ stub -version=0x602+ GetCurrentPackageFullNameW	
;@ stub -version=0x602+ GetCurrentPackageId	
@ stub -version=0x602+ GetCurrentPackageIdW	
@ stub -version=0x602+ GetCurrentPackageInfo	
@ stub -version=0x602+ GetCurrentPackageInfoW	
@ stub -version=0x602+ GetCurrentPackageMonikerW	
@ stub -version=0x602+ GetCurrentPackagePath	
@ stub -version=0x602+ GetCurrentPackagePathW	
@ stub -version=0x602+ GetCurrentThreadStackLimits	
@ stub -version=0x602+ GetDateFormatAWorker	
@ stub -version=0x602+ GetDateFormatWWorker	
@ stub -version=0x602+ GetEnabledXStateFeatures	
@ stub -version=0x602+ GetFirmwareType	
@ stub -version=0x602+ GetHivePath	
@ stub -version=0x602+ GetOverlappedResultEx	
@ stub -version=0x602+ GetPackageFamilyName	
@ stub -version=0x602+ GetPackageFullName	
@ stub -version=0x602+ GetPackageFullNameW	
@ stub -version=0x602+ GetPackageId	
@ stub -version=0x602+ GetPackageIdW	
@ stub -version=0x602+ GetPackageInfo	
@ stub -version=0x602+ GetPackageMonikerW	
@ stub -version=0x602+ GetPackagePath	
@ stub -version=0x602+ GetPackagePathW	
@ stub -version=0x602+ GetPackagesByPackageFamily	
@ stub -version=0x602+ GetPackagesByPackageFamilyW	
@ stub -version=0x602+ GetProcessInformation	
@ stub -version=0x602+ GetProcessMitigationPolicy	
@ stub -version=0x602+ GetStateFolder	
@ stub -version=0x602+ GetStateVersion	
@ stub -version=0x602+ GetSystemAppDataFolder	
@ stub -version=0x602+ GetSystemAppDataKey	
;@ stub -version=0x602+ GetSystemTimePreciseAsFileTime	
@ stub -version=0x602+ GetThreadInformation	
@ stub -version=0x602+ GetTimeFormatAWorker	
@ stub -version=0x602+ GetTimeFormatWWorker	
@ stub -version=0x602+ GetXStateFeaturesMask	
@ stub -version=0x602+ GlobalAddAtomExA	
@ stub -version=0x602+ GlobalAddAtomExW	
@ stub -version=0x602+ InitializeContext	
@ stub -version=0x602+ IsNativeVhdBoot	
@ stub -version=0x602+ IsValidNLSVersion	
@ stub -version=0x602+ LoadPackagedLibrary	
@ stub -version=0x602+ LocateXStateFeature	
@ stub -version=0x602+ NtVdm64CreateProcessInternalW	
@ stub -version=0x602+ OpenConsoleWStub	
@ stub -version=0x602+ OpenPackageInfoByFullName	
@ stub -version=0x602+ OpenRoamingMutexes	
@ stub -version=0x602+ OpenRoamingNotificationEvent	
@ stub -version=0x602+ OpenState	
@ stub -version=0x602+ OpenStateAtom	
@ stub -version=0x602+ OpenStateExplicit	
@ stub -version=0x602+ PackageFamilyMonikerFromIdW	
@ stub -version=0x602+ PackageFamilyMonikerFromMonikerW	
@ stub -version=0x602+ PackageFamilyNameFromFullName	
@ stub -version=0x602+ PackageFamilyNameFromFullNameW	
@ stub -version=0x602+ PackageFamilyNameFromId	
@ stub -version=0x602+ PackageFamilyNameFromIdW	
@ stub -version=0x602+ PackageFullNameFromId	
@ stub -version=0x602+ PackageFullNameFromIdW	
@ stub -version=0x602+ PackageIdFromFullName	
@ stub -version=0x602+ PackageIdFromFullNameW	
@ stub -version=0x602+ PackageIdFromMonikerW	
@ stub -version=0x602+ PackageMonikerFromIdW	
@ stub -version=0x602+ PackageNameAndPublisherIdFromFamilyName	
@ stub -version=0x602+ PrefetchVirtualMemory	
@ stub -version=0x602+ QueryActCtxSettingsWWorker	
@ stub -version=0x602+ QueryActCtxWWorker	
@ stub -version=0x602+ QueryStateAtomValueInfo	
@ stub -version=0x602+ QueryStateContainerItemInfo	
@ stub -version=0x602+ RaiseInvalid16BitExeError	
@ stub -version=0x602+ ReadStateAtomValue	
@ stub -version=0x602+ ReadStateContainerValue	
;@ stub -version=0x602+ RegCopyTreeW	
@ stub -version=0x602+ RegisterBadMemoryNotification	
@ stub -version=0x602+ ReleaseActCtxWorker	
@ stub -version=0x602+ ResetState	
;@ stub -version=0x602+ ResolveDelayLoadedAPI	
@ stub -version=0x602+ ResolveDelayLoadsFromDll	
@ stub -version=0x602+ SetProcessInformation	
@ stub -version=0x602+ SetProcessMitigationPolicy	
@ stub -version=0x602+ SetStateVersion	
@ stub -version=0x602+ SetThreadInformation	
@ stub -version=0x602+ SetThreadpoolTimerEx	
@ stub -version=0x602+ SetThreadpoolWaitEx	
@ stub -version=0x602+ SetVolumeMountPointWStub	
@ stub -version=0x602+ SetXStateFeaturesMask	
@ stub -version=0x602+ TermsrvConvertSysRootToUserDir	
@ stub -version=0x602+ TermsrvCreateRegEntry	
@ stub -version=0x602+ TermsrvDeleteKey	
@ stub -version=0x602+ TermsrvDeleteValue	
@ stub -version=0x602+ TermsrvGetPreSetValue	
@ stub -version=0x602+ TermsrvGetWindowsDirectoryA	
@ stub -version=0x602+ TermsrvGetWindowsDirectoryW	
@ stub -version=0x602+ TermsrvOpenRegEntry	
@ stub -version=0x602+ TermsrvOpenUserClasses	
@ stub -version=0x602+ TermsrvRestoreKey	
@ stub -version=0x602+ TermsrvSetKeySecurity	
@ stub -version=0x602+ TermsrvSetValueKey	
@ stub -version=0x602+ TermsrvSyncUserIniFileExt	
@ stub -version=0x602+ UnmapViewOfFileEx	
@ stub -version=0x602+ UnregisterBadMemoryNotification	
@ stub -version=0x602+ WerRegisterMemoryBlockWorker	
@ stub -version=0x602+ WerUnregisterMemoryBlockWorker
@ stub -version=0x602+ WerpGetDebugger	
@ stub -version=0x602+ WerpLaunchAeDebug	
@ stub -version=0x602+ WerpNotifyLoadStringResourceWorker	
@ stub -version=0x602+ WerpNotifyUseStringResourceWorker	
@ stub -version=0x602+ WriteStateAtomValue	
@ stub -version=0x602+ WriteStateContainerValue	
@ stub -version=0x602+ ZombifyActCtxWorker	
@ stub -version=0x602+ timeBeginPeriod	
@ stub -version=0x602+ timeEndPeriod	
@ stub -version=0x602+ timeGetDevCaps	
@ stub -version=0x602+ timeGetSystemTime	
@ stub -version=0x602+ timeGetTime

;Windows 7 stuff
@ stdcall -version=0x601+ AddIntegrityLabelToBoundaryDescriptor() ntdll.RtlAddIntegrityLabelToBoundaryDescriptor
@ stub -version=0x601+ BaseCheckAppcompatCacheEx
@ stub -version=0x601+ BaseDllReadWriteIniFile
@ stub -version=0x601+ BaseVerifyUnicodeString
@ stub -version=0x601+ BasepAnsiStringToDynamicUnicodeString
@ stub -version=0x601+ BasepCheckAppCompat
;@ stub -version=0x601+ CreateProcessAsUserW
@ stub -version=0x601+ CreateRemoteThreadEx