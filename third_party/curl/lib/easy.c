#include "curl_setup.h"
#ifdef CURLX_NO_MEMORY_CALLBACKS
#error "libcurl shall not ever be built with CURLX_NO_MEMORY_CALLBACKS defined"
#endif
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
#include "vtls/vtls.h"
#include "url.h"
#include "getinfo.h"
#include "hostip.h"
#include "share.h"
#include "strdup.h"
#include "progress.h"
#include "easyif.h"
#include "multiif.h"
#include "select.h"
#include "sendf.h" /* for failf function prototype */
#include "connect.h" /* for Curl_getconnectinfo */
#include "slist.h"
#include "mime.h"
#include "amigaos.h"
#include "non-ascii.h"
#include "warnless.h"
#include "multiif.h"
#include "sigpipe.h"
#include "vssh/ssh.h"
#include "setopt.h"
#include "http_digest.h"
#include "system_win32.h"
#include "http2.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(_WIN32_WCE)
#define system_strdup _strdup
#elif !defined(HAVE_STRDUP)
#define system_strdup curlx_strdup
#else
#define system_strdup strdup
#endif
#if defined(_MSC_VER) && defined(_DLL) && !defined(__POCC__)
#  pragma warning(disable:4232) /* MSVC extension, dllimport identity */
#endif
#ifndef __SYMBIAN32__
#if defined(WIN32) && defined(UNICODE)
#endif
#else
#endif
#if defined(_MSC_VER) && defined(_DLL) && !defined(__POCC__)
#  pragma warning(default:4232) /* MSVC extension, dllimport identity */
#endif
#if defined(WIN32) && defined(UNICODE)
#endif
#ifdef WIN32
#endif
#ifdef __AMIGA__
#endif
#ifdef NETWARE
#endif
#if defined(USE_SSH)
#endif
#ifdef USE_WOLFSSH
#endif
#ifdef WIN32
#endif
#ifdef USE_WOLFSSH
#endif
#ifdef CURLDEBUG
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#else /* CURLDEBUG */
#define easy_events(x) CURLE_NOT_BUILT_IN
#endif
#ifdef CURLDEBUG
#endif
#undef curl_easy_getinfo
#ifdef USE_ARES
#endif /* USE_ARES */
#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_CRYPTO_AUTH)
#endif
