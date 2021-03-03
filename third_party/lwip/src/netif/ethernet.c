#include "lwip/opt.h"
#if LWIP_ARP || LWIP_ETHERNET
#include "netif/ethernet.h"
#include "lwip/def.h"
#include "lwip/stats.h"
#include "lwip/etharp.h"
#include "lwip/ip.h"
#include "lwip/snmp.h"
#include <string.h>
#include "netif/ppp/ppp_opts.h"
#if PPPOE_SUPPORT
#include "netif/ppp/pppoe.h"
#endif /* PPPOE_SUPPORT */
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#if LWIP_ARP || ETHARP_SUPPORT_VLAN || LWIP_IPV6
#endif /* LWIP_ARP || ETHARP_SUPPORT_VLAN */
#if ETHARP_SUPPORT_VLAN
#if defined(LWIP_HOOK_VLAN_CHECK) || defined(ETHARP_VLAN_CHECK) || defined(ETHARP_VLAN_CHECK_FN) /* if not, allow all VLANs */
#ifdef LWIP_HOOK_VLAN_CHECK
#elif defined(ETHARP_VLAN_CHECK_FN)
#elif defined(ETHARP_VLAN_CHECK)
#endif
#endif /* defined(LWIP_HOOK_VLAN_CHECK) || defined(ETHARP_VLAN_CHECK) || defined(ETHARP_VLAN_CHECK_FN) */
#endif /* ETHARP_SUPPORT_VLAN */
#if LWIP_ARP_FILTER_NETIF
#endif /* LWIP_ARP_FILTER_NETIF*/
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_ARP
#endif /* LWIP_IPV4 && LWIP_ARP */
#if PPPOE_SUPPORT
#endif /* PPPOE_SUPPORT */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#ifdef LWIP_HOOK_UNKNOWN_ETH_PROTOCOL
#endif
#if ETHARP_SUPPORT_VLAN && defined(LWIP_HOOK_VLAN_SET)
#endif /* ETHARP_SUPPORT_VLAN && defined(LWIP_HOOK_VLAN_SET) */
#endif /* LWIP_ARP || LWIP_ETHERNET */
