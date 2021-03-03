#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "internal/cryptlib.h"
#include <openssl/hmac.h>
#include <openssl/opensslconf.h>
#include "hmac_local.h"
#if OPENSSL_API_COMPAT < 0x10100000L
#endif
void HMAC_CTX_free(HMAC_CTX *ctx)
{
    if (ctx != NULL) {
        hmac_ctx_cleanup(ctx);
        EVP_MD_CTX_free(ctx->i_ctx);
        EVP_MD_CTX_free(ctx->o_ctx);
        EVP_MD_CTX_free(ctx->md_ctx);
        OPENSSL_free(ctx);
    }
}
