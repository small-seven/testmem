#include "cipher_adapt.h"
hi_void *crypto_memcpy(hi_void *dst, unsigned dstlen, const hi_void *src, unsigned len)
{
    if ((dst == NULL) || (src == NULL) || (dstlen < len)) {
        hi_err_cipher("Error: cipher call %s with invalid parameter.\n", __FUNCTION__);
        return NULL;
    }

    return memcpy(dst, src, len);
}
hi_void *crypto_memset(hi_void *dst, unsigned int dlen, unsigned val, unsigned int len)
{
    if ((dst == NULL) || (dlen < len)) {
        hi_err_cipher("Error: cipher call %s with invalid parameter.\n", __FUNCTION__);
        return NULL;
    }

    return memset(dst, val, len);
}
int crypto_memcmp(const hi_void *a, const hi_void *b, unsigned int len)
{
    if ((a == NULL) || (b == NULL)) {
        hi_err_cipher("Error: cipher call %s with invalid parameter, point is null.\n", __FUNCTION__);
        return HI_FAILURE;
    }

    if (a == b) {
        hi_err_cipher("Error: cipher call %s with invalid parameter, comparing with the same address.\n", __FUNCTION__);
        return HI_FAILURE;
    }

    return memcmp(a, b, len);
}
