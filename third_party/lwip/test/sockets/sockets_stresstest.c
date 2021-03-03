#include "lwip/opt.h"
#include "sockets_stresstest.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/mem.h"
#include <stdio.h>
#include <string.h>
#if LWIP_SOCKET && LWIP_IPV4 /* this uses IPv4 loopback sockets, currently */
#ifndef TEST_SOCKETS_STRESS
#define TEST_SOCKETS_STRESS   LWIP_DBG_OFF
#endif
#define TEST_TIME_SECONDS     10
#define TEST_TXRX_BUFSIZE     (TCP_MSS * 2)
#define TEST_MAX_RXWAIT_MS    50
#define TEST_MAX_CONNECTIONS  50
#define TEST_SOCK_READABLE    0x01
#define TEST_SOCK_WRITABLE    0x02
#define TEST_SOCK_ERR         0x04
#define TEST_MODE_SELECT      0x01
#define TEST_MODE_POLL        0x02
#define TEST_MODE_NONBLOCKING 0x04
#define TEST_MODE_WAIT        0x08
#define TEST_MODE_RECVTIMEO   0x10
#define TEST_MODE_SLEEP       0x20
#if LWIP_SOCKET_SELECT
#endif
#if LWIP_SOCKET_POLL
#endif
#if LWIP_SO_RCVTIMEO
#if LWIP_SO_SNDRCVTIMEO_NONSTANDARD
#else
#endif
#endif
#if LWIP_SOCKET_SELECT
#endif
#if LWIP_SOCKET_POLL
#endif
#if LWIP_SO_RCVTIMEO
#endif
#if LWIP_SOCKET_SELECT
#endif
#if LWIP_SOCKET_POLL
#endif
#if LWIP_SO_RCVTIMEO
#endif
#if LWIP_NETCONN_FULLDUPLEX
#endif
#if LWIP_NETCONN_FULLDUPLEX
#endif
#if 1
#else
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif
#if LWIP_IPV6
#endif
#endif /* LWIP_SOCKET && LWIP_IPV4 */
