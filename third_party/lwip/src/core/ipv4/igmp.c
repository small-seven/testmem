#include "lwip/opt.h"
#if LWIP_IPV4 && LWIP_IGMP /* don't build if not configured for use in lwipopts.h */
#include "lwip/igmp.h"
#include "lwip/debug.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/ip.h"
#include "lwip/inet_chksum.h"
#include "lwip/netif.h"
#include "lwip/stats.h"
#include "lwip/prot/igmp.h"
#include <string.h>
igmp_remove_group(struct netif *netif, struct igmp_group *group)
{
  err_t err = ERR_OK;
  struct igmp_group *tmp_group;

  /* Skip the first group in the list, it is always the allsystems group added in igmp_start() */
  for (tmp_group = netif_igmp_data(netif); tmp_group != NULL; tmp_group = tmp_group->next) {
    if (tmp_group->next == group) {
      tmp_group->next = group->next;
      break;
    }
  }
  /* Group not found in netif's igmp group list */
  if (tmp_group == NULL) {
    err = ERR_ARG;
  }

  return err;
}
#ifdef LWIP_RAND
#else /* LWIP_RAND */
#endif /* LWIP_RAND */
#endif /* LWIP_IPV4 && LWIP_IGMP */
