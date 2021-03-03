#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#ifndef PNG_SETJMP_SUPPORTED
#  include <setjmp.h> /* because png.h did *not* include this */
#endif
#if PNG_LIBPNG_VER >= 10601 && defined(HAVE_CONFIG_H)
#  define SKIP 77
#else
#  define SKIP 0
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
#ifdef PNG_READ_PNG_SUPPORTED
#     define CHUNK_NONE 0
#     define CHUNK_sBIT PNG_INFO_sBIT
#     define CHUNK_tRNS PNG_INFO_tRNS
#     define COLOR_MASK_X   0
#     define COLOR_MASK_P   PNG_COLOR_MASK_PALETTE
#     define COLOR_MASK_C   PNG_COLOR_MASK_COLOR
#     define COLOR_MASK_A   PNG_COLOR_MASK_ALPHA
#     define COLOR_MASK_ALL (PALETTE+COLOR+ALPHA)  /* absent = gray, no alpha */
#     define BD_ALL  (1 + 2 + 4 + 8 + 16)
#     define BD_PAL  (1 + 2 + 4 + 8)
#     define BD_LOW  (1 + 2 + 4)
#     define BD_16   16
#     define BD_TRUE (8+16) /* i.e. true-color depths */
#     define TRANSFORM_R  1
#     define TRANSFORM_W  2
#     define TRANSFORM_RW 3
#  define T(name,chunk,cm_required,cm_absent,bd,when)\
#ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#endif
#ifdef PNG_WRITE_PACK_SUPPORTED
#  define TRANSFORM_RW_PACK TRANSFORM_RW
#else
#  define TRANSFORM_RW_PACK TRANSFORM_R
#endif
#ifdef PNG_READ_PACK_SUPPORTED
#endif
#ifdef PNG_WRITE_PACKSWAP_SUPPORTED
#  define TRANSFORM_RW_PACKSWAP TRANSFORM_RW
#else
#  define TRANSFORM_RW_PACKSWAP TRANSFORM_R
#endif
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_SUPPORTED
#endif
#ifdef PNG_WRITE_INVERT_SUPPORTED
#  define TRANSFORM_RW_INVERT TRANSFORM_RW
#else
#  define TRANSFORM_RW_INVERT TRANSFORM_R
#endif
#ifdef PNG_READ_INVERT_SUPPORTED
#endif
#ifdef PNG_WRITE_SHIFT_SUPPORTED
#  define TRANSFORM_RW_SHIFT TRANSFORM_RW
#else
#  define TRANSFORM_RW_SHIFT TRANSFORM_R
#endif
#ifdef PNG_READ_SHIFT_SUPPORTED
#endif
#ifdef PNG_WRITE_BGR_SUPPORTED
#  define TRANSFORM_RW_BGR TRANSFORM_RW
#else
#  define TRANSFORM_RW_BGR TRANSFORM_R
#endif
#ifdef PNG_READ_BGR_SUPPORTED
#endif
#ifdef PNG_WRITE_SWAP_ALPHA_SUPPORTED
#  define TRANSFORM_RW_SWAP_ALPHA TRANSFORM_RW
#else
#  define TRANSFORM_RW_SWAP_ALPHA TRANSFORM_R
#endif
#ifdef PNG_READ_SWAP_ALPHA_SUPPORTED
#endif
#ifdef PNG_WRITE_SWAP_SUPPORTED
#  define TRANSFORM_RW_SWAP TRANSFORM_RW
#else
#  define TRANSFORM_RW_SWAP TRANSFORM_R
#endif
#ifdef PNG_READ_SWAP_SUPPORTED
#endif
#ifdef PNG_WRITE_INVERT_ALPHA_SUPPORTED
#  define TRANSFORM_RW_INVERT_ALPHA TRANSFORM_RW
#else
#  define TRANSFORM_RW_INVERT_ALPHA TRANSFORM_R
#endif
#ifdef PNG_READ_INVERT_ALPHA_SUPPORTED
#endif
#ifdef PNG_WRITE_FILLER_SUPPORTED
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#endif
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#endif
#undef T
#define ARRAY_SIZE(a) ((sizeof a)/(sizeof a[0]))
#define TTABLE_SIZE ARRAY_SIZE(transform_info)
#define NEW(type) ((type *)malloc(sizeof (type)))
#define DELETE(ptr) (free(ptr))
buffer_destroy(struct buffer *buffer)
{
   struct buffer_list *list = buffer->first.next;
   buffer_init(buffer);
   buffer_destroy_list(list);
}
#ifdef PNG_WRITE_PNG_SUPPORTED
#endif
#ifdef ENOMEM /* required by POSIX 1003.1 */
#  define MEMORY ENOMEM
#else
#  define MEMORY ERANGE /* required by ANSI-C */
#endif
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
#define EXHAUSTIVE      0x010 /* Test all combinations of active options */
#define STRICT          0x020 /* Fail on warnings as well as errors */
#define LOG             0x040 /* Log pass/fail to stdout */
#define CONTINUE        0x080 /* Continue on APP_FAIL errors */
#define SKIP_BUGS       0x100 /* Skip over known bugs */
#define LOG_SKIPPED     0x200 /* Log skipped bugs */
#define FIND_BAD_COMBOS 0x400 /* Attempt to deduce bad combos */
#define LIST_COMBOS     0x800 /* List combos by name */
#define RESULT_STRICT(r)   (((r) & ~((1U<<WARNINGS)-1)) == 0)
#define RESULT_RELAXED(r)  (((r) & ~((1U<<ERRORS)-1)) == 0)
#  ifdef PNG_WRITE_PNG_SUPPORTED
#  endif
#  ifdef PNG_WRITE_PNG_SUPPORTED
#  endif
#ifdef PNG_WRITE_PNG_SUPPORTED
#endif
#  ifdef PNG_WRITE_PNG_SUPPORTED
#  endif
display_destroy(struct display *dp)
{
    /* Release any memory held in the display. */
#  ifdef PNG_WRITE_PNG_SUPPORTED
      buffer_destroy(&dp->written_file);
#  endif

   buffer_destroy(&dp->original_file);
}
#ifdef __GNUC__
#  define VGATTR __attribute__((__format__ (__printf__,3,4)))
#else
#  define VGATTR
#endif
#  ifdef PNG_SET_USER_LIMITS_SUPPORTED
#  endif
#if 0 /* crazy debugging */
#endif
#  define C(item) if (item != dp->item) \
#     ifdef PNG_sBIT_SUPPORTED
#     else /* !sBIT */
#     endif /* !sBIT */
#ifdef PNG_WRITE_PNG_SUPPORTED
#  ifdef PNG_SET_USER_LIMITS_SUPPORTED
#  endif
#endif /* WRITE_PNG */
#ifdef PNG_WRITE_PNG_SUPPORTED
#endif
#ifdef PNG_WRITE_PNG_SUPPORTED
#endif
#else /* !READ_PNG */
#endif
