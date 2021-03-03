#include "curl_setup.h"
#include "socketpair.h"
#ifdef CURLRES_THREADED
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
#if defined(USE_THREADS_POSIX)
#  ifdef HAVE_PTHREAD_H
#    include <pthread.h>
#  endif
#elif defined(USE_THREADS_WIN32)
#  ifdef HAVE_PROCESS_H
#    include <process.h>
#  endif
#endif
#if (defined(NETWARE) && defined(__NOVELL_LIBC__))
#undef in_addr_t
#define in_addr_t unsigned long
#endif
#ifdef HAVE_GETADDRINFO
#  define RESOLVER_ENOMEM  EAI_MEMORY
#else
#  define RESOLVER_ENOMEM  ENOMEM
#endif
#include "urldata.h"
#include "sendf.h"
#include "hostip.h"
#include "hash.h"
#include "share.h"
#include "strerror.h"
#include "url.h"
#include "multiif.h"
#include "inet_ntop.h"
#include "curl_threads.h"
#include "connect.h"
#include "socketpair.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef USE_SOCKETPAIR
#endif
#ifdef HAVE_GETADDRINFO
#endif
#ifdef USE_SOCKETPAIR
#endif
#ifdef HAVE_GETADDRINFO
#else
#endif
#ifdef USE_SOCKETPAIR
#endif
#ifdef HAVE_GETADDRINFO
#ifdef USE_SOCKETPAIR
#endif
#ifdef USE_SOCKETPAIR
#endif
#else /* HAVE_GETADDRINFO */
#endif /* HAVE_GETADDRINFO */
#ifdef USE_SOCKETPAIR
#endif
#ifdef USE_SOCKETPAIR
#endif
#ifdef HAVE_GETADDRINFO
#else
#endif
#ifdef USE_SOCKETPAIR
#else
#endif
#ifdef USE_SOCKETPAIR
#endif
#ifdef USE_SOCKETPAIR
#endif
#ifndef HAVE_GETADDRINFO
#else /* !HAVE_GETADDRINFO */
#ifdef CURLRES_IPV6
#endif /* CURLRES_IPV6 */
#endif /* !HAVE_GETADDRINFO */
#endif /* CURLRES_THREADED */
