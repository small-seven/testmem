#include "zlib.h"
#include <stdio.h>
#ifdef STDC
#  include <string.h>
#  include <stdlib.h>
#endif
#ifdef USE_MMAP
#  include <sys/types.h>
#  include <sys/mman.h>
#  include <sys/stat.h>
#endif
#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  ifdef UNDER_CE
#    include <stdlib.h>
#  endif
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif
#if defined(_MSC_VER) && _MSC_VER < 1900
#  define snprintf _snprintf
#endif
#ifdef VMS
#  define unlink delete
#  define GZ_SUFFIX "-gz"
#endif
#ifdef RISCOS
#  define unlink remove
#  define GZ_SUFFIX "-gz"
#  define fileno(file) file->__file
#endif
#if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
#  include <unix.h> /* for fileno */
#endif
#if !defined(Z_HAVE_UNISTD_H) && !defined(_LARGEFILE64_SOURCE)
#ifndef WIN32 /* unlink already in stdio.h for WIN32 */
#endif
#endif
#if defined(UNDER_CE)
#  include <windows.h>
#  define perror(s) pwinerror(s)
#endif /* UNDER_CE */
#ifndef GZ_SUFFIX
#  define GZ_SUFFIX ".gz"
#endif
#define SUFFIX_LEN (sizeof(GZ_SUFFIX)-1)
#define BUFLEN      16384
#define MAX_NAME_LEN 1024
#ifdef MAXSEG_64K
#  define local static
#else
#  define local
#endif
#ifdef Z_SOLO
#if defined(Z_HAVE_UNISTD_H) || defined(Z_LARGE)
#  include <unistd.h>       /* for unlink() */
#endif
typedef struct gzFile_s {
    FILE *file;
    int write;
    int err;
    char *msg;
    z_stream strm;
} *gzFile;
#endif
#ifdef USE_MMAP
#endif
#ifdef USE_MMAP
#endif
#ifdef USE_MMAP /* MMAP version, Miguel Albrecht <malbrech@eso.org> */
#endif /* USE_MMAP */
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
#if !defined(NO_snprintf) && !defined(NO_vsnprintf)
#else
#endif
