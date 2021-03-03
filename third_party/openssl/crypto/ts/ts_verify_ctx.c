#include "internal/cryptlib.h"
#include <openssl/objects.h>
#include <openssl/ts.h>
#include "ts_local.h"
void TS_VERIFY_CTX_free(TS_VERIFY_CTX *ctx)
{
    if (!ctx)
        return;

    TS_VERIFY_CTX_cleanup(ctx);
    OPENSSL_free(ctx);
}
