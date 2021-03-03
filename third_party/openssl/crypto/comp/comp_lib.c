#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/objects.h>
#include <openssl/comp.h>
#include <openssl/err.h>
#include "comp_local.h"
void COMP_CTX_free(COMP_CTX *ctx)
{
    if (ctx == NULL)
        return;
    if (ctx->meth->finish != NULL)
        ctx->meth->finish(ctx);

    OPENSSL_free(ctx);
}
