#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#define PROTO_NAME(f)	((f)->callbacks->proto_name)
#endif /* PPP_SUPPORT */
