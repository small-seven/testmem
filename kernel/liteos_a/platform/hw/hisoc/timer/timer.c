#include "los_timer_pri.h"
#include "los_tick_pri.h"
#include "los_sys_pri.h"
#include "los_hwi.h"
#include "hisoc/sys_ctrl.h"
#include "los_swtmr.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define TIMER_ENABLE_BIT           7
#define TIMER_COUNTING_MODE_BIT    6
#define TIMER_INTERRUPT_ENABLE_BIT 5
#define TIMER_FREQUENCY_DIV_BIT    3
#define TIMER_SIZE_SELECT_BIT      1
#define TIMER_ONESHOT_BIT          0
#define READ_TIMER (*(volatile UINT32 *)(TIMER_TICK_REG_BASE + TIMER_VALUE))
#define US_PER_MS  1000
#define MS_PER_S   1000
#ifdef LOSCFG_KERNEL_TICKLESS
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
