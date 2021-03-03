#include <stdio.h>
#include <assert.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/rand_drbg.h>
#include <openssl/engine.h>
#include "crypto/evp.h"
#include "evp_local.h"
#ifndef OPENSSL_NO_ENGINE
#endif
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *ctx)
{
    EVP_CIPHER_CTX_reset(ctx);
    OPENSSL_free(ctx);
}
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifdef PTRDIFF_T
# undef PTRDIFF_T
#endif
#if defined(OPENSSL_SYS_VMS) && __INITIAL_POINTER_SIZE==64
# define PTRDIFF_T uint64_t
#else
# define PTRDIFF_T size_t
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
