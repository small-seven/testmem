#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/numbers.h"
#include <openssl/asn1t.h>
#include <openssl/bn.h>
#include "asn1_local.h"
#define INTxx_FLAG_ZERO_DEFAULT (1<<0)
#define INTxx_FLAG_SIGNED       (1<<1)
static void uint64_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    OPENSSL_free(*pval);
    *pval = NULL;
}
static void uint32_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    OPENSSL_free(*pval);
    *pval = NULL;
}
#define ABS_INT32_MIN ((uint32_t)INT32_MAX + 1)
