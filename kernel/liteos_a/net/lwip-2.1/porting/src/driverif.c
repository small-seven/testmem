#include <lwip/sys.h>
#include <lwip/netif.h>
#include <lwip/snmp.h>
#include <lwip/etharp.h>
#include <lwip/sockets.h>
#include <lwip/snmp.h>
#include <lwip/etharp.h>
#include <lwip/ethip6.h>
#define LWIP_NETIF_HOSTNAME_DEFAULT         "default"
#define LINK_SPEED_OF_YOUR_NETIF_IN_BPS     100000000 // 100Mbps
#define link_rx_drop cachehit
#define link_rx_overrun cachehit
#define NETIF_NAME_LEN 2
#define LWIP_STATIC static
#ifndef LWIP_NETIF_IFINDEX_MAX_EX
#define LWIP_NETIF_IFINDEX_MAX_EX 255
#endif
#if PF_PKT_SUPPORT
#endif
#if ETH_PAD_SIZE
#endif
#if ETH_PAD_SIZE
#endif
#if PF_PKT_SUPPORT
#if  (DRIVERIF_DEBUG & LWIP_DBG_OFF)
#endif
#else
#endif
#if PF_PKT_SUPPORT
#if  (DRIVERIF_DEBUG & LWIP_DBG_OFF)
#endif
#else
#if ETHARP_SUPPORT_VLAN
#endif /* ETHARP_SUPPORT_VLAN */
#endif
#if LWIP_NETIF_PROMISC
#endif
#if LWIP_NETIF_HOSTNAME
#if LOSCFG_NET_LWIP_SACK_2_0
#else
#endif
#endif /* LWIP_NETIF_HOSTNAME */
#if LWIP_NETIF_HOSTNAME
#if LOSCFG_NET_LWIP_SACK_2_0
#else
#endif
#endif
#if DRIVER_STATUS_CHECK
#endif
#if LWIP_IGMP
#endif
#if LWIP_IPV6 && LWIP_IPV6_MLD
#if LWIP_MLD6_ENABLE_MLD_ON_DAD
#endif /* LWIP_MLD6_ENABLE_MLD_ON_DAD */
#endif
#if DRIVER_STATUS_CHECK
#endif /* DRIVER_STATUS_CHECK */
