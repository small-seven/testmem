#include "lock_free_queue.h"
#include <ohos_errno.h>
#include <pthread.h>
#include <securec.h>
#include <memory_adapter.h>
LockFreeQueue *LFQUE_Create(int size, int count)
{
    if (size <= 0 || count <= 0) {
        return NULL;
    }

    int total = size * count + 1;
    if (total <= 0) {
        return NULL;
    }

    register LockFreeQueue *queue = (LockFreeQueue *)SAMGR_Malloc(sizeof(LockFreeQueue) + total);
    if (queue == NULL) {
        return NULL;
    }
    queue->write = 0;
    queue->read = 0;
    queue->itemSize = size;
    queue->totalSize = total;
    return queue;
}
