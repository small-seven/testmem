#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <setjmp.h>
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
#if defined(PNG_SET_UNKNOWN_CHUNKS_SUPPORTED) &&\
#if defined(PNG_READ_USER_CHUNKS_SUPPORTED) ||\
#if PNG_LIBPNG_VER < 10500
typedef png_byte *png_const_bytep;

/* This is copied from 1.5.1 png.h: */
#define PNG_INTERLACE_ADAM7_PASSES 7
#define PNG_PASS_START_ROW(pass) (((1U&~(pass))<<(3-((pass)>>1)))&7)
#define PNG_PASS_START_COL(pass) (((1U& (pass))<<(3-(((pass)+1)>>1)))&7)
#define PNG_PASS_ROW_SHIFT(pass) ((pass)>2?(8-(pass))>>1:3)
#define PNG_PASS_COL_SHIFT(pass) ((pass)>1?(7-(pass))>>1:3)
#define PNG_PASS_ROWS(height, pass) (((height)+(((1<<PNG_PASS_ROW_SHIFT(pass))\
   -1)-PNG_PASS_START_ROW(pass)))>>PNG_PASS_ROW_SHIFT(pass))
#define PNG_PASS_COLS(width, pass) (((width)+(((1<<PNG_PASS_COL_SHIFT(pass))\
   -1)-PNG_PASS_START_COL(pass)))>>PNG_PASS_COL_SHIFT(pass))
#define PNG_ROW_FROM_PASS_ROW(yIn, pass) \
   (((yIn)<<PNG_PASS_ROW_SHIFT(pass))+PNG_PASS_START_ROW(pass))
#define PNG_COL_FROM_PASS_COL(xIn, pass) \
   (((xIn)<<PNG_PASS_COL_SHIFT(pass))+PNG_PASS_START_COL(pass))
#define PNG_PASS_MASK(pass,off) ( \
   ((0x110145AFU>>(((7-(off))-(pass))<<2)) & 0xFU) | \
   ((0x01145AF0U>>(((7-(off))-(pass))<<2)) & 0xF0U))
#define PNG_ROW_IN_INTERLACE_PASS(y, pass) \
   ((PNG_PASS_MASK(pass,0) >> ((y)&7)) & 1)
#define PNG_COL_IN_INTERLACE_PASS(x, pass) \
   ((PNG_PASS_MASK(pass,1) >> ((x)&7)) & 1)

/* These are needed too for the default build: */
#define PNG_WRITE_16BIT_SUPPORTED
#define PNG_READ_16BIT_SUPPORTED

/* This comes from pnglibconf.h after 1.5: */
#define PNG_FP_1 100000
#define PNG_GAMMA_THRESHOLD_FIXED\
   ((png_fixed_point)(PNG_GAMMA_THRESHOLD * PNG_FP_1))
#endif

#if PNG_LIBPNG_VER < 10600
   /* 1.6.0 constifies many APIs. The following exists to allow pngvalid to be
    * compiled against earlier versions.
    */
#  define png_const_structp png_structp
#endif

#if PNG_LIBPNG_VER < 10700
   /* Copied from libpng 1.7.0 png.h */
#define PNG_u2(b1, b2) (((unsigned int)(b1) << 8) + (b2))

#define PNG_U16(b1, b2) ((png_uint_16)PNG_u2(b1, b2))
#define PNG_U32(b1, b2, b3, b4)\
   (((png_uint_32)PNG_u2(b1, b2) << 16) + PNG_u2(b3, b4))

/* Constants for known chunk types.
 */
#define png_IDAT PNG_U32( 73,  68,  65,  84)
#define png_IEND PNG_U32( 73,  69,  78,  68)
#define png_IHDR PNG_U32( 73,  72,  68,  82)
#define png_PLTE PNG_U32( 80,  76,  84,  69)
#define png_bKGD PNG_U32( 98,  75,  71,  68)
#define png_cHRM PNG_U32( 99,  72,  82,  77)
#define png_eXIf PNG_U32(101,  88,  73, 102) /* registered July 2017 */
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

