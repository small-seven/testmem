#include "curl_setup.h"
#include <curl/curl.h>
#include "urldata.h"
#include "transfer.h"
#include "url.h"
#include "connect.h"
#include "progress.h"
#include "easyif.h"
#include "share.h"
#include "psl.h"
#include "multiif.h"
#include "sendf.h"
#include "timeval.h"
#include "http.h"
#include "select.h"
#include "warnless.h"
#include "speedcheck.h"
#include "conncache.h"
#include "multihandle.h"
#include "sigpipe.h"
#include "vtls/vtls.h"
#include "connect.h"
#include "http_proxy.h"
#include "http2.h"
#include "socketpair.h"
#include "socks.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef CURL_SOCKET_HASH_TABLE_SIZE
#define CURL_SOCKET_HASH_TABLE_SIZE 911
#endif
#ifndef CURL_CONNECTION_HASH_SIZE
#define CURL_CONNECTION_HASH_SIZE 97
#endif
#define CURL_MULTI_HANDLE 0x000bab1e
#define GOOD_MULTI_HANDLE(x) \
#ifdef DEBUGBUILD
#endif
typedef void (*init_multistate_func)(struct Curl_easy *data);

static void Curl_init_completed(struct Curl_easy *data)
{
  /* this is a completed transfer */

  /* Important: reset the conn pointer so that we don't point to memory
     that could be freed anytime */
  Curl_detach_connnection(data);
  Curl_expire_clear(data); /* stop all timers */
}
#ifdef DEBUGBUILD
#endif
#if defined(DEBUGBUILD) && defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifndef DEBUGBUILD
#define multistate(x,y) mstate(x,y)
#else
#define multistate(x,y) mstate(x,y, __LINE__)
#endif
#define SH_READ  1
#define SH_WRITE 2
#define TRHASH_SIZE 13
#ifdef ENABLE_WAKEUP
#endif
#ifdef USE_LIBPSL
#endif
#if 0
#endif
#if defined(USE_NTLM)
#endif
#if defined(USE_SPNEGO)
#endif
#ifdef USE_LIBPSL
#endif
#ifdef USE_SSL
#endif
#ifdef ENABLE_QUIC
#endif
#if 0 /* switch back on these cases to get the compiler to check for all enums
#endif
#define NUM_POLLS_ON_STACK 10
#ifdef ENABLE_WAKEUP
#endif
#ifdef ENABLE_WAKEUP
#endif
#ifdef ENABLE_WAKEUP
#ifndef USE_WINSOCK
#endif
#endif
#ifdef ENABLE_WAKEUP
#ifdef USE_WINSOCK
#else
#endif
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifdef CURLRES_ASYNCH
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifdef USE_LIBPSL
#endif
#ifdef ENABLE_WAKEUP
#endif
#undef curl_multi_setopt
#undef curl_multi_socket
#ifdef DEBUGBUILD
#endif
#ifdef DEBUGBUILD
#endif
