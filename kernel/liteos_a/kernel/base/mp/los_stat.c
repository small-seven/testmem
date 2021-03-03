#include "los_task_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_KERNEL_SCHED_STATISTICS == YES)
#define HIGHTASKPRI           16
#define NS_PER_MS             1000000
#define DECIMAL_TO_PERCENTAGE 100
typedef struct {
    UINT64      idleRuntime;
    UINT64      idleStarttime;
    UINT64      highTaskRuntime;
    UINT64      highTaskStarttime;
    UINT64      spinWaitRuntime;
    UINT64      sumPriority;
    UINT32      prioritySwitch;
    UINT32      highTaskSwitch;
    UINT32      contexSwitch;
    UINT32      hwiNum;
    UINT32      ipiIrqNum;
} MpStatPercpu;
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
