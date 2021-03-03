#include "mqueue.h"
#include "fcntl.h"
#include "pthread.h"
#include "map_error.h"
#include "time_posix.h"
#include "los_memory.h"
#include "los_vm_map.h"
#include "user_copy.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define FNONBLOCK   O_NONBLOCK
#define OS_MQ_GOTO_ERROUT_UNLOCK_IF(expr, errcode) \
#define OS_MQ_GOTO_ERROUT_IF(expr, errcode) \
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
