#include <los_builddef.h>
#include "los_sr.h"
#include "los_task.inc"
#include "los_exc.h"
#include "securec.h"
#include <los_builddef.h>
#include "los_tick.ph"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#define OS_SYSTICK_CONTROL_REG    0xE000E010
#if(LOSCFG_BASE_CORE_TIMESLICE == YES)
#endif
#if (OS_SR_WAKEUP_INFO == YES)
#endif
#if (LOSCFG_BASE_CORE_TICK_HW_TIME == NO)
#else
#endif
#if (LOSCFG_BASE_CORE_TICK_HW_TIME == NO)
#else
#endif
#if(LOSCFG_BASE_CORE_TIMESLICE == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#endif
#ifdef CHIP_APOLLO
#else
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
