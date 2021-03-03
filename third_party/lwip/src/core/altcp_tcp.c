#include "lwip/opt.h"
#if LWIP_ALTCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/altcp.h"
#include "lwip/altcp_tcp.h"
#include "lwip/priv/altcp_priv.h"
#include "lwip/tcp.h"
#include "lwip/mem.h"
#include <string.h>
#define ALTCP_TCP_ASSERT_CONN(conn) do { \
#define ALTCP_TCP_ASSERT_CONN_PCB(conn, tpcb) do { \
altcp_tcp_alloc(void *arg, u8_t ip_type)
{
  LWIP_UNUSED_ARG(arg);
  return altcp_tcp_new_ip_type(ip_type);
}
#ifdef LWIP_DEBUG
#endif
#ifdef LWIP_DEBUG
#endif
#endif /* LWIP_ALTCP */
