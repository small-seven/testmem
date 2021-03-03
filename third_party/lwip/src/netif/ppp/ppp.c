#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#include "lwip/pbuf.h"
#include "lwip/stats.h"
#include "lwip/sys.h"
#include "lwip/tcpip.h"
#include "lwip/api.h"
#include "lwip/snmp.h"
#include "lwip/ip4.h" /* for ip4_input() */
#if PPP_IPV6_SUPPORT
#include "lwip/ip6.h" /* for ip6_input() */
#endif /* PPP_IPV6_SUPPORT */
#include "lwip/dns.h"
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/pppos.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/lcp.h"
#include "netif/ppp/magic.h"
#if PAP_SUPPORT
#include "netif/ppp/upap.h"
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#include "netif/ppp/chap-new.h"
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#include "netif/ppp/eap.h"
#endif /* EAP_SUPPORT */
#if CCP_SUPPORT
#include "netif/ppp/ccp.h"
#endif /* CCP_SUPPORT */
#if MPPE_SUPPORT
#include "netif/ppp/mppe.h"
#endif /* MPPE_SUPPORT */
#if ECP_SUPPORT
#include "netif/ppp/ecp.h"
#endif /* EAP_SUPPORT */
#if VJ_SUPPORT
#include "netif/ppp/vj.h"
#endif /* VJ_SUPPORT */
#if PPP_IPV4_SUPPORT
#include "netif/ppp/ipcp.h"
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#include "netif/ppp/ipv6cp.h"
#endif /* PPP_IPV6_SUPPORT */
#if PPPOS_SUPPORT
#endif
#if PPPOE_SUPPORT
#endif
#if PPPOL2TP_SUPPORT
#endif
#if LWIP_PPP_API && LWIP_MPU_COMPATIBLE
#endif
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if CBCP_SUPPORT
#endif /* CBCP_SUPPORT */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if CCP_SUPPORT
#endif /* CCP_SUPPORT */
#if ECP_SUPPORT
#endif /* ECP_SUPPORT */
#ifdef AT_CHANGE
#endif /* AT_CHANGE */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if PPP_AUTH_SUPPORT
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PPP_AUTH_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if PPP_NOTIFY_PHASE
#endif /* PPP_NOTIFY_PHASE */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if LWIP_NETIF_HOSTNAME
#endif /* LWIP_NETIF_HOSTNAME */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if CCP_SUPPORT
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#endif /* CCP_SUPPORT */
#if PPPOS_SUPPORT
#endif
#if PPPOE_SUPPORT
#endif
#if PPPOL2TP_SUPPORT
#endif
#if LWIP_PPP_API && LWIP_MPU_COMPATIBLE
#endif
#if PAP_SUPPORT
#if PPP_SERVER
#endif /* PPP_SERVER */
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if PPP_SERVER
#endif /* PPP_SERVER */
#endif /* CHAP_SUPPPORT */
#if EAP_SUPPORT
#if PPP_SERVER
#endif /* PPP_SERVER */
#endif /* EAP_SUPPORT */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if PPP_DEBUG && PPP_PROTOCOLNAME
#endif /* PPP_DEBUG && PPP_PROTOCOLNAME */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CCP_SUPPORT
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#endif /* CCP_SUPPORT */
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if 0   /* UNUSED
#endif /* UNUSED */
#if PPP_DEBUG
#if PPP_PROTOCOLNAME
#endif /* PPP_PROTOCOLNAME */
#endif /* PPP_DEBUG */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_NOTIFY_PHASE
#endif /* PPP_NOTIFY_PHASE */
#if PPP_IPV4_SUPPORT
#if 0 /* UNUSED - PROXY ARP */
#endif /* UNUSED - PROXY ARP */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if PPP_IPV6_SUPPORT
#endif /* PPP_IPV6_SUPPORT */
#if 0
#endif /* 0 */
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
#define IN6_LLADDR_FROM_EUI64(ip6, eui64) do {    \
#if PPP_IPV4_SUPPORT
#endif /* PPP_IPV4_SUPPORT */
#endif /* PPP_IPV6_SUPPORT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if CCP_SUPPORT
#if 0 /* unused */
#endif /* unused */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if 0 /* unused */
#endif /* unused */
#endif /* CCP_SUPPORT */
#if PPP_IDLETIMELIMIT
#endif /* PPP_IDLETIMELIMIT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if PPP_PROTOCOLNAME
#endif /* PPP_PROTOCOLNAME */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#endif /* PPP_SUPPORT */
