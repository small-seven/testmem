#include "lwip/apps/http_client.h"
#include "lwip/altcp_tcp.h"
#include "lwip/dns.h"
#include "lwip/debug.h"
#include "lwip/mem.h"
#include "lwip/altcp_tls.h"
#include "lwip/init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if LWIP_TCP && LWIP_CALLBACK_API
#ifndef HTTPC_DEBUG
#define HTTPC_DEBUG                 LWIP_DBG_OFF
#endif
#ifndef HTTPC_DEBUG_REQUEST
#define HTTPC_DEBUG_REQUEST         0
#endif
#ifndef HTTPC_CLIENT_AGENT
#define HTTPC_CLIENT_AGENT "lwIP/" LWIP_VERSION_STRING " (http://savannah.nongnu.org/projects/lwip)"
#endif
#define HTTPC_DEBUG_TRACE        (HTTPC_DEBUG | LWIP_DBG_TRACE)
#define HTTPC_DEBUG_STATE        (HTTPC_DEBUG | LWIP_DBG_STATE)
#define HTTPC_DEBUG_WARN         (HTTPC_DEBUG | LWIP_DBG_LEVEL_WARNING)
#define HTTPC_DEBUG_WARN_STATE   (HTTPC_DEBUG | LWIP_DBG_LEVEL_WARNING | LWIP_DBG_STATE)
#define HTTPC_DEBUG_SERIOUS      (HTTPC_DEBUG | LWIP_DBG_LEVEL_SERIOUS)
#define HTTPC_POLL_INTERVAL     1
#define HTTPC_POLL_TIMEOUT      30 /* 15 seconds */
#define HTTPC_CONTENT_LEN_INVALID 0xFFFFFFFF
#define HTTPC_REQ_11 "GET %s HTTP/1.1\r\n" /* URI */\
#define HTTPC_REQ_11_FORMAT(uri) HTTPC_REQ_11, uri, HTTPC_CLIENT_AGENT
#define HTTPC_REQ_11_HOST "GET %s HTTP/1.1\r\n" /* URI */\
#define HTTPC_REQ_11_HOST_FORMAT(uri, srv_name) HTTPC_REQ_11_HOST, uri, HTTPC_CLIENT_AGENT, srv_name
#define HTTPC_REQ_11_PROXY "GET http://%s%s HTTP/1.1\r\n" /* HOST, URI */\
#define HTTPC_REQ_11_PROXY_FORMAT(host, uri, srv_name) HTTPC_REQ_11_PROXY, host, uri, HTTPC_CLIENT_AGENT, srv_name
#define HTTPC_REQ_11_PROXY_PORT "GET http://%s:%d%s HTTP/1.1\r\n" /* HOST, host-port, URI */\
#define HTTPC_REQ_11_PROXY_PORT_FORMAT(host, host_port, uri, srv_name) HTTPC_REQ_11_PROXY_PORT, host, host_port, uri, HTTPC_CLIENT_AGENT, srv_name
typedef enum ehttpc_parse_state {
  HTTPC_PARSE_WAIT_FIRST_LINE = 0,
  HTTPC_PARSE_WAIT_HEADERS,
  HTTPC_PARSE_RX_DATA
} httpc_parse_state_t;
typedef struct _httpc_state
{
  struct altcp_pcb* pcb;
  ip_addr_t remote_addr;
  u16_t remote_port;
  int timeout_ticks;
  struct pbuf *request;
  struct pbuf *rx_hdrs;
  u16_t rx_http_version;
  u16_t rx_status;
  altcp_recv_fn recv_fn;
  const httpc_connection_t *conn_settings;
  void* callback_arg;
  u32_t rx_content_len;
  u32_t hdr_content_len;
  httpc_parse_state_t parse_state;
#if HTTPC_DEBUG_REQUEST
  char* server_name;
  char* uri;
#endif
} httpc_state_t;
#if LWIP_DNS
#endif /* LWIP_DNS */
#if LWIP_DNS
#else
#endif
#if HTTPC_DEBUG_REQUEST
#endif
#if HTTPC_DEBUG_REQUEST
#endif
#if HTTPC_DEBUG_REQUEST
#endif
#if LWIP_HTTPC_HAVE_FILE_IO
typedef struct _httpc_filestate
{
  const char* local_file_name;
  FILE *file;
  httpc_connection_t settings;
  const httpc_connection_t *client_settings;
  void *callback_arg;
} httpc_filestate_t;
httpc_fs_free(httpc_filestate_t *filestate)
{
  if (filestate != NULL) {
    if (filestate->file != NULL) {
      fclose(filestate->file);
      filestate->file = NULL;
    }
    mem_free(filestate);
  }
}
#endif /* LWIP_HTTPC_HAVE_FILE_IO */
#endif /* LWIP_TCP && LWIP_CALLBACK_API */
