#include "string.h"
#include "securec.h"
#include "los_cpup_pri.h"
#include "los_task_pri.h"
#include "los_memory_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_BASE_CORE_CPUP == YES)
#define OS_THREAD_TYPE_TASK     0
#define OS_THREAD_TYPE_HWI      1
#define OS_CPUP_RECORD_PERIOD   (g_sysClock)
#endif /* LOSCFG_BASE_CORE_CPUP */
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
