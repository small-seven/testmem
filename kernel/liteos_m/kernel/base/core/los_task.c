#include "los_task_pri.h"
#include "string.h"
#include "securec.h"
#include "los_base_pri.h"
#include "los_memory_pri.h"
#include "los_memstat_pri.h"
#include "los_priqueue_pri.h"
#include "los_sem_pri.h"
#include "los_mux_pri.h"
#if (LOSCFG_PLATFORM_EXC == YES)
#include "los_exc_pri.h"
#endif
#if (LOSCFG_KERNEL_TICKLESS == YES)
#include "los_tickless_pri.h"
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#include "los_cpup_pri.h"
#endif
#include "los_hw.h"
#if (LOSCFG_KERNEL_TRACE == YES)
#include "los_trace.h"
#endif
#include "los_sleep.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define EVALUATE_L(NUMBER, VALUE)  \
#define EVALUATE_H(NUMBER, VALUE)  \
#define UWROLLNUMSUB(NUMBER1, NUMBER2)  \
#define UWROLLNUMADD(NUMBER1, NUMBER2)  \
#define UWROLLNUM(NUMBER) ((NUMBER) & 0x07ffffff)
#define UWSORTINDEX(NUMBER) ((NUMBER) >> 27)
#define UWROLLNUMDEC(NUMBER)  \
#define OS_CHECK_TASK_BLOCK                     (OS_TASK_STATUS_DELAY | \
#define OS_TASK_ID_CHECK(taskID)              LOS_ASSERT_COND(OS_TSK_GET_INDEX(taskID) < g_taskMaxNum)
#define OS_CHECK_TSK_PID_NOIDLE(taskID)       (OS_TSK_GET_INDEX(taskID) >= g_taskMaxNum)
#define OS_TASK_STACK_TOP_OFFSET                4
#if (LOSCFG_BASE_CORE_TSK_MONITOR == YES)
#endif /* LOSCFG_BASE_CORE_TSK_MONITOR == YES */
#if (LOSCFG_BASE_CORE_EXC_TSK_SWITCH == YES)
#endif
#if (LOSCFG_KERNEL_TICKLESS == YES)
#endif
#if (LOSCFG_KERNEL_TICKLESS == YES)
#endif
#if (LOSCFG_KERNEL_RUNSTOP == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif /* LOSCFG_BASE_CORE_CPUP */
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif /* LOSCFG_BASE_CORE_CPUP */
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_EXC_HRADWARE_STACK_PROTECTION == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif /* LOSCFG_BASE_CORE_CPUP */
#if (LOSCFG_EXC_HRADWARE_STACK_PROTECTION == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_PLATFORM_EXC == YES)
#endif
#if (LOSCFG_BASE_CORE_TSK_MONITOR == YES)
#if (LOSCFG_EXC_HRADWARE_STACK_PROTECTION == NO)
#endif
#if (LOSCFG_BASE_CORE_EXC_TSK_SWITCH == YES)
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif /* LOSCFG_BASE_CORE_CPUP */
#if (LOSCFG_BASE_CORE_EXC_TSK_SWITCH == YES)
#if (LOSCFG_PLATFORM_EXC == YES)
#endif
#endif
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_EXC_HRADWARE_STACK_PROTECTION == YES)
#endif
#if (LOSCFG_EXC_HRADWARE_STACK_PROTECTION == YES)
#endif
#if (LOSCFG_EXC_HRADWARE_STACK_PROTECTION == YES)
#endif
#if (LOSCFG_BASE_CORE_EXC_TSK_SWITCH == YES)
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
