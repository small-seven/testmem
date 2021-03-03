#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include FT_CONFIG_STANDARD_LIBRARY_H
#if defined( TT_CONFIG_OPTION_EMBEDDED_BITMAPS ) && \
#define PNG_SKIP_SETJMP_CHECK 1
#include <png.h>
#include "pngshim.h"
#include "sferrors.h"
#if ( ( defined( __GNUC__ )                                &&             \
#ifdef __clang__
#define vector_shuffle  __builtin_shufflevector
#else
#define vector_shuffle  __builtin_shuffle
#endif
    typedef unsigned short  v82 __attribute__(( vector_size( 16 ) ));


    if ( row_info->rowbytes > 15 )
    {
      /* process blocks of 16 bytes in one rush, which gives a nice speed-up */
      limit = row_info->rowbytes - 16 + 1;
      for ( ; i < limit; i += 16 )
      {
        unsigned char*  base = &data[i];

        v82  s, s0, s1, a;

        /* clang <= 3.9 can't apply scalar values to vectors */
        /* (or rather, it needs a different syntax)          */
        v82  n0x80 = { 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80 };
#endif /* use `vector_size' */
#ifdef PNG_SETJMP_SUPPORTED
#endif
#if PNG_LIBPNG_VER >= 10209
#else
#endif
#else /* !(TT_CONFIG_OPTION_EMBEDDED_BITMAPS && FT_CONFIG_OPTION_USE_PNG) */
