#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#if !(OPENSSL_API_COMPAT < 0x10200000L)
#else
#define COPY_SIZE(a, b) (sizeof(a) < sizeof(b) ? sizeof(a) : sizeof(b))
static void long_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    memcpy(pval, &it->size, COPY_SIZE(*pval, it->size));
}
#endif
