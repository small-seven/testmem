#include "curl_setup.h"
#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#if !defined(HAVE_SELECT) && !defined(HAVE_POLL_FINE)
#error "We can't compile without select() or poll() support."
#endif
#if defined(__BEOS__) && !defined(__HAIKU__)
#include <socket.h>
#endif
#ifdef MSDOS
#include <dos.h>  /* delay() */
#endif
#ifdef __VXWORKS__
#include <strings.h>  /* bzero() in FD_SET */
#endif
#include <curl/curl.h>
#include "urldata.h"
#include "connect.h"
#include "select.h"
#include "warnless.h"
#define ELAPSED_MS() (int)Curl_timediff(Curl_now(), initial_tv)
#if defined(MSDOS)
#elif defined(USE_WINSOCK)
#else
#if defined(HAVE_POLL_FINE)
#else
#endif /* HAVE_POLL_FINE */
#endif /* USE_WINSOCK */
#ifdef HAVE_POLL_FINE
#else
#endif
#if SIZEOF_TIME_T != SIZEOF_INT
#endif
#ifdef HAVE_POLL_FINE
#else  /* HAVE_POLL_FINE */
#ifdef USE_WINSOCK
#else
#endif
#endif  /* HAVE_POLL_FINE */
#ifndef HAVE_POLL_FINE
#endif
#ifdef HAVE_POLL_FINE
#else  /* HAVE_POLL_FINE */
#ifdef USE_WINSOCK
#endif
#ifdef USE_WINSOCK
#else
#endif
#endif  /* HAVE_POLL_FINE */
#ifdef TPF
#endif /* TPF */
