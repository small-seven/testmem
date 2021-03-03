#include "shmsg.h"
#include "shell_pri.h"
#include "shcmd.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "securec.h"
#include "los_base.h"
#include "los_task.h"
#include "los_event.h"
#include "los_list.h"
#include "los_printf.h"
#include "hisoc/uart.h"
#ifdef LOSCFG_FS_VFS
#include "console.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_FS_VFS
#ifdef LOSCFG_PLATFORM_CONSOLE
#endif
#ifdef LOSCFG_PLATFORM_CONSOLE
#endif
#endif
#define SERIAL_SHELL_TASK_NAME "SerialShellTask"
#define SERIAL_ENTRY_TASK_NAME "SerialEntryTask"
#define TELNET_SHELL_TASK_NAME "TelnetShellTask"
#define TELNET_ENTRY_TASK_NAME "TelnetEntryTask"
#ifdef LOSCFG_PLATFORM_CONSOLE
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
