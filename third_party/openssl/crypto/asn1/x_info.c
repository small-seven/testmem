#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
void X509_INFO_free(X509_INFO *x)
{
    if (x == NULL)
        return;

    X509_free(x->x509);
    X509_CRL_free(x->crl);
    X509_PKEY_free(x->x_pkey);
    OPENSSL_free(x->enc_data);
    OPENSSL_free(x);
}
