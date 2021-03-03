#include "os_adapter.h"
#include <mqueue.h>
#include <pthread.h>
#include <unistd.h>
int SemCreate(unsigned short count, unsigned long *semHandle)
{
    if (semHandle == NULL) {
        return -1;
    }

    (void)count;
    int ret = sem_init((sem_t *)semHandle, 1, 0);
    if (ret == 0) {
        return sem_post((sem_t *)semHandle);
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

    struct mq_attr newAttr = {0};
    newAttr.mq_flags = flags;
    newAttr.mq_maxmsg = len;
    newAttr.mq_msgsize = maxMsgSize;
    int mqd = mq_open(queueName, O_RDWR | O_CREAT, &newAttr);
    if (mqd < 0) {
        return -1;
    }

    *queueID = mqd;
    return 0;
}
