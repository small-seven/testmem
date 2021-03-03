#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/lcp.h"
#if CHAP_SUPPORT
#include "netif/ppp/chap-new.h"
#endif /* CHAP_SUPPORT */
#include "netif/ppp/magic.h"
#define DELAYED_UP	0x80
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#if PPP_LCP_ADAPTIVE
#endif
#endif /* UNUSED */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if PPP_OPTIONS
#if PPP_LCP_ADAPTIVE
#endif
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#endif /* PPP_OPTIONS */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
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
#define CILEN_CHAR	3
#define CILEN_SHORT	4	/* CILEN_VOID + 2 */
#if CHAP_SUPPORT
#define CILEN_CHAP	5	/* CILEN_VOID + 2 + 1 */
#endif /* CHAP_SUPPORT */
#define CILEN_LONG	6	/* CILEN_VOID + 4 */
#if LQR_SUPPORT
#define CILEN_LQR	8	/* CILEN_VOID + 2 + 4 */
#endif /* LQR_SUPPORT */
#define CILEN_CBCP	3
#define CODENAME(x)	((x) == CONFACK ? "ACK" : \
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if PPP_PROTOCOLNAME
#endif /* PPP_PROTOCOLNAME */
#if PPP_PROTOCOLNAME
#endif /* PPP_PROTOCOLNAME */
#if PPP_PROTOCOLNAME
#endif /* PPP_PROTOCOLNAME */
#if PPP_PROTOCOLNAME
#endif /* #if PPP_PROTOCOLNAME */
#if 0
#endif
#if PPP_AUTH_SUPPORT
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PPP_SERVER
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PPP_SERVER */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PPP_AUTH_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if 0 /* UNUSED */
#endif /* UNUSED */
#define LENCIVOID(neg)	((neg) ? CILEN_VOID : 0)
#if CHAP_SUPPORT
#define LENCICHAP(neg)	((neg) ? CILEN_CHAP : 0)
#endif /* CHAP_SUPPORT */
#define LENCISHORT(neg)	((neg) ? CILEN_SHORT : 0)
#define LENCILONG(neg)	((neg) ? CILEN_LONG : 0)
#if LQR_SUPPORT
#define LENCILQR(neg)	((neg) ? CILEN_LQR: 0)
#endif /* LQR_SUPPORT */
#define LENCICBCP(neg)	((neg) ? CILEN_CBCP: 0)
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT /* cannot be improved, embedding a directive within macro arguments is not portable */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if !EAP_SUPPORT
#endif /* !EAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT /* cannot be improved, embedding a directive within macro arguments is not portable */
#if EAP_SUPPORT && CHAP_SUPPORT
#endif /* EAP_SUPPORT && CHAP_SUPPORT */
#if EAP_SUPPORT && !CHAP_SUPPORT
#endif /* EAP_SUPPORT && !CHAP_SUPPORT */
#if !EAP_SUPPORT && CHAP_SUPPORT
#endif /* !EAP_SUPPORT && CHAP_SUPPORT */
#if !EAP_SUPPORT && !CHAP_SUPPORT
#endif /* !EAP_SUPPORT && !CHAP_SUPPORT */
#endif /* PAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#define ADDCIVOID(opt, neg) \
#define ADDCISHORT(opt, neg, val) \
#if CHAP_SUPPORT
#define ADDCICHAP(opt, neg, val) \
#endif /* CHAP_SUPPORT */
#define ADDCILONG(opt, neg, val) \
#if LQR_SUPPORT
#define ADDCILQR(opt, neg, val) \
#endif /* LQR_SUPPORT */
#define ADDCICHAR(opt, neg, val) \
#define ADDCIENDP(opt, neg, class, val, len) \
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT /* cannot be improved, embedding a directive within macro arguments is not portable */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if !EAP_SUPPORT
#endif /* !EAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT /* cannot be improved, embedding a directive within macro arguments is not portable */
#if EAP_SUPPORT && CHAP_SUPPORT
#endif /* EAP_SUPPORT && CHAP_SUPPORT */
#if EAP_SUPPORT && !CHAP_SUPPORT
#endif /* EAP_SUPPORT && !CHAP_SUPPORT */
#if !EAP_SUPPORT && CHAP_SUPPORT
#endif /* !EAP_SUPPORT && CHAP_SUPPORT */
#if !EAP_SUPPORT && !CHAP_SUPPORT
#endif /* !EAP_SUPPORT && !CHAP_SUPPORT */
#endif /* PAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#endif
#define ACKCIVOID(opt, neg) \
#define ACKCISHORT(opt, neg, val) \
#define ACKCICHAR(opt, neg, val) \
#if CHAP_SUPPORT
#define ACKCICHAP(opt, neg, val) \
#endif /* CHAP_SUPPORT */
#define ACKCILONG(opt, neg, val) \
#if LQR_SUPPORT
#define ACKCILQR(opt, neg, val) \
#endif /* LQR_SUPPORT */
#define ACKCIENDP(opt, neg, class, val, vlen) \
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT /* cannot be improved, embedding a directive within macro arguments is not portable */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if !EAP_SUPPORT
#endif /* !EAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT /* cannot be improved, embedding a directive within macro arguments is not portable */
#if EAP_SUPPORT && CHAP_SUPPORT
#endif /* EAP_SUPPORT && CHAP_SUPPORT */
#if EAP_SUPPORT && !CHAP_SUPPORT
#endif /* EAP_SUPPORT && !CHAP_SUPPORT */
#if !EAP_SUPPORT && CHAP_SUPPORT
#endif /* !EAP_SUPPORT && CHAP_SUPPORT */
#if !EAP_SUPPORT && !CHAP_SUPPORT
#endif /* !EAP_SUPPORT && !CHAP_SUPPORT */
#endif /* PAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#define NAKCIVOID(opt, neg) \
#if CHAP_SUPPORT
#define NAKCICHAP(opt, neg, code) \
#endif /* CHAP_SUPPORT */
#define NAKCICHAR(opt, neg, code) \
#define NAKCISHORT(opt, neg, code) \
#define NAKCILONG(opt, neg, code) \
#if LQR_SUPPORT
#define NAKCILQR(opt, neg, code) \
#endif /* LQR_SUPPORT */
#define NAKCIENDP(opt, neg) \
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PAP_SUPPORT
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#else /* HAVE_MULTILINK */
#endif /* HAVE_MULTILINK */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#define REJCIVOID(opt, neg) \
#define REJCISHORT(opt, neg, val) \
#if CHAP_SUPPORT && EAP_SUPPORT && PAP_SUPPORT
#define REJCICHAP(opt, neg, val) \
#endif /* CHAP_SUPPORT && EAP_SUPPORT && PAP_SUPPORT */
#if CHAP_SUPPORT && !EAP_SUPPORT && PAP_SUPPORT
#define REJCICHAP(opt, neg, val) \
#endif /* CHAP_SUPPORT && !EAP_SUPPORT && PAP_SUPPORT */
#if CHAP_SUPPORT && EAP_SUPPORT && !PAP_SUPPORT
#define REJCICHAP(opt, neg, val) \
#endif /* CHAP_SUPPORT && EAP_SUPPORT && !PAP_SUPPORT */
#if CHAP_SUPPORT && !EAP_SUPPORT && !PAP_SUPPORT
#define REJCICHAP(opt, neg, val) \
#endif /* CHAP_SUPPORT && !EAP_SUPPORT && !PAP_SUPPORT */
#define REJCILONG(opt, neg, val) \
#if LQR_SUPPORT
#define REJCILQR(opt, neg, val) \
#endif /* LQR_SUPPORT */
#define REJCICBCP(opt, neg, val) \
#define REJCIENDP(opt, neg, class, val, vlen) \
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PAP_SUPPORT
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#endif /* EAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if PRINTPKT_SUPPORT
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if LQR_SUPPORT
#endif /* LQR_SUPPORT */
#ifdef HAVE_MULTILINK
#else
#endif
#endif /* PRINTPKT_SUPPORT */
#if PPP_LCP_ADAPTIVE
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#endif
#endif /* PPP_SUPPORT */
