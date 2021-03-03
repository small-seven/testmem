#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <openssl/bio.h>
#include "apps.h"
typedef struct prefix_ctx_st {
    char *prefix;
    int linestart;               /* flag to indicate we're at the line start */
} PREFIX_CTX;
static int prefix_destroy(BIO *b)
{
    PREFIX_CTX *ctx = BIO_get_data(b);

    OPENSSL_free(ctx->prefix);
    OPENSSL_free(ctx);
    return 1;
}
