#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_MD5
#include "netif/ppp/polarssl/md5.h"
#include <string.h>
#ifndef GET_ULONG_LE
#define GET_ULONG_LE(n,b,i)                             \
#endif
#ifndef PUT_ULONG_LE
#define PUT_ULONG_LE(n,b,i)                             \
#endif
#define S(x,n) ((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))
#define P(a,b,c,d,k,s,t)                                \
#define F(x,y,z) (z ^ (x & (y ^ z)))
#undef F
#define F(x,y,z) (y ^ (z & (x ^ y)))
#undef F
#define F(x,y,z) (x ^ y ^ z)
#undef F
#define F(x,y,z) (y ^ (x | ~z))
#undef F
#endif /* PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_MD5 */
