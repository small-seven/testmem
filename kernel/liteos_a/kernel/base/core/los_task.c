#include "los_task_pri.h"
#include "los_base_pri.h"
#include "los_priqueue_pri.h"
#include "los_sem_pri.h"
#include "los_event_pri.h"
#include "los_mux_pri.h"
#include "los_hw_pri.h"
#include "los_exc.h"
#include "los_memstat_pri.h"
#include "los_mp.h"
#include "los_spinlock.h"
#include "los_percpu_pri.h"
#include "los_process_pri.h"
#if (LOSCFG_KERNEL_TRACE == YES)
#include "los_trace.h"
#endif
#ifdef LOSCFG_KERNEL_TICKLESS
#include "los_tickless_pri.h"
#endif
#ifdef LOSCFG_KERNEL_CPUP
#include "los_cpup_pri.h"
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#include "los_swtmr_pri.h"
#endif
#ifdef LOSCFG_EXC_INTERACTION
#include "los_exc_interaction_pri.h"
#endif
#if (LOSCFG_KERNEL_LITEIPC == YES)
#include "hm_liteipc.h"
#endif
#include "user_copy.h"
#include "los_vm_syscall.h"
#ifdef LOSCFG_ENABLE_OOM_LOOP_TASK
#include "los_oom.h"
#endif
#include "los_vm_map.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_BASE_CORE_TSK_LIMIT <= 0)
#error "task maxnum cannot be zero"
#endif  /* LOSCFG_BASE_CORE_TSK_LIMIT <= 0 */
#define OS_CHECK_TASK_BLOCK (OS_TASK_STATUS_DELAY |    \
#if (LOSCFG_KERNEL_SMP_LOCKDEP == YES)
#endif
#ifdef LOSCFG_KERNEL_TICKLESS
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_LITEIPC == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_BASE_CORE_TSK_MONITOR == YES)
#endif
#if (LOSCFG_BASE_CORE_TSK_MONITOR == YES)
#endif /* LOSCFG_BASE_CORE_TSK_MONITOR == YES */
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#ifdef LOSCFG_EXC_INTERACTION
#endif
#if (LOSCFG_KERNEL_SMP_TASK_SYNC == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP_TASK_SYNC == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP_TASK_SYNC == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP_TASK_SYNC == YES)
#else
#endif
#ifdef LOSCFG_EXC_INTERACTION
#endif
#if (LOSCFG_KERNEL_LITEIPC == YES)
#endif
#if (LOSCFG_KERNEL_SMP_TASK_SYNC == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_LITEIPC == YES)
#endif
#if (LOSCFG_KERNEL_SMP_TASK_SYNC == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#define INVALID_CPU_AFFI_MASK   0
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef LOSCFG_ENABLE_OOM_LOOP_TASK
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
