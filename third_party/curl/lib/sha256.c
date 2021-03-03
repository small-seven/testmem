#include "curl_setup.h"
#ifndef CURL_DISABLE_CRYPTO_AUTH
#include "warnless.h"
#include "curl_sha256.h"
#if defined(USE_OPENSSL)
#include <openssl/opensslv.h>
#if (OPENSSL_VERSION_NUMBER >= 0x0090800fL)
#define USE_OPENSSL_SHA256
#endif
#endif /* USE_OPENSSL */
#ifdef USE_MBEDTLS
#include <mbedtls/version.h>
#if(MBEDTLS_VERSION_NUMBER >= 0x02070000)
#endif
#endif /* USE_MBEDTLS */
#if defined(USE_OPENSSL_SHA256)
#include <openssl/sha.h>
#elif defined(USE_GNUTLS_NETTLE)
#include <nettle/sha.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct sha256_ctx SHA256_CTX;

static void SHA256_Init(SHA256_CTX *ctx)
{
  sha256_init(ctx);
}
#elif defined(USE_GNUTLS)
#include <gcrypt.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef gcry_md_hd_t SHA256_CTX;

static void SHA256_Init(SHA256_CTX *ctx)
{
  gcry_md_open(ctx, GCRY_MD_SHA256, 0);
}
#elif defined(USE_MBEDTLS)
#include <mbedtls/sha256.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef mbedtls_sha256_context SHA256_CTX;

static void SHA256_Init(SHA256_CTX *ctx)
{
#if !defined(HAS_RESULT_CODE_BASED_FUNCTIONS)
  mbedtls_sha256_starts(ctx, 0);
#else
  (void) mbedtls_sha256_starts_ret(ctx, 0);
#endif
}
#if !defined(HAS_RESULT_CODE_BASED_FUNCTIONS)
#else
#endif
#if !defined(HAS_RESULT_CODE_BASED_FUNCTIONS)
#else
#endif
#elif (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && \
#include <CommonCrypto/CommonDigest.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef CC_SHA256_CTX SHA256_CTX;

static void SHA256_Init(SHA256_CTX *ctx)
{
  (void) CC_SHA256_Init(ctx);
}
#elif defined(USE_WIN32_CRYPTO)
#include <wincrypt.h>
typedef struct {
  HCRYPTPROV hCryptProv;
  HCRYPTHASH hHash;
} SHA256_CTX;
#if !defined(CALG_SHA_256)
#define CALG_SHA_256 0x0000800c
#endif
#else
#define WPA_GET_BE32(a) ((((unsigned long)(a)[0]) << 24) | \
#define WPA_PUT_BE32(a, val)                                        \
#ifdef HAVE_LONGLONG
#define WPA_PUT_BE64(a, val)                                    \
#else
#define WPA_PUT_BE64(a, val)                                  \
#endif
typedef struct sha256_state {
#ifdef HAVE_LONGLONG
  unsigned long long length;
#else
  unsigned __int64 length;
#endif
  unsigned long state[8], curlen;
  unsigned char buf[64];
} SHA256_CTX;
#define RORc(x, y) \
#define Ch(x,y,z)   (z ^ (x & (y ^ z)))
#define Maj(x,y,z)  (((x | y) & z) | (x & y))
#define S(x, n)     RORc((x), (n))
#define R(x, n)     (((x)&0xFFFFFFFFUL)>>(n))
#define Sigma0(x)   (S(x, 2) ^ S(x, 13) ^ S(x, 22))
#define Sigma1(x)   (S(x, 6) ^ S(x, 11) ^ S(x, 25))
#define Gamma0(x)   (S(x, 7) ^ S(x, 18) ^ R(x, 3))
#define Gamma1(x)   (S(x, 17) ^ S(x, 19) ^ R(x, 10))
#define RND(a,b,c,d,e,f,g,h,i)                                  \
#define block_size 64
#endif /* CRYPTO LIBS */
#endif /* CURL_DISABLE_CRYPTO_AUTH */
