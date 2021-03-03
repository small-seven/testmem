#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/crypto.h>
#include <openssl/buffer.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "crypto/x509.h"
#include "x509_local.h"
#define SET_HOST 0
#define ADD_HOST 1
static void str_free(char *s)
{
    OPENSSL_free(s);
}
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)
{
    if (param == NULL)
        return;
    sk_ASN1_OBJECT_pop_free(param->policies, ASN1_OBJECT_free);
    sk_OPENSSL_STRING_pop_free(param->hosts, str_free);
    OPENSSL_free(param->peername);
    OPENSSL_free(param->email);
    OPENSSL_free(param->ip);
    OPENSSL_free(param);
}
#define test_x509_verify_param_copy(field, def) \
#define x509_verify_param_copy(field, def) \
#define vpm_empty_id NULL, 0U, NULL, NULL, 0, NULL, 0
