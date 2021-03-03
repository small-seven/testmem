#include "curl_setup.h"
#ifdef USE_OPENSSL
#include <limits.h>
#include "urldata.h"
#include "sendf.h"
#include "formdata.h" /* for the boundary function */
#include "url.h" /* for the ssl config check function */
#include "inet_pton.h"
#include "openssl.h"
#include "connect.h"
#include "slist.h"
#include "select.h"
#include "vtls.h"
#include "strcase.h"
#include "hostcheck.h"
#include "multiif.h"
#include "strerror.h"
#include "curl_printf.h"
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/x509v3.h>
#ifndef OPENSSL_NO_DSA
#include <openssl/dsa.h>
#endif
#include <openssl/dh.h>
#include <openssl/err.h>
#include <openssl/md5.h>
#include <openssl/conf.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/pkcs12.h>
#ifdef USE_AMISSL
#include "amigaos.h"
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090808fL) && !defined(OPENSSL_NO_OCSP)
#include <openssl/ocsp.h>
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090700fL) && /* 0.9.7 or later */     \
#define USE_OPENSSL_ENGINE
#include <openssl/engine.h>
#endif
#include "warnless.h"
#include "non-ascii.h" /* for Curl_convert_from_utf8 prototype */
#include "curl_memory.h"
#include "memdebug.h"
#define ALLOW_RENEG 1
#ifndef OPENSSL_VERSION_NUMBER
#error "OPENSSL_VERSION_NUMBER not defined"
#endif
#ifdef USE_OPENSSL_ENGINE
#include <openssl/ui.h>
#endif
#if OPENSSL_VERSION_NUMBER >= 0x00909000L
#define SSL_METHOD_QUAL const
#else
#define SSL_METHOD_QUAL
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
#define HAVE_ERR_REMOVE_THREAD_STATE 1
#endif
#if !defined(HAVE_SSLV2_CLIENT_METHOD) || \
#undef OPENSSL_NO_SSL2 /* undef first to avoid compiler warnings */
#define OPENSSL_NO_SSL2
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && /* OpenSSL 1.1.0+ */ \
#define SSLEAY_VERSION_NUMBER OPENSSL_VERSION_NUMBER
#define HAVE_X509_GET0_EXTENSIONS 1 /* added in 1.1.0 -pre1 */
#define HAVE_OPAQUE_EVP_PKEY 1 /* since 1.1.0 -pre3 */
#define HAVE_OPAQUE_RSA_DSA_DH 1 /* since 1.1.0 -pre5 */
#define CONST_EXTS const
#define HAVE_ERR_REMOVE_THREAD_STATE_DEPRECATED 1
#ifdef LIBRESSL_VERSION_NUMBER
#define ARG2_X509_signature_print (X509_ALGOR *)
#else
#define ARG2_X509_signature_print
#endif
#else
#define ASN1_STRING_get0_data(x) ASN1_STRING_data(x)
#define X509_get0_notBefore(x) X509_get_notBefore(x)
#define X509_get0_notAfter(x) X509_get_notAfter(x)
#define CONST_EXTS /* nope */
#ifndef LIBRESSL_VERSION_NUMBER
#define OpenSSL_version_num() SSLeay()
#endif
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x1000200fL) && /* 1.0.2 or later */ \
#define HAVE_X509_GET0_SIGNATURE 1
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x1000200fL) /* 1.0.2 or later */
#define HAVE_SSL_GET_SHUTDOWN 1
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10002003L && \
#define HAVE_SSL_COMP_FREE_COMPRESSION_METHODS 1
#endif
#if (OPENSSL_VERSION_NUMBER < 0x0090808fL)
#define OPENSSL_load_builtin_modules(x)
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10101000L && \
#define HAVE_KEYLOG_CALLBACK
#endif
#if ((OPENSSL_VERSION_NUMBER >= 0x10101000L) && \
#define HAVE_SSL_CTX_SET_CIPHERSUITES
#define HAVE_SSL_CTX_SET_POST_HANDSHAKE_AUTH
#endif
#if defined(LIBRESSL_VERSION_NUMBER)
#define OSSL_PACKAGE "LibreSSL"
#elif defined(OPENSSL_IS_BORINGSSL)
#define OSSL_PACKAGE "BoringSSL"
#else
#define OSSL_PACKAGE "OpenSSL"
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
#define DEFAULT_CIPHER_SELECTION NULL
#else
#define DEFAULT_CIPHER_SELECTION \
#endif
#define ENABLE_SSLKEYLOGFILE
#ifdef ENABLE_SSLKEYLOGFILE
typedef struct ssl_tap_state {
  int master_key_length;
  unsigned char master_key[SSL_MAX_MASTER_KEY_LENGTH];
  unsigned char client_random[SSL3_RANDOM_SIZE];
} ssl_tap_state_t;
#endif /* ENABLE_SSLKEYLOGFILE */
#ifdef ENABLE_SSLKEYLOGFILE
#endif
#define BACKEND connssl->backend
#define RAND_LOAD_LENGTH 1024
#ifdef ENABLE_SSLKEYLOGFILE
#ifdef HAVE_KEYLOG_CALLBACK
#else
#define KEYLOG_PREFIX      "CLIENT_RANDOM "
#define KEYLOG_PREFIX_LEN  (sizeof(KEYLOG_PREFIX) - 1)
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
#else
#endif
#endif /* !HAVE_KEYLOG_CALLBACK */
#endif /* ENABLE_SSLKEYLOGFILE */
#if defined(SSL_ERROR_WANT_ASYNC)
#endif
#if defined(SSL_ERROR_WANT_ASYNC_JOB)
#endif
#if defined(SSL_ERROR_WANT_EARLY)
#endif
#ifdef OPENSSL_IS_BORINGSSL
#else
#endif
#ifndef RANDOM_FILE
#define RANDOM_FILE "" /* doesn't matter won't be used */
#endif
#if defined(HAVE_RAND_EGD)
#ifndef EGD_SOCKET
#define EGD_SOCKET "" /* doesn't matter won't be used */
#endif
#endif
#ifndef SSL_FILETYPE_ENGINE
#define SSL_FILETYPE_ENGINE 42
#endif
#ifndef SSL_FILETYPE_PKCS12
#define SSL_FILETYPE_PKCS12 43
#endif
#ifdef USE_OPENSSL_ENGINE
#endif
#if defined(USE_OPENSSL_ENGINE) && defined(ENGINE_CTRL_GET_CMD_FROM_NAME)
#else
#endif
#ifdef USE_AMISSL
#else
#endif
#ifdef USE_OPENSSL_ENGINE
#else
#endif
#if !defined(OPENSSL_NO_RSA) && !defined(OPENSSL_IS_BORINGSSL)
#ifdef HAVE_OPAQUE_EVP_PKEY
#else
#endif
#endif
#if 0
#else
#endif
#ifdef ENABLE_SSLKEYLOGFILE
#endif
#ifdef USE_OPENSSL_ENGINE
#endif
#ifndef CONF_MFLAGS_DEFAULT_SECTION
#define CONF_MFLAGS_DEFAULT_SECTION 0x0
#endif
#ifndef CURL_DISABLE_OPENSSL_AUTO_LOAD_CONFIG
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
#else
#endif
#ifdef ENABLE_SSLKEYLOGFILE
#ifdef WIN32
#else
#endif
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
#else
#ifdef USE_OPENSSL_ENGINE
#endif
#ifdef HAVE_ERR_REMOVE_THREAD_STATE
#else
#endif
#ifdef HAVE_SSL_COMP_FREE_COMPRESSION_METHODS
#endif
#endif
#ifdef ENABLE_SSLKEYLOGFILE
#endif
#ifdef MSG_PEEK
#if defined(EAGAIN) && (EAGAIN != EWOULDBLOCK)
#endif
#ifdef ECONNABORTED
#endif
#ifdef ENETDOWN
#endif
#ifdef ENETRESET
#endif
#ifdef ESHUTDOWN
#endif
#ifdef ETIMEDOUT
#endif
#endif
#ifdef USE_OPENSSL_ENGINE
#if OPENSSL_VERSION_NUMBER >= 0x00909000L
#else
#endif
#else
#endif
#ifdef USE_OPENSSL_ENGINE
#else
#endif
#ifdef USE_OPENSSL_ENGINE
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifdef HAVE_SSL_GET_SHUTDOWN
#endif
static void Curl_ossl_session_free(void *ptr)
{
  /* free the ID */
  SSL_SESSION_free(ptr);
}
#ifdef USE_OPENSSL_ENGINE
#else
#endif
#if !defined(HAVE_ERR_REMOVE_THREAD_STATE_DEPRECATED) && \
#endif
#ifdef CURL_DOES_CONVERSIONS
#else
#ifdef CURL_DISABLE_VERBOSE_STRINGS
#endif
#endif
#ifdef ENABLE_IPV6
#else
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef OPENSSL_IS_BORINGSSL
#else
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090808fL) && !defined(OPENSSL_NO_TLSEXT) && \
#if ((OPENSSL_VERSION_NUMBER <= 0x1000201fL) /* Fixed after 1.0.2a */ || \
#endif
#endif
#endif /* USE_OPENSSL */
#ifdef SSL_CTRL_SET_MSG_CALLBACK
#ifdef SSL2_VERSION_MAJOR
#endif
#ifdef SSL3_MT_NEWSESSION_TICKET
#endif
#ifdef SSL3_MT_CERTIFICATE_STATUS
#endif
#ifdef SSL3_MT_ENCRYPTED_EXTENSIONS
#endif
#ifdef SSL3_MT_END_OF_EARLY_DATA
#endif
#ifdef SSL3_MT_KEY_UPDATE
#endif
#ifdef SSL3_MT_NEXT_PROTO
#endif
#ifdef SSL3_MT_MESSAGE_HASH
#endif
#ifdef SSL3_RT_HEADER
#endif
#ifdef SSL2_VERSION /* removed in recent versions */
#endif
#ifdef SSL3_VERSION
#endif
#ifdef TLS1_1_VERSION
#endif
#ifdef TLS1_2_VERSION
#endif
#ifdef TLS1_3_VERSION
#endif
#ifdef SSL3_RT_INNER_CONTENT_TYPE
#endif
#endif
#ifdef USE_OPENSSL
#ifdef SSL_CTRL_SET_TLSEXT_HOSTNAME
#  define use_sni(x)  sni = (x)
#else
#  define use_sni(x)  Curl_nop_stmt
#endif
#undef HAS_ALPN
#if OPENSSL_VERSION_NUMBER >= 0x10002000L \
#  define HAS_ALPN 1
#endif
#undef HAS_NPN
#if OPENSSL_VERSION_NUMBER >= 0x10001000L \
#  define HAS_NPN 1
#endif
#ifdef HAS_NPN
#ifdef USE_NGHTTP2
#endif
#endif /* HAS_NPN */
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#ifdef TLS1_3_VERSION
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#endif
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) /* 1.1.0 */
#if defined(OPENSSL_IS_BORINGSSL) || defined(LIBRESSL_VERSION_NUMBER)
#else
#endif
#ifdef TLS1_3_VERSION
#endif
#ifdef TLS1_3_VERSION
#endif
#endif
#ifdef OPENSSL_IS_BORINGSSL
typedef uint32_t ctx_option_t;
#else
typedef long ctx_option_t;
#endif

