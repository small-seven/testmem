#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && PPP_IPV4_SUPPORT /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/ipcp.h"
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* moved to ppp_settings */
#endif /* moved to ppp_setting */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_NOTIFY
#endif /* PPP_NOTIFY */
#if 0 /* moved to ppp_pcb */
#endif /* moved to ppp_pcb */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_DATAINPUT
#endif /* PPP_DATAINPUT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#define CILEN_VOID	2
#define CILEN_COMPRESS	4	/* min length for compression protocol opt. */
#define CILEN_VJ	6	/* length for RFC1332 Van-Jacobson opt. */
#define CILEN_ADDR	6	/* new-style single address option */
#define CILEN_ADDRS	10	/* old-style dual address option */
#define CODENAME(x)	((x) == CONFACK ? "ACK" : \
#if 0 /* UNUSED, already defined by lwIP */
#endif /* UNUSED, already defined by lwIP */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if 0 /* Not necessary, everything is cleared in ppp_new() */
#endif /* 0 */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if VJ_SUPPORT
#endif /* #if VJ_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#define LENCIADDRS(neg)		(neg ? CILEN_ADDRS : 0)
#if VJ_SUPPORT
#define LENCIVJ(neg, old)	(neg ? (old? CILEN_COMPRESS : CILEN_VJ) : 0)
#endif /* VJ_SUPPORT */
#define LENCIADDR(neg)		(neg ? CILEN_ADDR : 0)
#if LWIP_DNS
#define LENCIDNS(neg)		LENCIADDR(neg)
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#define LENCIWINS(neg)		LENCIADDR(neg)
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#define ADDCIADDRS(opt, neg, val1, val2) \
#if VJ_SUPPORT
#define ADDCIVJ(opt, neg, val, old, maxslotindex, cflag) \
#endif /* VJ_SUPPORT */
#define ADDCIADDR(opt, neg, val) \
#if LWIP_DNS
#define ADDCIDNS(opt, neg, addr) \
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#define ADDCIWINS(opt, addr) \
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#define ACKCIADDRS(opt, neg, val1, val2) \
#if VJ_SUPPORT
#define ACKCIVJ(opt, neg, val, old, maxslotindex, cflag) \
#endif /* VJ_SUPPORT */
#define ACKCIADDR(opt, neg, val) \
#if LWIP_DNS
#define ACKCIDNS(opt, neg, addr) \
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#define ACKCIWINS(opt, addr) \
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#define NAKCIADDRS(opt, neg, code) \
#if VJ_SUPPORT
#define NAKCIVJ(opt, neg, code) \
#endif /* VJ_SUPPORT */
#define NAKCIADDR(opt, neg, code) \
#if LWIP_DNS
#define NAKCIDNS(opt, neg, code) \
#endif /* LWIP_DNS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* #if LWIP_DNS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#define REJCIADDRS(opt, neg, val1, val2) \
#if VJ_SUPPORT
#define REJCIVJ(opt, neg, val, old, maxslot, cflag) \
#endif /* VJ_SUPPORT */
#define REJCIADDR(opt, neg, val) \
#if LWIP_DNS
#define REJCIDNS(opt, neg, dnsaddr) \
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#define REJCIWINS(opt, addr) \
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if DEMAND_SUPPORT
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED - PROXY ARP */
#endif /* UNUSED - PROXY ARP */
#endif /* DEMAND_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if LWIP_DNS
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* LWIP_DNS */
#if PPP_SERVER && PPP_AUTH_SUPPORT
#endif /* PPP_SERVER && PPP_AUTH_SUPPORT */
#if 0 /* Unused */
#endif /* Unused */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if DEMAND_SUPPORT
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#if 0 /* UNUSED - PROXY ARP */
#endif /* UNUSED - PROXY ARP */
#endif /* DEMAND_SUPPORT */
#if !(defined(SVR4) && (defined(SNI) || defined(__USLC__)))
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#endif
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#if (defined(SVR4) && (defined(SNI) || defined(__USLC__)))
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#endif
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED - PROXY ARP */
#endif /* UNUSED - PROXY ARP */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#if PPP_NOTIFY
#endif /* PPP_NOTIFY */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#if PPP_NOTIFY
#endif /* PPP_NOTIFY */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - PROXY ARP */
#endif /* UNUSED - PROXY ARP */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PRINTPKT_SUPPORT
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if VJ_SUPPORT
#endif /* VJ_SUPPORT */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if 0 /* UNUSED - WINS */
#endif /* UNUSED - WINS */
#endif /* PRINTPKT_SUPPORT */
#if DEMAND_SUPPORT
#define IP_HDRLEN	20	/* bytes */
#define IP_OFFMASK	0x1fff
#ifndef IPPROTO_TCP
#define IPPROTO_TCP	6
#endif
#define TCP_HDRLEN	20
#define TH_FIN		0x01
#define net_short(x)	(((x)[0] << 8) + (x)[1])
#define get_iphl(x)	(((unsigned char *)(x))[0] & 0xF)
#define get_ipoff(x)	net_short((unsigned char *)(x) + 6)
#define get_ipproto(x)	(((unsigned char *)(x))[9])
#define get_tcpoff(x)	(((unsigned char *)(x))[12] >> 4)
#define get_tcpflags(x)	(((unsigned char *)(x))[13])
#endif /* DEMAND_SUPPORT */
#endif /* PPP_SUPPORT && PPP_IPV4_SUPPORT */
