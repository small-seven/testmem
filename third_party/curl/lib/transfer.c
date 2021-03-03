#include "curl_setup.h"
#include "strtoofft.h"
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
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#ifndef HAVE_SOCKET
#error "We can't compile without socket() support!"
#endif
#include "urldata.h"
#include <curl/curl.h>
#include "netrc.h"
#include "content_encoding.h"
#include "hostip.h"
#include "transfer.h"
#include "sendf.h"
#include "speedcheck.h"
#include "progress.h"
#include "http.h"
#include "url.h"
#include "getinfo.h"
#include "vtls/vtls.h"
#include "select.h"
#include "multiif.h"
#include "connect.h"
#include "non-ascii.h"
#include "http2.h"
#include "mime.h"
#include "strcase.h"
#include "urlapi-int.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if !defined(CURL_DISABLE_HTTP) || !defined(CURL_DISABLE_SMTP) || \
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifdef CURL_DO_LINEEND_CONV
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif /* CURL_DOES_CONVERSIONS */
#ifndef CURL_DISABLE_HTTP
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif /* CURL_DOES_CONVERSIONS */
#if defined(USE_NGHTTP2)
#elif defined(ENABLE_QUIC)
#else
#endif
#if defined(USE_NGHTTP2)
#endif
#ifndef CURL_DISABLE_HTTP
#endif /* CURL_DISABLE_HTTP */
#ifndef CURL_DISABLE_HTTP
#endif /* CURL_DISABLE_HTTP */
#ifndef CURL_DISABLE_HTTP
#endif   /* CURL_DISABLE_HTTP */
#ifndef CURL_DISABLE_POP3
#endif /* CURL_DISABLE_POP3 */
#if defined(WIN32) && !defined(USE_LWIPSOCK)
#ifndef SIO_IDEAL_SEND_BACKLOG_QUERY
#define SIO_IDEAL_SEND_BACKLOG_QUERY 0x4004747B
#endif
#else
#define win_update_buffer_size(x)
#endif
#ifdef CURL_DO_LINEEND_CONV
#endif
#ifndef CURL_DISABLE_SMTP
#endif /* CURL_DISABLE_SMTP */
#ifdef CURL_DO_LINEEND_CONV
#endif /* CURL_DO_LINEEND_CONV */
#if defined(HAVE_SIGNAL) && defined(SIGPIPE) && !defined(HAVE_MSG_NOSIGNAL)
#endif
#ifndef CURL_DISABLE_FTP
#endif
#if defined(HAVE_SIGNAL) && defined(SIGPIPE) && !defined(HAVE_MSG_NOSIGNAL)
#else
#endif
#ifdef CURL_DISABLE_HTTP
#else
#endif /* CURL_DISABLE_HTTP */
