#include "netif/ppp/ppp_opts.h"
#if LWIP_PPP_API /* don't build if not configured for use in lwipopts.h */
#include "netif/ppp/pppapi.h"
#include "lwip/priv/tcpip_priv.h"
#include "netif/ppp/pppoe.h"
#include "netif/ppp/pppol2tp.h"
#include "netif/ppp/pppos.h"
#if LWIP_MPU_COMPATIBLE
#endif
#define PPPAPI_VAR_REF(name)               API_VAR_REF(name)
#define PPPAPI_VAR_DECLARE(name)           API_VAR_DECLARE(struct pppapi_msg, name)
#define PPPAPI_VAR_ALLOC(name)             API_VAR_ALLOC_POOL(struct pppapi_msg, PPPAPI_MSG, name, ERR_MEM)
#define PPPAPI_VAR_ALLOC_RETURN_NULL(name) API_VAR_ALLOC_POOL(struct pppapi_msg, PPPAPI_MSG, name, NULL)
#define PPPAPI_VAR_FREE(name)              API_VAR_FREE_POOL(PPPAPI_MSG, name)
#if PPP_NOTIFY_PHASE
#endif /* PPP_NOTIFY_PHASE */
#if PPPOS_SUPPORT
#endif /* PPPOS_SUPPORT */
#if PPPOE_SUPPORT
#endif /* PPPOE_SUPPORT */
#if PPPOL2TP_SUPPORT
#if PPPOL2TP_AUTH_SUPPORT
#else /* PPPOL2TP_AUTH_SUPPORT */
#endif /* PPPOL2TP_AUTH_SUPPORT */
#if !PPPOL2TP_AUTH_SUPPORT
#endif /* !PPPOL2TP_AUTH_SUPPORT */
#if PPPOL2TP_AUTH_SUPPORT
#endif /* PPPOL2TP_AUTH_SUPPORT */
#endif /* PPPOL2TP_SUPPORT */
#if PPP_SERVER
#endif /* PPP_SERVER */
pppapi_do_ppp_free(struct tcpip_api_call_data *m)
{
  /* cast through void* to silence alignment warnings. 
   * We know it works because the structs have been instantiated as struct pppapi_msg */
  struct pppapi_msg *msg = (struct pppapi_msg *)(void*)m;

  return ppp_free(msg->msg.ppp);
}
pppapi_free(ppp_pcb *pcb)
{
  err_t err;
  PPPAPI_VAR_DECLARE(msg);
  PPPAPI_VAR_ALLOC(msg);

  PPPAPI_VAR_REF(msg).msg.ppp = pcb;
  err = tcpip_api_call(pppapi_do_ppp_free, &PPPAPI_VAR_REF(msg).call);
  PPPAPI_VAR_FREE(msg);
  return err;
}
#endif /* LWIP_PPP_API */
