#include "los_base.h"
#include "los_spinlock.h"
#include "los_task_pri.h"
#include "los_printf_pri.h"
#include "los_atomic.h"
#include "los_exc.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_KERNEL_SMP_LOCKDEP == YES)
#define LOCKDEP_GET_NAME(lockDep, index)    (((SPIN_LOCK_S *)((lockDep)->heldLocks[(index)].lockPtr))->name)
#define LOCKDEP_GET_ADDR(lockDep, index)    ((lockDep)->heldLocks[(index)].lockAddr)
STATIC INLINE VOID OsLockDepRelease(UINT32 intSave)
{
    LOS_AtomicSet(&g_lockdepAvailable, 1);
    LOS_IntRestore(intSave);
}
#endif /* LOSCFG_KERNEL_SMP_LOCKDEP */
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
