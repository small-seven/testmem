#include "osal_sem.h"
#include <errno.h>
#include <semaphore.h>
#include <time.h>
#include "securec.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_sem
#define HDF_NANO_UNITS 1000000000
int32_t OsalSemDestroy(struct OsalSem *sem)
{
    if (sem == NULL || sem->realSemaphore == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    int32_t ret = sem_destroy((sem_t *)sem->realSemaphore);
    if (ret != 0) {
        HDF_LOGE("sem_destroy fail errno:%d", errno);
        return HDF_FAILURE;
    }
    OsalMemFree(sem->realSemaphore);
    sem->realSemaphore = NULL;

    return HDF_SUCCESS;
}
