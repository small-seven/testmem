#include <los_config.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#ifdef LOSCFG_NET_LWIP_SACK
#include <lwip/sockets.h>
#if !LWIP_COMPAT_SOCKETS
#define CHECK_NULL_PTR(ptr) do { if (ptr == NULL) { set_errno(EFAULT); return -1; } } while (0)
#ifndef LWIP_INET_ADDR_FUNC
#endif
#ifndef LWIP_INET_ATON_FUNC
#endif
#ifndef LWIP_INET_NTOA_FUNC
#endif
#endif /* !LWIP_COMPAT_SOCKETS */
#endif /* LOSCFG_NET_LWIP_SACK */