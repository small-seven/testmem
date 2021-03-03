#include "netif/lowpan6_common.h"
#if LWIP_IPV6
#include "lwip/ip.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/udp.h"
#include <string.h>
#if LWIP_6LOWPAN_IPHC
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#endif /* LWIP_6LOWPAN_NUM_CONTEXTS > 0 */
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#else /* LWIP_6LOWPAN_NUM_CONTEXTS > 0 */
#endif /* LWIP_6LOWPAN_NUM_CONTEXTS > 0 */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_LOWPAN6_IP_COMPRESSED_DEBUG
#endif
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#else
#endif
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#endif
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_UDP
#define UDP_HLEN_ALLOC UDP_HLEN
#else
#define UDP_HLEN_ALLOC 0
#endif
#endif /* LWIP_6LOWPAN_IPHC */
#endif /* LWIP_IPV6 */
