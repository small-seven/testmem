#include <ft2build.h>
#include FT_INTERNAL_MEMORY_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_DEBUG_H
#include FT_GZIP_H
#include FT_CONFIG_STANDARD_LIBRARY_H
#include FT_MODULE_ERRORS_H
#undef FTERRORS_H_
#undef  FT_ERR_PREFIX
#define FT_ERR_PREFIX  Gzip_Err_
#define FT_ERR_BASE    FT_Mod_Err_Gzip
#include FT_ERRORS_H
#ifdef FT_CONFIG_OPTION_USE_ZLIB
#ifdef FT_CONFIG_OPTION_SYSTEM_ZLIB
#include <zlib.h>
#else /* !FT_CONFIG_OPTION_SYSTEM_ZLIB */
#ifndef USE_ZLIB_ZCALLOC
#define MY_ZCALLOC /* prevent all zcalloc() & zfree() in zutil.c */
#endif
#include "zlib.h"
#undef  SLOW
#define SLOW  1  /* we can't use asm-optimized sources here! */
#if defined( _MSC_VER )      /* Visual C++ (and Intel C++)   */
#pragma warning( push )
#pragma warning( disable : 4244 )
#endif /* _MSC_VER */
#define NO_INFLATE_MASK
#include "zutil.h"
#include "inftrees.h"
#include "infblock.h"
#include "infcodes.h"
#include "infutil.h"
#undef  NO_INFLATE_MASK
#include "zutil.c"
#include "inftrees.c"
#include "infutil.c"
#include "infcodes.c"
#include "infblock.c"
#include "inflate.c"
#include "adler32.c"
#if defined( _MSC_VER )
#pragma warning( pop )
#endif
#endif /* !FT_CONFIG_OPTION_SYSTEM_ZLIB */
#if !defined( FT_CONFIG_OPTION_SYSTEM_ZLIB ) && !defined( USE_ZLIB_ZCALLOC )
#endif /* !SYSTEM_ZLIB && !USE_ZLIB_ZCALLOC */
#define FT_GZIP_BUFFER_SIZE  4096
  typedef struct  FT_GZipFileRec_
  {
    FT_Stream  source;         /* parent/source stream        */
    FT_Stream  stream;         /* embedding stream            */
    FT_Memory  memory;         /* memory allocator            */
    z_stream   zstream;        /* zlib input stream           */

    FT_ULong   start;          /* starting position, after .gz header */
    FT_Byte    input[FT_GZIP_BUFFER_SIZE];   /* input read buffer  */

    FT_Byte    buffer[FT_GZIP_BUFFER_SIZE];  /* output buffer      */
    FT_ULong   pos;                          /* position in output */
    FT_Byte*   cursor;
    FT_Byte*   limit;

  } FT_GZipFileRec, *FT_GZipFile;
#define FT_GZIP_ASCII_FLAG   0x01 /* bit 0 set: file probably ascii text */
#define FT_GZIP_HEAD_CRC     0x02 /* bit 1 set: header CRC present */
#define FT_GZIP_EXTRA_FIELD  0x04 /* bit 2 set: extra field present */
#define FT_GZIP_ORIG_NAME    0x08 /* bit 3 set: original file name present */
#define FT_GZIP_COMMENT      0x10 /* bit 4 set: file comment present */
#define FT_GZIP_RESERVED     0xE0 /* bits 5..7: reserved */
#else /* !FT_CONFIG_OPTION_USE_ZLIB */
#endif /* !FT_CONFIG_OPTION_USE_ZLIB */
