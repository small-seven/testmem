#include <lwip/sockets.h>
#include <lwip/priv/tcpip_priv.h>
#include <api_shell_fix.h>
#if LWIP_ENABLE_NET_CAPABILITY
#include "capability_type.h"
#include "capability_api.h"
#define BIND_SERVICE_CAP_MIN_PORT 1024
#endif
#define netif_find netifapi_netif_find_by_name
#define IOCTL_CMD_CASE_HANDLER() \
#ifdef lwip_socket
#undef lwip_socket
#endif
#define lwip_socket static lwip_socket2
#ifdef lwip_setsockopt
#undef lwip_setsockopt
#endif
#define lwip_setsockopt static lwip_setsockopt2
#ifdef lwip_bind
#undef lwip_bind
#endif
#define lwip_bind static lwip_bind2
#ifdef lwip_sendto
#undef lwip_sendto
#endif
#define lwip_sendto lwip_sendto2
#include "../api/sockets.c"
#undef lwip_socket
#undef lwip_setsockopt
#undef lwip_bind
#undef lwip_sendto
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL
#endif /* LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL */
#if !LWIP_COMPAT_SOCKETS
#define API_ALIAS(old, new) \
#endif /* !LWIP_COMPAT_SOCKETS */
#if LWIP_ENABLE_LOS_SHELL_CMD
#if LWIP_NETCONN_FULLDUPLEX
#endif
#endif
#define LWIP_IOCTL_ROUTE                1
#define LWIP_IOCTL_IF                   1
#define LWIP_NETIF_PROMISC              1
#define LWIP_NETIF_ETHTOOL              0
#define LWIP_IOCTL_IPV6DPCTD            0
#undef LWIP_IPV6_DUP_DETECT_ATTEMPTS
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   0
#ifndef SIOCSIPV6DAD
#define SIOCSIPV6DAD _IOW('z', 0, unsigned long) /* set DAD enable/disable on netif */
#endif
#ifndef SIOCGIPV6DAD
#define SIOCGIPV6DAD _IOR('z', 1, unsigned long) /* get DAD status on netif */
#endif
#ifndef SIOCSIPV6DPCTD
#define SIOCSIPV6DPCTD _IOW('z', 2, unsigned long)
#endif
#ifndef SIOCGIPV6DPCTD
#define SIOCGIPV6DPCTD _IOR('z', 3, unsigned long)
#endif
#ifndef SIOCETHTOOL
#define SIOCETHTOOL 0x8946
#endif
#if LWIP_NETIF_PROMISC
#define NETIF_FLAG_PROMISC 0x80U
#endif /* LWIP_NETIF_PROMISC */
#if LWIP_IOCTL_ROUTE
#include <net/route.h>
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#endif
#if LWIP_IOCTL_IF
#ifndef LWIP_IPV6_PREFIX_LEN
#define LWIP_IPV6_PREFIX_LEN 64
#endif
#ifndef LWIP_NETIF_IFINDEX_MAX_EX
#define LWIP_NETIF_IFINDEX_MAX_EX 255
#endif
#include "lwip/dhcp.h"
#include "lwip/dhcp6.h"
#include "lwip/prot/dhcp.h"
#include "lwip/prot/dhcp6.h"
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_HAVE_LOOPIF
#endif
#if LWIP_DHCP
#endif
#if LWIP_ARP
#endif /* LWIP_ARP */
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_HAVE_LOOPIF
#endif
#if LWIP_DHCP
#endif
#if LWIP_IPV4 && LWIP_ARP
#endif /* LWIP_IPV4 && LWIP_ARP */
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_HAVE_LOOPIF
#endif
#if LWIP_DHCP // LWIP_DHCP
#endif
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_HAVE_LOOPIF
#endif
#if LWIP_HAVE_LOOPIF
#endif /* LWIP_HAVE_LOOPIF */
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_HAVE_LOOPIF
#endif /* LWIP_HAVE_LOOPIF */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV6 && LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV6 && LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if LWIP_DHCP
#if !LWIP_DHCP_SUBSTITUTE
#endif
#endif
#if LWIP_NETIF_PROMISC
#endif /* LWIP_NETIF_PROMISC */
#if LWIP_IGMP || LWIP_IPV6_MLD
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IGMP && LWIP_IPV6_MLD
#endif /* LWIP_IGMP && LWIP_IPV6_MLD */
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#endif /* LWIP_IGMP || LWIP_IPV6_MLD */
#if LWIP_DHCP
#endif
#if LWIP_HAVE_LOOPIF
#endif
#if LWIP_NETIF_PROMISC
#endif /* LWIP_NETIF_PROMISC */
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#if LWIP_HAVE_LOOPIF
#endif
#endif /* LWIP_IOCTL_IF */
#if LWIP_NETIF_ETHTOOL
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#endif
#if LWIP_IPV6
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#endif
#if LWIP_IOCTL_IPV6DPCTD
#if LWIP_ENABLE_NET_CAPABILITY
#endif
#endif /* LWIP_IOCTL_IPV6DPCTD */
#endif
#if LWIP_NETIF_ETHTOOL
#endif
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS || LWIP_IOCTL_IPV6DPCTD || LWIP_IOCTL_IF || LWIP_NETIF_ETHTOOL
#endif
#if LWIP_IOCTL_ROUTE
#endif
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS || LWIP_IOCTL_IPV6DPCTD || LWIP_IOCTL_ROUTE || LWIP_IOCTL_IF
#endif
#if LWIP_IPV6
#if LWIP_IPV6_DUP_DETECT_ATTEMPTS
#endif /* LWIP_IPV6_DUP_DETECT_ATTEMPTS */
#if LWIP_IOCTL_IPV6DPCTD
#endif
#endif /* LWIP_IPV6 */
#if LWIP_IOCTL_ROUTE
#endif
#if LWIP_IOCTL_IF
#endif /* LWIP_IOCTL_IF */
#if LWIP_NETIF_ETHTOOL
#endif
#include "los_vm_map.h"
#include "user_copy.h"
