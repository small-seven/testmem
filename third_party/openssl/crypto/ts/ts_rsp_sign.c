#include "e_os.h"
#include "internal/cryptlib.h"
#include <openssl/objects.h>
#include <openssl/ts.h>
#include <openssl/pkcs7.h>
#include <openssl/crypto.h>
#include "ts_local.h"
#if defined(OPENSSL_SYS_UNIX)
#else
#endif
void TS_RESP_CTX_free(TS_RESP_CTX *ctx)
{
    if (!ctx)
        return;

    X509_free(ctx->signer_cert);
    EVP_PKEY_free(ctx->signer_key);
    sk_X509_pop_free(ctx->certs, X509_free);
    sk_ASN1_OBJECT_pop_free(ctx->policies, ASN1_OBJECT_free);
    ASN1_OBJECT_free(ctx->default_policy);
    sk_EVP_MD_free(ctx->mds);   /* No EVP_MD_free method exists. */
    ASN1_INTEGER_free(ctx->seconds);
    ASN1_INTEGER_free(ctx->millis);
    ASN1_INTEGER_free(ctx->micros);
    OPENSSL_free(ctx);
}
#define TS_RESP_CTX_accuracy_free(ctx)          \
