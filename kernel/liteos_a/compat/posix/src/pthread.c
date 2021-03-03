#include "pprivate.h"
#include "pthread.h"
#include "sched.h"
#include "stdio.h"
#include "map_error.h"
#include "los_process_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_KERNEL_SMP == YES)
#endif
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*startRoutine)(void *), void *arg)
{
    pthread_attr_t userAttr;
    UINT32 ret;
    CHAR name[PTHREAD_DATA_NAME_MAX];
    STATIC UINT16 pthreadNumber = 1;
    TSK_INIT_PARAM_S taskInitParam = {0};
    UINT32 taskHandle;
    _pthread_data *self = pthread_get_self_data();

    if ((thread == NULL) || (startRoutine == NULL)) {
        return EINVAL;
    }

    SetPthreadAttr(self, attr, &userAttr);

    (VOID)memset_s(name, sizeof(name), 0, sizeof(name));
    (VOID)snprintf_s(name, sizeof(name), sizeof(name) - 1, "pth%02d", pthreadNumber);
    pthreadNumber++;

    taskInitParam.pcName       = name;
    taskInitParam.pfnTaskEntry = (TSK_ENTRY_FUNC)startRoutine;
    taskInitParam.auwArgs[0]   = (UINTPTR)arg;
    taskInitParam.usTaskPrio   = (UINT16)userAttr.schedparam.sched_priority;
    taskInitParam.uwStackSize  = userAttr.stacksize;
    if (OsProcessIsUserMode(OsCurrProcessGet())) {
        taskInitParam.processID = OsGetKernelInitProcessID();
    } else {
        taskInitParam.processID = OsCurrProcessGet()->processID;
    }
    if (userAttr.detachstate == PTHREAD_CREATE_DETACHED) {
        taskInitParam.uwResved = LOS_TASK_STATUS_DETACHED;
    } else {
        /* Set the pthread default joinable */
        taskInitParam.uwResved = 0;
    }

    PthreadReap();
    ret = LOS_TaskCreateOnly(&taskHandle, &taskInitParam);
    if (ret == LOS_OK) {
        *thread = (pthread_t)taskHandle;
        ret = InitPthreadData(*thread, &userAttr, name, PTHREAD_DATA_NAME_MAX);
        if (ret != LOS_OK) {
            goto ERROR_OUT_WITH_TASK;
        }
        (VOID)LOS_SetTaskScheduler(taskHandle, SCHED_RR, taskInitParam.usTaskPrio);
    }

    if (ret == LOS_OK) {
        return ENOERR;
    } else {
        goto ERROR_OUT;
    }

ERROR_OUT_WITH_TASK:
    (VOID)LOS_TaskDelete(taskHandle);
ERROR_OUT:
    *thread = (pthread_t)-1;

    return map_errno(ret);
}
int pthread_detach(pthread_t thread)
{
    int ret = 0;
    UINT32 intSave;

    _pthread_data *detached = NULL;

    if (pthread_mutex_lock(&g_pthreadsDataMutex) != ENOERR) {
        ret = ESRCH;
    }
    detached = pthread_get_data(thread);
    if (detached == NULL) {
        ret = ESRCH; /* No such thread */
    } else if (detached->state == PTHREAD_STATE_DETACHED) {
        ret = EINVAL; /* Already detached! */
    } else if (detached->state == PTHREAD_STATE_JOIN) {
        detached->state = PTHREAD_STATE_EXITED;
        g_pthreadsExited++;
    } else {
        /* Set state to detached and kick any joinees to make them return. */
        SCHEDULER_LOCK(intSave);
        if (!(detached->task->taskStatus & OS_TASK_STATUS_EXIT)) {
            ret = OsTaskSetDeatchUnsafe(detached->task);
            if (ret == ESRCH) {
                ret = LOS_OK;
            } else if (ret == LOS_OK) {
                detached->state = PTHREAD_STATE_DETACHED;
            }
        } else {
            detached->state = PTHREAD_STATE_EXITED;
            g_pthreadsExited++;
        }
        SCHEDULER_UNLOCK(intSave);
    }

    /* Dispose of any dead threads */
    PthreadReap();
    if (pthread_mutex_unlock(&g_pthreadsDataMutex) != ENOERR) {
        ret = ESRCH;
    }

    return ret;
}
int pthread_key_create(pthread_key_t *key, void (*destructor)(void *))
{
    (VOID)key;
    (VOID)destructor;
    PRINT_ERR("[%s] is not support.\n", __FUNCTION__);
    return 0;
}
void pthread_cleanup_push_inner(struct pthread_cleanup_buffer *buffer,
                                void (*routine)(void *), void *arg)
{
    (VOID)buffer;
    (VOID)routine;
    (VOID)arg;
    PRINT_ERR("[%s] is not support.\n", __FUNCTION__);
    return;
}
void pthread_cleanup_pop_inner(struct pthread_cleanup_buffer *buffer, int execute)
{
    (VOID)buffer;
    (VOID)execute;
    PRINT_ERR("[%s] is not support.\n", __FUNCTION__);
    return;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
