#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/objects.h>
#include <openssl/ts.h>
#include <openssl/pkcs7.h>
#include "ts_local.h"
void TS_TST_INFO_ext_free(TS_TST_INFO *a)
{
    if (!a)
        return;
    sk_X509_EXTENSION_pop_free(a->extensions, X509_EXTENSION_free);
    a->extensions = NULL;
}
