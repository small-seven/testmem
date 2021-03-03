#include "curl_setup.h"
#if !defined(CURL_DISABLE_CRYPTO_AUTH)
#include "curl_md4.h"
#include "warnless.h"
#ifdef USE_OPENSSL
#include <openssl/opensslconf.h>
#endif /* USE_OPENSSL */
#ifdef USE_MBEDTLS
#include <mbedtls/config.h>
#include <mbedtls/version.h>
#if(MBEDTLS_VERSION_NUMBER >= 0x02070000)
#endif
#endif /* USE_MBEDTLS */
#if defined(USE_GNUTLS_NETTLE)
#include <nettle/md4.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct md4_ctx MD4_CTX;

static void MD4_Init(MD4_CTX *ctx)
{
  md4_init(ctx);
}
#elif defined(USE_GNUTLS)
#include <gcrypt.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef gcry_md_hd_t MD4_CTX;

static void MD4_Init(MD4_CTX *ctx)
{
  gcry_md_open(ctx, GCRY_MD_MD4, 0);
}
#elif defined(USE_OPENSSL) && !defined(OPENSSL_NO_MD4)
#include <openssl/md4.h>
#elif (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && \
#include <CommonCrypto/CommonDigest.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef CC_MD4_CTX MD4_CTX;

static void MD4_Init(MD4_CTX *ctx)
{
  (void)CC_MD4_Init(ctx);
}
#elif defined(USE_WIN32_CRYPTO)
#include <wincrypt.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct {
  HCRYPTPROV hCryptProv;
  HCRYPTHASH hHash;
} MD4_CTX;
#elif(defined(USE_MBEDTLS) && defined(MBEDTLS_MD4_C))
#include <mbedtls/md4.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct {
  void *data;
  unsigned long size;
} MD4_CTX;
#if !defined(HAS_MBEDTLS_RESULT_CODE_BASED_FUNCTIONS)
#else
#endif
#else
#include <string.h>
typedef unsigned int MD4_u32plus;

typedef struct {
  MD4_u32plus lo, hi;
  MD4_u32plus a, b, c, d;
  unsigned char buffer[64];
  MD4_u32plus block[16];
} MD4_CTX;
#define F(x, y, z)                      ((z) ^ ((x) & ((y) ^ (z))))
#define G(x, y, z)                      (((x) & ((y) | (z))) | ((y) & (z)))
#define H(x, y, z)                      ((x) ^ (y) ^ (z))
#define STEP(f, a, b, c, d, x, s) \
#if defined(__i386__) || defined(__x86_64__) || defined(__vax__)
#define SET(n) \
#define GET(n) \
#else
#define SET(n) \
#define GET(n) \
#endif
#endif /* CRYPTO LIBS */
#endif /* CURL_DISABLE_CRYPTO_AUTH */
