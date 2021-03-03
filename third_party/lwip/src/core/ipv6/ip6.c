#include "lwip/opt.h"
#if LWIP_IPV6  /* don't build if not configured for use in lwipopts.h */
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/netif.h"
#include "lwip/ip.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/ip6_frag.h"
#include "lwip/icmp6.h"
#include "lwip/priv/raw_priv.h"
#include "lwip/udp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/dhcp6.h"
#include "lwip/nd6.h"
#include "lwip/mld6.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#if LWIP_SINGLE_NETIF
#else /* LWIP_SINGLE_NETIF */
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#if LWIP_IPV6_SCOPES
#else /* LWIP_IPV6_SCOPES */
#endif /* LWIP_IPV6_SCOPES */
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#ifdef LWIP_HOOK_IP6_ROUTE
#endif
#if LWIP_NETIF_LOOPBACK && !LWIP_HAVE_LOOPIF
#endif /* LWIP_NETIF_LOOPBACK && !LWIP_HAVE_LOOPIF */
#endif /* !LWIP_SINGLE_NETIF */
#if LWIP_IPV6_FORWARD
#if LWIP_ICMP6
#endif /* LWIP_ICMP6 */
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#if LWIP_ICMP6
#endif /* LWIP_ICMP6 */
#if LWIP_ICMP6
#endif /* LWIP_ICMP6 */
#endif /* LWIP_IPV6_FORWARD */
#if IPV6_CUSTOM_SCOPES
#endif /* IPV6_CUSTOM_SCOPES */
#if 0 /*IP_ACCEPT_LINK_LAYER_ADDRESSING*/
#endif /* IP_ACCEPT_LINK_LAYER_ADDRESSING */
#if LWIP_RAW
#endif /* LWIP_RAW */
#ifdef LWIP_HOOK_IP6_INPUT
#endif
#if LWIP_IPV6_MLD
#else /* LWIP_IPV6_MLD */
#endif /* LWIP_IPV6_MLD */
#if !IPV6_CUSTOM_SCOPES
#endif /* !IPV6_CUSTOM_SCOPES */
#if !LWIP_NETIF_LOOPBACK || LWIP_HAVE_LOOPIF
#endif /* !LWIP_NETIF_LOOPBACK || LWIP_HAVE_LOOPIF */
#if !LWIP_SINGLE_NETIF
#endif /* !LWIP_SINGLE_NETIF */
#if LWIP_IPV6_FORWARD
#endif /* LWIP_IPV6_FORWARD */
#if LWIP_IPV6_REASS
#else /* LWIP_IPV6_REASS */
#endif /* LWIP_IPV6_REASS */
#if LWIP_RAW
#else /* LWIP_RAW */
#endif /* LWIP_RAW */
#if LWIP_UDP
#if LWIP_UDPLITE
#endif /* LWIP_UDPLITE */
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_ICMP6
#endif /* LWIP_ICMP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_ICMP6
#endif /* LWIP_ICMP */
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#if ENABLE_LOOPBACK
#if !LWIP_HAVE_LOOPIF
#endif /* !LWIP_HAVE_LOOPIF */
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#endif /* ENABLE_LOOPBACK */
#if LWIP_IPV6_FRAG
#endif /* LWIP_IPV6_FRAG */
#if LWIP_NETIF_USE_HINTS
#endif /* LWIP_NETIF_USE_HINTS*/
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if IP6_DEBUG
#endif /* IP6_DEBUG */
#endif /* LWIP_IPV6 */
