#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#define implies(x,y) assert(!(x) || (y))
#ifdef __GNUC__
#  define FIX_GCC volatile
#else
#  define FIX_GCC
#endif
#define PROGRAM_NAME "pngfix"
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#if PNG_LIBPNG_VER < 10603 /* 1.6.3 */
#  error "pngfix will not work with libpng prior to 1.6.3"
#endif
#ifdef PNG_SETJMP_SUPPORTED
#include <setjmp.h>
#if defined(PNG_READ_SUPPORTED) && defined(PNG_EASY_ACCESS_SUPPORTED) &&\
#ifndef ZLIB_CONST
#  define ZLIB_CONST
#endif
#include <zlib.h>
#ifdef const
#  undef const
#endif
#if ZLIB_VERNUM < 0x1260
#  define PNGZ_MSG_CAST(s) constcast(char*,s)
#  define PNGZ_INPUT_CAST(b) constcast(png_bytep,b)
#else
#  define PNGZ_MSG_CAST(s) (s)
#  define PNGZ_INPUT_CAST(b) (b)
#endif
#ifndef PNG_MAXIMUM_INFLATE_WINDOW
#  error "pngfix not supported in this libpng version"
#endif
#if ZLIB_VERNUM >= 0x1240
#ifdef __cplusplus
#  define voidcast(type, value) static_cast<type>(value)
#  define constcast(type, value) const_cast<type>(value)
#  define aligncast(type, value) \
#  define aligncastconst(type, value) \
#else
#  define voidcast(type, value) (value)
#  define constcast(type, value) ((type)(value))
#  define aligncast(type, value) ((void*)(value))
#  define aligncastconst(type, value) ((const void*)(value))
#endif /* __cplusplus */
#if PNG_LIBPNG_VER < 10700
#define PNG_32b(b,s) ((png_uint_32)(b) << (s))
#define PNG_U32(b1,b2,b3,b4) \
#define png_IDAT PNG_U32( 73,  68,  65,  84)
#define png_IEND PNG_U32( 73,  69,  78,  68)
#define png_IHDR PNG_U32( 73,  72,  68,  82)
#define png_PLTE PNG_U32( 80,  76,  84,  69)
#define png_bKGD PNG_U32( 98,  75,  71,  68)
#define png_cHRM PNG_U32( 99,  72,  82,  77)
#define png_fRAc PNG_U32(102,  82,  65,  99) /* registered, not defined */
#define png_gAMA PNG_U32(103,  65,  77,  65)
#define png_gIFg PNG_U32(103,  73,  70, 103)
#define png_gIFt PNG_U32(103,  73,  70, 116) /* deprecated */
#define png_gIFx PNG_U32(103,  73,  70, 120)
#define png_hIST PNG_U32(104,  73,  83,  84)
#define png_iCCP PNG_U32(105,  67,  67,  80)
#define png_iTXt PNG_U32(105,  84,  88, 116)
#define png_oFFs PNG_U32(111,  70,  70, 115)
#define png_pCAL PNG_U32(112,  67,  65,  76)
#define png_pHYs PNG_U32(112,  72,  89, 115)
#define png_sBIT PNG_U32(115,  66,  73,  84)
#define png_sCAL PNG_U32(115,  67,  65,  76)
#define png_sPLT PNG_U32(115,  80,  76,  84)
#define png_sRGB PNG_U32(115,  82,  71,  66)
#define png_sTER PNG_U32(115,  84,  69,  82)
#define png_tEXt PNG_U32(116,  69,  88, 116)
#define png_tIME PNG_U32(116,  73,  77,  69)
#define png_tRNS PNG_U32(116,  82,  78,  83)
#define png_zTXt PNG_U32(122,  84,  88, 116)
#endif
#define sig1 PNG_U32(137,  80,  78,  71)
#define sig2 PNG_U32( 13,  10,  26,  10)
#define CRITICAL(chunk) (((chunk) & PNG_U32(32,0,0,0)) == 0)
#define SAFE_TO_COPY(chunk) (((chunk) & PNG_U32(0,0,0,32)) != 0)
#ifndef PNG_ERROR_TEXT_SUPPORTED
#  define png_error(a,b) png_err(a)
#endif
#define UNREACHED 0
typedef png_uint_16  udigit; /* A 'unum' is an array of these */
typedef png_uint_16p uarb;
typedef png_const_uint_16p uarbc;

