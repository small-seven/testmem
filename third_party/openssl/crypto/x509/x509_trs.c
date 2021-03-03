#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/x509v3.h>
#include "crypto/x509.h"
#define X509_TRUST_COUNT        OSSL_NELEM(trstandard)
static void trtable_free(X509_TRUST *p)
{
    if (!p)
        return;
    if (p->flags & X509_TRUST_DYNAMIC) {
        if (p->flags & X509_TRUST_DYNAMIC_NAME)
            OPENSSL_free(p->name);
        OPENSSL_free(p);
    }
}
