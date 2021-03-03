#include <ft2build.h>
#include <ftconfig.h>
#include FT_INTERNAL_DEBUG_H
#include FT_SYSTEM_H
#include FT_ERRORS_H
#include FT_TYPES_H
#include FT_INTERNAL_STREAM_H
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/mman.h>
#ifndef MAP_FILE
#define MAP_FILE  0x00
#endif
#ifdef MUNMAP_USES_VOIDP
#define MUNMAP_ARG_CAST  void *
#else
#define MUNMAP_ARG_CAST  char *
#endif
#ifdef NEED_MUNMAP_DECL
#ifdef __cplusplus
#else
#endif
#define MUNMAP_ARG_CAST  char *
#endif /* NEED_DECLARATION_MUNMAP */
#include <sys/types.h>
#include <sys/stat.h>
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#undef  FT_COMPONENT
#define FT_COMPONENT  io
#define STREAM_FILE( stream )  ( (FILE*)stream->descriptor.pointer )
#ifdef F_SETFD
#ifdef FD_CLOEXEC
#else
#endif /* FD_CLOEXEC */
#endif /* F_SETFD */
    /* `stream->size' is typedef'd to unsigned long (in `ftsystem.h'); */
    /* `stat_buf.st_size', however, is usually typedef'd to off_t      */
    /* (in sys/stat.h).                                                */
    /* On some platforms, the former is 32bit and the latter is 64bit. */
    /* To avoid overflow caused by fonts in huge files larger than     */
    /* 2GB, do a test.  Temporary fix proposed by Sean McBride.        */
    /*                                                                 */
    if ( stat_buf.st_size > LONG_MAX )
    {
      FT_ERROR(( "FT_Stream_Open: file is too big\n" ));
      goto Fail_Map;
    }
#ifdef FT_DEBUG_MEMORY
#endif
#ifdef FT_DEBUG_MEMORY
#endif
#ifdef FT_DEBUG_MEMORY
#endif
