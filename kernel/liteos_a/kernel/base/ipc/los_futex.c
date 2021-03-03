#include "los_futex_pri.h"
#include "los_process_pri.h"
#include "los_sys_pri.h"
#include "los_sched_pri.h"
#include "los_mp.h"
#include "los_exc.h"
#include "los_mux_pri.h"
#include "user_copy.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
#define OS_FUTEX_FROM_FUTEXLIST(ptr) LOS_DL_LIST_ENTRY(ptr, FutexNode, futexList)
#define OS_FUTEX_FROM_QUEUELIST(ptr) LOS_DL_LIST_ENTRY(ptr, FutexNode, queueList)
#define OS_FUTEX_KEY_BASE USER_ASPACE_BASE
#define OS_FUTEX_KEY_MAX (USER_ASPACE_BASE + USER_ASPACE_SIZE)
typedef struct {
    LosMux      listLock;
    LOS_DL_LIST lockList;
} FutexHash;
#define FUTEX_INDEX_MAX  128
#ifdef LOS_FUTEX_DEBUG
#endif
#ifdef LOS_FUTEX_DEBUG
#endif
#ifdef LOS_FUTEX_DEBUG
#endif
#ifdef LOS_FUTEX_DEBUG
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
