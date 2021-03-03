#include "lwip/opt.h"
#if LWIP_NETCONN /* don't build if not configured for use in lwipopts.h */
#include "lwip/api.h"
#include "lwip/memp.h"
#include "lwip/ip.h"
#include "lwip/raw.h"
#include "lwip/udp.h"
#include "lwip/priv/api_msg.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/priv/tcpip_priv.h"
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#include <string.h>
#define API_MSG_VAR_REF(name)               API_VAR_REF(name)
#define API_MSG_VAR_DECLARE(name)           API_VAR_DECLARE(struct api_msg, name)
#define API_MSG_VAR_ALLOC(name)             API_VAR_ALLOC(struct api_msg, MEMP_API_MSG, name, ERR_MEM)
#define API_MSG_VAR_ALLOC_RETURN_NULL(name) API_VAR_ALLOC(struct api_msg, MEMP_API_MSG, name, NULL)
#define API_MSG_VAR_FREE(name)              API_VAR_FREE(MEMP_API_MSG, name)
#if TCP_LISTEN_BACKLOG
#define API_MSG_VAR_ALLOC_ACCEPT(msg) API_MSG_VAR_ALLOC(msg)
#define API_MSG_VAR_FREE_ACCEPT(msg) API_MSG_VAR_FREE(msg)
#else /* TCP_LISTEN_BACKLOG */
#define API_MSG_VAR_ALLOC_ACCEPT(msg)
#define API_MSG_VAR_FREE_ACCEPT(msg)
#endif /* TCP_LISTEN_BACKLOG */
#if LWIP_NETCONN_FULLDUPLEX
#define NETCONN_RECVMBOX_WAITABLE(conn) (sys_mbox_valid(&(conn)->recvmbox) && (((conn)->flags & NETCONN_FLAG_MBOXINVALID) == 0))
#define NETCONN_ACCEPTMBOX_WAITABLE(conn) (sys_mbox_valid(&(conn)->acceptmbox) && (((conn)->flags & (NETCONN_FLAG_MBOXCLOSED|NETCONN_FLAG_MBOXINVALID)) == 0))
#define NETCONN_MBOX_WAITING_INC(conn) SYS_ARCH_INC(conn->mbox_threads_waiting, 1)
#define NETCONN_MBOX_WAITING_DEC(conn) SYS_ARCH_DEC(conn->mbox_threads_waiting, 1)
#else /* LWIP_NETCONN_FULLDUPLEX */
#define NETCONN_RECVMBOX_WAITABLE(conn)   sys_mbox_valid(&(conn)->recvmbox)
#define NETCONN_ACCEPTMBOX_WAITABLE(conn) (sys_mbox_valid(&(conn)->acceptmbox) && (((conn)->flags & NETCONN_FLAG_MBOXCLOSED) == 0))
#define NETCONN_MBOX_WAITING_INC(conn)
#define NETCONN_MBOX_WAITING_DEC(conn)
#endif /* LWIP_NETCONN_FULLDUPLEX */
#ifdef LWIP_DEBUG
#endif /* LWIP_DEBUG */
#if LWIP_NETCONN_SEM_PER_THREAD
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if !LWIP_NETCONN_SEM_PER_THREAD
#endif /* !LWIP_NETCONN_SEM_PER_THREAD */
#if LWIP_SO_SNDTIMEO || LWIP_SO_LINGER
#else /* LWIP_SO_SNDTIMEO || LWIP_SO_LINGER */
#if LWIP_TCP
#endif /* LWIP_TCP */
#endif /* LWIP_SO_SNDTIMEO || LWIP_SO_LINGER */
#if LWIP_NETCONN_FULLDUPLEX
#endif /* LWIP_NETCONN_FULLDUPLEX */
#if LWIP_MPU_COMPATIBLE
#else /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_TCP
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#else /* LWIP_TCP */
#endif /* LWIP_TCP */
#if LWIP_TCP
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#if LWIP_SO_RCVTIMEO
#else
#endif /* LWIP_SO_RCVTIMEO*/
#if LWIP_NETCONN_FULLDUPLEX
#endif
#if TCP_LISTEN_BACKLOG
#endif /* TCP_LISTEN_BACKLOG */
#else /* LWIP_TCP */
#endif /* LWIP_TCP */
#if LWIP_SO_RCVTIMEO
#else
#endif /* LWIP_SO_RCVTIMEO*/
#if LWIP_NETCONN_FULLDUPLEX
#endif
#if LWIP_TCP
#if (LWIP_UDP || LWIP_RAW)
#endif /* (LWIP_UDP || LWIP_RAW) */
#endif /* LWIP_TCP */
#if LWIP_TCP && (LWIP_UDP || LWIP_RAW)
#endif /* LWIP_TCP && (LWIP_UDP || LWIP_RAW) */
#if (LWIP_UDP || LWIP_RAW)
#endif /* (LWIP_UDP || LWIP_RAW) */
#if LWIP_SO_RCVBUF
#endif /* LWIP_SO_RCVBUF */
#if LWIP_TCP
#if LWIP_MPU_COMPATIBLE
#endif
#endif /* LWIP_TCP */
#if LWIP_TCP
#endif /* LWIP_TCP */
#if LWIP_TCP
#if (LWIP_UDP || LWIP_RAW)
#endif /* (LWIP_UDP || LWIP_RAW) */
#endif /* LWIP_TCP */
#if LWIP_TCP && (LWIP_UDP || LWIP_RAW)
#endif /* LWIP_TCP && (LWIP_UDP || LWIP_RAW) */
#if (LWIP_UDP || LWIP_RAW)
#endif /* (LWIP_UDP || LWIP_RAW) */
#if LWIP_SO_SNDTIMEO
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_SO_SNDTIMEO
#endif /* LWIP_SO_SNDTIMEO */
#if LWIP_TCP
#if LWIP_SO_SNDTIMEO || LWIP_SO_LINGER
#else /* LWIP_SO_SNDTIMEO || LWIP_SO_LINGER */
#endif /* LWIP_SO_SNDTIMEO || LWIP_SO_LINGER */
#endif /* LWIP_TCP */
#if LWIP_IGMP || (LWIP_IPV6 && LWIP_IPV6_MLD)
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#if LWIP_IPV4
#endif /* LWIP_IPV4 */
#endif /* LWIP_IGMP || (LWIP_IPV6 && LWIP_IPV6_MLD) */
#if LWIP_DNS
#if LWIP_IPV4 && LWIP_IPV6
#else
#endif
#if !LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_MPU_COMPATIBLE
#endif
#ifdef LWIP_HOOK_NETCONN_EXTERNAL_RESOLVE
#if LWIP_IPV4 && LWIP_IPV6
#else
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#endif /* LWIP_HOOK_NETCONN_EXTERNAL_RESOLVE */
#if LWIP_MPU_COMPATIBLE
#else /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_MPU_COMPATIBLE */
#if LWIP_IPV4 && LWIP_IPV6
#endif /* LWIP_IPV4 && LWIP_IPV6 */
#if LWIP_NETCONN_SEM_PER_THREAD
#else /* LWIP_NETCONN_SEM_PER_THREAD*/
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#if !LWIP_NETCONN_SEM_PER_THREAD
#endif /* !LWIP_NETCONN_SEM_PER_THREAD */
#if LWIP_MPU_COMPATIBLE
#endif /* LWIP_MPU_COMPATIBLE */
#endif /* LWIP_DNS*/
#if LWIP_NETCONN_SEM_PER_THREAD
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_NETCONN */
