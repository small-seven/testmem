#include <stdio.h>
#include <time.h>
#include <errno.h>
#include "internal/cryptlib.h"
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include <openssl/ossl_typ.h>
#include "x509_local.h"
void X509_LOOKUP_meth_free(X509_LOOKUP_METHOD *method)
{
    if (method != NULL)
        OPENSSL_free(method->name);
    OPENSSL_free(method);
}
int X509_LOOKUP_meth_set_free(
    X509_LOOKUP_METHOD *method,
    void (*free_fn) (X509_LOOKUP *ctx))
{
    method->free = free_fn;
    return 1;
}
void (*X509_LOOKUP_meth_get_free(const X509_LOOKUP_METHOD* method))
    (X509_LOOKUP *ctx)
{
    return method->free;
}
