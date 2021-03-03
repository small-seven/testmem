#include "e_os.h"               /* for strncasecmp */
#include "internal/cryptlib.h"
#include <stdio.h>
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include <openssl/engine.h>
#include "crypto/asn1.h"
#include "crypto/evp.h"
#include "standard_methods.h"
typedef int sk_cmp_fn_type(const char *const *a, const char *const *b);
static STACK_OF(EVP_PKEY_ASN1_METHOD) *app_methods = NULL;

DECLARE_OBJ_BSEARCH_CMP_FN(const EVP_PKEY_ASN1_METHOD *,
                           const EVP_PKEY_ASN1_METHOD *, ameth);

static int ameth_cmp(const EVP_PKEY_ASN1_METHOD *const *a,
                     const EVP_PKEY_ASN1_METHOD *const *b)
{
    return ((*a)->pkey_id - (*b)->pkey_id);
}
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
void EVP_PKEY_asn1_free(EVP_PKEY_ASN1_METHOD *ameth)
{
    if (ameth && (ameth->pkey_flags & ASN1_PKEY_DYNAMIC)) {
        OPENSSL_free(ameth->pem_str);
        OPENSSL_free(ameth->info);
        OPENSSL_free(ameth);
    }
}
void EVP_PKEY_asn1_set_free(EVP_PKEY_ASN1_METHOD *ameth,
                            void (*pkey_free) (EVP_PKEY *pkey))
{
    ameth->pkey_free = pkey_free;
}
