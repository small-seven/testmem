#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && CHAP_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdlib.h>
#include <string.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/chap-new.h"
#include "netif/ppp/chap-md5.h"
#include "netif/ppp/magic.h"
#include "netif/ppp/pppcrypt.h"
#define MD5_HASH_SIZE		16
#define MD5_MIN_CHALLENGE	17
#define MD5_MAX_CHALLENGE	24
#define MD5_MIN_MAX_POWER_OF_TWO_CHALLENGE     3   /* 2^3-1 = 7, 17+7 = 24 */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#endif /* PPP_SUPPORT && CHAP_SUPPORT */
