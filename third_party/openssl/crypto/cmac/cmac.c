#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "internal/cryptlib.h"
#include <openssl/cmac.h>
#include <openssl/err.h>
void CMAC_CTX_free(CMAC_CTX *ctx)
{
    if (!ctx)
        return;
    CMAC_CTX_cleanup(ctx);
    EVP_CIPHER_CTX_free(ctx->cctx);
    OPENSSL_free(ctx);
}
