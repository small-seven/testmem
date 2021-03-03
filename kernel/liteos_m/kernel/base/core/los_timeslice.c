#include "los_sys_pri.h"
#include "los_task_pri.h"
#include "los_tick_pri.h"
#include "los_typedef_pri.h"
#include "los_typedef_pri.h"
#include "los_timeslice_pri.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#if (LOSCFG_BASE_CORE_TIMESLICE == YES)
LITE_OS_SEC_BSS OsTaskRobin g_taskTimeSlice;

/*****************************************************************************
 Function     : OsTimesliceInit
 Description  : Initialztion Timeslice
 Input        : None
 Output       : None
 Return       : None
 *****************************************************************************/
LITE_OS_SEC_TEXT_INIT VOID OsTimesliceInit(VOID)
{
    g_taskTimeSlice.task = (LosTaskCB *)NULL;
    g_taskTimeSlice.tout = LOSCFG_BASE_CORE_TIMESLICE_TIMEOUT;
}
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
