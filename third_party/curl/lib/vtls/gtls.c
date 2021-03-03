#include "curl_setup.h"
#ifdef USE_GNUTLS
#include <gnutls/abstract.h>
#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#ifdef USE_GNUTLS_NETTLE
#include <gnutls/crypto.h>
#include <nettle/md5.h>
#include <nettle/sha2.h>
#else
#include <gcrypt.h>
#endif
#include "urldata.h"
#include "sendf.h"
#include "inet_pton.h"
#include "gtls.h"
#include "vtls.h"
#include "parsedate.h"
#include "connect.h" /* for the connect timeout */
#include "select.h"
#include "strcase.h"
#include "warnless.h"
#include "x509asn1.h"
#include "multiif.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef GTLSDEBUG
#endif
#if defined(GNUTLS_VERSION_NUMBER)
#  if (GNUTLS_VERSION_NUMBER >= 0x020c00)
#    undef gnutls_transport_set_lowat
#    define gnutls_transport_set_lowat(A,B) Curl_nop_stmt
#    define USE_GNUTLS_PRIORITY_SET_DIRECT 1
#  endif
#  if (GNUTLS_VERSION_NUMBER >= 0x020c03)
#    define GNUTLS_MAPS_WINSOCK_ERRORS 1
#  endif
#  if HAVE_GNUTLS_ALPN_SET_PROTOCOLS
#    define HAS_ALPN
#  endif
#  if HAVE_GNUTLS_OCSP_REQ_INIT
#    define HAS_OCSP
#  endif
#  if (GNUTLS_VERSION_NUMBER >= 0x030306)
#    define HAS_CAPATH
#  endif
#endif
#if (GNUTLS_VERSION_NUMBER >= 0x030603)
#define HAS_TLS13
#endif
#ifdef HAS_OCSP
# include <gnutls/ocsp.h>
#endif
#ifdef USE_TLS_SRP
#endif
#define BACKEND connssl->backend
#if defined(USE_WINSOCK) && !defined(GNUTLS_MAPS_WINSOCK_ERRORS)
#  define gtls_EINTR  4
#  define gtls_EIO    5
#  define gtls_EAGAIN 11
#endif
#if defined(USE_WINSOCK) && !defined(GNUTLS_MAPS_WINSOCK_ERRORS)
#endif
#if defined(USE_WINSOCK) && !defined(GNUTLS_MAPS_WINSOCK_ERRORS)
#endif
#ifdef GTLSDEBUG
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifndef USE_GNUTLS_PRIORITY_SET_DIRECT
#ifdef HAS_TLS13
#endif
#ifdef HAS_TLS13
#else
#endif
#else
#define GNUTLS_CIPHERS "NORMAL:-ARCFOUR-128:-CTYPE-ALL:+CTYPE-X509"
#define GNUTLS_SRP "+SRP"
#ifdef HAS_TLS13
#else
#endif
#ifdef HAS_TLS13
#endif
#ifdef HAS_TLS13
#endif
#ifdef HAS_TLS13
#endif
#ifdef HAS_TLS13
#endif
#endif
#ifdef ENABLE_IPV6
#else
#endif
#ifndef USE_GNUTLS_PRIORITY_SET_DIRECT
#else
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef HAS_CAPATH
#endif
#ifdef CURL_CA_FALLBACK
#endif
#if defined(GNUTLS_FORCE_CLIENT_CERT)
#endif
#if defined(GNUTLS_NO_TICKETS)
#endif
#ifdef ENABLE_IPV6
#endif
#ifndef USE_GNUTLS_PRIORITY_SET_DIRECT
#ifdef HAS_TLS13
#endif
#else
#ifdef HAS_TLS13
#endif
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#if HAVE_GNUTLS_CERTIFICATE_SET_X509_KEY_FILE2
#else
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef HAS_OCSP
#endif
#ifdef HAS_ALPN
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef HAS_OCSP
#endif
#if GNUTLS_VERSION_NUMBER < 0x030306
#ifdef ENABLE_IPV6
#else
#endif
#ifdef ENABLE_IPV6
#endif
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#ifdef USE_TLS_SRP
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifdef USE_TLS_SRP
#endif
static void Curl_gtls_session_free(void *ptr)
{
  free(ptr);
}
#ifndef USE_GNUTLS_NETTLE
#endif
#if defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#endif
#if defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#endif
#if defined(USE_GNUTLS_NETTLE)
#elif defined(USE_GNUTLS)
#endif
#ifdef HAS_OCSP
#else
#endif
#endif /* USE_GNUTLS */
