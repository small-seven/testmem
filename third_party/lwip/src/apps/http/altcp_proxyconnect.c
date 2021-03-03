#include "lwip/apps/altcp_proxyconnect.h"
#if LWIP_ALTCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/altcp.h"
#include "lwip/priv/altcp_priv.h"
#include "lwip/altcp_tcp.h"
#include "lwip/altcp_tls.h"
#include "lwip/mem.h"
#include "lwip/init.h"
#include <stdio.h>
#ifndef ALTCP_PROXYCONNECT_CLIENT_AGENT
#define ALTCP_PROXYCONNECT_CLIENT_AGENT "lwIP/" LWIP_VERSION_STRING " (http://savannah.nongnu.org/projects/lwip)"
#endif
#define ALTCP_PROXYCONNECT_FLAGS_CONNECT_STARTED  0x01
#define ALTCP_PROXYCONNECT_FLAGS_HANDSHAKE_DONE   0x02
typedef struct altcp_proxyconnect_state_s
{
  ip_addr_t outer_addr;
  u16_t outer_port;
  struct altcp_proxyconnect_config *conf;
  u8_t flags;
} altcp_proxyconnect_state_t;
altcp_proxyconnect_state_free(altcp_proxyconnect_state_t *state)
{
  LWIP_ASSERT("state != NULL", state != NULL);
  mem_free(state);
}
#define PROXY_CONNECT "CONNECT %s:%d HTTP/1.1\r\n" /* HOST, PORT */ \
#define PROXY_CONNECT_FORMAT(host, port) PROXY_CONNECT, host, port, ALTCP_PROXYCONNECT_CLIENT_AGENT
#if LWIP_IPV6
#else
#endif
#if LWIP_ALTCP_TLS
#endif /* LWIP_ALTCP_TLS */
#ifdef LWIP_DEBUG
#endif
#endif /* LWIP_ALTCP */
