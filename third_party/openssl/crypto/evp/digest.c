#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/engine.h>
#include "crypto/evp.h"
#include "evp_local.h"
#ifndef OPENSSL_NO_ENGINE
#endif
void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
{
    EVP_MD_CTX_reset(ctx);
    OPENSSL_free(ctx);
}
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