#if (OPENSSL_VERSION_NUMBER < 0x10100000L) /* 1.1.0 */
static CURLcode
set_ssl_version_min_max_legacy(ctx_option_t *ctx_options,
                              struct connectdata *conn, int sockindex)
{
#if (OPENSSL_VERSION_NUMBER < 0x1000100FL) || !defined(TLS1_3_VERSION)
  /* convoluted #if condition just to avoid compiler warnings on unused
     variable */
  struct Curl_easy *data = conn->data;
#endif
  long ssl_version = SSL_CONN_CONFIG(version);
  long ssl_version_max = SSL_CONN_CONFIG(version_max);

  switch(ssl_version) {
    case CURL_SSLVERSION_TLSv1_3:
#ifdef TLS1_3_VERSION
    {
      struct ssl_connect_data *connssl = &conn->ssl[sockindex];
      SSL_CTX_set_max_proto_version(BACKEND->ctx, TLS1_3_VERSION);
      *ctx_options |= SSL_OP_NO_TLSv1_2;
    }
#else
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#else
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#else
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#endif
#ifdef TLS1_3_VERSION
#endif
#ifdef TLS1_3_VERSION
#else
#endif
#endif
#ifdef SSL_CTRL_SET_TLSEXT_HOSTNAME
#ifdef ENABLE_IPV6
#else
#endif
#endif
#ifdef USE_TLS_SRP
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
#else
#endif
#ifdef OPENSSL_NO_SSL2
#else
#ifdef USE_TLS_SRP
#endif
#endif
#ifdef OPENSSL_NO_SSL3_METHOD
#else
#ifdef USE_TLS_SRP
#endif
#endif
#ifdef SSL_MODE_RELEASE_BUFFERS
#endif
#ifdef SSL_CTRL_SET_MSG_CALLBACK
#endif
#ifdef SSL_OP_NO_TICKET
#endif
#ifdef SSL_OP_NO_COMPRESSION
#endif
#ifdef SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG
#endif
#ifdef SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10100000L /* 1.1.0 */
#else
#  if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#    ifdef TLS1_3_VERSION
#    endif
#  endif
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10100000L /* 1.1.0 */
#else
#  if OPENSSL_VERSION_NUMBER >= 0x1000100FL
#    ifdef TLS1_3_VERSION
#    endif
#  endif
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) /* 1.1.0 */
#else
#endif
#ifdef HAS_NPN
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#ifdef HAVE_SSL_CTX_SET_CIPHERSUITES
#endif
#ifdef HAVE_SSL_CTX_SET_POST_HANDSHAKE_AUTH
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef CURL_CA_FALLBACK
#endif
#if defined(X509_V_FLAG_TRUSTED_FIRST) && !defined(X509_V_FLAG_NO_ALT_CHAINS)
#endif
#ifdef X509_V_FLAG_PARTIAL_CHAIN
#endif
#if defined(ENABLE_SSLKEYLOGFILE) && defined(HAVE_KEYLOG_CALLBACK)
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090808fL) && !defined(OPENSSL_NO_TLSEXT) && \
#endif
#if defined(OPENSSL_IS_BORINGSSL) && defined(ALLOW_RENEG)
#endif
#ifdef SSL_CTRL_SET_TLSEXT_HOSTNAME
#ifdef ENABLE_IPV6
#endif
#endif
#if defined(ENABLE_SSLKEYLOGFILE) && !defined(HAVE_KEYLOG_CALLBACK)
#endif
#ifdef SSL_ERROR_WANT_ASYNC
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#define push_certinfo(_label, _num) \
#ifdef HAVE_OPAQUE_RSA_DSA_DH
#endif
#ifdef HAVE_OPAQUE_RSA_DSA_DH
#define print_pubkey_BN(_type, _name, _num)              \
#else
#define print_pubkey_BN(_type, _name, _num)    \
#endif
#ifdef OPENSSL_IS_BORINGSSL
typedef size_t numcert_t;
#else
typedef int numcert_t;
#endif

