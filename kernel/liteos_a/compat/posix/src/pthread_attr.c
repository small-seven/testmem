#include "pthread.h"
#include "pprivate.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_KERNEL_SMP == YES)
#endif
int pthread_attr_destroy(pthread_attr_t *attr)
{
    if (attr == NULL) {
        return EINVAL;
    }

    /* Nothing to do here... */
    return ENOERR;
}
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachState)
{
    if ((attr != NULL) && ((detachState == PTHREAD_CREATE_JOINABLE) || (detachState == PTHREAD_CREATE_DETACHED))) {
        attr->detachstate = (UINT32)detachState;
        return ENOERR;
    }

    return EINVAL;
}
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachState)
{
    if ((attr == NULL) || (detachState == NULL)) {
        return EINVAL;
    }

    *detachState = (int)attr->detachstate;

    return ENOERR;
}
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
