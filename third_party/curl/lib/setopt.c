#include "curl_setup.h"
#include <limits.h>
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_LINUX_TCP_H
#include <linux/tcp.h>
#endif
#include "urldata.h"
#include "url.h"
#include "progress.h"
#include "content_encoding.h"
#include "strcase.h"
#include "share.h"
#include "vtls/vtls.h"
#include "warnless.h"
#include "sendf.h"
#include "http2.h"
#include "setopt.h"
#include "multiif.h"
#include "altsvc.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define C_SSLVERSION_VALUE(x) (x & 0xffff)
#define C_SSLVERSION_MAX_VALUE(x) (x & 0xffff0000)
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_TFTP
#endif
#ifndef CURL_DISABLE_NETRC
#endif
#ifdef USE_SSL
#else
#endif
#ifndef CURL_DISABLE_HTTP
#endif   /* CURL_DISABLE_HTTP */
#ifndef CURL_DISABLE_HTTP
#ifndef CURL_DISABLE_PROXY
#endif
#if !defined(CURL_DISABLE_COOKIES)
#endif /* !CURL_DISABLE_COOKIES */
#ifdef ENABLE_QUIC
#endif
#ifndef USE_NGHTTP2
#else
#endif
#endif   /* CURL_DISABLE_HTTP */
#ifndef USE_NTLM
#elif !defined(NTLM_WB_ENABLED)
#endif
#ifndef USE_SPNEGO
#endif
#ifndef CURL_DISABLE_PROXY
#ifndef USE_NTLM
#elif !defined(NTLM_WB_ENABLED)
#endif
#ifndef USE_SPNEGO
#endif
#endif   /* CURL_DISABLE_PROXY */
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifdef USE_SSL
#endif
#ifdef USE_SSL
#endif
#ifdef USE_SSL
#endif
#ifdef USE_SSL
#endif
#ifndef CURL_DISABLE_PROXY
#ifdef USE_SSL
#endif
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifdef USE_SSL
#endif
#ifndef CURL_DISABLE_PROXY
#ifdef USE_SSL
#endif
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_TELNET
#endif
#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_COOKIES)
#endif
#ifdef USE_LIBPSL
#endif
#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_COOKIES)
#endif   /* CURL_DISABLE_HTTP */
#ifdef USE_LIBPSL
#endif
#ifdef USE_SSL
#ifndef CURL_DISABLE_PROXY
#endif
#endif
#ifdef USE_SSH
#endif /* USE_SSH */
#if !defined(CURL_DISABLE_FTP) || defined(USE_SSH)
#endif
#if SIZEOF_LONG > 4
#endif
#ifndef CURL_DISABLE_SMTP
#endif
#ifndef CURL_DISABLE_RTSP
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef USE_ARES
#endif
#if defined(CONNECT_DATA_IDEMPOTENT) || defined(MSG_FASTOPEN) || \
#else
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifndef USE_NGHTTP2
#else
#endif
#ifndef USE_NGHTTP2
#else
#endif
#ifndef CURL_DISABLE_SHUFFLE_DNS
#endif
#ifndef CURL_DISABLE_DOH
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifdef USE_ALTSVC
#endif
#undef curl_easy_setopt
