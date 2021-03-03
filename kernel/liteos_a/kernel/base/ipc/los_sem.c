#include "los_sem_pri.h"
#include "los_sem_debug_pri.h"
#include "los_err_pri.h"
#include "los_task_pri.h"
#include "los_exc.h"
#include "los_spinlock.h"
#include "los_mp.h"
#include "los_percpu_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
#if (LOSCFG_BASE_IPC_SEM == YES)
#if (LOSCFG_BASE_IPC_SEM_LIMIT <= 0)
#error "sem maxnum cannot be zero"
#endif /* LOSCFG_BASE_IPC_SEM_LIMIT <= 0 */
LITE_OS_SEC_TEXT_INIT UINT32 OsSemCreate(UINT16 count, UINT16 maxCount, UINT32 *semHandle)
{
    UINT32 intSave;
    LosSemCB *semCreated = NULL;
    LOS_DL_LIST *unusedSem = NULL;
    UINT32 errNo;
    UINT32 errLine;

    if (semHandle == NULL) {
        return LOS_ERRNO_SEM_PTR_NULL;
    }

    if (count > maxCount) {
        OS_GOTO_ERR_HANDLER(LOS_ERRNO_SEM_OVERFLOW);
    }

    SCHEDULER_LOCK(intSave);

    if (LOS_ListEmpty(&g_unusedSemList)) {
        SCHEDULER_UNLOCK(intSave);
        OsSemInfoGetFullDataHook();
        OS_GOTO_ERR_HANDLER(LOS_ERRNO_SEM_ALL_BUSY);
    }

    unusedSem = LOS_DL_LIST_FIRST(&g_unusedSemList);
    LOS_ListDelete(unusedSem);
    semCreated = GET_SEM_LIST(unusedSem);
    semCreated->semCount = count;
    semCreated->semStat = OS_SEM_USED;
    semCreated->maxSemCount = maxCount;
    LOS_ListInit(&semCreated->semList);
    *semHandle = semCreated->semID;

    OsSemDbgUpdateHook(semCreated->semID, OsCurrTaskGet()->taskEntry, count);

    SCHEDULER_UNLOCK(intSave);
    return LOS_OK;

ERR_HANDLER:
    OS_RETURN_ERROR_P2(errLine, errNo);
}
LITE_OS_SEC_TEXT_INIT UINT32 LOS_SemCreate(UINT16 count, UINT32 *semHandle)
{
    return OsSemCreate(count, OS_SEM_COUNT_MAX, semHandle);
}
LITE_OS_SEC_TEXT_INIT UINT32 LOS_BinarySemCreate(UINT16 count, UINT32 *semHandle)
{
    return OsSemCreate(count, OS_SEM_BINARY_COUNT_MAX, semHandle);
}
#endif /* (LOSCFG_BASE_IPC_SEM == YES) */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
