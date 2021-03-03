#ifdef __linux__
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#define _LARGEFILE64_SOURCE
#endif
#include "config.h"
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/param.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/file.h>
#include <signal.h>
#include <stdint.h>
#ifdef CRAY
#include <sys/secparm.h>
#include <sys/iosw.h>
#include <sys/listio.h>
#else
#include <sys/uio.h>		/* readv(2)/writev(2) */
#include <string.h>
#endif
#if defined(__linux__) || defined(__sun) || defined(__hpux) || defined(_AIX)
#if !defined(UCLINUX) && !defined(__UCLIBC__)
#include <aio.h>
#endif
#endif
#include <stdlib.h>		/* atoi, abs */
#include "tlibio.h"		/* defines LIO* marcos */
#include "random_range.h"
#ifndef PATH_MAX
#define PATH_MAX	MAXPATHLEN
#endif
#if 0				/* disabled until it's needed -- roehrich 6/11/97 */
#define BUG1_workaround	1	/* Work around a condition where aio_return gives
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#else
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif /* sgi */
#ifdef  CRAY
#else
#endif
#if defined (sgi)
#endif
#if defined(__linux__) && !defined(__UCLIBC__)
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef  CRAY
#else
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#if defined(sgi)
#else
#endif
#ifdef sgi
#elif defined(__linux__) && !defined(__UCLIBC__)
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif /* sgi */
#if defined(sgi)
#endif
#if defined(__linux__) && !defined(__UCLIBC__)
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined (sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifndef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef  CRAY
#else
#endif
#ifdef sgi
#endif
#if defined (__linux__) && !defined(__UCLIBC__)
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef  CRAY
#else
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#if defined(sgi)
#else
#endif
#ifdef sgi
#elif defined(__linux__) && !defined(__UCLIBC__)
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#endif
#if defined(sgi) || (defined(__linux__)&& !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif /* CRAY */
#if defined(sgi)
#endif
#if defined(__linux__) && !defined(__UCLIBC__)
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifndef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#ifdef CRAY
#endif
#if defined(sgi) || (defined(__linux__) && !defined(__UCLIBC__))
#endif
#if !defined(__sun) && !defined(__hpux) && !defined(_AIX)
#ifdef CRAY
#elif defined(sgi)
#elif defined(__linux__) && !defined(__UCLIBC__)
#ifdef CRAY
#else
#ifdef SIGEV_CALLBACK
#endif
#ifdef BUG1_workaround
#endif /* BUG1_workaround */
#endif
#endif
#ifdef CRAY
#elif defined(sgi)
#elif defined(__linux__) && !defined(__UCLIBC__)
#ifdef sgi
#endif
#if defined(__linux__)&& !defined(__UCLIBC__)
#endif
#if defined(sgi) || (defined(__linux__)&& !defined(__UCLIBC__))
#endif
#ifdef CRAY
#else
#ifdef SIGEV_CALLBACK
#endif
#ifdef SIGEV_CALLBACK
#endif
#endif
#ifdef CRAY
#else
#endif
#ifdef sgi
#endif
#ifdef CRAY
#else
#endif
#ifdef CRAY
#else
#endif
#ifdef CRAY
#endif
#endif /* ifndef linux */
#endif
#if UNIT_TEST
#endif
