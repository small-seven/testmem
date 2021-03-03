#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_MD4
#include "netif/ppp/polarssl/md4.h"
#include <string.h>
#ifndef GET_ULONG_LE
#define GET_ULONG_LE(n,b,i)                             \
#endif
#ifndef PUT_ULONG_LE
#define PUT_ULONG_LE(n,b,i)                             \
#endif
#define S(x,n) ((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))
#define F(x, y, z) ((x & y) | ((~x) & z))
#define P(a,b,c,d,x,s) { a += F(b,c,d) + x; a = S(a,s); }
#undef P
#undef F
#define F(x,y,z) ((x & y) | (x & z) | (y & z))
#define P(a,b,c,d,x,s) { a += F(b,c,d) + x + 0x5A827999; a = S(a,s); }
#undef P
#undef F
#define F(x,y,z) (x ^ y ^ z)
#define P(a,b,c,d,x,s) { a += F(b,c,d) + x + 0x6ED9EBA1; a = S(a,s); }
#undef F
#undef P
#endif /* PPP_SUPPORT && LWIP_INCLUDED_POLARSSL_MD4 */
