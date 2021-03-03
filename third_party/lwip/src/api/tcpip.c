#include "lwip/opt.h"
#if !NO_SYS /* don't build if not configured for use in lwipopts.h */
#include "lwip/priv/tcpip_priv.h"
#include "lwip/sys.h"
#include "lwip/memp.h"
#include "lwip/mem.h"
#include "lwip/init.h"
#include "lwip/ip.h"
#include "lwip/pbuf.h"
#include "lwip/etharp.h"
#include "netif/ethernet.h"
#define TCPIP_MSG_VAR_REF(name)     API_VAR_REF(name)
#define TCPIP_MSG_VAR_DECLARE(name) API_VAR_DECLARE(struct tcpip_msg, name)
#define TCPIP_MSG_VAR_ALLOC(name)   API_VAR_ALLOC(struct tcpip_msg, MEMP_TCPIP_MSG_API, name, ERR_MEM)
#define TCPIP_MSG_VAR_FREE(name)    API_VAR_FREE(MEMP_TCPIP_MSG_API, name)
#if LWIP_TCPIP_CORE_LOCKING
#endif /* LWIP_TCPIP_CORE_LOCKING */
#if !LWIP_TIMERS
#define TCPIP_MBOX_FETCH(mbox, msg) sys_mbox_fetch(mbox, msg)
#else /* !LWIP_TIMERS */
#define TCPIP_MBOX_FETCH(mbox, msg) tcpip_timeouts_mbox_fetch(mbox, msg)
#endif /* !LWIP_TIMERS */
#if !LWIP_TCPIP_CORE_LOCKING
#endif /* !LWIP_TCPIP_CORE_LOCKING */
#if !LWIP_TCPIP_CORE_LOCKING_INPUT
#endif /* !LWIP_TCPIP_CORE_LOCKING_INPUT */
#if LWIP_TCPIP_TIMEOUT && LWIP_TIMERS
#endif /* LWIP_TCPIP_TIMEOUT && LWIP_TIMERS */
#ifdef TCPIP_THREAD_TEST
#endif
#if LWIP_TCPIP_CORE_LOCKING_INPUT
#else /* LWIP_TCPIP_CORE_LOCKING_INPUT */
#endif /* LWIP_TCPIP_CORE_LOCKING_INPUT */
#if LWIP_ETHERNET
#endif /* LWIP_ETHERNET */
#if LWIP_TCPIP_TIMEOUT && LWIP_TIMERS
#endif /* LWIP_TCPIP_TIMEOUT && LWIP_TIMERS */
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#if LWIP_TCPIP_CORE_LOCKING
#else /* LWIP_TCPIP_CORE_LOCKING */
#if !LWIP_NETCONN_SEM_PER_THREAD
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#if LWIP_NETCONN_SEM_PER_THREAD
#else /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#if !LWIP_NETCONN_SEM_PER_THREAD
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* LWIP_TCPIP_CORE_LOCKING */
#if LWIP_TCPIP_CORE_LOCKING
#endif /* LWIP_TCPIP_CORE_LOCKING */
pbuf_free_int(void *p)
{
  struct pbuf *q = (struct pbuf *)p;
  pbuf_free(q);
}
pbuf_free_callback(struct pbuf *p)
{
  return tcpip_try_callback(pbuf_free_int, p);
}
mem_free_callback(void *m)
{
  return tcpip_try_callback(mem_free, m);
}
#endif /* !NO_SYS */
