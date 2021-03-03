#include "los_queue_pri.h"
#include "los_queue_debug_pri.h"
#include "los_task_pri.h"
#include "los_spinlock.h"
#include "los_mp.h"
#include "los_percpu_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
#if (LOSCFG_BASE_IPC_QUEUE == YES)
#if (LOSCFG_BASE_IPC_QUEUE_LIMIT <= 0)
#error "queue maxnum cannot be zero"
#endif /* LOSCFG_BASE_IPC_QUEUE_LIMIT <= 0 */
#endif /* (LOSCFG_BASE_IPC_QUEUE == YES) */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
