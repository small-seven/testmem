#if defined(_WIN32)
# include <windows.h>
#endif
#include <stdio.h>
#include <string.h>
#include <openssl/engine.h>
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/async.h>
#include <openssl/bn.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/modes.h>
#if defined(OPENSSL_SYS_UNIX) && defined(OPENSSL_THREADS)
# undef ASYNC_POSIX
# define ASYNC_POSIX
# include <unistd.h>
#elif defined(_WIN32)
# undef ASYNC_WIN
# define ASYNC_WIN
#endif
#include "e_dasync_err.c"
# ifndef OPENSSL_NO_DYNAMIC_ENGINE
# endif
static int dasync_destroy(ENGINE *e)
{
    destroy_digests();
    destroy_ciphers();
    RSA_meth_free(dasync_rsa_method);
    ERR_unload_DASYNC_strings();
    return 1;
}
#if defined(ASYNC_WIN)
#elif defined(ASYNC_POSIX)
#endif
#define DUMMY_CHAR 'X'
#if defined(ASYNC_WIN)
#elif defined(ASYNC_POSIX)
#endif
#if defined(ASYNC_WIN)
#elif defined(ASYNC_POSIX)
#endif
#if defined(ASYNC_WIN)
#elif defined(ASYNC_POSIX)
#endif
#if defined(ASYNC_WIN)
#elif defined(ASYNC_POSIX)
#endif
#undef data
#define data(ctx) ((SHA_CTX *)EVP_MD_CTX_md_data(ctx))
