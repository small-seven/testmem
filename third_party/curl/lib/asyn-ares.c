#include "curl_setup.h"
#ifdef CURLRES_ARES
#include <limits.h>
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef __VMS
#include <in.h>
#include <inet.h>
#endif
#ifdef HAVE_PROCESS_H
#include <process.h>
#endif
#if (defined(NETWARE) && defined(__NOVELL_LIBC__))
#undef in_addr_t
#define in_addr_t unsigned long
#endif
#include "urldata.h"
#include "sendf.h"
#include "hostip.h"
#include "hash.h"
#include "share.h"
#include "strerror.h"
#include "url.h"
#include "multiif.h"
#include "inet_pton.h"
#include "connect.h"
#include "select.h"
#include "progress.h"
#  if defined(CURL_STATICLIB) && !defined(CARES_STATICLIB) && \
#    define CARES_STATICLIB
#  endif
#  include <ares.h>
#  include <ares_version.h> /* really old c-ares didn't include this by
#if ARES_VERSION >= 0x010500
#define HAVE_CARES_CALLBACK_TIMEOUTS 1
#endif
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define HAPPY_EYEBALLS_DNS_TIMEOUT 5000
#ifdef CARES_HAVE_ARES_LIBRARY_INIT
#endif
#ifdef CARES_HAVE_ARES_LIBRARY_CLEANUP
#endif
#ifdef HAVE_CARES_CALLBACK_TIMEOUTS
#endif
#ifdef HAVE_CARES_CALLBACK_TIMEOUTS
#endif
#ifdef ENABLE_IPV6 /* CURLRES_IPV6 */
#if ARES_VERSION >= 0x010601
#endif
#endif /* CURLRES_IPV6 */
#ifdef ENABLE_IPV6 /* CURLRES_IPV6 */
#endif /* CURLRES_IPV6 */
#if (ARES_VERSION >= 0x010704)
#if (ARES_VERSION >= 0x010b00)
#else
#endif
#else /* too old c-ares version! */
#endif
#if (ARES_VERSION >= 0x010704)
#else /* c-ares version too old! */
#endif
#if (ARES_VERSION >= 0x010704)
#else /* c-ares version too old! */
#endif
#if (ARES_VERSION >= 0x010704) && defined(ENABLE_IPV6)
#else /* c-ares version too old! */
#endif
#endif /* CURLRES_ARES */
