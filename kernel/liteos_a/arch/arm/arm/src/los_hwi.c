#include "los_hwi.h"
#include "los_memory.h"
#include "los_tickless_pri.h"
#include "los_spinlock.h"
#ifdef LOSCFG_KERNEL_CPUP
#include "los_cpup_pri.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define HWI_LOCK(state)       LOS_SpinLockSave(&g_hwiSpin, &(state))
#define HWI_UNLOCK(state)     LOS_SpinUnlockRestore(&g_hwiSpin, (state))
typedef VOID (*HWI_PROC_FUNC0)(VOID);
typedef VOID (*HWI_PROC_FUNC2)(INT32, VOID *);
VOID OsInterrupt(UINT32 intNum)
{
    HwiHandleForm *hwiForm = NULL;
    UINT32 *intCnt = NULL;

    intCnt = &g_intCount[ArchCurrCpuid()];
    *intCnt = *intCnt + 1;

#ifdef LOSCFG_CPUP_INCLUDE_IRQ
    OsCpupIrqStart();
#endif

#ifdef LOSCFG_KERNEL_TICKLESS
    OsTicklessUpdate(intNum);
#endif
    hwiForm = (&g_hwiForm[intNum]);
#ifndef LOSCFG_NO_SHARED_IRQ
    while (hwiForm->pstNext != NULL) {
        hwiForm = hwiForm->pstNext;
#endif
        if (hwiForm->uwParam) {
            HWI_PROC_FUNC2 func = (HWI_PROC_FUNC2)hwiForm->pfnHook;
            if (func != NULL) {
                UINTPTR *param = (UINTPTR *)(hwiForm->uwParam);
                func((INT32)(*param), (VOID *)(*(param + 1)));
            }
#ifndef LOSCFG_NO_SHARED_IRQ
#endif
#ifdef LOSCFG_CPUP_INCLUDE_IRQ
#endif
#ifdef LOSCFG_NO_SHARED_IRQ
#else
STATIC UINT32 OsHwiCreateShared(HWI_HANDLE_T hwiNum, HWI_MODE_T hwiMode,
                                HWI_PROC_FUNC hwiHandler, const HwiIrqParam *irqParam)
{
    UINT32 intSave;
    HwiHandleForm *hwiFormNode = NULL;
    HwiHandleForm *hwiForm = NULL;
    HwiIrqParam *hwiParam = NULL;
    HWI_MODE_T modeResult = hwiMode & IRQF_SHARED;

    if (modeResult && ((irqParam == NULL) || (irqParam->pDevId == NULL))) {
        return OS_ERRNO_HWI_SHARED_ERROR;
    }

    HWI_LOCK(intSave);

    hwiForm = &g_hwiForm[hwiNum];
    if ((hwiForm->pstNext != NULL) && ((modeResult == 0) || (!(hwiForm->uwParam & IRQF_SHARED)))) {
        HWI_UNLOCK(intSave);
        return OS_ERRNO_HWI_SHARED_ERROR;
    }

    while (hwiForm->pstNext != NULL) {
        hwiForm = hwiForm->pstNext;
        hwiParam = (HwiIrqParam *)(hwiForm->uwParam);
        if (hwiParam->pDevId == irqParam->pDevId) {
            HWI_UNLOCK(intSave);
            return OS_ERRNO_HWI_ALREADY_CREATED;
        }
    }

    hwiFormNode = (HwiHandleForm *)LOS_MemAlloc(m_aucSysMem0, sizeof(HwiHandleForm));
    if (hwiFormNode == NULL) {
        HWI_UNLOCK(intSave);
        return OS_ERRNO_HWI_NO_MEMORY;
    }

    hwiFormNode->uwParam = OsHwiCpIrqParam(irqParam);
    if (hwiFormNode->uwParam == LOS_NOK) {
        HWI_UNLOCK(intSave);
        (VOID)LOS_MemFree(m_aucSysMem0, hwiFormNode);
        return OS_ERRNO_HWI_NO_MEMORY;
    }

    hwiFormNode->pfnHook = hwiHandler;
    hwiFormNode->pstNext = (struct tagHwiHandleForm *)NULL;
    hwiForm->pstNext = hwiFormNode;

    if ((irqParam != NULL) && (irqParam->pName != NULL)) {
        g_hwiFormName[hwiNum] = (CHAR *)irqParam->pName;
    }

    g_hwiForm[hwiNum].uwParam = modeResult;

    HWI_UNLOCK(intSave);
    return LOS_OK;
}
#endif
LITE_OS_SEC_TEXT_INIT UINT32 LOS_HwiCreate(HWI_HANDLE_T hwiNum,
                                           HWI_PRIOR_T hwiPrio,
                                           HWI_MODE_T hwiMode,
                                           HWI_PROC_FUNC hwiHandler,
                                           HwiIrqParam *irqParam)
{
    UINT32 ret;

    (VOID)hwiPrio;
    if (hwiHandler == NULL) {
        return OS_ERRNO_HWI_PROC_FUNC_NULL;
    }
    if ((hwiNum > OS_USER_HWI_MAX) || ((INT32)hwiNum < OS_USER_HWI_MIN)) {
        return OS_ERRNO_HWI_NUM_INVALID;
    }

#ifdef LOSCFG_NO_SHARED_IRQ
    ret = OsHwiCreateNoShared(hwiNum, hwiMode, hwiHandler, irqParam);
#else
    ret = OsHwiCreateShared(hwiNum, hwiMode, hwiHandler, irqParam);
#endif
    return ret;
}
#ifdef LOSCFG_NO_SHARED_IRQ
#else
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
