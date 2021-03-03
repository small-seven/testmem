#include "telnet_loop.h"
#ifdef LOSCFG_NET_TELNET
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"
#include "netinet/tcp.h"
#include "sys/select.h"
#include "sys/types.h"
#include "sys/prctl.h"
#include "los_task.h"
#include "linux/atomic.h"
#include "lwip/sockets.h"
#include "lwip/inet.h"
#include "lwip/netif.h"
#include "console.h"
#ifdef LOSCFG_SHELL
#include "shell.h"
#include "shcmd.h"
#endif
#include "telnet_pri.h"
#include "telnet_dev.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define TELNET_SB   250 /* Indicates that what follows is subnegotiation of the indicated option */
#define TELNET_WILL 251 /* Indicates the desire to perform the indicated option */
#define TELNET_DO   253 /* Indicates the request for the other party to perform the indicated option */
#define TELNET_IAC  255 /* Interpret as Command */
#define TELNET_ECHO 1    /* Echo */
#define TELNET_SGA  3    /* Suppress Go Ahead */
#define TELNET_NAWS 31   /* Negotiate About Window Size */
#define TELNET_NOP  0xf1 /* Unassigned in IANA, putty use this to keepalive */
#define LEN_IAC_CMD      2 /* Only 2 char: |IAC|cmd| */
#define LEN_IAC_CMD_OPT  3 /* Only 3 char: |IAC|cmd|option| */
#define LEN_IAC_CMD_NAWS 9 /* NAWS: |IAC|SB|NAWS|x1|x2|x3|x4|IAC|SE| */
#define TELNET_TASK_STACK_SIZE  0x2000
#define TELNET_TASK_PRIORITY    9
#define TELNET_LISTEN_BACKLOG   128
#define TELNET_ACCEPT_INTERVAL  200
#define TELNET_CLIENT_POLL_TIMEOUT  2000
#define TELNET_CLIENT_READ_BUF_SIZE 256
#define TELNET_CLIENT_READ_FILTER_BUF_SIZE (8 * 1024)
STATIC VOID TelnetRelease(VOID)
{
    if (g_telnetClientFd >= 0) {
        (VOID)close(g_telnetClientFd);
        g_telnetClientFd = -1;
    }

    if (g_telnetListenFd >= 0) {
        (VOID)close(g_telnetListenFd);
        g_telnetListenFd = -1;
    }
}
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL_CMD_DEBUG */
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
