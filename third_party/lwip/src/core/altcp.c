#include "lwip/opt.h"
#if LWIP_ALTCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/altcp.h"
#include "lwip/priv/altcp_priv.h"
#include "lwip/altcp_tcp.h"
#include "lwip/tcp.h"
#include "lwip/mem.h"
#include <string.h>
altcp_alloc(void)
{
  struct altcp_pcb *ret = (struct altcp_pcb *)memp_malloc(MEMP_ALTCP_PCB);
  if (ret != NULL) {
    memset(ret, 0, sizeof(struct altcp_pcb));
  }
  return ret;
}
altcp_free(struct altcp_pcb *conn)
{
  if (conn) {
    if (conn->fns && conn->fns->dealloc) {
      conn->fns->dealloc(conn);
    }
    memp_free(MEMP_ALTCP_PCB, conn);
  }
}
#ifdef LWIP_DEBUG
#endif
#ifdef LWIP_DEBUG
#endif
#endif /* LWIP_ALTCP */
