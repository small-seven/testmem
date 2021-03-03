#include "tool_setup.h"
#ifdef USE_METALINK
#include <sys/stat.h>
#include <stdlib.h>
#ifdef HAVE_FCNTL_H
#  include <fcntl.h>
#endif
#undef HAVE_NSS_CONTEXT
#ifdef USE_OPENSSL
#  include <openssl/md5.h>
#  include <openssl/sha.h>
#elif defined(USE_GNUTLS_NETTLE)
#  include <nettle/md5.h>
#  include <nettle/sha.h>
#  define MD5_CTX    struct md5_ctx
#  define SHA_CTX    struct sha1_ctx
#  define SHA256_CTX struct sha256_ctx
#elif defined(USE_GNUTLS)
#  include <gcrypt.h>
#  define MD5_CTX    gcry_md_hd_t
#  define SHA_CTX    gcry_md_hd_t
#  define SHA256_CTX gcry_md_hd_t
#elif defined(USE_NSS)
#  include <nss.h>
#  include <pk11pub.h>
#  define MD5_CTX    void *
#  define SHA_CTX    void *
#  define SHA256_CTX void *
#  define HAVE_NSS_CONTEXT
#elif (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && \
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#elif defined(USE_WIN32_CRYPTO)
#  include <wincrypt.h>
#  ifndef ALG_SID_SHA_256
#    define ALG_SID_SHA_256  12
#  endif
#  ifndef CALG_SHA_256
#    define CALG_SHA_256 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_256)
#  endif
#  define MD5_CTX    struct win32_crypto_hash
#  define SHA_CTX    struct win32_crypto_hash
#  define SHA256_CTX struct win32_crypto_hash
#else
#  error "Can't compile METALINK support without a crypto library."
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_getparam.h"
#include "tool_paramhlp.h"
#include "tool_cfgable.h"
#include "tool_metalink.h"
#include "tool_operate.h"
#include "tool_msgs.h"
#include "memdebug.h" /* keep this as LAST include */
#define GetStr(str,val) do { \
#if defined(USE_OPENSSL)
#elif defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#elif defined(USE_NSS)
#elif defined(USE_WIN32_CRYPTO)
#endif /* CRYPTO LIBS */
#ifdef O_BINARY
#endif
#ifdef HAVE_NSS_CONTEXT
#endif
#endif /* USE_METALINK */
