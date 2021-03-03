#include "los_membox.h"
#include "los_hwi.h"
#include "los_spinlock.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_AARCH64
#define OS_MEMBOX_MAGIC 0xa55a5aa5a55a5aa5
#else
#define OS_MEMBOX_MAGIC 0xa55a5aa5
#endif
#define OS_MEMBOX_SET_MAGIC(addr) \
#define OS_MEMBOX_CHECK_MAGIC(addr) \
#define OS_MEMBOX_USER_ADDR(addr) \
#define OS_MEMBOX_NODE_ADDR(addr) \
#define MEMBOX_LOCK(state)       LOS_SpinLockSave(&g_memboxSpin, &(state))
#define MEMBOX_UNLOCK(state)     LOS_SpinUnlockRestore(&g_memboxSpin, (state))
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
