#include "los_config.h"
#include "string.h"
#include "stdio.h"
#include "los_oom.h"
#ifdef LOSCFG_COMPAT_LINUXKPI
#include "linux/workqueue.h"
#include "linux/module.h"
#endif
#include "los_sys.h"
#include "los_tick.h"
#include "los_task_pri.h"
#include "los_printf.h"
#include "los_swtmr.h"
#include "los_swtmr_pri.h"
#include "los_timeslice_pri.h"
#include "los_memory_pri.h"
#include "los_sem_pri.h"
#include "los_mux_pri.h"
#include "los_queue_pri.h"
#include "los_memstat_pri.h"
#include "los_hwi_pri.h"
#include "los_spinlock.h"
#include "los_mp.h"
#include "los_atomic.h"
#include "los_exc_pri.h"
#include "gic_common.h"
#include "los_vm_boot.h"
#ifdef LOSCFG_FS_VFS
#include "fs/fs.h"
#include "fs/fs_operation.h"
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#include "los_trace.h"
#endif
#ifdef LOSCFG_KERNEL_CPUP
#include "los_cpup_pri.h"
#endif
#ifdef LOSCFG_COMPAT_POSIX
#include "pprivate.h"
#endif
#ifdef LOSCFG_DRIVERS_HDF_PLATFORM_UART
#include "console.h"
#endif
#ifdef LOSCFG_KERNEL_TICKLESS
#include "los_tickless.h"
#endif
#ifdef LOSCFG_ARCH_CORTEX_M7
#include "los_exc_pri.h"
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#include "los_memrecord_pri.h"
#endif
#include "los_hw_tick_pri.h"
#include "los_hwi_pri.h"
#if defined(LOSCFG_HW_RANDOM_ENABLE) || defined (LOSCFG_DRIVERS_RANDOM)
#include "randomdev.h"
#include "yarrow.h"
#endif
#ifdef LOSCFG_SHELL_DMESG
#include "dmesg_pri.h"
#endif
#ifdef LOSCFG_SHELL_LK
#include "shell_pri.h"
#endif
#ifdef LOSCFG_KERNEL_PIPE
#include "pipe_common.h"
#endif
#include "los_process_pri.h"
#include "los_futex_pri.h"
#ifdef LOSCFG_KERNEL_VDSO
#include "los_vdso.h"
#endif
#if (LOSCFG_KERNEL_LITEIPC == YES)
#include "hm_liteipc.h"
#endif
#ifdef LOSCFG_DRIVERS_HIEVENT
#include "hievent_driver.h"
#endif
#if (LOSCFG_BASE_CORE_HILOG == YES)
#include "los_hilog.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_BASE_IPC_SEM == YES)
#endif
#if (LOSCFG_BASE_IPC_QUEUE == YES)
#endif
#ifdef LOSCFG_KERNEL_PIPE
#endif
#ifdef LOSCFG_DRIVERS_HIEVENT
#endif
#ifdef LOSCFG_COMPAT_BSD
#endif
#ifdef LOSCFG_SHELL_DMESG
#endif
#ifdef LOSCFG_SHELL_LK
#endif
#ifdef LOSCFG_EXC_INTERACTION
#ifdef LOSCFG_ARCH_CORTEX_M7
#else
#endif
#endif
#if (LOSCFG_PLATFORM_HWI == YES)
#endif
#ifdef LOSCFG_PLATFORM_UART_WITHOUT_VFS
#ifdef LOSCFG_DRIVERS
#endif
#ifdef LOSCFG_SHELL
#endif //LOSCFG_SHELL
#endif //LOSCFG_PLATFORM_UART_WITHOUT_VFS
#if ((LOSCFG_BASE_IPC_QUEUE == YES) || (LOSCFG_BASE_IPC_MUX == YES) || (LOSCFG_BASE_IPC_SEM == YES))
#endif
#ifdef LOSCFG_KERNEL_CPUP
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#endif
#ifdef LOSCFG_KERNEL_CPUP
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if defined(LOSCFG_HW_RANDOM_ENABLE) || defined (LOSCFG_DRIVERS_RANDOM)
#endif
#ifdef LOSCFG_COMPAT_BSD
#endif
#ifdef LOSCFG_KERNEL_PIPE
#endif
#if LOSCFG_DRIVERS_HIEVENT
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (LOSCFG_KERNEL_LITEIPC == YES)
#endif
#if (LOSCFG_BASE_CORE_HILOG == YES)
#endif
#ifdef LOSCFG_KERNEL_VDSO
#endif
STATIC UINT32 OsSystemInitTaskCreate(VOID)
{
    UINT32 taskID;
    TSK_INIT_PARAM_S sysTask;

    (VOID)memset_s(&sysTask, sizeof(TSK_INIT_PARAM_S), 0, sizeof(TSK_INIT_PARAM_S));
    sysTask.pfnTaskEntry = (TSK_ENTRY_FUNC)SystemInit;
    sysTask.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    sysTask.pcName = "SystemInit";
    sysTask.usTaskPrio = LOSCFG_BASE_CORE_TSK_DEFAULT_PRIO;
    sysTask.uwResved = LOS_TASK_STATUS_DETACHED;
#if (LOSCFG_KERNEL_SMP == YES)
    sysTask.usCpuAffiMask = CPUID_TO_AFFI_MASK(ArchCurrCpuid());
#endif
    return LOS_TaskCreate(&taskID, &sysTask);
}
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_FS_VFS
#endif
#ifdef LOSCFG_COMPAT_LINUXKPI
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_KERNEL_TICKLESS
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
