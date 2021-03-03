#include "los_cpup_pri.h"
#include "los_process_pri.h"
#include "los_base.h"
#include "los_swtmr.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_KERNEL_CPUP
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#define OS_CPUP_UNUSED 0x0U
#define OS_CPUP_USED   0x1U
#define HIGH_BITS 32
#define CPUP_PRE_POS(pos) (((pos) == 0) ? (OS_CPUP_HISTORY_RECORD_NUM - 1) : ((pos) - 1))
#define CPUP_POST_POS(pos) (((pos) == (OS_CPUP_HISTORY_RECORD_NUM - 1)) ? 0 : ((pos) + 1))
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
STATIC VOID OsRemoveInterTimeFromPorcess(UINT32 runPID)
{
    UINT16 loop;
    UINT32 pid;

    for (loop = 0; loop < LOSCFG_KERNEL_CORE_NUM; loop++) {
        pid = OsCpuProcessIDGetUnsafe(loop);
        if (pid != runPID) {
            continue;
        }

        g_cpup[runPID].allTime -= timeInIrqPerProcessSwitch[loop];
        timeInIrqPerProcessSwitch[loop] = 0;
    }
}
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#endif /* LOSCFG_KERNEL_CPUP */
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
