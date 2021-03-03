#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/objects.h>
#include <openssl/x509v3.h>
#include <openssl/ts.h>
#include "ts_local.h"
void TS_REQ_ext_free(TS_REQ *a)
{
    if (!a)
        return;
    sk_X509_EXTENSION_pop_free(a->extensions, X509_EXTENSION_free);
    a->extensions = NULL;
}
