#include "osal_mutex.h"
#include "los_mux.h"
#include "los_sys.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_mutex
int32_t OsalMutexDestroy(struct OsalMutex *mutex)
{
    uint32_t ret;

    if (mutex == NULL || mutex->realMutex == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    ret = LOS_MuxDestroy((LosMux *)mutex->realMutex);
    if (ret != LOS_OK) {
        HDF_LOGE("%s fail %d %d", __func__, ret, __LINE__);
        return HDF_FAILURE;
    }

    OsalMemFree(mutex->realMutex);
    mutex->realMutex = NULL;
    return HDF_SUCCESS;
}
