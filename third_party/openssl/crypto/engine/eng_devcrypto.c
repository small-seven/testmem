#include "e_os.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <assert.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/objects.h>
#include <crypto/cryptodev.h>
#include "crypto/engine.h"
#if CRYPTO_ALGORITHM_MIN < CRYPTO_ALGORITHM_MAX
# define CHECK_BSD_STYLE_MACROS
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_CAST
#endif
#ifndef OPENSSL_NO_RC4
#endif
#if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_AES_CTR)
#endif
#if 0                            /* Not yet supported */
#endif
#if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_AES_ECB)
#endif
#if 0                            /* Not yet supported */
#endif
#ifndef OPENSSL_NO_CAMELLIA
#endif
#if !defined(COP_FLAG_WRITE_IV)
#endif
#if !defined(COP_FLAG_WRITE_IV)
#else
#endif
#if !defined(COP_FLAG_WRITE_IV)
#endif
#if defined(CIOCCPHASH) && defined(COP_FLAG_UPDATE) && defined(COP_FLAG_FINAL)
#define IMPLEMENT_DIGEST
#ifndef OPENSSL_NO_MD5
#endif
#ifndef OPENSSL_NO_RMD160
# if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_RIPEMD160)
# endif
#endif
#if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_SHA2_224)
#endif
#if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_SHA2_256)
#endif
#if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_SHA2_384)
#endif
#if !defined(CHECK_BSD_STYLE_MACROS) || defined(CRYPTO_SHA2_512)
#endif
#endif
#ifdef IMPLEMENT_DIGEST
#endif
#ifndef ENGINE_DEVCRYPTO_DEBUG
#endif
#ifdef IMPLEMENT_DIGEST
#endif
#if 0
# ifndef OPENSSL_NO_RSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DH
# endif
# ifndef OPENSSL_NO_EC
# endif
#endif
#ifdef IMPLEMENT_DIGEST
#endif
