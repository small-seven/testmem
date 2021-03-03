#include "server_setup.h"
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef _XOPEN_SOURCE_EXTENDED
#include <arpa/inet.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_POLL_H
#include <poll.h>
#elif defined(HAVE_SYS_POLL_H)
#include <sys/poll.h>
#endif
#ifdef __MINGW32__
#include <w32api.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "getpart.h"
#include "util.h"
#include "timeval.h"
#ifdef USE_WINSOCK
#undef  EINTR
#define EINTR    4 /* errno.h value */
#undef  EINVAL
#define EINVAL  22 /* errno.h value */
#endif
#if defined(ENABLE_IPV6) && defined(__MINGW32__)
#if (__W32API_MAJOR_VERSION < 3) || \
#endif /* w32api < 3.6 */
#endif /* ENABLE_IPV6 && __MINGW32__*/
#ifdef WIN32
#endif  /* WIN32 */
#ifdef USE_WINSOCK
#endif  /* USE_WINSOCK */
#if !defined(MSDOS) && !defined(USE_WINSOCK)
#ifndef HAVE_POLL_FINE
#endif
#endif
#if defined(MSDOS)
#elif defined(USE_WINSOCK)
#else
#if defined(HAVE_POLL_FINE)
#else
#endif /* HAVE_POLL_FINE */
#endif /* USE_WINSOCK */
#if !defined(CURL_DOES_CONVERSIONS)
#else
#endif
#if defined(WIN32) && !defined(MSDOS)
#if defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0600) && \
#else
#endif
#elif defined(HAVE_CLOCK_GETTIME_MONOTONIC)
#ifdef HAVE_GETTIMEOFDAY
#else
#endif
#elif defined(HAVE_GETTIMEOFDAY)
#else
#endif
