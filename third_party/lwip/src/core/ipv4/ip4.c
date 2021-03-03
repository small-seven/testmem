#include "lwip/opt.h"
#if LWIP_IPV4
#include "lwip/ip.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/ip4_frag.h"
#include "lwip/inet_chksum.h"
#include "lwip/netif.h"
#include "lwip/icmp.h"
#include "lwip/igmp.h"
#include "lwip/priv/raw_priv.h"
#include "lwip/udp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/autoip.h"
#include "lwip/stats.h"
#include "lwip/prot/iana.h"
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#ifndef LWIP_INLINE_IP_CHKSUM
#if LWIP_CHECKSUM_CTRL_PER_NETIF
#define LWIP_INLINE_IP_CHKSUM   0
#else /* LWIP_CHECKSUM_CTRL_PER_NETIF */
#define LWIP_INLINE_IP_CHKSUM   1
#endif /* LWIP_CHECKSUM_CTRL_PER_NETIF */
#endif
#if LWIP_INLINE_IP_CHKSUM && CHECKSUM_GEN_IP
#define CHECKSUM_GEN_IP_INLINE  1
#else
#define CHECKSUM_GEN_IP_INLINE  0
#endif
#if LWIP_DHCP || defined(LWIP_IP_ACCEPT_UDP_PORT)
#define IP_ACCEPT_LINK_LAYER_ADDRESSING 1
#if LWIP_DHCP && defined(LWIP_IP_ACCEPT_UDP_PORT)
#define IP_ACCEPT_LINK_LAYER_ADDRESSED_PORT(port) (((port) == PP_NTOHS(LWIP_IANA_PORT_DHCP_CLIENT)) \
#elif defined(LWIP_IP_ACCEPT_UDP_PORT) /* LWIP_DHCP && defined(LWIP_IP_ACCEPT_UDP_PORT) */
#define IP_ACCEPT_LINK_LAYER_ADDRESSED_PORT(port) (LWIP_IP_ACCEPT_UDP_PORT(port))
#else /* LWIP_DHCP && defined(LWIP_IP_ACCEPT_UDP_PORT) */
#define IP_ACCEPT_LINK_LAYER_ADDRESSED_PORT(port) ((port) == PP_NTOHS(LWIP_IANA_PORT_DHCP_CLIENT))
#endif /* LWIP_DHCP && defined(LWIP_IP_ACCEPT_UDP_PORT) */
#else /* LWIP_DHCP */
#define IP_ACCEPT_LINK_LAYER_ADDRESSING 0
#endif /* LWIP_DHCP */
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#ifdef LWIP_HOOK_IP4_ROUTE_SRC
#endif /* LWIP_HOOK_IP4_ROUTE_SRC */
#if !LWIP_SINGLE_NETIF
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#if LWIP_NETIF_LOOPBACK && !LWIP_HAVE_LOOPIF
#endif /* LWIP_NETIF_LOOPBACK && !LWIP_HAVE_LOOPIF */
#ifdef LWIP_HOOK_IP4_ROUTE_SRC
#elif defined(LWIP_HOOK_IP4_ROUTE)
#endif
#endif /* !LWIP_SINGLE_NETIF */
#if IP_FORWARD
#ifdef LWIP_HOOK_IP4_CANFORWARD
#endif /* LWIP_HOOK_IP4_CANFORWARD */
#if !IP_FORWARD_ALLOW_TX_ON_RX_NETIF
#endif /* IP_FORWARD_ALLOW_TX_ON_RX_NETIF */
#if LWIP_ICMP
#endif /* LWIP_ICMP */
#if IP_FRAG
#else /* IP_FRAG */
#endif /* IP_FRAG */
#if LWIP_ICMP
#endif /* LWIP_ICMP */
#endif /* IP_FORWARD */
#if LWIP_NETIF_LOOPBACK && !LWIP_HAVE_LOOPIF
#endif /* LWIP_NETIF_LOOPBACK && !LWIP_HAVE_LOOPIF */
#if LWIP_AUTOIP
#endif /* LWIP_AUTOIP */
#if IP_ACCEPT_LINK_LAYER_ADDRESSING || LWIP_IGMP
#endif /* IP_ACCEPT_LINK_LAYER_ADDRESSING || LWIP_IGMP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#ifdef LWIP_HOOK_IP4_INPUT
#endif
#if CHECKSUM_CHECK_IP
#endif
#if LWIP_IGMP
#else /* LWIP_IGMP */
#endif /* LWIP_IGMP */
#if !LWIP_NETIF_LOOPBACK || LWIP_HAVE_LOOPIF
#endif /* !LWIP_NETIF_LOOPBACK || LWIP_HAVE_LOOPIF */
#if !LWIP_SINGLE_NETIF
#endif /* !LWIP_SINGLE_NETIF */
#if IP_ACCEPT_LINK_LAYER_ADDRESSING
#endif /* IP_ACCEPT_LINK_LAYER_ADDRESSING */
#if LWIP_IGMP || IP_ACCEPT_LINK_LAYER_ADDRESSING
#if IP_ACCEPT_LINK_LAYER_ADDRESSING
#endif /* IP_ACCEPT_LINK_LAYER_ADDRESSING */
#endif /* LWIP_IGMP || IP_ACCEPT_LINK_LAYER_ADDRESSING */
#if IP_FORWARD
#endif /* IP_FORWARD */
#if IP_REASSEMBLY /* packet fragment reassembly code present? */
#else /* IP_REASSEMBLY == 0, no packet fragment reassembly code present */
#endif /* IP_REASSEMBLY */
#if IP_OPTIONS_ALLOWED == 0 /* no support for IP options in the IP header? */
#if LWIP_IGMP
#else
#endif /* LWIP_IGMP */
#endif /* IP_OPTIONS_ALLOWED == 0 */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_UDP
#if LWIP_UDPLITE
#endif /* LWIP_UDPLITE */
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_ICMP
#endif /* LWIP_ICMP */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_ICMP
#endif /* LWIP_ICMP */
#if IP_OPTIONS_SEND
#endif /* IP_OPTIONS_SEND */
#if IP_OPTIONS_SEND
#else /* IP_OPTIONS_SEND */
#endif /* IP_OPTIONS_SEND */
#if IP_OPTIONS_SEND
#endif /* IP_OPTIONS_SEND */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if IP_OPTIONS_SEND
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#endif /* IP_OPTIONS_SEND */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP_INLINE
#endif /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP_INLINE
#if LWIP_CHECKSUM_CTRL_PER_NETIF
#endif /* LWIP_CHECKSUM_CTRL_PER_NETIF*/
#else /* CHECKSUM_GEN_IP_INLINE */
#if CHECKSUM_GEN_IP
#endif /* CHECKSUM_GEN_IP */
#endif /* CHECKSUM_GEN_IP_INLINE */
#if ENABLE_LOOPBACK
#if !LWIP_HAVE_LOOPIF
#endif /* !LWIP_HAVE_LOOPIF */
#if LWIP_MULTICAST_TX_OPTIONS
#endif /* LWIP_MULTICAST_TX_OPTIONS */
#endif /* ENABLE_LOOPBACK */
#if IP_FRAG
#endif /* IP_FRAG */
#if LWIP_NETIF_USE_HINTS
#endif /* LWIP_NETIF_USE_HINTS*/
#if IP_DEBUG
#endif /* IP_DEBUG */
#endif /* LWIP_IPV4 */
