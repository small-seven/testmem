#include <string.h>
#include "internal/cryptlib.h"
#include "crypto/bn.h"
#include "ec_local.h"
#include "internal/refcount.h"
#if BN_BITS2 != 64
# define TOBN(hi,lo)    lo,hi
#else
# define TOBN(hi,lo)    ((BN_ULONG)hi<<32|lo)
#endif
#if defined(__GNUC__)
# define ALIGN32        __attribute((aligned(32)))
#elif defined(_MSC_VER)
# define ALIGN32        __declspec(align(32))
#else
# define ALIGN32
#endif
#define ALIGNPTR(p,N)   ((unsigned char *)p+N-(size_t)p%N)
#define P256_LIMBS      (256/BN_BITS2)
typedef unsigned short u16;

typedef struct {
    BN_ULONG X[P256_LIMBS];
    BN_ULONG Y[P256_LIMBS];
    BN_ULONG Z[P256_LIMBS];
} P256_POINT;
typedef struct {
    BN_ULONG X[P256_LIMBS];
    BN_ULONG Y[P256_LIMBS];
} P256_POINT_AFFINE;
typedef P256_POINT_AFFINE PRECOMP256_ROW[64];

/* structure for precomputed multiples of the generator */
struct nistz256_pre_comp_st {
    const EC_GROUP *group;      /* Parent EC_GROUP object */
    size_t w;                   /* Window size */
    /*
     * Constant time access to the X and Y coordinates of the pre-computed,
     * generator multiplies, in the Montgomery domain. Pre-calculated
     * multiplies are stored in affine form.
     */
    PRECOMP256_ROW *precomp;
    void *precomp_storage;
    CRYPTO_REF_COUNT references;
    CRYPTO_RWLOCK *lock;
};
#ifndef ECP_NISTZ256_REFERENCE_IMPLEMENTATION
#else
#endif
#if defined(ECP_NISTZ256_AVX2)
# if !(defined(__x86_64) || defined(__x86_64__) || \
#  undef ECP_NISTZ256_AVX2
# else
# endif
#endif
#if defined(ECP_NISTZ256_AVX2)
#endif
void EC_nistz256_pre_comp_free(NISTZ256_PRE_COMP *pre)
{
    int i;

    if (pre == NULL)
        return;

    CRYPTO_DOWN_REF(&pre->references, &i, pre->lock);
    REF_PRINT_COUNT("EC_nistz256", x);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    OPENSSL_free(pre->precomp_storage);
    CRYPTO_THREAD_lock_free(pre->lock);
    OPENSSL_free(pre);
}
#if defined(__x86_64) || defined(__x86_64__) || \
#if 0
#else
#endif
#else
# define ecp_nistz256_inv_mod_ord NULL
#endif
