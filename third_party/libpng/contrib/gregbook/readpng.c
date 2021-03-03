#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "png.h"        /* libpng header */
#include "readpng.h"    /* typedefs, common macros, public prototypes */
#include "readpng.h"    /* typedefs, common macros, public prototypes */

/* future versions of libpng will provide this macro: */
#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr)   ((png_ptr)->jmpbuf)
#endif


static png_structp png_ptr = NULL;
static png_infop info_ptr = NULL;

png_uint_32  width, height;
int  bit_depth, color_type;
uch  *image_data = NULL;


void readpng_version_info(void)
{
    fprintf(stderr, "   Compiled with libpng %s; using libpng %s.\n",
      PNG_LIBPNG_VER_STRING, png_libpng_ver);
    fprintf(stderr, "   Compiled with zlib %s; using zlib %s.\n",
      ZLIB_VERSION, zlib_version);
}
#ifdef PNG_READ_16_TO_8_SUPPORTED
#  ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#  else
#  endif
#endif
