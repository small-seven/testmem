#include "netif/lowpan6.h"
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
#include "netif/ieee802154.h"
#include <string.h>
#if LWIP_6LOWPAN_802154_HW_CRC
#define LWIP_6LOWPAN_DO_CALC_CRC(buf, len) 0
#else
#define LWIP_6LOWPAN_DO_CALC_CRC(buf, len) LWIP_6LOWPAN_CALC_CRC(buf, len)
#endif
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#endif
#define LOWPAN6_MAX_PAYLOAD (127 - 2)
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#define LWIP_6LOWPAN_CONTEXTS(netif) lowpan6_data.lowpan6_context
#else
#define LWIP_6LOWPAN_CONTEXTS(netif) NULL
#endif
#if LWIP_6LOWPAN_INFER_SHORT_ADDRESS
#endif /* LWIP_6LOWPAN_INFER_SHORT_ADDRESS */
#define CCITT_POLY_16 0x8408U
free_reass_datagram(struct lowpan6_reass_helper *lrh)
{
  if (lrh->reass) {
    pbuf_free(lrh->reass);
  }
  if (lrh->frags) {
    pbuf_free(lrh->frags);
  }
  mem_free(lrh);
}
#if LWIP_6LOWPAN_IPHC
#else /* LWIP_6LOWPAN_IPHC */
#endif /* LWIP_6LOWPAN_IPHC */
#if LWIP_6LOWPAN_NUM_CONTEXTS > 0
#else
#endif
#if LWIP_6LOWPAN_INFER_SHORT_ADDRESS
#endif /* LWIP_6LOWPAN_INFER_SHORT_ADDRESS */
#if LWIP_6LOWPAN_INFER_SHORT_ADDRESS
#endif /* LWIP_6LOWPAN_INFER_SHORT_ADDRESS */
#if LWIP_6LOWPAN_INFER_SHORT_ADDRESS
#endif /* LWIP_6LOWPAN_INFER_SHORT_ADDRESS */
#if LWIP_6LOWPAN_INFER_SHORT_ADDRESS
#endif /* LWIP_6LOWPAN_INFER_SHORT_ADDRESS */
#if !NO_SYS
#endif /* !NO_SYS */
#endif /* LWIP_IPV6 */
