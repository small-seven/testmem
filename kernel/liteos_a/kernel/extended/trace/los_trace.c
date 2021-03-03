#include "los_trace_pri.h"
#include "securec.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_task_pri.h"
#include "los_memory.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#if (LOSCFG_KERNEL_TRACE == YES)
LITE_OS_SEC_BSS SPIN_LOCK_INIT(g_traceSpin);
#define TRACE_LOCK(state)       LOS_SpinLockSave(&g_traceSpin, &(state))
#define TRACE_UNLOCK(state)     LOS_SpinUnlockRestore(&g_traceSpin, (state))

STATIC SPIN_LOCK_S g_traceCpuSpin[LOSCFG_KERNEL_CORE_NUM];
#define TRACE_CPU_LOCK(state, cpuID)       LOS_SpinLockSave(&g_traceCpuSpin[(cpuID)], &(state))
#define TRACE_CPU_UNLOCK(state, cpuID)     LOS_SpinUnlockRestore(&g_traceCpuSpin[(cpuID)], (state))

STATIC TraceBuffer g_traceBuf[LOSCFG_KERNEL_CORE_NUM];
STATIC TraceHook *g_traceInfo[LOS_TRACE_TYPE_NUM];
STATIC UINT16 g_frameSize[LOS_TRACE_TYPE_NUM];

STATIC VOID OsTracePosAdj(UINT16 bufferSize)
{
    UINT32 cpu = ArchCurrCpuid();
    if ((g_traceBuf[cpu].tracePos == LOS_TRACE_BUFFER_SIZE) ||
        ((g_traceBuf[cpu].tracePos + bufferSize + LOS_TRACE_TAG_LENGTH) > LOS_TRACE_BUFFER_SIZE)) {
        /* When wrap happened, record the postion before wrap */
        g_traceBuf[cpu].traceWrapPos = g_traceBuf[cpu].tracePos;
        g_traceBuf[cpu].tracePos = 0;
    }
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
