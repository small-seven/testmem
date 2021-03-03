#include "los_hwi.h"
#include "los_sr.h"
#if (LOSCFG_KERNEL_TICKLESS == YES)
#include "los_tickless_pri.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef __ICCARM__
#pragma location = ".data.vector"
#elif defined(__CC_ARM) || defined(__GNUC__)
#endif
#if (OS_HWI_WITH_ARG == YES)
#else
#endif
#if (LOSCFG_KERNEL_RUNSTOP == YES)
#endif
#if (LOSCFG_KERNEL_TICKLESS == YES)
#endif
#if (OS_HWI_WITH_ARG == YES)
#else
#endif
#if (__CORTEX_M >= 0x03U) /* only for Cortex-M3 and above */
#endif
LITE_OS_SEC_TEXT_INIT UINT32 LOS_HwiCreate(HWI_HANDLE_T hwiNum,
                                           HWI_PRIOR_T hwiPrio,
                                           HWI_MODE_T mode,
                                           HWI_PROC_FUNC handler,
                                           HWI_ARG_T arg)
{
    UINTPTR intSave;

    if (handler == NULL) {
        return OS_ERRNO_HWI_PROC_FUNC_NULL;
    }

    if (hwiNum >= OS_HWI_MAX_NUM) {
        return OS_ERRNO_HWI_NUM_INVALID;
    }

    if (g_hwiForm[hwiNum + OS_SYS_VECTOR_CNT] != (HWI_PROC_FUNC)OsHwiDefaultHandler) {
        return OS_ERRNO_HWI_ALREADY_CREATED;
    }

    if (hwiPrio > OS_HWI_PRIO_LOWEST) {
        return OS_ERRNO_HWI_PRIO_INVALID;
    }

    intSave = LOS_IntLock();
#if (OS_HWI_WITH_ARG == YES)
    OsSetVector(hwiNum, handler, arg);
#else
    OsSetVector(hwiNum, handler);
#endif
    NVIC_EnableIRQ((IRQn_Type)hwiNum);
    NVIC_SetPriority((IRQn_Type)hwiNum, hwiPrio);

    LOS_IntRestore(intSave);

    return LOS_OK;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
