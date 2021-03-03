#include "pthread.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if defined POSIX_MUTEX_DEFAULT_INHERIT
#elif defined POSIX_MUTEX_DEFAULT_PROTECT
#else
#endif
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr)
{
    return LOS_MuxAttrDestroy(attr);
}
#if defined POSIX_MUTEX_DEFAULT_INHERIT
#elif defined POSIX_MUTEX_DEFAULT_PROTECT
#else
#endif
int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
    return LOS_MuxDestroy(mutex);
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
