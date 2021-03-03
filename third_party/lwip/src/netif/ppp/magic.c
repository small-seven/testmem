#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/magic.h"
#if PPP_MD5_RANDM /* Using MD5 for better randomness if enabled */
#include "netif/ppp/pppcrypt.h"
#define MD5_HASH_SIZE 16
#ifdef LWIP_RAND
#endif /* LWIP_RAND */
#ifdef LWIP_RAND
#endif /* LWIP_RAND */
#else /* PPP_MD5_RANDM */
#ifndef LWIP_RAND
#endif /* LWIP_RAND */
#ifndef LWIP_RAND
#endif /* LWIP_RAND */
#ifndef LWIP_RAND
#endif /* LWIP_RAND */
#ifndef LWIP_RAND
#endif /* LWIP_RAND */
#ifdef LWIP_RAND
#else /* LWIP_RAND */
#endif /* LWIP_RAND */
#endif /* PPP_MD5_RANDM */
#endif /* PPP_SUPPORT */
