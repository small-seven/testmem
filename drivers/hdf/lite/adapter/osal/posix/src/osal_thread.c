#include "osal_thread.h"
#include <pthread.h>
#include "hdf_base.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define OSAL_PTHREAD_STACK_MIN 4096
#define HDF_LOG_TAG osal_thread
typedef void *(*posixEntry)(void *data);

struct ThreadWrapper {
    OsalThreadEntry threadEntry;
    void *entryPara;
    pthread_t id;
};
#ifdef _LINUX_USER_
#else
#endif
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
        return HDF_FAILURE;
    }

    para->entryPara = entryPara;
    para->threadEntry = threadEntry;
    thread->realThread = para;

    return HDF_SUCCESS;
}
int32_t OsalThreadDestroy(struct OsalThread *thread)
{
    if (thread->realThread != NULL) {
        OsalMemFree(thread->realThread);
        thread->realThread = NULL;
    }
    return HDF_SUCCESS;
}
static int OsalCreatePthread(pthread_t *threadId, pthread_attr_t *attribute, struct ThreadWrapper *para)
{
    int resultCode = pthread_create(threadId, attribute, (posixEntry)para->threadEntry, para->entryPara);
    if (resultCode != 0) {
        HDF_LOGE("pthread_create errorno: %d", resultCode);
        return resultCode;
    }
    resultCode = pthread_detach(*threadId);
    if (resultCode != 0) {
        HDF_LOGE("pthread_detach errorno: %d", resultCode);
        return resultCode;
    }
    resultCode = pthread_attr_destroy(attribute);
    if (resultCode != 0) {
        HDF_LOGE("pthread_attr_destroy errorno: %d", resultCode);
        return resultCode;
    }
    return 0;
}
