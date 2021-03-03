#include "lwip/opt.h"
#if LWIP_IPV6  /* don't build if not configured for use in lwipopts.h */
#include "lwip/ip_addr.h"
#include "lwip/def.h"
#include <string.h>
#if LWIP_IPV4
#include "lwip/ip4_addr.h" /* for ip6addr_aton to handle IPv4-mapped addresses */
#endif /* LWIP_IPV4 */
#define lwip_xchar(i)        ((char)((i) < 10 ? '0' + (i) : 'A' + (i) - 10))
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif
#if LWIP_IPV4
#define IP4MAPPED_HEADER "::FFFF:"
#endif /* LWIP_IPV4 */
#endif /* LWIP_IPV6 */
