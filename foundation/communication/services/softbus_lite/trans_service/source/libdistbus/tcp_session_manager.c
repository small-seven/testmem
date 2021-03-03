#include "tcp_session_manager.h"
#include <arpa/inet.h>
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#include <los_task.h>
#else
#include <pthread.h>
#include "pms_interface.h"
#include "pms_types.h"
#endif
#include <malloc.h>
#include <mbedtls/base64.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include "aes_gcm.h"
#include "auth_conn.h"
#include "auth_interface.h"
#include "bus_manager.h"
#include "cJSON.h"
#include "message.h"
#include "os_adapter.h"
#include "session.h"
#include "tcp_session.h"
#include "tcp_socket.h"
#include "trans_lock.h"
#include "wifi_auth_manager.h"
#define MAX_SESSION_NUM 3
#define MAX_SESSION_SERVER_NUM 8
#define MAX_SESSION_SUM_NUM (MAX_SESSION_NUM * MAX_SESSION_SERVER_NUM)
#define MODULE_SESSION 6
#define AUTH_PACKET_HEAD_SIZE 24
#define TRANS_PACKET_HEAD_SIZE 16
#define TRANS_SEQ_NUM_OFFSET 8
#define RECIVED_BUFF_SIZE 1024
#define LISTEN_BACKLOG 4
#define DEFAULT_SEQNUM 100
#define DEFAULT_TV_SEC 10
#define DEFAULT_TRANS_PORT 0
#define DEFAULT_API_VERSION 2
#define DEFAULT_LONG_LEN 8
#define SESSION_KEY_INDEX_SIZE 4
#define TRANS_FAILED    (-1)
#define DEFAULT_TIMEOUT 200
#define ONE_SEC 1000
#define SIZE_OF_INT         sizeof(int)
#define SIZE_OF_LONG_LONG   sizeof(long long)
#define SEND_BUFF_MAX_SIZE  (RECIVED_BUFF_SIZE - SESSION_KEY_INDEX_SIZE - TRANS_PACKET_HEAD_SIZE - OVERHEAD_LEN)
#define SOFTBUS_PERMISSION_NAME  "ohos.permission.DISTRIBUTED_DATASYNC"
typedef struct {
    char moduleName[NAME_LENGTH];
    char sessionName[NAME_LENGTH];
    struct ISessionListener *listener;
} SessionListenerMap;
typedef struct {
    bool asServer;
    int listenFd;
    bool isSelectLoopRunning;
    struct ISessionListener *callback_;
    TcpSession* sessionMap_[MAX_SESSION_SUM_NUM];
    SessionListenerMap* serverListenerMap[MAX_SESSION_SERVER_NUM];
} TcpSessionMgr;
static bool RemoveSession(TcpSessionMgr *tsm, int sessionId)
{
    if (tsm == NULL || sessionId < 0) {
        SOFTBUS_PRINT("[TRANS] RemoveSession invalid para\n");
        return false;
    }

    SessionSeqNumNode* node = NULL;
    List* pos = NULL;
    List* tmp = NULL;

    for (int i = 0; i < MAX_SESSION_SUM_NUM; i++) {
        if (tsm->sessionMap_[i] != NULL && tsm->sessionMap_[i]->fd == sessionId) {
            LIST_FOR_EACH_SAFE(pos, tmp, tsm->sessionMap_[i]->seqNumList) {
                node = (SessionSeqNumNode*)pos;
                if (node == NULL) {
                    continue;
                }
                free(node);
            }
            free(tsm->sessionMap_[i]->seqNumList);
            free(tsm->sessionMap_[i]);
            tsm->sessionMap_[i] = NULL;
            return true;
        }
    }

    return false;
}
static int RemoveExceptSessionFd(const TcpSessionMgr *tsm, fd_set *exceptfds)
{
    if (tsm == NULL || tsm->listenFd == -1 || exceptfds == NULL) {
        return TRANS_FAILED;
    }

    if (FD_ISSET(tsm->listenFd, exceptfds)) {
        return TRANS_FAILED;
    }

    if (GetTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }

    int result = TRANS_FAILED;
    for (int i = 0; i < MAX_SESSION_SUM_NUM; i++) {
        if ((tsm->sessionMap_[i]) == NULL) {
            continue;
        }

        int fd = tsm->sessionMap_[i]->fd;
        if (fd >= 0) {
            if (FD_ISSET(fd, exceptfds)) {
                result = 0;
                SOFTBUS_PRINT("Session is closed. %d\r\n", fd);
                CloseTransSession(fd);
            }
        }
    }

    if (ReleaseTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }

    return result;
}
static void FreeSessionRecvMem(char* recvDataBuf, TcpSession* session)
{
    if (recvDataBuf != NULL) {
        free(recvDataBuf);
    }
    if (session == NULL) {
        return;
    }

    CloseSession(session->fd);
    session->fd = -1;
}
static void FreeSessionMgr(void)
{
    free(g_sessionMgr);
    g_sessionMgr = NULL;
}
static int CreateSessionServerInner(const char* moduleName, const char* sessionName, struct ISessionListener *listener)
{
    if (g_sessionMgr == NULL || listener == NULL || sessionName == NULL || moduleName == NULL) {
        SOFTBUS_PRINT("[TRANS] CreateSessionServer invalid param\n");
        return TRANS_FAILED;
    }

    if (strlen(moduleName) >= NAME_LENGTH || strlen(sessionName) >= NAME_LENGTH) {
        SOFTBUS_PRINT("[TRANS] CreateSessionServerInner name length is too big\n");
        return TRANS_FAILED;
    }

    int findIndex = -1;
    for (int i = 0; i < MAX_SESSION_SERVER_NUM; i++) {
        if (g_sessionMgr->serverListenerMap[i] == NULL) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        return TRANS_FAILED;
    }

    if (findIndex >= 0 && findIndex < MAX_SESSION_SERVER_NUM) {
        g_sessionMgr->serverListenerMap[findIndex] = malloc(sizeof(SessionListenerMap));
        if (g_sessionMgr->serverListenerMap[findIndex] == NULL) {
            return TRANS_FAILED;
        }
        SessionListenerMap *listenerMap = g_sessionMgr->serverListenerMap[findIndex];
        if (strncpy_s(listenerMap->sessionName, NAME_LENGTH, sessionName, strlen(sessionName)) ||
            strncpy_s(listenerMap->moduleName, NAME_LENGTH, moduleName, strlen(moduleName))) {
            free(listenerMap);
            listenerMap = NULL;
            return TRANS_FAILED;
        }

        listenerMap->listener = listener;
    }

    return 0;
}
static int RemoveSessionServerInner(const char* moduleName, const char *sessionName)
{
    if (g_sessionMgr == NULL) {
        return TRANS_FAILED;
    }
    int removeFd = -1;
    for (int i = 0; i < MAX_SESSION_SUM_NUM; i++) {
        if (g_sessionMgr->sessionMap_[i] != NULL &&
            strcmp(g_sessionMgr->sessionMap_[i]->sessionName, sessionName) == 0) {
            removeFd = g_sessionMgr->sessionMap_[i]->fd;
            CloseTransSession(removeFd);
            free(g_sessionMgr->sessionMap_[i]);
            g_sessionMgr->sessionMap_[i] = NULL;
        }
    }
    for (int i = 0; i < MAX_SESSION_SERVER_NUM; i++) {
        SessionListenerMap *serverListener = g_sessionMgr->serverListenerMap[i];
        if (serverListener != NULL && (strcmp(serverListener->sessionName, sessionName) == 0) &&
            (strcmp(serverListener->moduleName, moduleName) == 0)) {
            if (serverListener->listener != NULL && serverListener->listener->onSessionClosed != NULL) {
                serverListener->listener->onSessionClosed(removeFd);
            }
            free(serverListener);
            serverListener = NULL;
            break;
        }
    }
    return 0;
}
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#define MIN_STACK_SIZE 0x8000
typedef void *(*Runnable)(void *argv);
typedef struct ThreadAttr ThreadAttr;
struct ThreadAttr {
    const char *name;   // name of the thread
    uint32_t stackSize;   // size of stack
    uint8_t priority;     // initial thread priority
    uint8_t reserved1;    // reserved1 (must be 0)
    uint16_t reserved2;   // reserved2 (must be 0)
};
typedef void *ThreadId;

