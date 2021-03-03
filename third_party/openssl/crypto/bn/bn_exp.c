#include "internal/cryptlib.h"
#include "internal/constant_time.h"
#include "bn_local.h"
#include <stdlib.h>
#ifdef _WIN32
# include <malloc.h>
# ifndef alloca
#  define alloca _alloca
# endif
#elif defined(__GNUC__)
# ifndef alloca
#  define alloca(s) __builtin_alloca((s))
# endif
#elif defined(__sun)
# include <alloca.h>
#endif
#include "rsaz_exp.h"
#undef SPARC_T4_MONT
#if defined(OPENSSL_BN_ASM_MONT) && (defined(__sparc__) || defined(__sparc))
# include "sparc_arch.h"
# define SPARC_T4_MONT
#endif
#define TABLE_SIZE      32
#define MONT_MUL_MOD
#define MONT_EXP_WORD
#define RECP_MUL_MOD
#ifdef MONT_MUL_MOD
# ifdef MONT_EXP_WORD
# endif
#endif
#ifdef RECP_MUL_MOD
#else
#endif
#if 1                           /* by Shay Gueron's suggestion */
#endif
#if defined(SPARC_T4_MONT)
#endif
#define MOD_EXP_CTIME_ALIGN(x_) \
#if defined(SPARC_T4_MONT)
#endif
#ifdef RSAZ_ENABLED
#endif
#if defined(SPARC_T4_MONT)
#endif
#if defined(OPENSSL_BN_ASM_MONT5)
#endif
#ifdef alloca
#endif
#ifdef alloca
#endif
#if 1                           /* by Shay Gueron's suggestion */
#endif
#if defined(SPARC_T4_MONT)
        typedef int (*bn_pwr5_mont_f) (BN_ULONG *tp, const BN_ULONG *np,
                                       const BN_ULONG *n0, const void *table,
                                       int power, int bits);
        int bn_pwr5_mont_t4_8(BN_ULONG *tp, const BN_ULONG *np,
                              const BN_ULONG *n0, const void *table,
                              int power, int bits);
        int bn_pwr5_mont_t4_16(BN_ULONG *tp, const BN_ULONG *np,
                               const BN_ULONG *n0, const void *table,
                               int power, int bits);
        int bn_pwr5_mont_t4_24(BN_ULONG *tp, const BN_ULONG *np,
                               const BN_ULONG *n0, const void *table,
                               int power, int bits);
        int bn_pwr5_mont_t4_32(BN_ULONG *tp, const BN_ULONG *np,
                               const BN_ULONG *n0, const void *table,
                               int power, int bits);
        static const bn_pwr5_mont_f pwr5_funcs[4] = {
            bn_pwr5_mont_t4_8, bn_pwr5_mont_t4_16,
            bn_pwr5_mont_t4_24, bn_pwr5_mont_t4_32
        };
        typedef int (*bn_mul_mont_f) (BN_ULONG *rp, const BN_ULONG *ap,
                                      const void *bp, const BN_ULONG *np,
                                      const BN_ULONG *n0);
        int bn_mul_mont_t4_8(BN_ULONG *rp, const BN_ULONG *ap, const void *bp,
                             const BN_ULONG *np, const BN_ULONG *n0);
        int bn_mul_mont_t4_16(BN_ULONG *rp, const BN_ULONG *ap,
                              const void *bp, const BN_ULONG *np,
                              const BN_ULONG *n0);
        int bn_mul_mont_t4_24(BN_ULONG *rp, const BN_ULONG *ap,
                              const void *bp, const BN_ULONG *np,
                              const BN_ULONG *n0);
        int bn_mul_mont_t4_32(BN_ULONG *rp, const BN_ULONG *ap,
                              const void *bp, const BN_ULONG *np,
                              const BN_ULONG *n0);
        static const bn_mul_mont_f mul_funcs[4] = {
            bn_mul_mont_t4_8, bn_mul_mont_t4_16,
            bn_mul_mont_t4_24, bn_mul_mont_t4_32
        };
#endif
#if defined(OPENSSL_BN_ASM_MONT5)
# if 0
# else
# endif
#endif
#if defined(SPARC_T4_MONT)
#endif
#define BN_MOD_MUL_WORD(r, w, m) \
#define BN_TO_MONTGOMERY_WORD(r, w, mont) \
