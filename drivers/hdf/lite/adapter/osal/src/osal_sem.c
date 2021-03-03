#include "osal_sem.h"
#include "los_hwi.h"
#include "los_sem.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "hdf_log.h"

#define HDF_LOG_TAG osal_sem
#define HDF_INVALID_SEM_ID UINT32_MAX

int32_t OsalSemInit(struct OsalSem *sem, uint32_t value)
{
    uint32_t semId;
    uint32_t ret;

    if (sem == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }
int32_t OsalSemDestroy(struct OsalSem *sem)
{
    uint32_t ret;

    if (sem == NULL || sem->realSemaphore == (void *)(uintptr_t)HDF_INVALID_SEM_ID) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    ret = LOS_SemDelete((uint32_t)(uintptr_t)sem->realSemaphore);
    if (ret != LOS_OK) {
        HDF_LOGE("%s LOS_SemDelete fail %d", __func__, ret);
        return HDF_FAILURE;
    }
    sem->realSemaphore = (void *)(uintptr_t)HDF_INVALID_SEM_ID;
    return HDF_SUCCESS;
}
