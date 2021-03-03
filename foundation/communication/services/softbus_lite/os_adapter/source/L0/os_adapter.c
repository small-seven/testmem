#include "os_adapter.h"
#include <los_queue.h>
#include <los_task.h>
#include "lwip/sockets.h"
int SemCreate(unsigned short count, unsigned long *semHandle)
{
    if (semHandle == NULL) {
        return -1;
    }
    int ret = LOS_SemCreate(count, (unsigned int*)semHandle);
    if (ret == 0) {
        return LOS_SemPost((unsigned int)*semHandle);
    }
    return ret;
}
int CreateMsgQue(const char *queueName,
    unsigned short len, unsigned int *queueID,
    unsigned int flags, unsigned short maxMsgSize)
{
    if (queueName == NULL || queueID == NULL) {
        return -1;
    }
    int ret = LOS_QueueCreate(queueName, len, queueID, flags, maxMsgSize);
    return ret;
}
