#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && EAP_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/eap.h"
#include "netif/ppp/magic.h"
#include "netif/ppp/pppcrypt.h"
#ifdef USE_SRP
#include <t_pwd.h>
#include <t_server.h>
#include <t_client.h>
#endif /* USE_SRP */
#ifndef SHA_DIGESTSIZE
#define	SHA_DIGESTSIZE 20
#endif
#ifdef USE_SRP
#endif
#if PPP_OPTIONS
#ifdef USE_SRP
#endif
#endif /* PPP_OPTIONS */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_DATAINPUT
#endif /* PPP_DATAINPUT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if DEMAND_SUPPORT
#endif /* DEMAND_SUPPORT */
#ifdef USE_SRP
#endif
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#ifdef USE_SRP
#endif /* USE_SRP */
#if PPP_SERVER
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#if PPP_REMOTENAME
#endif /* PPP_REMOTENAME */
#ifdef USE_SRP
#endif /* USE_SRP */
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#if PPP_REMOTENAME
#endif /* PPP_REMOTENAME */
#ifdef USE_SRP
#endif /* USE_SRP */
#ifdef USE_SRP
#endif /* USE_SRP */
#if PPP_SERVER
#ifdef USE_SRP
#endif /* USE_SRP */
#if PPP_REMOTENAME
#endif /* PPP_REMOTENAME */
#if PPP_REMOTENAME
#endif /* PPP_REMOTENAME */
#ifdef USE_SRP
#endif /* USE_SRP */
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#endif /* PPP_SUPPORT && EAP_SUPPORT */
