#include <ft2build.h>
#include FT_INTERNAL_MEMORY_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_DEBUG_H
#include FT_LZW_H
#include FT_CONFIG_STANDARD_LIBRARY_H
#include FT_MODULE_ERRORS_H
#undef FTERRORS_H_
#undef  FT_ERR_PREFIX
#define FT_ERR_PREFIX  LZW_Err_
#define FT_ERR_BASE    FT_Mod_Err_LZW
#include FT_ERRORS_H
#ifdef FT_CONFIG_OPTION_USE_LZW
#include "ftzopen.h"
#define FT_LZW_BUFFER_SIZE  4096
  typedef struct  FT_LZWFileRec_
  {
    FT_Stream       source;         /* parent/source stream        */
    FT_Stream       stream;         /* embedding stream            */
    FT_Memory       memory;         /* memory allocator            */
    FT_LzwStateRec  lzw;            /* lzw decompressor state      */

    FT_Byte         buffer[FT_LZW_BUFFER_SIZE]; /* output buffer      */
    FT_ULong        pos;                        /* position in output */
    FT_Byte*        cursor;
    FT_Byte*        limit;

  } FT_LZWFileRec, *FT_LZWFile;
#include "ftzopen.c"
#else  /* !FT_CONFIG_OPTION_USE_LZW */
#endif /* !FT_CONFIG_OPTION_USE_LZW */
