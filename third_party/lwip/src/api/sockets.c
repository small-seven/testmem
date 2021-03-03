#include "lwip/opt.h"
#if LWIP_SOCKET /* don't build if not configured for use in lwipopts.h */
#include "lwip/sockets.h"
#include "lwip/priv/sockets_priv.h"
#include "lwip/api.h"
#include "lwip/igmp.h"
#include "lwip/inet.h"
#include "lwip/tcp.h"
#include "lwip/raw.h"
#include "lwip/udp.h"
#include "lwip/memp.h"
#include "lwip/pbuf.h"
#include "lwip/netif.h"
#include "lwip/priv/tcpip_priv.h"
#include "lwip/mld6.h"
#if LWIP_CHECKSUM_ON_COPY
#include "lwip/inet_chksum.h"
#endif
#if LWIP_COMPAT_SOCKETS == 2 && LWIP_POSIX_SOCKETS_IO_NAMES
#include <stdarg.h>
#endif
#include <string.h>
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#if !LWIP_NETCONN
#undef LWIP_NETCONN
#define LWIP_NETCONN 1
#include "api_msg.c"
#include "api_lib.c"
#include "netbuf.c"
#undef LWIP_NETCONN
#define LWIP_NETCONN 0
#endif
#define API_SELECT_CB_VAR_REF(name)               API_VAR_REF(name)
#define API_SELECT_CB_VAR_DECLARE(name)           API_VAR_DECLARE(struct lwip_select_cb, name)
#define API_SELECT_CB_VAR_ALLOC(name, retblock)   API_VAR_ALLOC_EXT(struct lwip_select_cb, MEMP_SELECT_CB, name, retblock)
#define API_SELECT_CB_VAR_FREE(name)              API_VAR_FREE(MEMP_SELECT_CB, name)
#if LWIP_IPV4
#define IP4ADDR_PORT_TO_SOCKADDR(sin, ipaddr, port) do { \
#define SOCKADDR4_TO_IP4ADDR_PORT(sin, ipaddr, port) do { \
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
#define IP6ADDR_PORT_TO_SOCKADDR(sin6, ipaddr, port) do { \
#define SOCKADDR6_TO_IP6ADDR_PORT(sin6, ipaddr, port) do { \
#endif /* LWIP_IPV6 */
#if LWIP_IPV4 && LWIP_IPV6
#define IS_SOCK_ADDR_LEN_VALID(namelen)  (((namelen) == sizeof(struct sockaddr_in)) || \
#define IS_SOCK_ADDR_TYPE_VALID(name)    (((name)->sa_family == AF_INET) || \
#define SOCK_ADDR_TYPE_MATCH(name, sock) \
#define IPADDR_PORT_TO_SOCKADDR(sockaddr, ipaddr, port) do { \
#define SOCKADDR_TO_IPADDR_PORT(sockaddr, ipaddr, port) sockaddr_to_ipaddr_port(sockaddr, ipaddr, &(port))
#define DOMAIN_TO_NETCONN_TYPE(domain, type) (((domain) == AF_INET) ? \
#elif LWIP_IPV6 /* LWIP_IPV4 && LWIP_IPV6 */
#define IS_SOCK_ADDR_LEN_VALID(namelen)  ((namelen) == sizeof(struct sockaddr_in6))
#define IS_SOCK_ADDR_TYPE_VALID(name)    ((name)->sa_family == AF_INET6)
#define SOCK_ADDR_TYPE_MATCH(name, sock) 1
#define IPADDR_PORT_TO_SOCKADDR(sockaddr, ipaddr, port) \
#define SOCKADDR_TO_IPADDR_PORT(sockaddr, ipaddr, port) \
#define DOMAIN_TO_NETCONN_TYPE(domain, netconn_type) (netconn_type)
#else /*-> LWIP_IPV4: LWIP_IPV4 && LWIP_IPV6 */
#define IS_SOCK_ADDR_LEN_VALID(namelen)  ((namelen) == sizeof(struct sockaddr_in))
#define IS_SOCK_ADDR_TYPE_VALID(name)    ((name)->sa_family == AF_INET)
#define SOCK_ADDR_TYPE_MATCH(name, sock) 1
#define IPADDR_PORT_TO_SOCKADDR(sockaddr, ipaddr, port) \
#define SOCKADDR_TO_IPADDR_PORT(sockaddr, ipaddr, port) \
#define DOMAIN_TO_NETCONN_TYPE(domain, netconn_type) (netconn_type)
#endif /* LWIP_IPV6 */
#define IS_SOCK_ADDR_TYPE_VALID_OR_UNSPEC(name)    (((name)->sa_family == AF_UNSPEC) || \
#define SOCK_ADDR_TYPE_MATCH_OR_UNSPEC(name, sock) (((name)->sa_family == AF_UNSPEC) || \
#define IS_SOCK_ADDR_ALIGNED(name)      ((((mem_ptr_t)(name)) % 4) == 0)
#define LWIP_SOCKOPT_CHECK_OPTLEN(sock, optlen, opttype) do { if ((optlen) < sizeof(opttype)) { done_socket(sock); return EINVAL; }}while(0)
#define LWIP_SOCKOPT_CHECK_OPTLEN_CONN(sock, optlen, opttype) do { \
#define LWIP_SOCKOPT_CHECK_OPTLEN_CONN_PCB(sock, optlen, opttype) do { \
#define LWIP_SOCKOPT_CHECK_OPTLEN_CONN_PCB_TYPE(sock, optlen, opttype, netconntype) do { \
#define LWIP_SETGETSOCKOPT_DATA_VAR_REF(name)     API_VAR_REF(name)
#define LWIP_SETGETSOCKOPT_DATA_VAR_DECLARE(name) API_VAR_DECLARE(struct lwip_setgetsockopt_data, name)
#define LWIP_SETGETSOCKOPT_DATA_VAR_FREE(name)    API_VAR_FREE(MEMP_SOCKET_SETGETSOCKOPT_DATA, name)
#if LWIP_MPU_COMPATIBLE
#define LWIP_SETGETSOCKOPT_DATA_VAR_ALLOC(name, sock) do { \
#else /* LWIP_MPU_COMPATIBLE */
#define LWIP_SETGETSOCKOPT_DATA_VAR_ALLOC(name, sock)
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_SO_SNDRCVTIMEO_NONSTANDARD
#define LWIP_SO_SNDRCVTIMEO_OPTTYPE int
#define LWIP_SO_SNDRCVTIMEO_SET(optval, val) (*(int *)(optval) = (val))
#define LWIP_SO_SNDRCVTIMEO_GET_MS(optval)   ((long)*(const int*)(optval))
#else
#define LWIP_SO_SNDRCVTIMEO_OPTTYPE struct timeval
#define LWIP_SO_SNDRCVTIMEO_SET(optval, val)  do { \
#define LWIP_SO_SNDRCVTIMEO_GET_MS(optval) ((((const struct timeval *)(optval))->tv_sec * 1000) + (((const struct timeval *)(optval))->tv_usec / 1000))
#endif
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#ifndef LWIP_SOCKET_MAX_MEMBERSHIPS
#define LWIP_SOCKET_MAX_MEMBERSHIPS NUM_SOCKETS
#endif
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL
#if LWIP_TCPIP_CORE_LOCKING
#define LWIP_SOCKET_SELECT_DECL_PROTECT(lev)
#define LWIP_SOCKET_SELECT_PROTECT(lev)   LOCK_TCPIP_CORE()
#define LWIP_SOCKET_SELECT_UNPROTECT(lev) UNLOCK_TCPIP_CORE()
#else /* LWIP_TCPIP_CORE_LOCKING */
#define LWIP_SOCKET_SELECT_DECL_PROTECT(lev)  SYS_ARCH_DECL_PROTECT(lev)
#define LWIP_SOCKET_SELECT_PROTECT(lev)       SYS_ARCH_PROTECT(lev)
#define LWIP_SOCKET_SELECT_UNPROTECT(lev)     SYS_ARCH_UNPROTECT(lev)
#endif /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL */
#define sock_set_errno(sk, e) do { \
#if LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL
#define DEFAULT_SOCKET_EVENTCB event_callback
#else
#define DEFAULT_SOCKET_EVENTCB NULL
#endif
#if !LWIP_TCPIP_CORE_LOCKING
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
lwip_socket_thread_cleanup(void)
{
  netconn_thread_cleanup();
}
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#define sock_inc_used(sock)         1
#define sock_inc_used_locked(sock)  1
#define done_socket(sock)
#endif /* LWIP_NETCONN_FULLDUPLEX */
alloc_socket(struct netconn *newconn, int accepted)
{
  int i;
  SYS_ARCH_DECL_PROTECT(lev);
  LWIP_UNUSED_ARG(accepted);

  /* allocate a new socket identifier */
  for (i = 0; i < NUM_SOCKETS; ++i) {
    /* Protect socket array */
    SYS_ARCH_PROTECT(lev);
    if (!sockets[i].conn) {
#if LWIP_NETCONN_FULLDUPLEX
      if (sockets[i].fd_used) {
        SYS_ARCH_UNPROTECT(lev);
        continue;
      }
      sockets[i].fd_used    = 1;
      sockets[i].fd_free_pending = 0;
#endif
      sockets[i].conn       = newconn;
      /* The socket is not yet known to anyone, so no need to protect
         after having marked it as used. */
      SYS_ARCH_UNPROTECT(lev);
      sockets[i].lastdata.pbuf = NULL;
#if LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL
      LWIP_ASSERT("sockets[i].select_waiting == 0", sockets[i].select_waiting == 0);
      sockets[i].rcvevent   = 0;
      /* TCP sendbuf is empty, but the socket is not yet writable until connected
       * (unless it has been created by accept()). */
      sockets[i].sendevent  = (NETCONNTYPE_GROUP(newconn->type) == NETCONN_TCP ? (accepted != 0) : 1);
      sockets[i].errevent   = 0;
      init_waitqueue_head(&sockets[i].wq);
#endif /* LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL */
      return i + LWIP_SOCKET_OFFSET;
    }
    SYS_ARCH_UNPROTECT(lev);
  }
  return -1;
}
free_socket_locked(struct lwip_sock *sock, int is_tcp, struct netconn **conn,
                   union lwip_sock_lastdata *lastdata)
{
#if LWIP_NETCONN_FULLDUPLEX
  LWIP_ASSERT("sock->fd_used > 0", sock->fd_used > 0);
  sock->fd_used--;
  if (sock->fd_used > 0) {
    sock->fd_free_pending = LWIP_SOCK_FD_FREE_FREE | (is_tcp ? LWIP_SOCK_FD_FREE_TCP : 0);
    return 0;
  }
#else /* LWIP_NETCONN_FULLDUPLEX */
  LWIP_UNUSED_ARG(is_tcp);
#endif /* LWIP_NETCONN_FULLDUPLEX */

