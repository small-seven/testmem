#include "los_tick_pri.h"
#include "los_base_pri.h"
#include "los_swtmr_pri.h"
#include "los_task_pri.h"
#include "los_timeslice_pri.h"
#if (LOSCFG_KERNEL_TICKLESS == YES)
#include "los_tickless_pri.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_BASE_CORE_TICK_HW_TIME == YES)
#endif
#if (LOSCFG_KERNEL_TICKLESS == YES)
#if (LOSCFG_BASE_CORE_TICK_HW_TIME == YES)
#endif
#if (LOSCFG_BASE_CORE_TIMESLICE == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#endif
#endif
#if (LOSCFG_KERNEL_TICKLESS == YES)
#endif
#if (LOSCFG_BASE_CORE_TICK_HW_TIME == YES)
#endif
#if (LOSCFG_BASE_CORE_TIMESLICE == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
