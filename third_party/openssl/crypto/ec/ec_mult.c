#include <string.h>
#include <openssl/err.h>
#include "internal/cryptlib.h"
#include "crypto/bn.h"
#include "ec_local.h"
#include "internal/refcount.h"
void EC_ec_pre_comp_free(EC_PRE_COMP *pre)
{
    int i;

    if (pre == NULL)
        return;

    CRYPTO_DOWN_REF(&pre->references, &i, pre->lock);
    REF_PRINT_COUNT("EC_ec", pre);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    if (pre->points != NULL) {
        EC_POINT **pts;

        for (pts = pre->points; *pts != NULL; pts++)
            EC_POINT_free(*pts);
        OPENSSL_free(pre->points);
    }
    CRYPTO_THREAD_lock_free(pre->lock);
    OPENSSL_free(pre);
}
#define EC_POINT_BN_set_flags(P, flags) do { \
#define EC_POINT_CSWAP(c, a, b, w, t) do {         \
#undef EC_POINT_CSWAP
#undef EC_POINT_BN_set_flags
#define EC_window_bits_for_scalar_size(b) \
