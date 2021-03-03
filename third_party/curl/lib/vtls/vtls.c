#include "curl_setup.h"
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#include "urldata.h"
#include "vtls.h" /* generic SSL protos etc */
#include "slist.h"
#include "sendf.h"
#include "strcase.h"
#include "url.h"
#include "progress.h"
#include "share.h"
#include "multiif.h"
#include "timeval.h"
#include "curl_md5.h"
#include "warnless.h"
#include "curl_base64.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define SSLSESSION_SHARED(data) (data->share &&                        \
#define CLONE_STRING(var)                    \
#ifdef USE_SSL
#endif
#ifdef USE_SSL
#else
#endif
#ifdef USE_SSL
#if defined(USE_OPENSSL) || defined(USE_GNUTLS) || defined(USE_SCHANNEL) || \
#else
#endif
#ifdef CURL_WITH_MULTI_SSL
#else
#endif
#ifndef CURL_DISABLE_CRYPTO_AUTH
#endif
void Curl_none_session_free(void *ptr UNUSED_PARAM)
{
  (void)ptr;
}
#ifndef CURL_DISABLE_CRYPTO_AUTH
#else
#endif
#if defined(CURL_WITH_MULTI_SSL)
#elif defined(USE_WOLFSSL)
#elif defined(USE_SECTRANSP)
#elif defined(USE_GNUTLS)
#elif defined(USE_GSKIT)
#elif defined(USE_MBEDTLS)
#elif defined(USE_NSS)
#elif defined(USE_OPENSSL)
#elif defined(USE_SCHANNEL)
#elif defined(USE_MESALINK)
#elif defined(USE_BEARSSL)
#else
#error "Missing struct Curl_ssl for selected SSL backend"
#endif
#if defined(USE_WOLFSSL)
#endif
#if defined(USE_SECTRANSP)
#endif
#if defined(USE_GNUTLS)
#endif
#if defined(USE_GSKIT)
#endif
#if defined(USE_MBEDTLS)
#endif
#if defined(USE_NSS)
#endif
#if defined(USE_OPENSSL)
#endif
#if defined(USE_SCHANNEL)
#endif
#if defined(USE_MESALINK)
#endif
#if defined(USE_BEARSSL)
#endif
#ifdef CURL_DEFAULT_SSL_BACKEND
#endif
#if defined(CURL_WITH_MULTI_SSL)
#else
#endif
#else /* USE_SSL */
#endif /* !USE_SSL */
