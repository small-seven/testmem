#include "los_process_pri.h"
#include "los_task_pri.h"
#include "los_hw_pri.h"
#include "los_sys_pri.h"
#include "los_futex_pri.h"
#include "user_copy.h"
#include "time.h"
#ifdef LOSCFG_SECURITY_CAPABILITY
#include "capability_api.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#else
#endif
unsigned int SysCreateUserThread(const TSK_ENTRY_FUNC func, const UserTaskParam *userParam, bool joinable)
{
    TSK_INIT_PARAM_S param = { 0 };
    int ret;

    ret = LOS_ArchCopyFromUser(&(param.userParam), userParam, sizeof(UserTaskParam));
    if (ret != 0) {
        return OS_INVALID_VALUE;
    }

    param.pfnTaskEntry = func;
    if (joinable == TRUE) {
        param.uwResved = OS_TASK_FLAG_PTHREAD_JOIN;
    } else {
        param.uwResved = OS_TASK_FLAG_DETACHED;
    }

    return OsCreateUserTask(OS_INVALID_VALUE, &param);
}
int SysUserThreadDetach(unsigned int taskID)
{
    unsigned int intSave;
    LosTaskCB *taskCB = NULL;
    unsigned int ret;

    if (OS_TID_CHECK_INVALID(taskID)) {
        return EINVAL;
    }

    SCHEDULER_LOCK(intSave);
    taskCB = OS_TCB_FROM_TID(taskID);
    ret = OsUserTaskOperatePermissionsCheck(taskCB);
    if (ret != LOS_OK) {
        SCHEDULER_UNLOCK(intSave);
        return ret;
    }

    ret = OsTaskDeleteUnsafe(taskCB, OS_PRO_EXIT_OK, intSave);
    if (ret != LOS_OK) {
        return ESRCH;
    }

    return LOS_OK;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
