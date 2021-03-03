#include "pprivate.h"
#include "pthread.h"
#include "stdlib.h"
#include "time_posix.h"
#include "los_atomic.h"
#include "los_event_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define BROADCAST_EVENT     1
#define COND_COUNTER_STEP   0x0004U
#define COND_FLAGS_MASK     0x0003U
#define COND_COUNTER_MASK   (~COND_FLAGS_MASK)
int pthread_condattr_destroy(pthread_condattr_t *attr)
{
    if (attr == NULL) {
        return EINVAL;
    }

    return 0;
}
int pthread_cond_destroy(pthread_cond_t *cond)
{
    if (cond == NULL) {
        return EINVAL;
    }

    if (CondInitCheck(cond)) {
        return ENOERR;
    }

    if (LOS_EventDestroy(&cond->event) != LOS_OK) {
        return EBUSY;
    }
    if (pthread_mutex_destroy(cond->mutex) != ENOERR) {
        PRINT_ERR("%s mutex destroy fail!\n", __FUNCTION__);
        return EINVAL;
    }
    free(cond->mutex);
    cond->mutex = NULL;
    return ENOERR;
}
#ifndef LOSCFG_ARCH_CORTEX_M7
#else
#endif
#ifndef LOSCFG_ARCH_CORTEX_M7
#else
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */