#include "task_manager.h"
#include <securec.h>
#include <log.h>
#include <ohos_errno.h>
#include "memory_adapter.h"
#include "time_adapter.h"
#include "queue_adapter.h"
#include "service_impl.h"
#include "message_inner.h"
#include "samgr_lite_inner.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
#define DONT_WAIT 0
TaskPool *SAMGR_CreateFixedTaskPool(const TaskConfig *config, const char *name, uint8 size)
{
    if (config == NULL || size == 0 || MAX_TASK_SIZE <= THREAD_Total()) {
        return NULL;
    }

    MQueueId queueId = (MQueueId)QUEUE_Create(name, sizeof(Exchange), config->queueSize);
    if (queueId == NULL) {
        HILOG_ERROR(HILOG_MODULE_SAMGR, "Create Queue<%s> size:%d failed!", name, config->queueSize);
        return NULL;
    }

    TaskPool *taskPool = (TaskPool *)SAMGR_Malloc(sizeof(TaskPool) + sizeof(ThreadId) * size);
    if (taskPool == NULL) {
        HILOG_ERROR(HILOG_MODULE_SAMGR, "Create TaskPool<%s> size:%d failed!", name, config->queueSize);
        QUEUE_Destroy(queueId);
        return NULL;
    }

    (void)memset_s(taskPool, sizeof(TaskPool) + sizeof(ThreadId) * size, 0,
                   sizeof(TaskPool) + sizeof(ThreadId) * size);
    taskPool->queueId = queueId;
    taskPool->stackSize = config->stackSize;
    taskPool->priority = (uint8)config->priority;
    taskPool->size = size;
    taskPool->top = 0;
    taskPool->ref = 1;
    return taskPool;
}
int32 SAMGR_ReleaseTaskPool(TaskPool *pool)
{
    if (pool == NULL) {
        return EC_INVALID;
    }

    pool->ref--;
    if (pool->ref == 0) {
        Exchange exchange = {0};
        exchange.type = MSG_EXIT;
        QUEUE_Put(pool->queueId, &exchange, 0, DONT_WAIT);
        SAMGR_Free(pool);
    }
    return EC_SUCCESS;
}
