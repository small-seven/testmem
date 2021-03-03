#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_DES
#include "netif/ppp/polarssl/des.h"
#ifndef GET_ULONG_BE
#define GET_ULONG_BE(n,b,i)                             \
#endif
#ifndef PUT_ULONG_BE
#define PUT_ULONG_BE(n,b,i)                             \
#endif
#define DES_IP(X,Y)                                             \
#define DES_FP(X,Y)                                             \
#define DES_ROUND(X,Y)                          \
#define SWAP(a,b) { unsigned long t = a; a = b; b = t; t = 0; }
#endif /* PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_DES */
