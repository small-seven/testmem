#include "curl_setup.h"
#ifdef USE_MBEDTLS
#include <mbedtls/version.h>
#if MBEDTLS_VERSION_NUMBER >= 0x02040000
#include <mbedtls/net_sockets.h>
#else
#include <mbedtls/net.h>
#endif
#include <mbedtls/ssl.h>
#include <mbedtls/certs.h>
#include <mbedtls/x509.h>
#include <mbedtls/error.h>
#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/sha256.h>
#include "urldata.h"
#include "sendf.h"
#include "inet_pton.h"
#include "mbedtls.h"
#include "vtls.h"
#include "parsedate.h"
#include "connect.h" /* for the connect timeout */
#include "select.h"
#include "multiif.h"
#include "mbedtls_threadlock.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define BACKEND connssl->backend
#if defined(USE_THREADS_POSIX) || defined(USE_THREADS_WIN32)
#define THREADING_SUPPORT
#endif
#if defined(THREADING_SUPPORT)
#endif /* THREADING_SUPPORT */
#undef MBEDTLS_DEBUG
#ifdef MBEDTLS_DEBUG
#else
#endif
#ifdef USE_NGHTTP2
#  undef HAS_ALPN
#  ifdef MBEDTLS_SSL_ALPN
#    define HAS_ALPN
#  endif
#endif
#define RSA_PUB_DER_MAX_BYTES   (38 + 2 * MBEDTLS_MPI_MAX_SIZE)
#define ECP_PUB_DER_MAX_BYTES   (30 + 2 * MBEDTLS_ECP_MAX_BYTES)
#define PUB_DER_MAX_BYTES   (RSA_PUB_DER_MAX_BYTES > ECP_PUB_DER_MAX_BYTES ? \
#ifdef THREADING_SUPPORT
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#else
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#endif /* THREADING_SUPPORT */
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#ifdef MBEDTLS_DEBUG
#endif
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#ifndef THREADING_SUPPORT
#endif /* THREADING_SUPPORT */
static void Curl_mbedtls_session_free(void *ptr)
{
  mbedtls_ssl_session_free(ptr);
  free(ptr);
}
#ifdef MBEDTLS_VERSION_C
#else
#endif
#if defined(MBEDTLS_CTR_DRBG_C)
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#ifdef MBEDTLS_ERROR_C
#endif /* MBEDTLS_ERROR_C */
#elif defined(MBEDTLS_HAVEGE_C)
#else
#endif
#if MBEDTLS_VERSION_NUMBER < 0x02070000
#else
#endif
#endif /* USE_MBEDTLS */
