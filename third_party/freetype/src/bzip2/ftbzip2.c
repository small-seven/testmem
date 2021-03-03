#include <ft2build.h>
#include FT_INTERNAL_MEMORY_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_DEBUG_H
#include FT_BZIP2_H
#include FT_CONFIG_STANDARD_LIBRARY_H
#include FT_MODULE_ERRORS_H
#undef FTERRORS_H_
#undef  FT_ERR_PREFIX
#define FT_ERR_PREFIX  Bzip2_Err_
#define FT_ERR_BASE    FT_Mod_Err_Bzip2
#include FT_ERRORS_H
#ifdef FT_CONFIG_OPTION_USE_BZIP2
#define BZ_NO_STDIO /* Do not need FILE */
#include <bzlib.h>
  typedef void *(* alloc_func)(void*, int, int);
  typedef void (* free_func)(void*, void*);

  static void*
  ft_bzip2_alloc( FT_Memory  memory,
                  int        items,
                  int        size )
  {
    FT_ULong    sz = (FT_ULong)size * (FT_ULong)items;
    FT_Error    error;
    FT_Pointer  p  = NULL;


    (void)FT_ALLOC( p, sz );
    return p;
  }
#define FT_BZIP2_BUFFER_SIZE  4096
  typedef struct  FT_BZip2FileRec_
  {
    FT_Stream  source;         /* parent/source stream        */
    FT_Stream  stream;         /* embedding stream            */
    FT_Memory  memory;         /* memory allocator            */
    bz_stream  bzstream;       /* bzlib input stream          */

    FT_Byte    input[FT_BZIP2_BUFFER_SIZE];  /* input read buffer  */

    FT_Byte    buffer[FT_BZIP2_BUFFER_SIZE]; /* output buffer      */
    FT_ULong   pos;                          /* position in output */
    FT_Byte*   cursor;
    FT_Byte*   limit;

  } FT_BZip2FileRec, *FT_BZip2File;
#else  /* !FT_CONFIG_OPTION_USE_BZIP2 */
#endif /* !FT_CONFIG_OPTION_USE_BZIP2 */
