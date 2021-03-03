#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && defined(HAVE_MULTILINK) /* don't build if not configured for use in lwipopts.h */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/lcp.h"
#include "netif/ppp/tdb.h"
#define set_ip_epdisc(ep, addr) do {	\
#define LOCAL_IP_ADDR(addr)						  \
#define process_exists(n)	(kill((n), 0) == 0 || errno != ESRCH)
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#endif /* PPP_SUPPORT && HAVE_MULTILINK */
