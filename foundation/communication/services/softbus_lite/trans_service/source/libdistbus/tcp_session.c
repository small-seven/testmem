#include "tcp_session.h"
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "os_adapter.h"
TcpSession *CreateTcpSession(void)
{
    TcpSession *tcpSession = (TcpSession *)malloc(sizeof(TcpSession));
    if (tcpSession == NULL) {
        return NULL;
    }
    if (strcpy_s(tcpSession->sessionName, NAME_LENGTH, "softbus_Lite_unknown") != 0) {
        SOFTBUS_PRINT("[TRANS] CreateTcpSession cpy busname fail\n");
        free(tcpSession);
        return NULL;
    }
    (void)memset_s(tcpSession->deviceId, MAX_DEV_ID_LEN, 0, MAX_DEV_ID_LEN);
    (void)memset_s(tcpSession->groupId, NAME_LENGTH, 0, NAME_LENGTH);
    (void)memset_s(tcpSession->sessionKey, SESSION_KEY_LENGTH, 0, SESSION_KEY_LENGTH);

    tcpSession->seqNum = 0;
    tcpSession->fd = -1;
    tcpSession->busVersion = 0;
    tcpSession->routeType = 0;
    tcpSession->isAccepted = false;
    tcpSession->uid = -1;
    tcpSession->pid = -1;
    tcpSession->seqNumList = malloc(sizeof(List));
    if (tcpSession->seqNumList == NULL) {
        free(tcpSession);
        return NULL;
    }
    ListInitHead(tcpSession->seqNumList);
    return tcpSession;
}
