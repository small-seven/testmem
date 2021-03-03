#include "curl_setup.h"
#ifdef CURLRES_IPV4 /* plain IPv4 code coming up */
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
#include "urldata.h"
#include "sendf.h"
#include "hostip.h"
#include "hash.h"
#include "share.h"
#include "strerror.h"
#include "url.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef CURLRES_SYNCH
#ifdef CURL_DISABLE_VERBOSE_STRINGS
#endif
#endif /* CURLRES_SYNCH */
#endif /* CURLRES_IPV4 */
#if defined(CURLRES_IPV4) && !defined(CURLRES_ARES)
#if !defined(HAVE_GETADDRINFO_THREADSAFE) && defined(HAVE_GETHOSTBYNAME_R_3)
#endif
#if defined(HAVE_GETADDRINFO_THREADSAFE)
#elif defined(HAVE_GETHOSTBYNAME_R)
#if defined(HAVE_GETHOSTBYNAME_R_5)
#elif defined(HAVE_GETHOSTBYNAME_R_6)
#elif defined(HAVE_GETHOSTBYNAME_R_3)
#endif /* HAVE_...BYNAME_R_5 || HAVE_...BYNAME_R_6 || HAVE_...BYNAME_R_3 */
#else /* HAVE_GETADDRINFO_THREADSAFE || HAVE_GETHOSTBYNAME_R */
#endif /* HAVE_GETADDRINFO_THREADSAFE || HAVE_GETHOSTBYNAME_R */
#endif /* defined(CURLRES_IPV4) && !defined(CURLRES_ARES) */
