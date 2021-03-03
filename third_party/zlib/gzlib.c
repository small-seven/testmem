#include "gzguts.h"
#if defined(_WIN32) && !defined(__BORLANDC__) && !defined(__MINGW32__)
#  define LSEEK _lseeki64
#else
#if defined(_LARGEFILE64_SOURCE) && _LFS64_LARGEFILE-0
#  define LSEEK lseek64
#else
#  define LSEEK lseek
#endif
#endif
#if defined UNDER_CE
#endif /* UNDER_CE */
#ifdef O_CLOEXEC
#endif
#ifdef O_EXCL
#endif
#ifndef NO_GZCOMPRESS
#endif
#ifdef O_CLOEXEC
#endif
#ifdef O_EXCL
#endif
#ifdef WIDECHAR
#endif
#ifdef WIDECHAR
#endif
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
#ifdef O_LARGEFILE
#endif
#ifdef O_BINARY
#endif
#ifdef O_CLOEXEC
#endif
#ifdef O_EXCL
#endif
#ifdef WIDECHAR
#endif
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
#ifdef WIDECHAR
#endif
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
#ifndef INT_MAX
#endif
