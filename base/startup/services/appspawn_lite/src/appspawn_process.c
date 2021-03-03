#define _GNU_SOURCE
#include "appspawn_process.h"
#include <errno.h>
#include <sys/prctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "appspawn_adapter.h"
#include "log.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#define DEFAULT_UMASK 022
#define CAP_NUM 2
#define ABILITY_EXE_FILE_FULL_PATH "/bin/abilityMain"
#define ABILITY_EXE_FILE_NAME "abilityMain"
#define ENV_TITLE "LD_LIBRARY_PATH="
#define UPPER_BOUND_GID   999
#define LOWER_BOUND_GID   100
#define GRP_NUM 2
#define DEVMGR_GRP 99
pid_t CreateProcess(const MessageSt* msgSt)
{
    char identityIDStr[MAX_IDENTITY_ID_LENGTH];
    char processNameStr[MAX_PROCESS_NAME_LENGTH];
    if (memset_s(identityIDStr, MAX_IDENTITY_ID_LENGTH, '\0', MAX_IDENTITY_ID_LENGTH) != EOK ||
        memset_s(processNameStr, MAX_PROCESS_NAME_LENGTH, '\0', MAX_PROCESS_NAME_LENGTH) != EOK) {
        HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] create service, memset_s failed.");
        return -1;
    }

    if (sprintf_s(identityIDStr, MAX_IDENTITY_ID_LENGTH, "%llu", msgSt->identityID) <= 0 ||
        sprintf_s(processNameStr, MAX_PROCESS_NAME_LENGTH, "%s", msgSt->bundleName) <= 0) {
        HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] sprintf_s failed. id %{public}llu, name %{public}s.",\
            msgSt->identityID, msgSt->bundleName);
        return -1;
    }

    char* envStr = GetEnvStrs(msgSt);
    if (envStr == NULL) {
        return -1;
    }

    // check if the exe file exists
    struct stat pathStat = {0};
    if (stat(ABILITY_EXE_FILE_FULL_PATH, &pathStat) != 0) {
        HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] stat %{public}s failed, err %{public}d.",\
            ABILITY_EXE_FILE_FULL_PATH, errno);
        free(envStr);
        return -1;
    }

    pid_t newPID = fork();
    if (newPID < 0) {
        HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] create process, fork failed! err %{public}d.", errno);
        free(envStr);
        return -1;
    }

    // in child process
    if (newPID == 0) {
        // set permissions
        if (SetPerms(msgSt->uID, msgSt->gID) != 0) {
            HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] process %{public}s exit!", processNameStr);
            _exit(0x7f); // 0x7f: user specified
        }

        char* argv[] = {ABILITY_EXE_FILE_NAME, identityIDStr, processNameStr, NULL};
        char* env[] = {envStr, NULL};
        if (execve(ABILITY_EXE_FILE_FULL_PATH, argv, env) != 0) {
            HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] execve %{public}s failed! err %{public}d.",\
                ABILITY_EXE_FILE_FULL_PATH, errno);
        }
        HILOG_ERROR(HILOG_MODULE_HIVIEW, "[appspawn] sub-process exit, pid %{public}d.", getpid());
        _exit(0x7f); // 0x7f: user specified
    }

    free(envStr);
    return newPID;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
