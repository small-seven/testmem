#include "lwip/opt.h"
#if LWIP_NETCONN /* don't build if not configured for use in lwipopts.h */
#include "lwip/netbuf.h"
#include "lwip/memp.h"
#include <string.h>
netbuf_alloc(struct netbuf *buf, u16_t size)
{
  LWIP_ERROR("netbuf_alloc: invalid buf", (buf != NULL), return NULL;);

  /* Deallocate any previously allocated memory. */
  if (buf->p != NULL) {
    pbuf_free(buf->p);
  }
  buf->p = pbuf_alloc(PBUF_TRANSPORT, size, PBUF_RAM);
  if (buf->p == NULL) {
    return NULL;
  }
  LWIP_ASSERT("check that first pbuf can hold size",
              (buf->p->len >= size));
  buf->ptr = buf->p;
  return buf->p->payload;
}
netbuf_free(struct netbuf *buf)
{
  LWIP_ERROR("netbuf_free: invalid buf", (buf != NULL), return;);
  if (buf->p != NULL) {
    pbuf_free(buf->p);
  }
  buf->p = buf->ptr = NULL;
#if LWIP_CHECKSUM_ON_COPY
  buf->flags = 0;
  buf->toport_chksum = 0;
#endif /* LWIP_CHECKSUM_ON_COPY */
}
#endif /* LWIP_NETCONN */
