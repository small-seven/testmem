#include "bn_local.h"
#include "internal/cryptlib.h"
#define BN_NIST_192_TOP (192+BN_BITS2-1)/BN_BITS2
#define BN_NIST_224_TOP (224+BN_BITS2-1)/BN_BITS2
#define BN_NIST_256_TOP (256+BN_BITS2-1)/BN_BITS2
#define BN_NIST_384_TOP (384+BN_BITS2-1)/BN_BITS2
#define BN_NIST_521_TOP (521+BN_BITS2-1)/BN_BITS2
#if BN_BITS2 == 64
#elif BN_BITS2 == 32
#else
# error "unsupported BN_BITS2"
#endif
#ifdef BN_DEBUG
#endif
#if BN_BITS2 == 64
# define bn_cp_64(to, n, from, m)        (to)[n] = (m>=0)?((from)[m]):0;
# define bn_64_set_0(to, n)              (to)[n] = (BN_ULONG)0;
# define bn_cp_32_naked(to, n, from, m)  (((n)&1)?(to[(n)/2]|=((m)&1)?(from[(m)/2]&BN_MASK2h):(from[(m)/2]<<32))\
# define bn_32_set_0(to, n)              (((n)&1)?(to[(n)/2]&=BN_MASK2l):(to[(n)/2]=0));
# define bn_cp_32(to,n,from,m)           ((m)>=0)?bn_cp_32_naked(to,n,from,m):bn_32_set_0(to,n)
# if defined(L_ENDIAN)
#  if defined(__arch64__)
#   define NIST_INT64 long
#  else
#   define NIST_INT64 long long
#  endif
# endif
#else
# define bn_cp_64(to, n, from, m) \
# define bn_64_set_0(to, n) \
# define bn_cp_32(to, n, from, m)        (to)[n] = (m>=0)?((from)[m]):0;
# define bn_32_set_0(to, n)              (to)[n] = (BN_ULONG)0;
# if defined(_WIN32) && !defined(__GNUC__)
#  define NIST_INT64 __int64
# elif defined(BN_LLONG)
#  define NIST_INT64 long long
# endif
#endif                          /* BN_BITS2 != 64 */
#define nist_set_192(to, from, a1, a2, a3) \
#if defined(NIST_INT64)
#else
#endif
typedef BN_ULONG (*bn_addsub_f) (BN_ULONG *, const BN_ULONG *,
                                 const BN_ULONG *, int);

#define nist_set_224(to, from, a1, a2, a3, a4, a5, a6, a7) \
        { \
        bn_cp_32(to, 0, from, (a7) - 7) \
        bn_cp_32(to, 1, from, (a6) - 7) \
        bn_cp_32(to, 2, from, (a5) - 7) \
        bn_cp_32(to, 3, from, (a4) - 7) \
        bn_cp_32(to, 4, from, (a3) - 7) \
        bn_cp_32(to, 5, from, (a2) - 7) \
        bn_cp_32(to, 6, from, (a1) - 7) \
        }
#if BN_BITS2==64
#else
#endif
#if defined(NIST_INT64) && BN_BITS2!=64
# if BN_BITS2==64
# endif
#else
# if BN_BITS2==64
# endif
#endif
#if BN_BITS2==64
#endif
#define nist_set_256(to, from, a1, a2, a3, a4, a5, a6, a7, a8) \
#if defined(NIST_INT64)
#else
#endif
#define nist_set_384(to,from,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12) \
#if defined(NIST_INT64)
#else
#endif
#define BN_NIST_521_RSHIFT      (521%BN_BITS2)
#define BN_NIST_521_LSHIFT      (BN_BITS2-BN_NIST_521_RSHIFT)
#define BN_NIST_521_TOP_MASK    ((BN_ULONG)BN_MASK2>>BN_NIST_521_LSHIFT)
#if 0
#else
#endif
