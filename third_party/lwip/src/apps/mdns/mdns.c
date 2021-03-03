#include "lwip/apps/mdns.h"
#include "lwip/apps/mdns_priv.h"
#include "lwip/netif.h"
#include "lwip/udp.h"
#include "lwip/ip_addr.h"
#include "lwip/mem.h"
#include "lwip/prot/dns.h"
#include "lwip/prot/iana.h"
#include "lwip/timeouts.h"
#include <string.h>
#if LWIP_MDNS_RESPONDER
#if (LWIP_IPV4 && !LWIP_IGMP)
#error "If you want to use MDNS with IPv4, you have to define LWIP_IGMP=1 in your lwipopts.h"
#endif
#if (LWIP_IPV6 && !LWIP_IPV6_MLD)
#error "If you want to use MDNS with IPv6, you have to define LWIP_IPV6_MLD=1 in your lwipopts.h"
#endif
#if (!LWIP_UDP)
#error "If you want to use MDNS, you have to define LWIP_UDP=1 in your lwipopts.h"
#endif
#if LWIP_IPV4
#include "lwip/igmp.h"
#endif
#if LWIP_IPV6
#include "lwip/mld6.h"
#endif
#define MDNS_TTL  255
#define NUM_DOMAIN_OFFSETS 10
#define DOMAIN_JUMP_SIZE 2
#define DOMAIN_JUMP 0xc000
#if MDNS_RESP_USENETIF_EXTCALLBACK
#endif
#define NETIF_TO_HOST(netif) (struct mdns_host*)(netif_get_client_data(netif, mdns_netif_client_id))
#define TOPDOMAIN_LOCAL "local"
#define REVERSE_PTR_TOPDOMAIN "arpa"
#define REVERSE_PTR_V4_DOMAIN "in-addr"
#define REVERSE_PTR_V6_DOMAIN "ip6"
#define SRV_PRIORITY 0
#define SRV_WEIGHT   0
#define OUTPACKET_SIZE 500
#define REPLY_HOST_A            0x01
#define REPLY_HOST_PTR_V4       0x02
#define REPLY_HOST_AAAA         0x04
#define REPLY_HOST_PTR_V6       0x08
#define REPLY_SERVICE_TYPE_PTR  0x10
#define REPLY_SERVICE_NAME_PTR  0x20
#define REPLY_SERVICE_SRV       0x40
#define REPLY_SERVICE_TXT       0x80
#define MDNS_PROBE_DELAY_MS       250
#define MDNS_PROBE_COUNT          3
#ifdef LWIP_RAND
#define MDNS_INITIAL_PROBE_DELAY_MS (LWIP_RAND() % MDNS_PROBE_DELAY_MS)
#else
#define MDNS_INITIAL_PROBE_DELAY_MS MDNS_PROBE_DELAY_MS
#endif
#define MDNS_PROBING_NOT_STARTED  0
#define MDNS_PROBING_ONGOING      1
#define MDNS_PROBING_COMPLETE     2
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_NETIF_EXT_STATUS_CALLBACK && MDNS_RESP_USENETIF_EXTCALLBACK
#endif /* LWIP_NETIF_EXT_STATUS_CALLBACK && MDNS_RESP_USENETIF_EXTCALLBACK */
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_MULTICAST_TX_OPTIONS
#else
#endif
#if MDNS_RESP_USENETIF_EXTCALLBACK
#endif
#endif /* LWIP_MDNS_RESPONDER */
