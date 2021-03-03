#include <assert.h>
#include <limits.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#include <openssl/opensslconf.h>
#include "internal/constant_time.h"
#if OPENSSL_API_COMPAT < 0x00908000L
#endif
#if BN_BITS2 > 32
#endif
void BN_clear_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (a->d != NULL && !BN_get_flags(a, BN_FLG_STATIC_DATA))
        bn_free_d(a, 1);
    if (BN_get_flags(a, BN_FLG_MALLOCED)) {
        OPENSSL_cleanse(a, sizeof(*a));
        OPENSSL_free(a);
    }
}
void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}
#define FLAGS_DATA(flags) ((flags) & (BN_FLG_STATIC_DATA \
#define FLAGS_STRUCT(flags) ((flags) & (BN_FLG_MALLOCED))
typedef enum {big, little} endianess_t;

/* ignore negative */
static
int bn2binpad(const BIGNUM *a, unsigned char *to, int tolen, endianess_t endianess)
{
    int n;
    size_t i, lasti, j, atop, mask;
    BN_ULONG l;

    /*
     * In case |a| is fixed-top, BN_num_bytes can return bogus length,
     * but it's assumed that fixed-top inputs ought to be "nominated"
     * even for padded output, so it works out...
     */
    n = BN_num_bytes(a);
    if (tolen == -1) {
        tolen = n;
    } else if (tolen < n) {     /* uncommon/unlike case */
#define BN_CONSTTIME_SWAP_FLAGS (BN_FLG_CONSTTIME | BN_FLG_FIXED_TOP)
#undef BN_CONSTTIME_SWAP_FLAGS
void BN_GENCB_free(BN_GENCB *cb)
{
    if (cb == NULL)
        return;
    OPENSSL_free(cb);
}
