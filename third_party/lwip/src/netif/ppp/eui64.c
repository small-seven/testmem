#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && PPP_IPV6_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/eui64.h"
#endif /* PPP_SUPPORT && PPP_IPV6_SUPPORT */
