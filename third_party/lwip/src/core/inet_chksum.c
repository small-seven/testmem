#include "lwip/opt.h"
#include "lwip/inet_chksum.h"
#include "lwip/def.h"
#include "lwip/ip_addr.h"
#include <string.h>
#ifndef LWIP_CHKSUM
# define LWIP_CHKSUM lwip_standard_chksum
# ifndef LWIP_CHKSUM_ALGORITHM
#  define LWIP_CHKSUM_ALGORITHM 2
# endif
#endif
#ifndef LWIP_CHKSUM_ALGORITHM
# define LWIP_CHKSUM_ALGORITHM 0
#endif
#if (LWIP_CHKSUM_ALGORITHM == 1) /* Version #1 */
#endif
#if (LWIP_CHKSUM_ALGORITHM == 2) /* Alternative version #2 */
#endif
#if (LWIP_CHKSUM_ALGORITHM == 3) /* Alternative version #3 */
#endif
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if (LWIP_CHKSUM_COPY_ALGORITHM == 1) /* Version #1 */
#endif /* (LWIP_CHKSUM_COPY_ALGORITHM == 1) */
