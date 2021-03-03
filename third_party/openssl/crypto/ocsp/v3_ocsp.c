# include <stdio.h>
# include "internal/cryptlib.h"
# include <openssl/conf.h>
# include <openssl/asn1.h>
# include <openssl/ocsp.h>
# include "ocsp_local.h"
# include <openssl/x509v3.h>
# include "../x509v3/ext_dat.h"
static void ocsp_nonce_free(void *a)
{
    ASN1_OCTET_STRING_free(a);
}
