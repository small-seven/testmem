#include "osal_mutex.h"
#include <errno.h>
#include <pthread.h>
#include "securec.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_mutex
#define HDF_NANO_UNITS 1000000000
int32_t OsalMutexDestroy(struct OsalMutex *mutex)
{
    int32_t ret;

    if (mutex == NULL || mutex->realMutex == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    ret = pthread_mutex_destroy((pthread_mutex_t *)mutex->realMutex);
    if (ret != 0) {
        HDF_LOGE("%s fail %d %d", __func__, ret, __LINE__);
        return HDF_FAILURE;
    }

    OsalMemFree(mutex->realMutex);
    mutex->realMutex = NULL;

    return HDF_SUCCESS;
}
