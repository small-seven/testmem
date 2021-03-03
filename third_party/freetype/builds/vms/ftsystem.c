#include <ft2build.h>
#include <ftconfig.h>
#include FT_INTERNAL_DEBUG_H
#include FT_SYSTEM_H
#include FT_ERRORS_H
#include FT_TYPES_H
#include FT_INTERNAL_OBJECTS_H
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
#undef  FT_COMPONENT
#define FT_COMPONENT  io
#define STREAM_FILE( stream )  ( (FILE*)stream->descriptor.pointer )
#ifdef FT_DEBUG_MEMORY
#endif
#ifdef FT_DEBUG_MEMORY
#endif
#ifdef FT_DEBUG_MEMORY
#endif
