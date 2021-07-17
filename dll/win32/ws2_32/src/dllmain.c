/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     ReactOS WinSock 2 API
 * FILE:        dll/win32/ws2_32/src/dllmain.c
 * PURPOSE:     DLL Entrypoint
 * PROGRAMMER:  Alex Ionescu (alex@relsoft.net)
 */

/*
 * BUGS:
 *       - GetAddrInfoW is completely IPv4 hacked and has some dirty code.
 *       - LookupNodeByAddr is missing some IPv6 support.
 */

/* INCLUDES ******************************************************************/

#include <ws2_32.h>

#define NDEBUG
#include <debug.h>

/* DATA **********************************************************************/

HANDLE WsSockHeap;
HINSTANCE WsDllHandle;
DWORD GlobalTlsIndex = TLS_OUT_OF_INDEXES;

/* FUNCTIONS *****************************************************************/

BOOL
APIENTRY
DllMain(HANDLE hModule,
        DWORD dwReason,
        LPVOID lpReserved)
{
    PWSPROCESS WsProcess;

    /* Main Entrypoint */
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            /* Save DLL Handle */
            WsDllHandle = hModule;

            /* Get Global Heap */
            WsSockHeap = GetProcessHeap();

            /* TLS Allocation */
            if (GlobalTlsIndex == TLS_OUT_OF_INDEXES)
            {
                GlobalTlsIndex = TlsAlloc();
                if (GlobalTlsIndex == TLS_OUT_OF_INDEXES)
                {
                    return FALSE;
                }
            }

            /* Initialize some critical sections */
            WsCreateStartupSynchronization();
            WsAsyncGlobalInitialize();
            WsRasInitializeAutodial();
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            /* Destroy the attached Winsock Thread */
            WsThreadDestroyCurrentThread();
            break;

        case DLL_PROCESS_DETACH:
            /* Make sure we were initialized */
            if (!WsDllHandle) break;

            /* Check if this was a FreeLibrary call (ie: not process cleanup) */
            if (lpReserved)
            {
                /* Destroy the thread which is exiting */
                WsThreadDestroyCurrentThread();

                /* Check if we have a process and destroy it */
                WsProcess = WsGetProcess();
                if (WsProcess) WsProcDelete(WsProcess);

                /* Cleanup the Thread and Socket managers */
                WsThreadCleanup();
                WsSockCleanup();

                /* Cleanup critical sections */
                WsDestroyStartupSynchronization();
                WsAsyncGlobalTerminate();

                /* Free the TLS Index */
                TlsFree(GlobalTlsIndex);
            }

            /* Cleanup RAS auto-dial helper */
            WsRasUninitializeAutodial();

            /* Clear our handle */
            WsDllHandle = NULL;
            break;
    }

    /* Return to OS */
    return TRUE;
}

/*
 * @implemented
 */
INT
WSAAPI
WSAGetLastError(VOID)
{
    /* Let the Windows Function do the work */
    return GetLastError();
}

/*
 * @implemented
 */
VOID
WSAAPI
WSASetLastError(IN INT iError)
{
    /* Let the Windows Function do the work */
    SetLastError(iError);
}

/*
 * @unimplemented
 */
PCSTR
WSAAPI
inet_ntop(INT Family,
          const VOID *pAddr,
          PSTR pStringBuf,
          size_t StringBufSize)
{
    UNIMPLEMENTED;
    return NULL;
}

/*
 * @unimplemented
 */
INT
WSAAPI
inet_pton(INT Family,
          PCSTR pszAddrString,
          PVOID pAddrBuf)
{
    UNIMPLEMENTED;
    return 1;
}

/*
 * @unimplemented
 */
PCWSTR
WSAAPI
InetNtopW(INT Family,
          const VOID *pAddr,
          PWSTR pStringBuf,
          size_t StringBufSize)
{
    UNIMPLEMENTED;
    return NULL;
}

/*
 * @unimplemented
 */
INT
WSAAPI
InetPtonW(INT Family,
          PCWSTR pszAddrString,
          PVOID pAddrBuf)
{
    UNIMPLEMENTED;
    return 1;
}

/*
 * @unimplemented
 */
int
WSAAPI
WSAPoll(PVOID fdArray, // LPWSAPOLLFD
        ULONG fds,
        INT timeout)
{
    UNIMPLEMENTED;
    return 0;
}

/*
 * @unimplemented
 */
int
WSAAPI
WSCGetProviderInfo(LPGUID lpProviderId,
                   PVOID InfoType, // WSC_PROVIDER_INFO_TYPE
                   PBYTE Info,
                   size_t *InfoSize,
                   DWORD Flags,
                   LPINT lpErrno)
{
    UNIMPLEMENTED;
    return ERROR_SUCCESS;
}
