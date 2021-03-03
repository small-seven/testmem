#include "curl_setup.h"
#include <curl/curl.h>
#ifdef HAVE_NETINET_IN_H
#  include <netinet/in.h>
#endif
#ifdef HAVE_NETINET_IN6_H
#  include <netinet/in6.h>
#endif
#ifdef HAVE_NETDB_H
#  include <netdb.h>
#endif
#ifdef HAVE_ARPA_INET_H
#  include <arpa/inet.h>
#endif
#ifdef HAVE_SYS_UN_H
#  include <sys/un.h>
#endif
#ifdef __VMS
#  include <in.h>
#  include <inet.h>
#endif
#if defined(NETWARE) && defined(__NOVELL_LIBC__)
#  undef  in_addr_t
#  define in_addr_t unsigned long
#endif
#if defined(WIN32) && defined(USE_UNIX_SOCKETS)
#include <afunix.h>
#endif
#include <stddef.h>
#include "curl_addrinfo.h"
#include "inet_pton.h"
#include "warnless.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(__INTEL_COMPILER) && (__INTEL_COMPILER == 910) && \
# define vqualifier volatile
#else
# define vqualifier
#endif
#ifdef HAVE_GETADDRINFO
#ifdef ENABLE_IPV6
#endif
#ifdef EAI_NONAME
#else
#endif
#ifdef USE_WINSOCK
#endif
#endif /* HAVE_GETADDRINFO */
 *     typedef struct Curl_addrinfo Curl_addrinfo;
 *
 *   hostent defined in <netdb.h>
 *
 *     struct hostent {
 *       char    *h_name;
 *       char    **h_aliases;
 *       int     h_addrtype;
 *       int     h_length;
 *       char    **h_addr_list;
 *     };
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#if defined(__VMS) && \
#pragma pointer_size save
#pragma pointer_size short
#pragma message disable PTRMISMATCH
#endif
#ifdef ENABLE_IPV6
#endif
#if defined(__VMS) && \
#pragma pointer_size restore
#pragma message enable PTRMISMATCH
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#if defined(CURLDEBUG) && defined(HAVE_GETADDRINFO) &&  \
#ifdef USE_LWIPSOCK
#else
#endif
#endif /* defined(CURLDEBUG) && defined(HAVE_FREEADDRINFO) */
#if defined(CURLDEBUG) && defined(HAVE_GETADDRINFO)
#ifdef USE_LWIPSOCK
#else
#endif
#endif /* defined(CURLDEBUG) && defined(HAVE_GETADDRINFO) */
#if defined(HAVE_GETADDRINFO) && defined(USE_RESOLVE_ON_IPS)
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#endif
