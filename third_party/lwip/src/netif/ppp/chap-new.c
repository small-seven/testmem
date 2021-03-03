#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && CHAP_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdlib.h>
#include <string.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#if 0 /* UNUSED */
#include "session.h"
#endif /* UNUSED */
#include "netif/ppp/chap-new.h"
#include "netif/ppp/chap-md5.h"
#if MSCHAP_SUPPORT
#include "netif/ppp/chap_ms.h"
#endif
#include "netif/ppp/magic.h"
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#define LOWERUP			1
#define AUTH_STARTED		2
#define AUTH_DONE		4
#define AUTH_FAILED		8
#define TIMEOUT_PENDING		0x10
#define CHALLENGE_VALID		0x20
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#if 0 /* Not necessary, everything is cleared in ppp_new() */
#if PPP_SERVER
#endif /* PPP_SERVER */
#endif /* 0 */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_REMOTENAME
#endif /* PPP_REMOTENAME */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_SERVER */
#if PPP_REMOTENAME
#endif /* PPP_REMOTENAME */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
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
#endif /* PPP_SUPPORT && CHAP_SUPPORT */
