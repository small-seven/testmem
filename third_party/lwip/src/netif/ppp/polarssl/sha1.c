#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_SHA1
#include "netif/ppp/polarssl/sha1.h"
#include <string.h>
#ifndef GET_ULONG_BE
#define GET_ULONG_BE(n,b,i)                             \
#endif
#ifndef PUT_ULONG_BE
#define PUT_ULONG_BE(n,b,i)                             \
#endif
#define S(x,n) ((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))
#define R(t)                                            \
#define P(a,b,c,d,e,x)                                  \
#define F(x,y,z) (z ^ (x & (y ^ z)))
#define K 0x5A827999
#undef K
#undef F
#define F(x,y,z) (x ^ y ^ z)
#define K 0x6ED9EBA1
#undef K
#undef F
#define F(x,y,z) ((x & y) | (z & (x | y)))
#define K 0x8F1BBCDC
#undef K
#undef F
#define F(x,y,z) (x ^ y ^ z)
#define K 0xCA62C1D6
#undef K
#undef F
#endif /* PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_SHA1 */