#define UDIGITS(unum) ((sizeof unum)/(sizeof (udigit))
   /* IMPORTANT: only apply this to an array, applied to a pointer the result
    * will typically be '2', which is not useful.
    */

static int
uarb_set(uarb result, png_alloc_size_t val)
   /* Set (initialize) 'result' to 'val'.  The size required for 'result' must
    * be determined by the caller from a knowledge of the maximum for 'val'.
    */
{
   int ndigits = 0;

   while (val > 0)
   {
      result[ndigits++] = (png_uint_16)(val & 0xffff);
      val >>= 16;
   }
#if 0 /*UNUSED*/
#endif
#define CLEAR(object) clear(&(object), sizeof (object))
#define CRC_INIT 0xffffffff
#     define IDAT_INIT_LENGTH 16
#     define SKIP_NONE      0
#     define SKIP_BAD_CRC   1    /* Chunks with a bad CRC */
#     define SKIP_UNSAFE    2    /* Chunks not safe to copy */
#     define SKIP_UNUSED    3    /* Chunks not used by libpng */
#     define SKIP_TRANSFORM 4    /* Chunks only used in transforms */
#     define SKIP_COLOR     5    /* Everything but tRNS, sBIT, gAMA and sRGB */
#     define SKIP_ALL       6    /* Everything but tRNS and sBIT */
#     define TOO_FAR_BACK   0x01 /* found a too-far-back error */
#     define CRC_ERROR      0x02 /* fixed an invalid CRC */
#     define STREAM_ERROR   0x04 /* damaged PNG stream (may be fixable) */
#     define TRUNCATED      0x08 /* truncated but still readable */
#     define FILE_ERROR     0x10 /* could not read the file */
#     define WRITE_ERROR    0x20 /* write error (this terminates the read) */
#     define INTERNAL_ERROR 0x40 /* internal limits/errors encountered */
#     define STATE_SIGNATURE  0  /* The signature is being written */
#     define STATE_CHUNKS     1  /* Non-IDAT chunks are being written */
#     define STATE_IDAT       2  /* An IDAT stream is being written */
#define LIBPNG_WARNING_CODE   1 /* generic png_error */
#define LIBPNG_ERROR_CODE     2 /* generic png_error */
#define ZLIB_ERROR_CODE       3 /* generic zlib error */
#define INVALID_ERROR_CODE    4 /* detected an invalid PNG */
#define READ_ERROR_CODE       5 /* read failed */
#define WRITE_ERROR_CODE      6 /* error in write */
#define UNEXPECTED_ERROR_CODE 7 /* unexpected (internal?) error */
#  ifdef EINTR
#  endif
#  define ZLIB_TOO_FAR_BACK (-1)
#  define ZLIB_OK           0
#  define ZLIB_STREAM_END   1
#  define ZLIB_FATAL        2
allocate(struct file *file, int allocate_idat)
{
   struct control *control = voidcast(struct control*, file->alloc_ptr);

   if (allocate_idat)
   {
      assert(file->idat == NULL);
      IDAT_init(&control->idat, file);
   }

   else /* chunk */
   {
      assert(file->chunk == NULL);
      chunk_init(&control->chunk, file);
   }
}
#     ifdef PNG_SET_USER_LIMITS_SUPPORTED
#     endif
#if 0 /*NYI*/
#ifdef PNG_MAXIMUM_INFLATE_WINDOW
#endif
#endif
#if 0
#     ifdef PNG_MAXIMUM_INFLATE_WINDOW
#     endif
#endif
#else /* ZLIB_VERNUM < 0x1240 */
#endif /* ZLIB_VERNUM */
#else /* No read support */
#endif /* PNG_READ_SUPPORTED && PNG_EASY_ACCESS_SUPPORTED */
#else /* No setjmp support */
#endif /* PNG_SETJMP_SUPPORTED */
