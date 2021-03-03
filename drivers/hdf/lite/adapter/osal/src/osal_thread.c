#include "osal_thread.h"
#include "los_hwi.h"
#include "los_task.h"
#include "securec.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_thread
#define LOS_PRIORITY_WIN 3
#define OS_TASK_PRIORITY_LOWEST 31
#define OSAL_THREAD_NAME "hdf_thread"
#define OSAL_INVALID_THREAD_ID UINT32_MAX
int32_t OsalThreadCreate(struct OsalThread *thread, OsalThreadEntry threadEntry, void *entryPara)
{
    struct ThreadWrapper *para = NULL;

    if (thread == NULL || threadEntry == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    thread->realThread = NULL;
    para = OsalMemAlloc(sizeof(*para));
    if (para == NULL) {
        HDF_LOGE("%s malloc fail", __func__);
        return HDF_ERR_MALLOC_FAIL;
    }

    para->entryPara = entryPara;
    para->threadEntry = threadEntry;
    para->tid = OSAL_INVALID_THREAD_ID;
    thread->realThread = para;

    return HDF_SUCCESS;
}
int32_t OsalThreadDestroy(struct OsalThread *thread)
{
    uint32_t ret;
    bool flag = false;

    flag = OsalCheckPara(thread);
    if (flag == false) {
        HDF_LOGE("%s invalid parameter %d\n", __func__, __LINE__);
        return HDF_ERR_INVALID_PARAM;
    }

    ret = LOS_TaskDelete(((struct ThreadWrapper *)thread->realThread)->tid);
    if (ret != LOS_OK) {
        HDF_LOGE("%s failed %d %d\n", __func__, ret, __LINE__);
        return HDF_FAILURE;
    }

    OsalMemFree(thread->realThread);
    thread->realThread = NULL;

    return HDF_SUCCESS;
}
