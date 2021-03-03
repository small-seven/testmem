#include "curl_setup.h"
#ifndef CURL_DISABLE_HTTP
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_NET_IF_H
#include <net/if.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include "urldata.h"
#include <curl/curl.h>
#include "transfer.h"
#include "sendf.h"
#include "formdata.h"
#include "mime.h"
#include "progress.h"
#include "curl_base64.h"
#include "cookie.h"
#include "vauth/vauth.h"
#include "vtls/vtls.h"
#include "http_digest.h"
#include "http_ntlm.h"
#include "curl_ntlm_wb.h"
#include "http_negotiate.h"
#include "url.h"
#include "share.h"
#include "hostip.h"
#include "http.h"
#include "select.h"
#include "parsedate.h" /* for the week day and month names */
#include "strtoofft.h"
#include "multiif.h"
#include "strcase.h"
#include "content_encoding.h"
#include "http_proxy.h"
#include "warnless.h"
#include "non-ascii.h"
#include "http2.h"
#include "connect.h"
#include "strdup.h"
#include "altsvc.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef CURL_DISABLE_PROXY
#endif
#ifdef USE_SSL
#else
#define https_connecting(x,y) CURLE_COULDNT_CONNECT
#endif
#ifdef USE_SSL
#endif
#ifndef CURL_DISABLE_PROXY
#else
#define Curl_checkProxyheaders(x,y) NULL
#endif
#ifndef CURL_DISABLE_HTTP_AUTH
#endif
#if defined(USE_NTLM)
#endif
#if defined(USE_SPNEGO)
#endif
#ifndef CURL_DISABLE_HTTP_AUTH
#ifdef CURL_DISABLE_CRYPTO_AUTH
#endif
#ifdef USE_SPNEGO
#endif
#ifdef USE_NTLM
#endif
#if defined(USE_NTLM) && defined(NTLM_WB_ENABLED)
#endif
#ifndef CURL_DISABLE_CRYPTO_AUTH
#endif
#ifndef CURL_DISABLE_PROXY
#else
#endif /* CURL_DISABLE_PROXY */
#else
#endif
#ifdef USE_SPNEGO
#endif
#ifdef USE_SPNEGO
#endif
#ifdef USE_NTLM
#ifdef NTLM_WB_ENABLED
#endif
#endif
#ifndef CURL_DISABLE_CRYPTO_AUTH
#endif
void Curl_add_buffer_free(Curl_send_buffer **inp)
{
  Curl_send_buffer *in;
  if(!inp)
    return;
  in = *inp;
  if(in) { /* deal with NULL input */
    free(in->buffer);
    free(in);
  }
  *inp = NULL;
}
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifdef USE_SSL
#ifdef ENABLE_QUIC
#endif
#endif /* USE_SSL */
#ifdef ENABLE_QUIC
#endif
#ifdef USE_NGHTTP2
#endif
#ifdef CURL_DO_LINEEND_CONV
#endif
#ifndef CURL_DISABLE_PARSEDATE
#else
#endif
#if !defined(CURL_DISABLE_COOKIES)
#endif
#ifdef USE_NGHTTP2
#endif
#if !defined(CURL_DISABLE_COOKIES)
#endif
#ifdef HAVE_LIBZ
#define TE_HEADER "TE: gzip\r\n"
#endif
#ifndef CURL_DISABLE_MIME
#endif
#if !defined(CURL_DISABLE_COOKIES)
#endif
#ifndef CURL_DISABLE_PROXY
#endif /* CURL_DISABLE_PROXY */
#ifndef CURL_DISABLE_PROXY
#endif
#ifdef USE_ALTSVC
#endif
#if !defined(CURL_DISABLE_COOKIES)
#endif
#ifndef CURL_DISABLE_MIME
#endif
typedef enum {
  STATUS_UNKNOWN, /* not enough data to tell yet */
  STATUS_DONE, /* a status line was read */
  STATUS_BAD /* not a status line */
} statusline;
#ifdef CURL_DOES_CONVERSIONS
#endif /* CURL_DOES_CONVERSIONS */
#ifdef CURL_DOES_CONVERSIONS
#endif /* CURL_DOES_CONVERSIONS */
#ifndef CURL_DISABLE_RTSP
#ifdef CURL_DOES_CONVERSIONS
#else
#endif /* CURL_DOES_CONVERSIONS */
#endif /* CURL_DISABLE_RTSP */
#ifndef CURL_DISABLE_RTSP
#else
#endif /* CURL_DISABLE_RTSP */
#ifdef CURL_DOES_CONVERSIONS
#else
#endif /* CURL_DOES_CONVERSIONS */
#if defined(USE_NTLM)
#endif
#if defined(USE_SPNEGO)
#endif
#ifndef CURL_DISABLE_RTSP
#endif
#if defined(USE_NGHTTP2)
#endif
#ifdef CURL_DOES_CONVERSIONS
#define HEADER1 scratch
#define SCRATCHSIZE 21
#else
#define HEADER1 k->p /* no conversion needed, just use k->p */
#endif /* CURL_DOES_CONVERSIONS */
#if !defined(CURL_DISABLE_COOKIES)
#endif
#ifdef USE_SPNEGO
#endif
#ifdef USE_ALTSVC
#ifdef CURLDEBUG
#else
#endif
#endif
#endif /* CURL_DISABLE_HTTP */
