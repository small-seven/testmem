#include "curl_setup.h"
#if !defined(CURL_DISABLE_PROXY)
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#include "urldata.h"
#include "sendf.h"
#include "select.h"
#include "connect.h"
#include "timeval.h"
#include "socks.h"
#include "multiif.h" /* for getsock macros */
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#ifndef DEBUGBUILD
#define sxstate(x,y) socksstate(x,y)
#else
#define sxstate(x,y) socksstate(x,y, __LINE__)
#endif
#ifdef DEBUGBUILD
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef CURLRES_ASYNCH
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#ifdef CURLRES_ASYNCH
#endif
#ifdef ENABLE_IPV6
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#endif /* CURL_DISABLE_PROXY */
