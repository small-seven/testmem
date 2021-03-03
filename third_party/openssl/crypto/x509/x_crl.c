#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include "crypto/x509.h"
#include <openssl/x509v3.h>
#include "x509_local.h"
void X509_CRL_METHOD_free(X509_CRL_METHOD *m)
{
    if (m == NULL || !(m->flags & X509_CRL_METHOD_DYNAMIC))
        return;
    OPENSSL_free(m);
}