ThreadId TcpCreate(Runnable run, void *argv, const ThreadAttr *attr)
{
    if (attr == NULL) {
        return NULL;
    }
#endif
int CreateTcpSessionMgr(bool asServer, const char* localIp)
{
    if (g_sessionMgr != NULL || localIp == NULL) {
        return TRANS_FAILED;
    }
    g_sessionMgr = malloc(sizeof(TcpSessionMgr));
    if (g_sessionMgr == NULL) {
        return TRANS_FAILED;
    }
    (void)memset_s(g_sessionMgr, sizeof(TcpSessionMgr), 0, sizeof(TcpSessionMgr));
    g_sessionMgr->asServer = asServer;
    g_sessionMgr->listenFd = -1;
    g_sessionMgr->isSelectLoopRunning = false;

    if (InitTcpMgrLock() != 0 || GetTcpMgrLock() != 0) {
        FreeSessionMgr();
        return TRANS_FAILED;
    }

    for (int i = 0; i < MAX_SESSION_SUM_NUM; i++) {
        g_sessionMgr->sessionMap_[i] = NULL;
    }

    for (int i = 0; i < MAX_SESSION_SERVER_NUM; i++) {
        g_sessionMgr->serverListenerMap[i] = NULL;
    }

    if (ReleaseTcpMgrLock() != 0) {
        FreeSessionMgr();
        return TRANS_FAILED;
    }

    int listenFd = OpenTcpServer(localIp, DEFAULT_TRANS_PORT);
    if (listenFd < 0) {
        SOFTBUS_PRINT("[TRANS] CreateTcpSessionMgr OpenTcpServer fail\n");
        FreeSessionMgr();
        return TRANS_FAILED;
    }
    int rc = listen(listenFd, LISTEN_BACKLOG);
    if (rc != 0) {
        SOFTBUS_PRINT("[TRANS] CreateTcpSessionMgr listen fail\n");
        CloseSession(listenFd);
        FreeSessionMgr();
        return TRANS_FAILED;
    }
    g_sessionMgr->listenFd = listenFd;

    signal(SIGPIPE, SIG_IGN);
    if (StartSelectLoop(g_sessionMgr) != 0) {
        SOFTBUS_PRINT("[TRANS] CreateTcpSessionMgr StartSelectLoop fail\n");
        CloseSession(listenFd);
        FreeSessionMgr();
        return TRANS_FAILED;
    }
    return GetSockPort(listenFd);
}
int RemoveTcpSessionMgr(void)
{
    if (g_sessionMgr == NULL) {
        return TRANS_FAILED;
    }
    if (GetTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }

    CloseAllSession(g_sessionMgr);
    CloseFd(g_sessionMgr->listenFd);
    g_sessionMgr->listenFd = -1;
    if (g_sessionMgr != NULL) {
        free(g_sessionMgr);
        g_sessionMgr = NULL;
    }

    if (ReleaseTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }
    return 0;
}
int CreateSessionServer(const char* moduleName, const char* sessionName, struct ISessionListener *listener)
{
    if (g_sessionMgr == NULL || moduleName == NULL || sessionName == NULL || listener == NULL) {
        return TRANS_FAILED;
    }

    if (SoftBusCheckPermission(SOFTBUS_PERMISSION_NAME) != 0) {
        return TRANS_FAILED;
    }

    if (GetTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }

    int ret = CreateSessionServerInner(moduleName, sessionName, listener);

    if (ReleaseTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }
    return ret;
}
int RemoveSessionServer(const char* moduleName, const char *sessionName)
{
    if (moduleName == NULL || sessionName == NULL) {
        SOFTBUS_PRINT("[TRANS] moduleName == NULL || sessionName == NULL\n");
        return TRANS_FAILED;
    }

    if (SoftBusCheckPermission(SOFTBUS_PERMISSION_NAME) != 0) {
        return TRANS_FAILED;
    }

    if (GetTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }

    int ret = RemoveSessionServerInner(moduleName, sessionName);

    if (ReleaseTcpMgrLock() != 0) {
        return TRANS_FAILED;
    }

    return ret;
}
