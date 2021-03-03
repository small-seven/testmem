#include "pnglibconf.h" /* To find how libpng was configured. */
#ifdef PNG_PNGCP_TIMING_SUPPORTED
#  define _POSIX_C_SOURCE 199309L
#else /* No timing support required */
#  define _POSIX_SOURCE 1
#endif
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#include <stdio.h>
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#if PNG_LIBPNG_VER < 10700
#  ifdef PNG_INFO_IMAGE_SUPPORTED
#     ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#        define PNG_READ_PNG_SUPPORTED
#     endif /* SEQUENTIAL_READ */
#     ifdef PNG_WRITE_SUPPORTED
#        define PNG_WRITE_PNG_SUPPORTED
#     endif /* WRITE */
#  endif /* INFO_IMAGE */
#endif /* pre 1.7.0 */
#if (defined(PNG_READ_PNG_SUPPORTED)) && (defined(PNG_WRITE_PNG_SUPPORTED))
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <zlib.h>
#ifndef PNG_SETJMP_SUPPORTED
#  include <setjmp.h> /* because png.h did *not* include this */
#endif
#ifdef __cplusplus
#  define voidcast(type, value) static_cast<type>(value)
#else
#  define voidcast(type, value) (value)
#endif /* __cplusplus */
#ifdef __GNUC__
#  define gv volatile
#else
#  define gv
#endif
#ifdef PNG_PNGCP_TIMING_SUPPORTED
#  include <time.h>   /* clock_gettime and associated definitions */
#  ifndef CLOCK_PROCESS_CPUTIME_ID
#     undef PNG_PNGCP_TIMING_SUPPORTED
#  endif
#endif /* PNGCP_TIMING */
typedef enum
{
   VERBOSE,        /* switches on all messages */
   INFORMATION,
   WARNINGS,       /* switches on warnings */
   LIBPNG_WARNING,
   APP_WARNING,
   ERRORS,         /* just errors */
   APP_FAIL,       /* continuable error - no need to longjmp */
   LIBPNG_ERROR,   /* this and higher cause a longjmp */
   LIBPNG_BUG,     /* erroneous behavior in libpng */
   APP_ERROR,      /* such as out-of-memory in a callback */
   QUIET,          /* no normal messages */
   USER_ERROR,     /* such as file-not-found */
   INTERNAL_ERROR
} error_level;
#define LEVEL_MASK      0xf   /* where the level is in 'options' */
#define STRICT          0x010 /* Fail on warnings as well as errors */
#define LOG             0x020 /* Log pass/fail to stdout */
#define CONTINUE        0x040 /* Continue on APP_FAIL errors */
#define SIZES           0x080 /* Report input and output sizes */
#define SEARCH          0x100 /* Search IDAT compression options */
#define NOWRITE         0x200 /* Do not write an output file */
#ifdef PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED
#  define IGNORE_INDEX  0x400 /* Ignore out of range palette indices (BAD!) */
#  ifdef PNG_GET_PALETTE_MAX_SUPPORTED
#     define FIX_INDEX  0x800 /* 'Fix' out of range palette indices (OK) */
#  endif /* GET_PALETTE_MAX */
#endif /* CHECK_FOR_INVALID_INDEX */
#define OPTION     0x80000000 /* Used for handling options */
#define LIST       0x80000001 /* Used for handling options */
#define RESULT_STRICT(r)   (((r) & ~((1U<<WARNINGS)-1)) == 0)
#define RESULT_RELAXED(r)  (((r) & ~((1U<<ERRORS)-1)) == 0)
#define RANGE(lo,hi) { range_lo, lo }, { range_hi, hi }
typedef struct value_list
{
   const char *name;  /* the command line name of the value */
   int         value; /* the actual value to use */
}  value_list;
#ifdef PNG_SW_COMPRESS_png_level
#endif /* SW_COMPRESS_png_level */
#if defined(PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED) ||\
#ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
#endif /* text compression */
#endif /* WRITE_CUSTOMIZE_*COMPRESSION */
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif /* WRITE_FILTER */
#ifdef PNG_PNGCP_TIMING_SUPPORTED
#  define PNGCP_TIME_READ  1
#  define PNGCP_TIME_WRITE 2
#endif /* PNGCP_TIMING */
#ifndef PNG_SW_IDAT_size
#  define png_set_IDAT_size(p,v) png_set_compression_buffer_size(p, v)
#endif /* !SW_IDAT_size */
#define SL 8 /* stack limit in display, below */
#ifdef PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
#endif /* IDAT compression */
typedef struct option
{
   const char       *name;         /* name of the option */
   png_uint_32       opt;          /* an option, or OPTION or LIST */
   png_byte          search;       /* Search on --search */
   png_byte          value_count;  /* length of the list of values: */
   const value_list *values;       /* values for OPTION or LIST */
}  option;
#  define S(n,v) { #n, v, 0, 2, vl_on_off },
#  ifdef IGNORE_INDEX
#  endif /* IGNORE_INDEX */
#  ifdef FIX_INDEX
#  endif /* FIX_INDEX */
#  undef S
#  define VLNAME(name) vl_ ## name
#  define VLSIZE(name) voidcast(png_byte,\
#  define VL(oname, name, type, search)\
#  define VLO(oname, name, search) VL(oname, name, OPTION, search)
#  ifdef PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
#     define VLCIDAT(name) VLO(#name, name, 1/*search*/)
#     ifdef PNG_SW_COMPRESS_level
#        define VLCiCCP(name) VLO("ICC-profile-" #name, name, 0/*search*/)
#     else
#        define VLCiCCP(name)
#     endif
#  else
#     define VLCIDAT(name)
#     define VLCiCCP(name)
#  endif /* WRITE_CUSTOMIZE_COMPRESSION */
#  ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
#     define VLCzTXt(name) VLO("text-" #name, name, 0/*search*/)
#  else
#     define VLCzTXt(name)
#  endif /* WRITE_CUSTOMIZE_ZTXT_COMPRESSION */
#  define VLC(name) VLCIDAT(name) VLCiCCP(name) VLCzTXt(name)
#  ifdef PNG_SW_COMPRESS_png_level
#  endif /* SW_COMPRESS_png_level */
#  ifdef PNG_SW_COMPRESS_windowBits
#  endif
#  undef VLO
#  define VLL(name, search) VL(#name, name, LIST, search)
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif /* WRITE_FILTER */
#ifdef PNG_PNGCP_TIMING_SUPPORTED
#endif /* PNGCP_TIMING */
#  undef VLL
#  undef VL
#ifdef __cplusplus
#else /* !__cplusplus */
#  define option_count ((sizeof options)/(sizeof options[0]))
#endif /* !__cplusplus */
#  if PNG_LIBPNG_VER < 10700 && defined PNG_TEXT_SUPPORTED
#  endif /* pre 1.7 */
#  ifdef PNG_PNGCP_TIMING_SUPPORTED
#  endif /* PNGCP_TIMING */
#  define MAX_SIZE ((png_alloc_size_t)(-1))
#  if PNG_LIBPNG_VER < 10700 && defined PNG_TEXT_SUPPORTED
#  endif /* pre 1.7 */
#  if PNG_LIBPNG_VER < 10700 && defined PNG_TEXT_SUPPORTED
#  endif /* pre 1.7 */
display_destroy(struct display *dp)
{
   /* Release any memory held in the display. */
   display_clean(dp);
}
#ifdef __GNUC__
#  define VGATTR __attribute__((__format__ (__printf__,3,4)))
#else
#  define VGATTR
#endif
#if PNG_LIBPNG_VER < 10700 && defined PNG_TEXT_SUPPORTED
#define text_stash(dp) if (!dp->text_stashed) text_stash(dp)
#define text_restore(dp) if (dp->text_stashed) text_restore(dp)
#else
#define text_stash(dp) ((void)0)
#define text_restore(dp) ((void)0)
#endif /* pre 1.7 */
#define OPTIND(dp, name) option_index(dp, #name, (sizeof #name)-1)
#     if 0
#     else
#     endif
#ifdef PNG_PNGCP_TIMING_SUPPORTED
#else /* !PNGCP_TIMING */
#define start_timer(dp, what) ((void)0)
#define end_timer(dp, what) ((void)0)
#endif /* !PNGCP_TIMING */
#  ifdef PNG_BENIGN_ERRORS_SUPPORTED
#  endif /* BENIGN_ERRORS */
#  ifdef FIX_INDEX
#     ifdef IGNORE_INDEX
#     endif /* IGNORE_INDEX */
#  endif /* FIX_INDEX */
#  ifdef IGNORE_INDEX
#  endif /* IGNORE_INDEX */
#  ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#  endif /* HANDLE_AS_UNKNOWN */
#  ifdef PNG_SET_USER_LIMITS_SUPPORTED
#  endif /* SET_USER_LIMITS */
#ifdef FIX_INDEX
#endif /* FIX_INDEX */
#define SET_COMPRESSION\
#ifdef PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
#  define SET(name, func) if (getsearchopts(dp, #name, &val))\
#  undef SET
#  define SET(name, func) if (getallopts(dp, #name, &val))\
#  undef SET
#ifdef PNG_SW_COMPRESS_level /* 1.7.0+ */
#  define SET(name, func) if (getallopts(dp, "ICC-profile-" #name, &val))\
#  undef SET
#else
#  define set_ICC_profile_compression(dp) ((void)0)
#endif
#else
#  define search_compression(dp) ((void)0)
#  define set_compression(dp) ((void)0)
#  define set_ICC_profile_compression(dp) ((void)0)
#endif /* WRITE_CUSTOMIZE_COMPRESSION */
#ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
#  define SET(name, func) if (getallopts(dp, "text-" #name, &val))\
#  undef SET
#else
#  define set_text_compression(dp) ((void)0)
#endif /* WRITE_CUSTOMIZE_ZTXT_COMPRESSION */
#  ifdef PNG_BENIGN_ERRORS_SUPPORTED
#  endif /* BENIGN_ERRORS */
#ifdef IGNORE_INDEX
#endif /* IGNORE_INDEX */
#  ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#  endif /* HANDLE_AS_UNKNOWN */
#  ifdef PNG_SET_USER_LIMITS_SUPPORTED
#  endif
#  ifdef PNG_SW_COMPRESS_png_level
#  endif /* png_level support */
#  ifdef PNG_WRITE_FILTER_SUPPORTED
#  endif /* WRITE_FILTER */
#              ifdef PNG_PNGCP_TIMING_SUPPORTED
#              endif /* PNGCP_TIMING */
#     ifdef PNG_PNGCP_TIMING_SUPPORTED
#     endif /* PNGCP_TIMING */
#else /* !READ_PNG || !WRITE_PNG */
#endif /* !READ_PNG || !WRITE_PNG */
