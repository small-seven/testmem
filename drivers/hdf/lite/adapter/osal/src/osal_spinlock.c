#include "osal_spinlock.h"
#include "linux/spinlock.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_spinlock
int32_t OsalSpinDestroy(OsalSpinlock *spinlock)
{
    if (spinlock == NULL || spinlock->realSpinlock == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    OsalMemFree(spinlock->realSpinlock);
    spinlock->realSpinlock = NULL;

    return HDF_SUCCESS;
}
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
