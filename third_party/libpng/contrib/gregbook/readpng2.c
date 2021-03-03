#include <stdlib.h>     /* for exit() prototype */
#include <setjmp.h>
#include <zlib.h>
#include "png.h"        /* libpng header from the local directory */
#include "readpng2.h"   /* typedefs, common macros, public prototypes */
#include "readpng2.h"   /* typedefs, common macros, public prototypes */


/* local prototypes */

static void readpng2_info_callback(png_structp png_ptr, png_infop info_ptr);
static void readpng2_row_callback(png_structp png_ptr, png_bytep new_row,
                                 png_uint_32 row_num, int pass);
static void readpng2_end_callback(png_structp png_ptr, png_infop info_ptr);
static void readpng2_error_handler(png_structp png_ptr, png_const_charp msg);
static void readpng2_warning_handler(png_structp png_ptr, png_const_charp msg);




void readpng2_version_info(void)
{
    fprintf(stderr, "   Compiled with libpng %s; using libpng %s\n",
      PNG_LIBPNG_VER_STRING, png_libpng_ver);

    fprintf(stderr, "   and with zlib %s; using zlib %s.\n",
      ZLIB_VERSION, zlib_version);
}
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif /* PNG_HANDLE_AS_UNKNOWN_SUPPORTED */
#ifdef PNG_FLOATING_POINT_SUPPORTED
#else
#endif
#ifdef PNG_READ_16_TO_8_SUPPORTED
#  ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#  else
#  endif
#endif
#ifdef PNG_FLOATING_POINT_SUPPORTED
#else
#endif
