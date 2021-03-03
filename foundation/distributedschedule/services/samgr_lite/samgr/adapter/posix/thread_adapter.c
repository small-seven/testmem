#include "thread_adapter.h"
#include <pthread.h>
#include <unistd.h>
#include "common.h"
#include "memory_adapter.h"
#define PRI_BUTT 39
#define MIN_STACK_SIZE 0x8000
ThreadId THREAD_Create(Runnable run, void *argv, const ThreadAttr *attr)
{
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_attr_setstacksize(&threadAttr, (attr->stackSize | MIN_STACK_SIZE));
    pthread_attr_setinheritsched(&threadAttr, PTHREAD_EXPLICIT_SCHED);
#ifdef SAMGR_LINUX_ADAPTER
    struct sched_param sched = {attr->priority};
#else
    struct sched_param sched = {PRI_BUTT - attr->priority};
#endif
    pthread_attr_setschedpolicy(&threadAttr, SCHED_RR);
    pthread_attr_setschedparam(&threadAttr, &sched);
    pthread_key_create(&g_localKey, NULL);
    pthread_t threadId = 0;
    int errno = pthread_create(&threadId, &threadAttr, run, argv);
    if (errno != 0) {
        return NULL;
    }

    MUTEX_GlobalLock();
    g_threadCount++;
    MUTEX_GlobalUnlock();
    return (ThreadId)threadId;
}
