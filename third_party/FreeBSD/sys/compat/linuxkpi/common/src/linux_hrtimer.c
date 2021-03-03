#include "linux/hrtimer.h"
#include "los_task_pri.h"
#include "los_hwi.h"
#include "asm/hal_platform_ints.h"
#include "los_spinlock.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define US_PER_SECOND 1000000
STATIC struct hrtimer_list_node *HrtimerListNodeInit(union ktime time)
{
    struct hrtimer_list_node *hrtimer = (struct hrtimer_list_node *)LOS_MemAlloc(m_aucSysMem0,
                                                                                 sizeof(struct hrtimer_list_node));
    if (hrtimer == NULL) {
        return NULL;
    }
    hrtimer->_softexpires = time;
    hrtimer->set_time_reload = (UINT32)((time.tv.sec * US_PER_SECOND + time.tv.usec) * HRTIMER_PERUS);
    hrtimer->HandlerHead = NULL;
    hrtimer->pstNext = NULL;
    return hrtimer;
}
int linux_hrtimer_create(struct hrtimer *timer, union ktime time, Handler handler)
{
    UINT32 ret;

    if ((timer == NULL) || (handler == NULL)) {
        return -1;
    }

    ret = CheckTime(&time);
    if (ret != LOS_OK) {
        return -1;
    }

    timer->_softexpires.tv.sec = time.tv.sec;
    timer->_softexpires.tv.usec = time.tv.usec;
    timer->function = handler;

    return 0;
}
STATIC struct handler_list_node *HandleNodeInit(union ktime time, struct hrtimer *timer)
{
    struct handler_list_node *handler = NULL;
    handler = (struct handler_list_node *)LOS_MemAlloc(m_aucSysMem0, sizeof(struct handler_list_node));
    if (handler == NULL) {
        return NULL;
    }
    handler->_softexpires = time;
    handler->pfnHandler = timer->function;
    handler->pstNext = NULL;
    return handler;
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
