#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <openssl/bn.h>
#include "internal/cryptlib.h"
#include "sparc_arch.h"
#if defined(__GNUC__) && defined(__linux)
#endif
            typedef int (*bn_mul_mont_f) (BN_ULONG *rp, const BN_ULONG *ap,
                                          const BN_ULONG *bp,
                                          const BN_ULONG *np,
                                          const BN_ULONG *n0);
            int bn_mul_mont_t4_8(BN_ULONG *rp, const BN_ULONG *ap,
                                 const BN_ULONG *bp, const BN_ULONG *np,
                                 const BN_ULONG *n0);
            int bn_mul_mont_t4_16(BN_ULONG *rp, const BN_ULONG *ap,
                                  const BN_ULONG *bp, const BN_ULONG *np,
                                  const BN_ULONG *n0);
            int bn_mul_mont_t4_24(BN_ULONG *rp, const BN_ULONG *ap,
                                  const BN_ULONG *bp, const BN_ULONG *np,
                                  const BN_ULONG *n0);
            int bn_mul_mont_t4_32(BN_ULONG *rp, const BN_ULONG *ap,
                                  const BN_ULONG *bp, const BN_ULONG *np,
                                  const BN_ULONG *n0);
            static const bn_mul_mont_f funcs[4] = {
                bn_mul_mont_t4_8, bn_mul_mont_t4_16,
                bn_mul_mont_t4_24, bn_mul_mont_t4_32
            };
#if defined(__sun) && defined(__SVR4)
#else
#endif
#if defined(__sun) && defined(__SVR4)
# if defined(__GNUC__) && __GNUC__>=2
# elif defined(__SUNPRO_C)
#pragma weak getisax
# else
# endif
#endif
#if defined(__sun) && defined(__SVR4)
#endif
# ifdef SIGEMT
# endif
# ifdef __linux
# endif
