#ifdef OPENSSL_NO_CT
# error "CT is disabled"
#endif
#include <openssl/ct.h>
#include <openssl/err.h>
#include <time.h>
#include "ct_local.h"
void CT_POLICY_EVAL_CTX_free(CT_POLICY_EVAL_CTX *ctx)
{
    if (ctx == NULL)
        return;
    X509_free(ctx->cert);
    X509_free(ctx->issuer);
    OPENSSL_free(ctx);
}
