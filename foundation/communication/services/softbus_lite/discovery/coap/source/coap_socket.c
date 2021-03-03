#include "coap_socket.h"
#include "coap_adapter.h"
#include "nstackx_error.h"
#include "os_adapter.h"
#include "securec.h"
typedef void (*TaskHandle)(void *arg);
SocketInfo g_socket = {0};
#define COAP_DEFAULT_PRIO 11
int CoapCreateUdpServer(const struct sockaddr_in *sockAddr)
{
    if (sockAddr == NULL) {
        return NSTACKX_EINVAL;
    }

    struct sockaddr_in localAddr;
    socklen_t len = sizeof(localAddr);
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        return NSTACKX_OVERFLOW;
    }

    (void)memset_s(&localAddr, sizeof(localAddr), 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = sockAddr->sin_port;
    if (sockAddr->sin_addr.s_addr != 0) {
        localAddr.sin_addr.s_addr = sockAddr->sin_addr.s_addr;
    } else {
        localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    }

    if (bind(sockfd, (struct sockaddr *)&localAddr, len) == -1) {
        CloseSocket(&sockfd);
        return NSTACKX_EFAILED;
    }

    if (getsockname(sockfd, (struct sockaddr *)&localAddr, &len) == -1) {
        CloseSocket(&sockfd);
        return NSTACKX_EFAILED;
    }
    return sockfd;
}
void CoapDeinitSocket(void)
{
    CloseSocket(&g_serverFd);
    CloseSocket(&g_clientFd);
    SOFTBUS_PRINT("[DISCOVERY] DeinitCoapSocket:%d\n", g_serverFd);
    return;
}
