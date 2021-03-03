#include "lwip/opt.h"
#if LWIP_NETCONN /* don't build if not configured for use in lwipopts.h */
#include "lwip/priv/api_msg.h"
#include "lwip/ip.h"
#include "lwip/ip_addr.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include "lwip/raw.h"
#include "lwip/memp.h"
#include "lwip/igmp.h"
#include "lwip/dns.h"
#include "lwip/mld6.h"
#include "lwip/priv/tcpip_priv.h"
#include <string.h>
#define NETCONN_TCP_POLL_INTERVAL 2
#define SET_NONBLOCKING_CONNECT(conn, val)  do { if (val) { \
#define IN_NONBLOCKING_CONNECT(conn) netconn_is_flag_set(conn, NETCONN_FLAG_IN_NONBLOCKING_CONNECT)
#if LWIP_NETCONN_FULLDUPLEX
#define NETCONN_MBOX_VALID(conn, mbox) (sys_mbox_valid(mbox) && ((conn->flags & NETCONN_FLAG_MBOXINVALID) == 0))
#else
#define NETCONN_MBOX_VALID(conn, mbox) sys_mbox_valid(mbox)
#endif
#if LWIP_TCP
#if LWIP_TCPIP_CORE_LOCKING
#define WRITE_DELAYED         , 1
#define WRITE_DELAYED_PARAM   , u8_t delayed
#else /* LWIP_TCPIP_CORE_LOCKING */
#define WRITE_DELAYED
#define WRITE_DELAYED_PARAM
#endif /* LWIP_TCPIP_CORE_LOCKING */
#endif
#if LWIP_TCPIP_CORE_LOCKING
#define TCPIP_APIMSG_ACK(m)
#else /* LWIP_TCPIP_CORE_LOCKING */
#define TCPIP_APIMSG_ACK(m)   do { sys_sem_signal(LWIP_API_MSG_SEM(m)); } while(0)
#endif /* LWIP_TCPIP_CORE_LOCKING */
#if LWIP_NETCONN_FULLDUPLEX
lwip_netconn_is_deallocated_msg(void *msg)
{
  if (msg == &netconn_deleted) {
    return 1;
  }
  return 0;
}
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_RAW
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#endif /* LWIP_RAW*/
#if LWIP_UDP
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if LWIP_SO_RCVBUF
#else  /* LWIP_SO_RCVBUF */
#endif /* LWIP_SO_RCVBUF */
#if LWIP_NETBUF_RECVINFO
#endif /* LWIP_NETBUF_RECVINFO */
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#endif /* LWIP_UDP */
#if LWIP_TCP
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if !LWIP_SO_SNDTIMEO && !LWIP_SO_LINGER
#endif /* !LWIP_SO_SNDTIMEO && !LWIP_SO_LINGER */
#endif /* LWIP_TCP */
#if LWIP_IPV6 && LWIP_IPV4
#endif
#if LWIP_RAW
#if LWIP_IPV6
#endif /* LWIP_IPV6 */
#endif /* LWIP_RAW */
#if LWIP_UDP
#if LWIP_UDPLITE
#endif /* LWIP_UDPLITE */
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif /* LWIP_TCP */
netconn_alloc(enum netconn_type t, netconn_callback callback)
{
  struct netconn *conn;
  int size;
  u8_t init_flags = 0;

  conn = (struct netconn *)memp_malloc(MEMP_NETCONN);
  if (conn == NULL) {
    return NULL;
  }

  conn->pending_err = ERR_OK;
  conn->type = t;
  conn->pcb.tcp = NULL;

  /* If all sizes are the same, every compiler should optimize this switch to nothing */
  switch (NETCONNTYPE_GROUP(t)) {
#if LWIP_RAW
    case NETCONN_RAW:
      size = DEFAULT_RAW_RECVMBOX_SIZE;
      break;
#endif /* LWIP_RAW */
#if LWIP_UDP
    case NETCONN_UDP:
      size = DEFAULT_UDP_RECVMBOX_SIZE;
#if LWIP_NETBUF_RECVINFO
      init_flags |= NETCONN_FLAG_PKTINFO;
#endif /* LWIP_NETBUF_RECVINFO */
      break;
#endif /* LWIP_UDP */
#if LWIP_TCP
    case NETCONN_TCP:
      size = DEFAULT_TCP_RECVMBOX_SIZE;
      break;
#endif /* LWIP_TCP */
    default:
      LWIP_ASSERT("netconn_alloc: undefined netconn_type", 0);
      goto free_and_return;
  }

  if (sys_mbox_new(&conn->recvmbox, size) != ERR_OK) {
    goto free_and_return;
  }
#if !LWIP_NETCONN_SEM_PER_THREAD
  if (sys_sem_new(&conn->op_completed, 0) != ERR_OK) {
    sys_mbox_free(&conn->recvmbox);
    goto free_and_return;
  }
#endif

#if LWIP_TCP
  sys_mbox_set_invalid(&conn->acceptmbox);
#endif
  conn->state        = NETCONN_NONE;
#if LWIP_SOCKET
  /* initialize socket to -1 since 0 is a valid socket */
  conn->socket       = -1;
#endif /* LWIP_SOCKET */
  conn->callback     = callback;
#if LWIP_TCP
  conn->current_msg  = NULL;
#endif /* LWIP_TCP */
#if LWIP_SO_SNDTIMEO
  conn->send_timeout = 0;
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_SO_RCVTIMEO
  conn->recv_timeout = 0;
#endif /* LWIP_SO_RCVTIMEO */
#if LWIP_SO_RCVBUF
  conn->recv_bufsize = RECV_BUFSIZE_DEFAULT;
  conn->recv_avail   = 0;
#endif /* LWIP_SO_RCVBUF */
#if LWIP_SO_LINGER
  conn->linger = -1;
#endif /* LWIP_SO_LINGER */
  conn->flags = init_flags;
  return conn;
free_and_return:
  memp_free(MEMP_NETCONN, conn);
  return NULL;
}
netconn_free(struct netconn *conn)
{
  LWIP_ASSERT("PCB must be deallocated outside this function", conn->pcb.tcp == NULL);

#if LWIP_NETCONN_FULLDUPLEX
  /* in fullduplex, netconn is drained here */
  netconn_drain(conn);
#endif /* LWIP_NETCONN_FULLDUPLEX */

  LWIP_ASSERT("recvmbox must be deallocated before calling this function",
              !sys_mbox_valid(&conn->recvmbox));
#if LWIP_TCP
  LWIP_ASSERT("acceptmbox must be deallocated before calling this function",
              !sys_mbox_valid(&conn->acceptmbox));
#endif /* LWIP_TCP */

#if !LWIP_NETCONN_SEM_PER_THREAD
  sys_sem_free(&conn->op_completed);
  sys_sem_set_invalid(&conn->op_completed);
#endif

  memp_free(MEMP_NETCONN, conn);
}
#if LWIP_NETCONN_FULLDUPLEX
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_NETCONN_FULLDUPLEX
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_TCP
#if LWIP_NETCONN_FULLDUPLEX
#endif /* LWIP_NETCONN_FULLDUPLEX */
#endif /* LWIP_TCP */
#if LWIP_NETCONN_FULLDUPLEX
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_TCP
#if LWIP_SO_LINGER
#endif /* LWIP_SO_LINGER */
#if LWIP_SO_LINGER
#endif /* LWIP_SO_LINGER */
#if LWIP_SO_LINGER
#endif /* LWIP_SO_LINGER */
#if LWIP_SO_SNDTIMEO || LWIP_SO_LINGER
#if LWIP_SO_SNDTIMEO
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_SO_LINGER
#endif
#else /* LWIP_SO_SNDTIMEO || LWIP_SO_LINGER */
#endif /* LWIP_SO_SNDTIMEO || LWIP_SO_LINGER */
#if LWIP_TCPIP_CORE_LOCKING
#endif
#endif /* LWIP_TCP */
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_TCP
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_TCP
#if LWIP_TCPIP_CORE_LOCKING
#endif /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCP */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_TCP
#if TCP_LISTEN_BACKLOG
#else  /* TCP_LISTEN_BACKLOG */
#endif /* TCP_LISTEN_BACKLOG */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_TCP */
#if LWIP_RAW
#endif
#if LWIP_UDP
#if LWIP_CHECKSUM_ON_COPY
#else /* LWIP_CHECKSUM_ON_COPY */
#endif /* LWIP_CHECKSUM_ON_COPY */
#endif /* LWIP_UDP */
#if LWIP_TCP
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#if LWIP_SO_SNDTIMEO
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_TCPIP_CORE_LOCKING
#endif
#if LWIP_TCPIP_CORE_LOCKING
#endif
#endif /* LWIP_TCP */
#if LWIP_TCP
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#else /* LWIP_TCP */
#endif /* LWIP_TCP */
#if (LWIP_UDP || LWIP_RAW)
#endif /* (LWIP_UDP || LWIP_RAW) */
#if LWIP_RAW
#endif /* LWIP_RAW */
#if LWIP_UDP
#endif /* LWIP_UDP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_TCP
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_NETCONN_FULLDUPLEX
#else /* LWIP_NETCONN_FULLDUPLEX */
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCP */
#if LWIP_IGMP || (LWIP_IPV6 && LWIP_IPV6_MLD)
#if LWIP_UDP
#if LWIP_IPV6 && LWIP_IPV6_MLD
#endif /* LWIP_IPV6 && LWIP_IPV6_MLD */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#endif /* LWIP_UDP */
#if (LWIP_TCP || LWIP_RAW)
#endif /* (LWIP_TCP || LWIP_RAW) */
#if LWIP_UDP
#if LWIP_IPV6 && LWIP_IPV6_MLD
#endif /* LWIP_IPV6 && LWIP_IPV6_MLD */
#if LWIP_IGMP
#endif /* LWIP_IGMP */
#endif /* LWIP_UDP */
#if (LWIP_TCP || LWIP_RAW)
#endif /* (LWIP_TCP || LWIP_RAW) */
#endif /* LWIP_IGMP || (LWIP_IPV6 && LWIP_IPV6_MLD) */
#if LWIP_DNS
#if LWIP_IPV4 && LWIP_IPV6
#else
#endif
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_DNS */
#endif /* LWIP_NETCONN */