  *lastdata = sock->lastdata;
  sock->lastdata.pbuf = NULL;
  *conn = sock->conn;
  sock->conn = NULL;
  return 1;
}
free_socket_free_elements(int is_tcp, struct netconn *conn, union lwip_sock_lastdata *lastdata)
{
  if (lastdata->pbuf != NULL) {
    if (is_tcp) {
      pbuf_free(lastdata->pbuf);
    } else {
      netbuf_delete(lastdata->netbuf);
    }
  }
  if (conn != NULL) {
    /* netconn_prepare_delete() has already been called, here we only free the conn */
    netconn_delete(conn);
  }
}
free_socket(struct lwip_sock *sock, int is_tcp)
{
  int freed;
  struct netconn *conn;
  union lwip_sock_lastdata lastdata;
  SYS_ARCH_DECL_PROTECT(lev);

  /* Protect socket array */
  SYS_ARCH_PROTECT(lev);

  freed = free_socket_locked(sock, is_tcp, &conn, &lastdata);
  SYS_ARCH_UNPROTECT(lev);
  /* don't use 'sock' after this line, as another task might have allocated it */

  if (freed) {
    free_socket_free_elements(is_tcp, conn, &lastdata);
  }
}
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_TCP
#endif
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_TCP
#if !SOCKETS_DEBUG
#endif /* !SOCKETS_DEBUG */
#endif
#if !SOCKETS_DEBUG
#endif /* !SOCKETS_DEBUG */
#if LWIP_NETBUF_RECVINFO
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_NETBUF_RECVINFO */
#if LWIP_TCP
#endif
#if LWIP_TCP
#else /* LWIP_TCP */
#endif /* LWIP_TCP */
#if LWIP_UDP || LWIP_RAW
#else /* LWIP_UDP || LWIP_RAW */
#endif /* LWIP_UDP || LWIP_RAW */
#if (LWIP_UDP || LWIP_RAW)
#else /* (LWIP_UDP || LWIP_RAW) */
#endif /* (LWIP_UDP || LWIP_RAW) */
#if LWIP_TCP
#endif
#if LWIP_TCP
#else /* LWIP_TCP */
#endif /* LWIP_TCP */
#if LWIP_UDP || LWIP_RAW
#if LWIP_NETIF_TX_SINGLE_PBUF
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
#else /* LWIP_NETIF_TX_SINGLE_PBUF */
#endif /* LWIP_NETIF_TX_SINGLE_PBUF */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#else /* LWIP_UDP || LWIP_RAW */
#endif /* LWIP_UDP || LWIP_RAW */
#if LWIP_TCP
#else /* LWIP_TCP */
#endif /* LWIP_TCP */
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
#if LWIP_NETIF_TX_SINGLE_PBUF
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
#else /* LWIP_NETIF_TX_SINGLE_PBUF */
#endif /* LWIP_NETIF_TX_SINGLE_PBUF */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_NETBUF_RECVINFO
#endif /* LWIP_NETBUF_RECVINFO */
#if LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL
#if !LWIP_TCPIP_CORE_LOCKING
#endif
#if !LWIP_TCPIP_CORE_LOCKING
#endif
#endif /* LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL */
#if LWIP_SOCKET_SELECT
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#define lwip_select_inc_sockets_used(maxfdp1, readset, writeset, exceptset, used_sockets)
#define lwip_select_dec_sockets_used(maxfdp1, used_sockets)
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_NETCONN_SEM_PER_THREAD
#endif
#if LWIP_NETCONN_FULLDUPLEX
#endif
#if LWIP_NETCONN_SEM_PER_THREAD
#else /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#if LWIP_NETCONN_SEM_PER_THREAD
#endif
#if LWIP_NETCONN_SEM_PER_THREAD
#else /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_SOCKET_SELECT */
#if LWIP_SOCKET_POLL
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#define lwip_poll_inc_sockets_used(fds, nfds)
#define lwip_poll_dec_sockets_used(fds, nfds)
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_NETCONN_SEM_PER_THREAD
#endif
#if LWIP_NETCONN_SEM_PER_THREAD
#else /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#if LWIP_NETCONN_SEM_PER_THREAD
#endif
#if LWIP_NETCONN_SEM_PER_THREAD
#else /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_SOCKET_POLL */
#if LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL
#if !LWIP_TCPIP_CORE_LOCKING
#endif /* !LWIP_TCPIP_CORE_LOCKING */
#if !LWIP_TCPIP_CORE_LOCKING
#endif /* !LWIP_TCPIP_CORE_LOCKING */
#if LWIP_SOCKET_POLL
#endif /* LWIP_SOCKET_POLL */
#if LWIP_SOCKET_SELECT && LWIP_SOCKET_POLL
#endif /* LWIP_SOCKET_SELECT && LWIP_SOCKET_POLL */
#if LWIP_SOCKET_SELECT
#endif /* LWIP_SOCKET_SELECT */
#if LWIP_TCPIP_CORE_LOCKING
#else
#endif
#endif /* LWIP_SOCKET_SELECT || LWIP_SOCKET_POLL */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if !LWIP_TCPIP_CORE_LOCKING
#endif /* !LWIP_TCPIP_CORE_LOCKING */
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#if LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#if !LWIP_MPU_COMPATIBLE
#endif /* !LWIP_MPU_COMPATIBLE */
#if LWIP_NETCONN_SEM_PER_THREAD
#else
#endif
#if LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#if !LWIP_TCPIP_CORE_LOCKING
#if LWIP_MPU_COMPATIBLE
#else /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_MPU_COMPATIBLE */
#endif  /* LWIP_TCPIP_CORE_LOCKING */
#ifdef LWIP_HOOK_SOCKETS_GETSOCKOPT
#endif
#if LWIP_TCP
#endif /* LWIP_TCP */
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_SO_SNDTIMEO
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_SO_RCVTIMEO
#endif /* LWIP_SO_RCVTIMEO */
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if LWIP_SO_LINGER
#endif /* LWIP_SO_LINGER */
#if LWIP_UDP
#if LWIP_UDPLITE
#endif /* LWIP_UDPLITE */
#endif /* LWIP_UDP*/
#if LWIP_IPV4 && LWIP_MULTICAST_TX_OPTIONS && LWIP_UDP
#endif /* LWIP_IPV4 && LWIP_MULTICAST_TX_OPTIONS && LWIP_UDP */
#if LWIP_TCP
#if LWIP_TCP_KEEPALIVE
#endif /* LWIP_TCP_KEEPALIVE */
#endif /* LWIP_TCP */
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#if LWIP_UDP && LWIP_UDPLITE
#endif /* LWIP_UDP */
#if LWIP_IPV6 && LWIP_RAW
#endif /* LWIP_IPV6 && LWIP_RAW */
#if !LWIP_TCPIP_CORE_LOCKING
#endif /* !LWIP_TCPIP_CORE_LOCKING */
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#if LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_MPU_COMPATIBLE
#else /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_NETCONN_SEM_PER_THREAD
#else
#endif
#endif  /* LWIP_TCPIP_CORE_LOCKING */
#if !LWIP_TCPIP_CORE_LOCKING
#if LWIP_MPU_COMPATIBLE
#else /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_MPU_COMPATIBLE */
#endif  /* LWIP_TCPIP_CORE_LOCKING */
#ifdef LWIP_HOOK_SOCKETS_SETSOCKOPT
#endif
#if SO_REUSE
#endif /* SO_REUSE */
#if LWIP_SO_SNDTIMEO
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_SO_RCVTIMEO
#endif /* LWIP_SO_RCVTIMEO */
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if LWIP_SO_LINGER
#endif /* LWIP_SO_LINGER */
#if LWIP_UDP
#if LWIP_UDPLITE
#endif /* LWIP_UDPLITE */
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif
#if LWIP_UDP
#endif
#if LWIP_RAW
#endif
#if LWIP_NETBUF_RECVINFO
#endif /* LWIP_NETBUF_RECVINFO */
#if LWIP_IPV4 && LWIP_MULTICAST_TX_OPTIONS && LWIP_UDP
#endif /* LWIP_IPV4 && LWIP_MULTICAST_TX_OPTIONS && LWIP_UDP */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_TCP
#if LWIP_TCP_KEEPALIVE
#endif /* LWIP_TCP_KEEPALIVE */
#endif /* LWIP_TCP*/
#if LWIP_IPV6
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#endif /* LWIP_IPV6 */
#if LWIP_UDP && LWIP_UDPLITE
#endif /* LWIP_UDP */
#if LWIP_IPV6 && LWIP_RAW
#endif /* LWIP_IPV6 && LWIP_RAW */
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if LWIP_SO_RCVBUF || LWIP_FIONREAD_LINUXMODE
#if LWIP_FIONREAD_LINUXMODE
#endif /* LWIP_FIONREAD_LINUXMODE */
#if LWIP_SO_RCVBUF
#else /* LWIP_SO_RCVBUF */
#endif /* LWIP_SO_RCVBUF */
#endif /* LWIP_SO_RCVBUF || LWIP_FIONREAD_LINUXMODE */
#if LWIP_TCPIP_CORE_LOCKING
#else
#endif
#if LWIP_TCP
#endif
#if LWIP_TCPIP_CORE_LOCKING
#else
#endif
#if LWIP_COMPAT_SOCKETS == 2 && LWIP_POSIX_SOCKETS_IO_NAMES
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IPV4
#endif
#if LWIP_IPV6
#endif
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#if LWIP_IPV6_MLD
#endif /* LWIP_IPV6_MLD */
#endif /* LWIP_SOCKET */
