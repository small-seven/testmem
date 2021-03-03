#include "los_base.h"
#ifdef LOSCFG_LIB_LIBC
#include "stdlib.h"
#include "unistd.h"
#endif
#include "los_hwi.h"
#include "los_memory_pri.h"
#include "uart.h"
#ifdef LOSCFG_FS_VFS
#include "console.h"
#endif
#ifdef LOSCFG_SHELL_DMESG
#include "dmesg_pri.h"
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#include "los_excinfo_pri.h"
#endif
#include "los_exc_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define SIZEBUF  256
#ifdef LOSCFG_SHELL_DMESG
#else
#endif
#ifdef LOSCFG_PLATFORM_CONSOLE
#endif
STATIC VOID OsVprintfFree(CHAR *buf, UINT32 bufLen)
{
    if (bufLen != SIZEBUF) {
        (VOID)LOS_MemFree(m_aucSysMem0, buf);
    }
}
#ifdef LOSCFG_SHELL_DMESG
#endif
#ifdef LOSCFG_PLATFORM_UART_WITHOUT_VFS
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifndef LOSCFG_SHELL_LK
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