static CURLcode get_cert_chain(struct connectdata *conn,
                               struct ssl_connect_data *connssl)

{
  CURLcode result;
  STACK_OF(X509) *sk;
  int i;
  struct Curl_easy *data = conn->data;
  numcert_t numcerts;
  BIO *mem;

  sk = SSL_get_peer_cert_chain(BACKEND->handle);
  if(!sk) {
    return CURLE_OUT_OF_MEMORY;
  }
#if defined(HAVE_X509_GET0_SIGNATURE) && defined(HAVE_X509_GET0_EXTENSIONS)
#else
#endif
#ifdef HAVE_OPAQUE_EVP_PKEY
#else
#endif
#ifdef HAVE_OPAQUE_EVP_PKEY
#else
#endif
#ifdef HAVE_OPAQUE_RSA_DSA_DH
#else
#endif
#ifndef OPENSSL_NO_DSA
#ifdef HAVE_OPAQUE_EVP_PKEY
#else
#endif
#ifdef HAVE_OPAQUE_RSA_DSA_DH
#else
#endif
#endif /* !OPENSSL_NO_DSA */
#ifdef HAVE_OPAQUE_EVP_PKEY
#else
#endif
#ifdef HAVE_OPAQUE_RSA_DSA_DH
#else
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090808fL) && !defined(OPENSSL_NO_TLSEXT) && \
#endif
#ifdef DEBUGBUILD
#endif
#ifdef LIBRESSL_VERSION_NUMBER
#if LIBRESSL_VERSION_NUMBER < 0x2070100fL
#else /* OpenSSL_version() first appeared in LibreSSL 2.7.1 */
#endif
#elif defined(OPENSSL_IS_BORINGSSL)
#elif defined(HAVE_OPENSSL_VERSION) && defined(OPENSSL_VERSION_STRING)
#else
#ifdef OPENSSL_FIPS
#endif
#endif /* OPENSSL_IS_BORINGSSL */
#if (OPENSSL_VERSION_NUMBER >= 0x0090800fL) && !defined(OPENSSL_NO_SHA256)
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090808fL) && !defined(OPENSSL_NO_TLSEXT) && \
#else
#endif
#ifdef HAVE_SSL_CTX_SET_CIPHERSUITES
#endif
#if (OPENSSL_VERSION_NUMBER >= 0x0090800fL) && !defined(OPENSSL_NO_SHA256)
#else
#endif
#endif /* USE_OPENSSL */
