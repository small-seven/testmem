#include "curl_setup.h"
#ifdef USE_WOLFSSL
#define WOLFSSL_OPTIONS_IGNORE_SYS
#include <wolfssl/version.h>
#include <wolfssl/options.h>
#ifndef HAVE_ALPN
#ifdef HAVE_WOLFSSL_USEALPN
#define HAVE_ALPN
#endif
#endif
#ifndef WOLFSSL_ALLOW_SSLV3
#if (LIBWOLFSSL_VERSION_HEX < 0x03006006) || \
#define WOLFSSL_ALLOW_SSLV3
#endif
#endif
#include <limits.h>
#include "urldata.h"
#include "sendf.h"
#include "inet_pton.h"
#include "vtls.h"
#include "parsedate.h"
#include "connect.h" /* for the connect timeout */
#include "select.h"
#include "strcase.h"
#include "x509asn1.h"
#include "curl_printf.h"
#include "multiif.h"
#include <wolfssl/openssl/ssl.h>
#include <wolfssl/ssl.h>
#include <wolfssl/error-ssl.h>
#include "wolfssl.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef KEEP_PEER_CERT
#if defined(HAVE_WOLFSSL_GET_PEER_CERTIFICATE) || \
#define KEEP_PEER_CERT
#endif
#endif
#define BACKEND connssl->backend
#ifdef HAVE_SNI
#define use_sni(x)  sni = (x)
#else
#define use_sni(x)  Curl_nop_stmt
#endif
#if LIBWOLFSSL_VERSION_HEX >= 0x03003000 /* >= 3.3.0 */
#else
#endif
#ifdef WOLFSSL_ALLOW_TLSV10
#else
#endif
#ifdef WOLFSSL_TLS13
#else
#endif
#ifdef WOLFSSL_ALLOW_SSLV3
#else
#endif
#if LIBWOLFSSL_VERSION_HEX > 0x03004006 /* > 3.4.6 */
#ifdef WOLFSSL_TLS13
#endif
#endif
#ifndef NO_FILESYSTEM
#endif /* !NO_FILESYSTEM */
#ifdef HAVE_SNI
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#endif
#ifdef NO_FILESYSTEM
#endif
#ifdef HAVE_ALPN
#ifdef USE_NGHTTP2
#endif
#endif /* HAVE_ALPN */
#if 1
#else
#endif
#if LIBWOLFSSL_VERSION_HEX >= 0x02007000 /* 2.7.0 */
#endif
#ifdef KEEP_PEER_CERT
#else
#endif
#ifdef HAVE_ALPN
#ifdef USE_NGHTTP2
#endif
#endif /* HAVE_ALPN */
#if (LIBWOLFSSL_VERSION_HEX >= 0x03009010)
#else
#endif
static void Curl_wolfssl_session_free(void *ptr)
{
  (void)ptr;
  /* wolfSSL reuses sessions on own, no free */
}
#if LIBWOLFSSL_VERSION_HEX >= 0x03006000
#elif defined(WOLFSSL_VERSION)
#endif
#ifdef KEEP_PEER_CERT
#endif
#endif
