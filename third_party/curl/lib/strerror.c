#include "curl_setup.h"
#ifdef HAVE_STRERROR_R
#  if (!defined(HAVE_POSIX_STRERROR_R) && \
#    error "strerror_r MUST be either POSIX, glibc or vxworks-style"
#  endif
#endif
#include <curl/curl.h>
#ifdef USE_LIBIDN2
#include <idn2.h>
#endif
#ifdef USE_WINDOWS_SSPI
#include "curl_sspi.h"
#endif
#include "strerror.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(WIN32) || defined(_WIN32_WCE)
#define PRESERVE_WINDOWS_ERROR_CODE
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#else
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#else
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#else
#endif
#ifdef USE_WINSOCK
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifdef CURL_DISABLE_VERBOSE_STRINGS
#else
#ifdef WSAEDISCON  /* missing in SalfordC! */
#endif
#endif
#endif   /* USE_WINSOCK */
#if defined(WIN32) || defined(_WIN32_WCE)
#ifdef _WIN32_WCE
#else
#endif
#endif /* WIN32 || _WIN32_WCE */
#ifdef PRESERVE_WINDOWS_ERROR_CODE
#endif
#if defined(WIN32) || defined(_WIN32_WCE)
#if defined(WIN32)
#endif
#ifdef USE_WINSOCK
#endif
#else /* not Windows coming up */
#if defined(HAVE_STRERROR_R) && defined(HAVE_POSIX_STRERROR_R)
#elif defined(HAVE_STRERROR_R) && defined(HAVE_GLIBC_STRERROR_R)
#elif defined(HAVE_STRERROR_R) && defined(HAVE_VXWORKS_STRERROR_R)
#else
#endif
#endif /* end of not Windows */
#ifdef PRESERVE_WINDOWS_ERROR_CODE
#endif
#if defined(WIN32) || defined(_WIN32_WCE)
#ifdef PRESERVE_WINDOWS_ERROR_CODE
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#else
#endif
#ifdef PRESERVE_WINDOWS_ERROR_CODE
#endif
#endif /* WIN32 || _WIN32_WCE */
#ifdef USE_WINDOWS_SSPI
#ifdef PRESERVE_WINDOWS_ERROR_CODE
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#define SEC2TXT(sec) case sec: txt = #sec; break
#else
#endif
#ifdef PRESERVE_WINDOWS_ERROR_CODE
#endif
#endif /* USE_WINDOWS_SSPI */
