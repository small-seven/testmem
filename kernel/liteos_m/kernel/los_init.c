#include "los_sys.h"
#include "los_tick.h"
#include "los_task_pri.h"
#include "los_tick_pri.h"
#include "los_config.h"
#if (LOSCFG_KERNEL_RUNSTOP == YES)
#include "los_sr.h"
#endif
#if (LOSCFG_PLATFORM_EXC == YES)
#include "los_exc_pri.h"
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#include "los_trace.h"
#endif
#if (LOSCFG_KERNEL_CPPSUPPORT == YES)
#include "los_cppsupport.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#if (LOSCFG_PLATFORM_EXC == YES)
#endif
#define FPU_ENABLE ((3UL << 20) | (3UL << 22))
#if (LOSCFG_BASE_CORE_TICK_HW_TIME == NO)
#else
#endif
#if (LOSCFG_PLATFORM_HWI == YES)
#endif
#if (LOSCFG_PLATFORM_EXC == YES)
#endif
#if (LOSCFG_BASE_CORE_TSK_MONITOR == YES)
#endif
#if (LOSCFG_BASE_CORE_CPUP == YES)
#endif
#if (LOSCFG_BASE_IPC_SEM == YES)
#endif
#if (LOSCFG_BASE_IPC_MUX == YES)
#endif
#if (LOSCFG_BASE_IPC_QUEUE == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#endif
#if (LOSCFG_BASE_CORE_TIMESLICE == YES)
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (LOSCFG_KERNEL_CPPSUPPORT == YES)
#endif
#ifdef LOSCFG_TEST
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
