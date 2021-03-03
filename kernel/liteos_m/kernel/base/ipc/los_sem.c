#include "los_sem_pri.h"
#include "los_base_pri.h"
#include "los_err_pri.h"
#include "los_memory_pri.h"
#include "los_priqueue_pri.h"
#include "los_sys_pri.h"
#include "los_task_pri.h"
#if (LOSCFG_PLATFORM_EXC == YES)
#include "los_exc.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
#if (LOSCFG_BASE_IPC_SEM == YES)
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

    intSave = LOS_IntLock();

    if (LOS_ListEmpty(&g_unusedSemList)) {
        LOS_IntRestore(intSave);
        OS_GOTO_ERR_HANDLER(LOS_ERRNO_SEM_ALL_BUSY);
    }

    unusedSem = LOS_DL_LIST_FIRST(&(g_unusedSemList));
    LOS_ListDelete(unusedSem);
    semCreated = (GET_SEM_LIST(unusedSem));
    semCreated->semCount = count;
    semCreated->semStat = OS_SEM_USED;
    semCreated->maxSemCount = maxCount;
    LOS_ListInit(&semCreated->semList);
    *semHandle = (UINT32)semCreated->semID;
    LOS_IntRestore(intSave);
    return LOS_OK;

ERR_HANDLER:
    OS_RETURN_ERROR_P2(errLine, errNo);
}
LITE_OS_SEC_TEXT_INIT UINT32 LOS_SemCreate(UINT16 count, UINT32 *semHandle)
{
    return OsSemCreate(count, OS_SEM_COUNTING_MAX_COUNT, semHandle);
}
LITE_OS_SEC_TEXT_INIT UINT32 LOS_BinarySemCreate(UINT16 count, UINT32 *semHandle)
{
    return OsSemCreate(count, OS_SEM_BINARY_MAX_COUNT, semHandle);
}
#if (LOSCFG_PLATFORM_EXC == YES)
#endif
#if (LOSCFG_PLATFORM_EXC == YES)
#endif
#endif /* (LOSCFG_BASE_IPC_SEM == YES) */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
