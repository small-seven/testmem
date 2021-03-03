#include "osal_timer.h"
#include "los_hwi.h"
#include "los_swtmr.h"
#include "los_swtmr_pri.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_timer
int32_t OsalTimerCreate(OsalTimer *timer, uint32_t interval, OsalTimerFunc func, uintptr_t arg)
{
    struct OsalLitetimer *liteTimer = NULL;

    if (func == NULL || timer == NULL || interval == 0) {
        HDF_LOGE("%s invalid para", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    timer->realTimer = NULL;

    liteTimer = (struct OsalLitetimer *)OsalMemCalloc(sizeof(*liteTimer));
    if (liteTimer == NULL) {
        HDF_LOGE("%s malloc fail", __func__);
        return HDF_ERR_MALLOC_FAIL;
    }
    liteTimer->timerID = MAX_INVALID_TIMER_VID;
    liteTimer->arg = arg;
    liteTimer->func = func;
    liteTimer->interval = interval;
    timer->realTimer = (void *)liteTimer;

    return HDF_SUCCESS;
}
