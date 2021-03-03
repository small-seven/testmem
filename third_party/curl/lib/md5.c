#include "curl_setup.h"
#ifndef CURL_DISABLE_CRYPTO_AUTH
#include <curl/curl.h>
#include "curl_md5.h"
#include "curl_hmac.h"
#include "warnless.h"
#ifdef USE_MBEDTLS
#include <mbedtls/version.h>
#if(MBEDTLS_VERSION_NUMBER >= 0x02070000)
#endif
#endif /* USE_MBEDTLS */
#if defined(USE_GNUTLS_NETTLE)
#include <nettle/md5.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct md5_ctx MD5_CTX;

static void MD5_Init(MD5_CTX *ctx)
{
  md5_init(ctx);
}
#elif defined(USE_GNUTLS)
#include <gcrypt.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef gcry_md_hd_t MD5_CTX;

static void MD5_Init(MD5_CTX *ctx)
{
  gcry_md_open(ctx, GCRY_MD_MD5, 0);
}
#elif defined(USE_OPENSSL) && !defined(USE_AMISSL)
#include <openssl/md5.h>
#include "curl_memory.h"
#include "memdebug.h"
#elif defined(USE_MBEDTLS)
#include <mbedtls/md5.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef mbedtls_md5_context MD5_CTX;

static void MD5_Init(MD5_CTX *ctx)
{
#if !defined(HAS_MBEDTLS_RESULT_CODE_BASED_FUNCTIONS)
  mbedtls_md5_starts(ctx);
#else
  (void) mbedtls_md5_starts_ret(ctx);
#endif
}
#if !defined(HAS_MBEDTLS_RESULT_CODE_BASED_FUNCTIONS)
#else
#endif
#if !defined(HAS_MBEDTLS_RESULT_CODE_BASED_FUNCTIONS)
#else
#endif
#elif (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && \
#  include <CommonCrypto/CommonDigest.h>
#  define MD5_CTX CC_MD5_CTX
#include "curl_memory.h"
#include "memdebug.h"
#elif defined(USE_WIN32_CRYPTO)
#include <wincrypt.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct {
  HCRYPTPROV hCryptProv;
  HCRYPTHASH hHash;
} MD5_CTX;
#else
#include <string.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef unsigned int MD5_u32plus;

typedef struct {
  MD5_u32plus lo, hi;
  MD5_u32plus a, b, c, d;
  unsigned char buffer[64];
  MD5_u32plus block[16];
} MD5_CTX;
#define F(x, y, z)                      ((z) ^ ((x) & ((y) ^ (z))))
#define G(x, y, z)                      ((y) ^ ((z) & ((x) ^ (y))))
#define H(x, y, z)                      (((x) ^ (y)) ^ (z))
#define H2(x, y, z)                     ((x) ^ ((y) ^ (z)))
#define I(x, y, z)                      ((y) ^ ((x) | ~(z)))
#define STEP(f, a, b, c, d, x, t, s) \
#if defined(__i386__) || defined(__x86_64__) || defined(__vax__)
#define SET(n) \
#define GET(n) \
#else
#define SET(n) \
#define GET(n) \
#endif
#endif /* CRYPTO LIBS */
#endif /* CURL_DISABLE_CRYPTO_AUTH */
