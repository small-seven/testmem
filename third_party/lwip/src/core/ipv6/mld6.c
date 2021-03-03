#include "lwip/opt.h"
#if LWIP_IPV6 && LWIP_IPV6_MLD  /* don't build if not configured for use in lwipopts.h */
#include "lwip/mld6.h"
#include "lwip/prot/mld6.h"
#include "lwip/icmp6.h"
#include "lwip/ip6.h"
#include "lwip/ip6_addr.h"
#include "lwip/ip.h"
#include "lwip/inet_chksum.h"
#include "lwip/pbuf.h"
#include "lwip/netif.h"
#include "lwip/memp.h"
#include "lwip/stats.h"
#include <string.h>
#define MLD6_HL                           1
#define MLD6_JOIN_DELAYING_MEMBER_TMR_MS  (500)
#define MLD6_GROUP_NON_MEMBER             0
#define MLD6_GROUP_DELAYING_MEMBER        1
#define MLD6_GROUP_IDLE_MEMBER            2
mld6_remove_group(struct netif *netif, struct mld_group *group)
{
  err_t err = ERR_OK;

  /* Is it the first group? */
  if (netif_mld6_data(netif) == group) {
    netif_set_client_data(netif, LWIP_NETIF_CLIENT_DATA_INDEX_MLD6, group->next);
  } else {
    /* look for group further down the list */
    struct mld_group *tmpGroup;
    for (tmpGroup = netif_mld6_data(netif); tmpGroup != NULL; tmpGroup = tmpGroup->next) {
      if (tmpGroup->next == group) {
        tmpGroup->next = group->next;
        break;
      }
    }
    /* Group not find group */
    if (tmpGroup == NULL) {
      err = ERR_ARG;
    }
  }

  return err;
}
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#if LWIP_IPV6_SCOPES
#endif /* LWIP_IPV6_SCOPES */
#ifdef LWIP_RAND
#endif /* LWIP_RAND */
#if CHECKSUM_GEN_ICMP6
#endif /* CHECKSUM_GEN_ICMP6 */
#endif /* LWIP_IPV6 */
