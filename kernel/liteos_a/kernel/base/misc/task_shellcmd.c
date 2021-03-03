#include "stdlib.h"
#include "los_config.h"
#include "los_exc.h"
#include "los_memstat_pri.h"
#include "los_sem_pri.h"
#include "los_seq_buf.h"
#include "los_task_pri.h"
#ifdef LOSCFG_SHELL
#include "shcmd.h"
#include "shell.h"
#endif
#ifdef LOSCFG_KERNEL_CPUP
#include "los_cpup_pri.h"
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#include "los_excinfo_pri.h"
#endif
#include "los_process_pri.h"
#include "los_vm_dump.h"
#ifdef LOSCFG_FS_VFS
#include "fs/fs.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
#define OS_PROCESS_MEM_INFO 0x2U
#define OS_PROCESS_INFO_LEN          (g_processMaxNum * (sizeof(LosProcessCB)))
#define OS_PROCESS_GROUP_INFO_LEN    (g_processMaxNum * sizeof(UINT32))
#define OS_PROCESS_UID_INFO_LEN      (g_processMaxNum * sizeof(UINT32))
#define OS_PROCESS_MEM_ALL_INFO_LEN  (g_processMaxNum * PROCESS_MEMINFO_LEN)
#ifdef LOSCFG_KERNEL_CPUP
#define OS_PROCESS_CPUP_INFO_LEN    (g_processMaxNum * sizeof(CPUP_INFO_S))
#define OS_PROCESS_CPUP_ALLINFO_LEN (OS_PROCESS_CPUP_INFO_LEN * 3)
#else
#define OS_PROCESS_CPUP_ALLINFO_LEN 0
#endif
#define OS_PROCESS_ALL_INFO_LEN (g_processMaxNum * (sizeof(LosProcessCB) + sizeof(UINT32)) + \
#ifdef LOSCFG_KERNEL_CPUP
#endif
#define OS_INVALID_SEM_ID         0xFFFFFFFF
#define OS_TASK_WATER_LINE_SIZE   (g_taskMaxNum * sizeof(UINT32))
#define OS_TASK_INFO_LEN          (g_taskMaxNum * sizeof(LosTaskCB))
#define OS_TASK_ALL_INFO_LEN      (g_taskMaxNum * (sizeof(LosTaskCB) + sizeof(UINT32)))
#ifdef LOSCFG_FS_VFS
#define PROCESS_INFO_SHOW(seqBuf, arg...) do {              \
#else
#define PROCESS_INFO_SHOW(seqBuf, arg...) PRINTK(arg)
#endif
#ifdef LOSCFG_KERNEL_CPUP
#endif /* LOSCFG_KERNEL_CPUP */
#ifdef LOSCFG_KERNEL_CPUP
#endif /* LOSCFG_KERNEL_CPUP */
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_KERNEL_CPUP
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif
#ifdef LOSCFG_SHELL
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
