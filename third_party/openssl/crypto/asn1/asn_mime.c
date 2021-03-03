#include <stdio.h>
#include "crypto/ctype.h"
#include "internal/cryptlib.h"
#include <openssl/rand.h>
#include <openssl/x509.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include "crypto/evp.h"
#include "internal/bio.h"
#include "asn1_local.h"
#define MAX_SMLEN 1024
#define mime_debug(x)           /* x */
#define MIME_INVALID    0
#define MIME_START      1
#define MIME_TYPE       2
#define MIME_NAME       3
#define MIME_VALUE      4
#define MIME_QUOTE      5
#define MIME_COMMENT    6
static void mime_hdr_free(MIME_HEADER *hdr)
{
    if (hdr == NULL)
        return;
    OPENSSL_free(hdr->name);
    OPENSSL_free(hdr->value);
    if (hdr->params)
        sk_MIME_PARAM_pop_free(hdr->params, mime_param_free);
    OPENSSL_free(hdr);
}
static void mime_param_free(MIME_PARAM *param)
{
    OPENSSL_free(param->param_name);
    OPENSSL_free(param->param_value);
    OPENSSL_free(param);
}
