#include "curl_setup.h"
#if defined(USE_NTLM)
#if !defined(USE_WINDOWS_SSPI) || defined(USE_WIN32_CRYPTO)
#ifdef USE_OPENSSL
#  include <openssl/des.h>
#  include <openssl/md5.h>
#  include <openssl/ssl.h>
#  include <openssl/rand.h>
#  if (OPENSSL_VERSION_NUMBER < 0x00907001L)
#    define DES_key_schedule des_key_schedule
#    define DES_cblock des_cblock
#    define DES_set_odd_parity des_set_odd_parity
#    define DES_set_key des_set_key
#    define DES_ecb_encrypt des_ecb_encrypt
#    define DESKEY(x) x
#    define DESKEYARG(x) x
#  else
#    define DESKEYARG(x) *x
#    define DESKEY(x) &x
#  endif
#elif defined(USE_GNUTLS_NETTLE)
#  include <nettle/des.h>
#elif defined(USE_GNUTLS)
#  include <gcrypt.h>
#  define MD5_DIGEST_LENGTH 16
#elif defined(USE_NSS)
#  include <nss.h>
#  include <pk11pub.h>
#  include <hasht.h>
#  define MD5_DIGEST_LENGTH MD5_LENGTH
#elif defined(USE_MBEDTLS)
#  include <mbedtls/des.h>
#  include "curl_md4.h"
#elif defined(USE_SECTRANSP)
#  include <CommonCrypto/CommonCryptor.h>
#  include <CommonCrypto/CommonDigest.h>
#elif defined(USE_OS400CRYPTO)
#  include "cipher.mih"  /* mih/cipher */
#elif defined(USE_WIN32_CRYPTO)
#  include <wincrypt.h>
#else
#  error "Can't compile NTLM support without a crypto library."
#endif
#include "urldata.h"
#include "non-ascii.h"
#include "strcase.h"
#include "curl_ntlm_core.h"
#include "curl_md5.h"
#include "curl_hmac.h"
#include "warnless.h"
#include "curl_endian.h"
#include "curl_des.h"
#include "curl_md4.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define NTLMv2_BLOB_SIGNATURE "\x01\x01\x00\x00"
#define NTLMv2_BLOB_LEN       (44 -16 + ntlm->target_info_len + 4)
#ifdef USE_OPENSSL
#elif defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#elif defined(USE_NSS)
#elif defined(USE_MBEDTLS)
#elif defined(USE_SECTRANSP)
#elif defined(USE_OS400CRYPTO)
#elif defined(USE_WIN32_CRYPTO)
#endif /* defined(USE_WIN32_CRYPTO) */
#ifdef USE_OPENSSL
#elif defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#elif defined(USE_NSS) || defined(USE_MBEDTLS) || defined(USE_SECTRANSP) \
#endif
#ifdef USE_OPENSSL
#elif defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#elif defined(USE_NSS) || defined(USE_MBEDTLS) || defined(USE_SECTRANSP) \
#endif
#ifdef USE_NTRESPONSES
#if defined(USE_NTLM_V2) && !defined(USE_WINDOWS_SSPI)
#endif /* USE_NTLM_V2 && !USE_WINDOWS_SSPI */
#if defined(USE_NTLM_V2) && !defined(USE_WINDOWS_SSPI)
#if CURL_SIZEOF_CURL_OFF_T < 8
#error "this section needs 64bit support to work"
#endif
#ifdef DEBUGBUILD
#endif
#endif /* USE_NTLM_V2 && !USE_WINDOWS_SSPI */
#endif /* USE_NTRESPONSES */
#endif /* !USE_WINDOWS_SSPI || USE_WIN32_CRYPTO */
#endif /* USE_NTLM */
