#define _ISOC90_SOURCE 1
#define MALLOC_CHECK_ 2/*glibc facility: turn on debugging*/
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#if PNG_LIBPNG_VER >= 10601 && defined(HAVE_CONFIG_H)
#  define SKIP 77
#else
#  define SKIP 0
#endif
#ifdef PNG_SIMPLIFIED_READ_SUPPORTED /* Else nothing can be done */
#include "../tools/sRGB.h"
#define ALLOW_UNUSED_GPC 0
#ifdef __cplusplus
#  define voidcast(type, value) static_cast<type>(value)
#  define aligncastconst(type, value) \
#else
#  define voidcast(type, value) (value)
#  define aligncastconst(type, value) ((const void*)(value))
#endif /* __cplusplus */
#if 0 /* not used */
#endif
#if ALLOW_UNUSED_GPC
#endif
#if 0 /* unused */
#endif /* unused */
#define USE_FILE 1       /* else memory */
#define USE_STDIO 2      /* else use file name */
#define STRICT 4         /* fail on warnings too */
#define VERBOSE 8
#define KEEP_TMPFILES 16 /* else delete temporary files */
#define KEEP_GOING 32
#define ACCUMULATE 64
#define FAST_WRITE 128
#define sRGB_16BIT 256
#define NO_RESEED  512   /* do not reseed on each new file */
#define GBG_ERROR 1024   /* do not ignore the gamma+background_rgb_to_gray
#if PNG_LIBPNG_VER < 10700 /* else on by default */
#endif
#define FORMAT_NO_CHANGE 0x80000000 /* additional flag */
#define FORMAT_COUNT 64
#define FORMAT_MASK 0x3f
#define FORMAT_SET_COUNT (FORMAT_COUNT / 32)
typedef struct
{
   png_uint_32 bits[FORMAT_SET_COUNT];
}
#if 0 /* currently unused */
#endif
#if 0 /* currently unused */
#endif
#        ifdef PNG_FORMAT_BGR_SUPPORTED
#        else
#        endif
#        ifdef PNG_FORMAT_AFIRST_SUPPORTED
#        else
#        endif
typedef struct
{
   png_image   image;
   png_uint_32 opts;
   const char *file_name;
   int         stride_extra;
   FILE       *input_file;
   png_voidp   input_memory;
   size_t      input_memory_size;
   png_bytep   buffer;
   ptrdiff_t   stride;
   size_t      bufsize;
   size_t      allocsize;
   char        tmpfile_name[32];
   png_uint_16 colormap[256*4];
}
#define BUFFER_INIT8 73
typedef struct
{
   /* The components, for grayscale images the gray value is in 'g' and if alpha
    * is not present 'a' is set to 255 or 65535 according to format.
    */
   int         r, g, b, a;
} Pixel;
typedef struct
{
   /* The background as the original sRGB 8-bit value converted to the final
    * integer format and as a double precision linear value in the range 0..1
    * for with partially transparent pixels.
    */
   int ir, ig, ib;
   double dr, dg, db; /* linear r,g,b scaled to 0..1 */
} Background;
#define BASE_FORMATS\
#ifdef PNG_FORMAT_AFIRST_SUPPORTED
#endif
#ifdef PNG_FORMAT_BGR_SUPPORTED
#endif
#ifdef PNG_FORMAT_BGR_SUPPORTED
#endif
#ifdef PNG_FORMAT_AFIRST_SUPPORTED
#endif
#if defined(PNG_FORMAT_AFIRST_SUPPORTED) && defined(PNG_FORMAT_BGR_SUPPORTED)
#endif
#ifdef PNG_FORMAT_AFIRST_SUPPORTED
#endif
#ifdef PNG_FORMAT_BGR_SUPPORTED
#endif
#ifdef PNG_FORMAT_BGR_SUPPORTED
#endif
#ifdef PNG_FORMAT_AFIRST_SUPPORTED
#endif
#if defined(PNG_FORMAT_AFIRST_SUPPORTED) && defined(PNG_FORMAT_BGR_SUPPORTED)
#endif
#        ifdef PNG_FORMAT_BGR_SUPPORTED
#                 ifdef PNG_FORMAT_AFIRST_SUPPORTED
#                 endif
#        endif
#              ifdef PNG_FORMAT_AFIRST_SUPPORTED
#              endif
#           ifdef PNG_FORMAT_AFIRST_SUPPORTED
#           endif
#        ifdef PNG_FORMAT_BGR_SUPPORTED
#                 ifdef PNG_FORMAT_AFIRST_SUPPORTED
#                 endif
#        endif
#              ifdef PNG_FORMAT_AFIRST_SUPPORTED
#              endif
#           ifdef PNG_FORMAT_AFIRST_SUPPORTED
#           endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if ALLOW_UNUSED_GPC
#endif
#if PNG_FORMAT_FLAG_ALPHA == 1 && PNG_FORMAT_FLAG_COLOR == 2 &&\
#if PNG_FORMAT_FLAG_COLORMAP == 8 /* extra check also required */
#  include "pngstest-errors.h" /* machine generated */
#endif /* COLORMAP flag check */
#endif /* flag checks */
typedef struct
{
   /* Basic pixel information: */
   Image*       in_image;   /* Input image */
   const Image* out_image;  /* Output image */

   /* 'background' is the value passed to the gpc_ routines, it may be NULL if
    * it should not be used (*this* program has an error if it crashes as a
    * result!)
    */
   Background        background_color;
   const Background* background;

   /* Precalculated values: */
   int          in_opaque;   /* Value of input alpha that is opaque */
   int          is_palette;  /* Sample values come from the palette */
   int          accumulate;  /* Accumulate component errors (don't log) */
   int          output_8bit; /* Output is 8-bit (else 16-bit) */

   void (*in_gp)(Pixel*, png_const_voidp);
   void (*out_gp)(Pixel*, png_const_voidp);

   void (*transform)(Pixel *out, const Pixel *in, const Background *back);
      /* A function to perform the required transform */

   void (*from_linear)(Pixel *out, const Pixel *in, const Background *back);
      /* For 'via_linear' transforms the final, from linear, step, else NULL */

   png_uint_16 error[4];
      /* Three error values for transparent, partially transparent and opaque
       * input pixels (in turn).
       */

   png_uint_16 *error_ptr;
      /* Where these are stored in the static array (for 'accumulate') */
}
#if 0
#endif
#     ifdef PNG_FORMAT_BGR_SUPPORTED
#     endif
#     ifdef PNG_FORMAT_AFIRST_SUPPORTED
#     endif
#        ifdef __GNUC__
#           define BYTE_CHARS 20 /* 2^32: GCC sprintf warning */
#        else
#           define BYTE_CHARS 3 /* 2^8: real maximum value */
#        endif
#  ifdef PNG_STDIO_SUPPORTED
#  else
#  endif
#ifndef __COVERITY__
#endif
#ifdef PNG_SIMPLIFIED_WRITE_SUPPORTED
#ifdef PNG_SIMPLIFIED_WRITE_STDIO_SUPPORTED
#ifndef __COVERITY__
#else
#endif
#else /* SIMPLIFIED_WRITE_STDIO */
#endif /* SIMPLIFIED_WRITE_STDIO */
#ifdef PNG_SIMPLIFIED_WRITE_STDIO_SUPPORTED
#else /* SIMPLIFIED_WRITE_STDIO */
#endif /* SIMPLIFIED_WRITE_STDIO */
#endif
#        ifdef PNG_SIMPLIFIED_WRITE_SUPPORTED
#        endif /* PNG_SIMPLIFIED_WRITE_SUPPORTED */
#     ifndef PNG_SIMPLIFIED_WRITE_SUPPORTED
#     endif
#if PNG_LIBPNG_VER >= 10700
#endif
#if 0
#endif
#        ifdef PNG_STDIO_SUPPORTED
#        else
#        endif
#        ifdef PNG_STDIO_SUPPORTED
#        else
#        endif
#else /* !PNG_SIMPLIFIED_READ_SUPPORTED */
#endif /* PNG_SIMPLIFIED_READ_SUPPORTED */
