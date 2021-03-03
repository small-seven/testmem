#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && PPP_IPV6_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
#include "netif/ppp/ipv6cp.h"
#include "netif/ppp/magic.h"
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
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
#if 0 /* UNUSED */
#endif /* UNUSED */
#define CILEN_VOID	2
#define CILEN_COMPRESS	4	/* length for RFC2023 compress opt. */
#define CILEN_IFACEID   10	/* RFC2472, interface identifier    */
#define CODENAME(x)	((x) == CONFACK ? "ACK" : \
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_OPTIONS
#define VALIDID(a) ( (((a).s6_addr32[0] == 0) && ((a).s6_addr32[1] == 0)) && \
#endif /* PPP_OPTIONS */
#if 0 /* Not necessary, everything is cleared in ppp_new() */
#endif /* 0 */
#ifdef IPV6CP_COMP
#endif
#ifdef IPV6CP_COMP
#define LENCIVJ(neg)		(neg ? CILEN_COMPRESS : 0)
#endif /* IPV6CP_COMP */
#define LENCIIFACEID(neg)	(neg ? CILEN_IFACEID : 0)
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#define ADDCIVJ(opt, neg, val) \
#endif /* IPV6CP_COMP */
#define ADDCIIFACEID(opt, neg, val1) \
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#define ACKCIVJ(opt, neg, val) \
#endif /* IPV6CP_COMP */
#define ACKCIIFACEID(opt, neg, val1) \
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#define NAKCIIFACEID(opt, neg, code) \
#ifdef IPV6CP_COMP
#define NAKCIVJ(opt, neg, code) \
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#define REJCIIFACEID(opt, neg, val1) \
#ifdef IPV6CP_COMP
#define REJCIVJ(opt, neg, val) \
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#ifdef IPV6CP_COMP
#endif
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#ifdef IPV6CP_COMP
#endif
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PRINTPKT_SUPPORT
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#ifdef IPV6CP_COMP
#endif /* IPV6CP_COMP */
#endif /* PRINTPKT_SUPPORT */
#if DEMAND_SUPPORT
#define IP6_HDRLEN	40	/* bytes */
#define IP6_NHDR_FRAG	44	/* fragment IPv6 header */
#define TCP_HDRLEN	20
#define TH_FIN		0x01
#define get_ip6nh(x)	(((unsigned char *)(x))[6])
#define get_tcpoff(x)	(((unsigned char *)(x))[12] >> 4)
#define get_tcpflags(x)	(((unsigned char *)(x))[13])
#endif /* DEMAND_SUPPORT */
#endif /* PPP_SUPPORT && PPP_IPV6_SUPPORT */
