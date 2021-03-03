#include "los_sem_debug_pri.h"
#include "stdlib.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_task_pri.h"
#include "los_ipcdebug_pri.h"
#ifdef LOSCFG_SHELL
#include "shcmd.h"
#endif /* LOSCFG_SHELL */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define OS_ALL_SEM_MASK 0xffffffff

#if defined(LOSCFG_DEBUG_SEMAPHORE) || defined(LOSCFG_SHELL_CMD_DEBUG)
STATIC VOID OsSemPendedTaskNamePrint(LosSemCB *semNode)
{
    LosTaskCB *tskCB = NULL;
    CHAR *nameArr[LOSCFG_BASE_CORE_TSK_LIMIT] = {0};
#endif
#ifdef LOSCFG_DEBUG_SEMAPHORE
typedef struct {
    UINT16  origSemCount;   /* Number of orignal available semaphores */
    UINT64  lastAccessTime; /* The last operation time */
    TSK_ENTRY_FUNC creater; /* The task entry who created this sem */
} SemDebugCB;
#endif /* LOSCFG_DEBUG_SEMAPHORE */
#ifdef LOSCFG_SHELL_CMD_DEBUG
#ifdef LOSCFG_DEBUG_SEMAPHORE
#else
#endif
#ifdef LOSCFG_DEBUG_SEMAPHORE
#endif
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