/* Test on flag values as defined in the spec (section 5.4): */
#define PNG_CHUNK_ANCILLARY(c)    (1 & ((c) >> 29))
#define PNG_CHUNK_CRITICAL(c)     (!PNG_CHUNK_ANCILLARY(c))
#define PNG_CHUNK_PRIVATE(c)      (1 & ((c) >> 21))
#define PNG_CHUNK_RESERVED(c)     (1 & ((c) >> 13))
#define PNG_CHUNK_SAFE_TO_COPY(c) (1 & ((c) >>  5))

#endif /* PNG_LIBPNG_VER < 10700 */

#ifdef __cplusplus
#  define this not_the_cpp_this
#  define new not_the_cpp_new
#  define voidcast(type, value) static_cast<type>(value)
#else
#  define voidcast(type, value) (value)
#endif /* __cplusplus */

/* Unused formal parameter errors are removed using the following macro which is
 * expected to have no bad effects on performance.
 */
#ifndef UNUSED
#  if defined(__GNUC__) || defined(_MSC_VER)
#     define UNUSED(param) (void)param;
#  else
#     define UNUSED(param)
#  endif
#endif

/* Types of chunks not known to libpng */
#define png_vpAg PNG_U32(118, 112, 65, 103)

/* Chunk information */
#define PNG_INFO_tEXt 0x10000000U
#define PNG_INFO_iTXt 0x20000000U
#define PNG_INFO_zTXt 0x40000000U

#define PNG_INFO_sTER 0x01000000U
#define PNG_INFO_vpAg 0x02000000U

#define ABSENT  0
#define START   1
#define END     2

static struct
{
   char        name[5];
   png_uint_32 flag;
   png_uint_32 tag;
   int         unknown;    /* Chunk not known to libpng */
   int         all;        /* Chunk set by the '-1' option */
   int         position;   /* position in pngtest.png */
   int         keep;       /* unknown handling setting */
} chunk_info[] = {
#     ifdef PNG_READ_bKGD_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_cHRM_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_eXIf_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_gAMA_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_hIST_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_iCCP_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_iTXt_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_oFFs_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_pCAL_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_pHYs_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_sBIT_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_sCAL_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_sPLT_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_sRGB_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_tEXt_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_tIME_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_tRNS_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_zTXt_SUPPORTED
#     else
#     endif
#define NINFO ((int)((sizeof chunk_info)/(sizeof chunk_info[0])))
#ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#endif
typedef struct
{
   jmp_buf     error_return;
   png_structp png_ptr;
   png_infop   info_ptr, end_ptr;
   png_uint_32 before_IDAT;
   png_uint_32 after_IDAT;
   int         error_count;
   int         warning_count;
   int         keep; /* the default value */
   const char *program;
   const char *file;
   const char *test;
} display;
#ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#  ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#  else
#  endif
#endif /* READ_USER_CHUNKS_SUPPORTED */
#ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#else /* SAVE_UNKNOWN_CHUNKS */
#  ifndef PNG_READ_USER_CHUNKS_SUPPORTED
#     error No store support and no user chunk support, this will not work
#  endif /* READ_USER_CHUNKS */
#endif /* SAVE_UNKNOWN_CHUNKS */
#  ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#  else
#  endif
#                 if PNG_LIBPNG_VER >= 10700 &&\
#                 endif /* 1.7+ SAVE_UNKNOWN_CHUNKS */
#                 if PNG_LIBPNG_VER >= 10700 &&\
#                 endif /* 1.7+ SAVE_UNKNOWN_CHUNKS */
#                 if PNG_LIBPNG_VER >= 10700 &&\
#                 endif /* 1.7+ SAVE_UNKNOWN_CHUNKS */
#     ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#     endif
#     ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#     endif
#     ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#     else
#     endif
#     ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#     endif
#     ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#     endif
#else /* !(READ_USER_CHUNKS || SAVE_UNKNOWN_CHUNKS) */
#endif /* READ_USER_CHUNKS || SAVE_UNKNOWN_CHUNKS */
#else /* !(SET_UNKNOWN_CHUNKS && READ) */
#endif /* SET_UNKNOWN_CHUNKS && READ*/
