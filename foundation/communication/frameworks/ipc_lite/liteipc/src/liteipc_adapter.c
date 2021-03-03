#include "liteipc_adapter.h"
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <threads.h>
#include <time.h>
#include "liteipc.h"
#include "utils_list.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define ENABLE_IPC_CB_TIMER YES
typedef struct {
    bool usedFlag;
    IpcMsgHandler hdler;
    void* arg;
} IpcMsgHandlerPair;
typedef struct {
    UTILS_DL_LIST list;
    uint32_t handle;
    IpcMsgHandlerPair hdlerPairs[MAX_DEATHCB_PER_SVC];
    size_t size;
    bool isCallbackRuning;
} Testament;
typedef struct {
    UTILS_DL_LIST list;
    uint32_t token;
    IpcMsgHandlerPair hdlerPair;
#if (ENABLE_IPC_CB_TIMER == YES)
    uint32_t mode;
    uint32_t timeout;
    timer_t timerId;
#endif
} AnonymousApi;
typedef void (*TimerHandler)(int);

typedef struct {
    pthread_mutex_t mutex;
    int32_t handleId;
    bool threadWorking;
    UTILS_DL_LIST apis;
    UTILS_DL_LIST testaments;
} IpcCallckCb;
#define DEATH_HANDLE UINT32_MAX
#define MAX_ERR_STR 60
#define NS_PER_MS  1000000ULL
#define NS_PER_SEC 1000000000ULL
#define LOG(level, format, ...)                      \
#define LOG_ERRNO(format, ...)                       \
#define RETURN_IF_IPC_IOCTL_FAILED(retVal)             \
int32_t FreeBuffer(const IpcContext* con, void* ptr)
{
    IpcContext context;
    int32_t ret;

    if (ptr == NULL) {
        LOG(ERROR, "Invalid parameter, null pointer.");
        return LITEIPC_EINVAL;
    }

    ret = GetLiteIpcContext(0, &context);
    if (ret != LITEIPC_OK) {
        LOG(ERROR, "GetLiteIpcContext failed.");
        return ret;
    }

    IpcContent content = {
        .flag = BUFF_FREE,
        .buffToFree = (IpcMsg*)ptr
    };
    ret = ioctl(context.fd, IPC_SEND_RECV_MSG, &content);
    RETURN_IF_IPC_IOCTL_FAILED(LITEIPC_EBADF);

    return ret;
}
typedef struct {
    uint32_t num;
    void* msg;
    IpcIo io;
    IpcMsgHandlerPair* cbs;
} HdlerArg;
#if (ENABLE_IPC_CB_TIMER == YES)
#endif
#if (ENABLE_IPC_CB_TIMER == YES)
#endif
#if (ENABLE_IPC_CB_TIMER == YES)
#endif
#if (ENABLE_IPC_CB_TIMER == YES)
#endif
#if (ENABLE_IPC_CB_TIMER == YES)
#endif
#if (ENABLE_IPC_CB_TIMER == YES)
#endif
static void RemoveDeathCallback(uint32_t handle)
{
    Testament* node = NULL;
    Testament* next = NULL;

    if (pthread_mutex_lock(&g_ipcCallbackCb.mutex) != 0) {
        LOG_ERRNO("Get callback mutex failed.");
        return;
    }
    UTILS_DL_LIST_FOR_EACH_ENTRY_SAFE(node, next, &g_ipcCallbackCb.testaments, Testament, list)
    {
        if (node->handle == handle) {
            UtilsListDelete(&node->list);
            free(node);
            break;
        }
    }
    pthread_mutex_unlock(&g_ipcCallbackCb.mutex);
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
