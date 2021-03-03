#include <assert.h>
#include <openssl/bn.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#if 0
#else
# if defined(BN_DIV3W)
# elif 0
#  if BN_BITS2 == 64 && defined(__SIZEOF_INT128__) && __SIZEOF_INT128__==16
#   undef BN_ULLONG
#   define BN_ULLONG __uint128_t
#   define BN_LLONG
#  endif
#  ifdef BN_LLONG
#   define BN_DIV3W
#  endif
# endif
# if !defined(OPENSSL_NO_ASM) && !defined(OPENSSL_NO_INLINE_ASM) \
#  if defined(__GNUC__) && __GNUC__>=2
#   if defined(__i386) || defined (__i386__)
#    undef bn_div_words
#    define bn_div_words(n0,n1,d0)                \
#    define REMAINDER_IS_ALREADY_CALCULATED
#   elif defined(__x86_64) && defined(SIXTY_FOUR_BIT_LONG)
#    undef bn_div_words
#    define bn_div_words(n0,n1,d0)                \
#    define REMAINDER_IS_ALREADY_CALCULATED
#   endif                       /* __<cpu> */
#  endif                        /* __GNUC__ */
# endif                         /* OPENSSL_NO_ASM */
# if defined(BN_DIV3W)
# else
#  ifdef BN_LLONG
#   if defined(BN_LLONG) && defined(BN_DIV2W) && !defined(bn_div_words)
#   else
#   endif
#   ifndef REMAINDER_IS_ALREADY_CALCULATED
#   endif
#  else                         /* !BN_LLONG */
#   ifndef REMAINDER_IS_ALREADY_CALCULATED
#   endif
#   if defined(BN_UMULT_LOHI)
#   elif defined(BN_UMULT_HIGH)
#   else
#   endif
#  endif                        /* !BN_LLONG */
# endif                         /* !BN_DIV3W */
#endif
