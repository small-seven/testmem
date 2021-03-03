#include "linux/workqueue.h"
#include "los_swtmr_pri.h"
#include "los_event.h"
#include "unistd.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define DELAY_TIME  10000
typedef BOOL (*OsSortLinkCond)(SWTMR_CTRL_S *swtmr, struct delayed_work *dwork);

/*
 * @ingroup workqueue
 * Obtain the first work in a workqueue.
 */
#define worklist_entry(ptr, type, member)  ((type *)((char *)(ptr)-((UINTPTR)&(((type*)0)->member))))

/*
 * @ingroup workqueue
 * Traverse a workqueue.
 */
#define LIST_FOR_WORK(pos, listObject, type, field)                   \
    for ((pos) = LOS_DL_LIST_ENTRY((listObject)->next, type, field);  \
         &(pos)->field != (listObject);                               \
         (pos) = LOS_DL_LIST_ENTRY((pos)->field.next, type, field))

#define LIST_FOR_WORK_DEL(pos, nextNode, listObject, type, field)         \
    for ((pos) = LOS_DL_LIST_ENTRY((listObject)->next, type, field),      \
         (nextNode) = LOS_DL_LIST_ENTRY((pos)->field.next, type, field);  \
         &(pos)->field != (listObject);                                   \
         (pos) = (nextNode), (nextNode) = LOS_DL_LIST_ENTRY((pos)->field.next, type, field))


void linux_init_delayed_work(struct delayed_work *dwork, work_func_t func)
{
    if ((dwork == NULL) || (func == NULL)) {
        return;
    }
struct workqueue_struct *__create_workqueue_key(char *name,
                                                int singleThread,
                                                int freezeable,
                                                int rt,
                                                struct lock_class_key *key,
                                                const char *lockName)
{
    struct workqueue_struct *wq = NULL;
    cpu_workqueue_struct *cwq   = NULL;
    UINT32 ret;
    (VOID)key;
    (VOID)lockName;

    if (name == NULL) {
        return NULL;
    }

    wq = (struct workqueue_struct *)LOS_MemAlloc(m_aucSysMem0, sizeof(struct workqueue_struct));
    if (wq == NULL) {
        return NULL;
    }

    wq->cpu_wq = (cpu_workqueue_struct *)LOS_MemAlloc(m_aucSysMem0, sizeof(cpu_workqueue_struct));
    if (wq->cpu_wq == NULL) {
        (VOID)LOS_MemFree(m_aucSysMem0, wq);
        return NULL;
    }

    wq->name = name;
    wq->singlethread = singleThread;
    wq->freezeable = freezeable;
    wq->rt = rt;
    wq->delayed_work_count = 0;
    INIT_LIST_HEAD(&wq->list);
    (VOID)LOS_EventInit(&wq->wq_event);

    if (singleThread) {
        cwq = InitCpuWorkqueue(wq, singleThread);
        ret = CreateWorkqueueThread(cwq, singleThread);
    } else {
        LOS_MemFree(m_aucSysMem0, wq->cpu_wq);
        LOS_MemFree(m_aucSysMem0, wq);
        return NULL;
    }

    if (ret) {
        destroy_workqueue(wq);
        wq = NULL;
    }

    return wq;
}
struct workqueue_struct *linux_create_singlethread_workqueue(char *name)
{
    return __create_workqueue_key(name, 1, 0, 0, NULL, NULL);
}
STATIC UINT32 CreateWorkqueueThread(cpu_workqueue_struct *cwq, INT32 cpu)
{
    struct workqueue_struct *wq = cwq->wq;
    TSK_INIT_PARAM_S taskInitParam = {0};
    UINT32 ret;
    (VOID)cpu;

    taskInitParam.pfnTaskEntry = (TSK_ENTRY_FUNC)WorkerThread;
    taskInitParam.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    taskInitParam.pcName       = wq->name;
    taskInitParam.usTaskPrio   = 1;
    taskInitParam.auwArgs[0]   = (UINTPTR)cwq;
    taskInitParam.uwResved     = LOS_TASK_STATUS_DETACHED;

    ret = LOS_TaskCreate(&cwq->wq->wq_id, &taskInitParam);
    if (ret != LOS_OK) {
        return LOS_NOK;
    }

    cwq->thread = (task_struct*)OS_TCB_FROM_TID(cwq->wq->wq_id);
    (VOID)LOS_TaskYield();

    return LOS_OK;
}
#ifdef WORKQUEUE_SUPPORT_PRIORITY
#else
#endif
#ifdef WORKQUEUE_SUPPORT_PRIORITY
#else
#endif
void linux_destroy_workqueue(struct workqueue_struct *wq)
{
    UINT32 intSave;
    if (wq == NULL) {
        return;
    }

    /* Drain it before proceeding with destruction */
    drain_workqueue(wq);

    (VOID)LOS_TaskDelete(wq->wq_id);

    LOS_SpinLockSave(&g_workqueueSpin, &intSave);
    wq->name = NULL;
    list_del_init(&wq->list);
    (VOID)LOS_EventDestroy(&(wq->wq_event));

    (VOID)LOS_MemFree(m_aucSysMem0, wq->cpu_wq);
    (VOID)LOS_MemFree(m_aucSysMem0, wq);
    LOS_SpinUnlockRestore(&g_workqueueSpin, intSave);
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif