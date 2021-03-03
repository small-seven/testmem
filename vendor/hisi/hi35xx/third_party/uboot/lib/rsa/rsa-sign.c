#include "mkimage.h"
#include <stdio.h>
#include <string.h>
#include <image.h>
#include <time.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/engine.h>
#if OPENSSL_VERSION_NUMBER >= 0x10000000L
#define HAVE_ERR_REMOVE_THREAD_STATE
#endif
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#endif
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#else
#endif
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#endif
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#endif
static void rsa_remove(void)
{
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x02070000fL)
	CRYPTO_cleanup_all_ex_data();
	ERR_free_strings();
#ifdef HAVE_ERR_REMOVE_THREAD_STATE
	ERR_remove_thread_state(NULL);
#else
	ERR_remove_state(0);
#endif
	EVP_cleanup();
#endif
}
static void rsa_engine_remove(ENGINE *e)
{
	if (e) {
		ENGINE_finish(e);
		ENGINE_free(e);
	}
}
#ifdef CONFIG_FIT_ENABLE_RSASSA_PSS_SUPPORT
#endif /* CONFIG_FIT_ENABLE_RSASSA_PSS_SUPPORT */
