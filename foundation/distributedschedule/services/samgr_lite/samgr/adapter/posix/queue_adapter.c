#include "queue_adapter.h"
#include <ohos_errno.h>
#include <pthread.h>
#include "memory_adapter.h"
#include "lock_free_queue.h"
typedef struct LockFreeBlockQueue LockFreeBlockQueue;
struct LockFreeBlockQueue {
    pthread_mutex_t wMutex;
    pthread_mutex_t rMutex;
    pthread_cond_t cond;
    LockFreeQueue *queue;
};
MQueueId QUEUE_Create(const char *name, int size, int count)
{
    LockFreeBlockQueue *queue = (LockFreeBlockQueue *)SAMGR_Malloc(sizeof(LockFreeBlockQueue));
    if (queue == NULL) {
        return NULL;
    }
    queue->queue = LFQUE_Create(size, count);
    if (queue->queue == NULL) {
        SAMGR_Free(queue);
        return NULL;
    }
    pthread_mutex_init(&queue->wMutex, NULL);
    pthread_mutex_init(&queue->rMutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
    return (MQueueId)queue;
}
int QUEUE_Destroy(MQueueId queueId)
{
    if (queueId == NULL) {
        return EC_INVALID;
    }

    LockFreeBlockQueue *queue = (LockFreeBlockQueue *)queueId;
    pthread_mutex_destroy(&queue->wMutex);
    pthread_mutex_destroy(&queue->rMutex);
    pthread_cond_destroy(&queue->cond);
    SAMGR_Free(queue->queue);
    SAMGR_Free(queue);
    return EC_SUCCESS;
}