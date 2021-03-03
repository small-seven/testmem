#include "los_swtmr_pri.h"
#include "los_sortlink_pri.h"
#include "los_queue_pri.h"
#include "los_task_pri.h"
#include "los_process_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#if (LOSCFG_BASE_CORE_SWTMR_LIMIT <= 0)
#error "swtmr maxnum cannot be zero"
#endif /* LOSCFG_BASE_CORE_SWTMR_LIMIT <= 0 */
#define SWTMR_LOCK(state)       LOS_SpinLockSave(&g_swtmrSpin, &(state))
#define SWTMR_UNLOCK(state)     LOS_SpinUnlockRestore(&g_swtmrSpin, (state))
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#endif /* (LOSCFG_BASE_CORE_SWTMR == YES) */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
