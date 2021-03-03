#include "hdf_workqueue.h"
#include "linux/workqueue.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG hdf_workqueue
void HdfWorkDestroy(HdfWork *work)
{
    if (work == NULL || work->realWork == NULL) {
        HDF_LOGE("%s invalid para", __func__);
        return;
    }

    OsalMemFree(work->realWork);
    work->realWork = NULL;

    return;
}
void HdfDelayedWorkDestroy(HdfWork *work)
{
    if (work == NULL || work->realWork == NULL) {
        HDF_LOGE("%s invalid para", __func__);
        return;
    }

    return HdfWorkDestroy(work);
}
void HdfWorkQueueDestroy(HdfWorkQueue *queue)
{
    if (queue == NULL || queue->realWorkQueue == NULL) {
        HDF_LOGE("%s invalid para", __func__);
        return;
    }

    destroy_workqueue(queue->realWorkQueue);

    return;
}
