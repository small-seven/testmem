#include "curl_setup.h"
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETINET_IN6_H
#include <netinet/in6.h>
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
#ifdef HAVE_SETJMP_H
#include <setjmp.h>
#endif
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_PROCESS_H
#include <process.h>
#endif
#include "urldata.h"
#include "sendf.h"
#include "hostip.h"
#include "hash.h"
#include "rand.h"
#include "share.h"
#include "strerror.h"
#include "url.h"
#include "inet_ntop.h"
#include "inet_pton.h"
#include "multiif.h"
#include "doh.h"
#include "warnless.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(CURLRES_SYNCH) && \
#define USE_ALARM_TIMEOUT
#endif
#define MAX_HOSTCACHE_LEN (255 + 7) /* max FQDN + colon + port number + zero */
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
hostcache_timestamp_remove(void *datap, void *hc)
{
  struct hostcache_prune_data *data =
    (struct hostcache_prune_data *) datap;
  struct Curl_dns_entry *c = (struct Curl_dns_entry *) hc;

  return (0 != c->timestamp)
    && (data->now - c->timestamp >= data->cache_timeout);
}
#ifdef HAVE_SIGSETJMP
#endif
#ifndef CURL_DISABLE_SHUFFLE_DNS
#endif
#ifndef CURL_DISABLE_SHUFFLE_DNS
#endif
#ifndef USE_RESOLVE_ON_IPS
#endif
#ifndef USE_RESOLVE_ON_IPS
#ifdef ENABLE_IPV6
#endif /* ENABLE_IPV6 */
#endif /* !USE_RESOLVE_ON_IPS */
#ifdef DEBUGBUILD
#endif
#ifdef USE_ALARM_TIMEOUT
#endif /* USE_ALARM_TIMEOUT */
#ifdef USE_ALARM_TIMEOUT
#ifdef HAVE_SIGACTION
#else
#ifdef HAVE_SIGNAL
#endif /* HAVE_SIGNAL */
#endif /* HAVE_SIGACTION */
#endif /* USE_ALARM_TIMEOUT */
#ifdef USE_ALARM_TIMEOUT
#ifdef HAVE_SIGACTION
#ifdef SA_RESTART
#endif
#else /* HAVE_SIGACTION */
#ifdef HAVE_SIGNAL
#endif
#endif /* HAVE_SIGACTION */
#else
#ifndef CURLRES_ASYNCH
#else
#endif
#endif /* USE_ALARM_TIMEOUT */
#ifdef USE_ALARM_TIMEOUT
#ifdef HAVE_SIGACTION
#else
#ifdef HAVE_SIGNAL
#endif
#endif /* HAVE_SIGACTION */
#endif /* USE_ALARM_TIMEOUT */
#if !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifndef ENABLE_IPV6
#endif
#if defined(CURL_DISABLE_DOH) && !defined(CURLRES_ASYNCH)
#endif
#ifdef CURLRES_ASYNCH
#else
#endif
