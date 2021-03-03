#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && MSCHAP_SUPPORT /* don't build if not necessary */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/pppcrypt.h"
#endif /* PPP_SUPPORT && MSCHAP_SUPPORT */
