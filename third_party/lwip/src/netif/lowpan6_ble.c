#include "netif/lowpan6_ble.h"
#if LWIP_IPV6
#include "lwip/ip.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/nd6.h"
#include "lwip/mem.h"
#include "lwip/udp.h"
#include "lwip/tcpip.h"
#include "lwip/snmp.h"
#include <string.h>
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#else
#define rfc7668_context NULL
#endif
#if LWIP_RFC7668_LINUX_WORKAROUND_PUBLIC_ADDRESS
#else
#endif
#if LWIP_6LOWPAN_IPHC
#else /* LWIP_6LOWPAN_IPHC */
#endif/* LWIP_6LOWPAN_IPHC */
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#else
#endif
#if LWIP_RFC7668_IP_UNCOMPRESSED_DEBUG
#endif
#if !NO_SYS
#endif /* !NO_SYS */
#endif /* LWIP_IPV6 */
