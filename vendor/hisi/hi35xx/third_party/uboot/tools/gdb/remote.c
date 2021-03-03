#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#ifdef __cplusplus
#endif
#ifdef __cplusplus
#endif
#endif /* alloca not defined.  */
#include "serial.h"
#include "error.h"
#include "remote.h"
#define REGISTER_BYTES 0
#define fprintf_unfiltered fprintf
#define fprintf_filtered fprintf
#define fputs_unfiltered fputs
#define fputs_filtered fputs
#define fputc_unfiltered fputc
#define fputc_filtered fputc
#define printf_unfiltered printf
#define printf_filtered printf
#define puts_unfiltered puts
#define puts_filtered puts
#define putchar_unfiltered putchar
#define putchar_filtered putchar
#define fputstr_unfiltered(a,b,c) fputs((a), (c))
#define gdb_stdlog stderr
#define SERIAL_READCHAR(fd,timo)	serialreadchar((fd), (timo))
#define SERIAL_WRITE(fd, addr, len)	serialwrite((fd), (addr), (len))
#define error Error
#define perror_with_name Perror
#define gdb_flush fflush
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define target_mourn_inferior() {}
#define ULONGEST unsigned long
#define CORE_ADDR unsigned long
#define MAXBUFBYTES(N) (((N)-32)/2)
#define	PBUFSIZ ((REGISTER_BYTES > MAXBUFBYTES (400)) \
#if 0
#endif
#define MAX_TRIES 3
