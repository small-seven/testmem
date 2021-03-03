#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#include <openssl/bn.h>
#define BN_SENSITIVE    1
static void bn_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    if (*pval == NULL)
        return;
    if (it->size & BN_SENSITIVE)
        BN_clear_free((BIGNUM *)*pval);
    else
        BN_free((BIGNUM *)*pval);
    *pval = NULL;
}
