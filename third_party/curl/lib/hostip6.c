#include "curl_setup.h"
#ifdef CURLRES_IPV6
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
#include "inet_pton.h"
#include "connect.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(CURLRES_SYNCH)
#ifdef DEBUG_ADDRINFO
#else
#define dump_addrinfo(x,y) Curl_nop_stmt
#endif
#ifndef USE_RESOLVE_ON_IPS
#endif
#if !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifndef USE_RESOLVE_ON_IPS
#endif
#endif /* CURLRES_SYNCH */
#endif /* CURLRES_IPV6 */
