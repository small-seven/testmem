#include <stdlib.h>     /* for exit() prototype */
#include <zlib.h>
#include "png.h"        /* libpng header, includes setjmp.h */
#include "writepng.h"   /* typedefs, common macros, public prototypes */
#include "writepng.h"   /* typedefs, common macros, public prototypes */


/* local prototype */

static void writepng_error_handler(png_structp png_ptr, png_const_charp msg);



void writepng_version_info(void)
{
  fprintf(stderr, "   Compiled with libpng %s; using libpng %s.\n",
    PNG_LIBPNG_VER_STRING, png_libpng_ver);
  fprintf(stderr, "   Compiled with zlib %s; using zlib %s.\n",
    ZLIB_VERSION, zlib_version);
}
