#include "semaphore.h"
#include "sys/types.h"
#include "map_error.h"
#include "time_posix.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
int sem_destroy(sem_t *sem)
{
    UINT32 ret;

    if ((sem == NULL) || (sem->sem == NULL)) {
        errno = EINVAL;
        return -1;
    }

    ret = LOS_SemDelete(sem->sem->semID);
    if (map_errno(ret) != ENOERR) {
        return -1;
    }
    return 0;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
