#define _POSIX_SOURCE 1
#define _ISOC99_SOURCE 1 /* For floating point */
#define _GNU_SOURCE 1 /* For the floating point exception extension */
#define _BSD_SOURCE 1 /* For the floating point exception extension */
#include <signal.h>
#include <stdio.h>
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#ifdef HAVE_FEENABLEEXCEPT /* from config.h, if included */
#  include <fenv.h>
#endif
#ifndef FE_DIVBYZERO
#  define FE_DIVBYZERO 0
#endif
#ifndef FE_INVALID
#  define FE_INVALID 0
#endif
#ifndef FE_OVERFLOW
#  define FE_OVERFLOW 0
#endif
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#ifdef PNG_ZLIB_HEADER
#  include PNG_ZLIB_HEADER
#else
#  include <zlib.h>   /* For crc32 */
#endif
#if PNG_LIBPNG_VER >= 10601 && defined(HAVE_CONFIG_H)
#  define SKIP 77
#else
#  define SKIP 0
#endif
#if defined(PNG_WRITE_SUPPORTED) &&\
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
   /* 1.6.0 constifies many APIs, the following exists to allow pngvalid to be
    * compiled against earlier versions.
    */
#  define png_const_structp png_structp
#endif

#ifndef RELEASE_BUILD
   /* RELEASE_BUILD is true for releases and release candidates: */
#  define RELEASE_BUILD (PNG_LIBPNG_BUILD_BASE_TYPE >= PNG_LIBPNG_BUILD_RC)
#endif
#if RELEASE_BUILD
#   define debugonly(something)
#else /* !RELEASE_BUILD */
#   define debugonly(something) something
#endif /* !RELEASE_BUILD */

#include <float.h>  /* For floating point constants */
#include <stdlib.h> /* For malloc */
#include <string.h> /* For memcpy, memset */
#include <math.h>   /* For floor */

/* Convenience macros. */
#define CHUNK(a,b,c,d) (((a)<<24)+((b)<<16)+((c)<<8)+(d))
#define CHUNK_IHDR CHUNK(73,72,68,82)
#define CHUNK_PLTE CHUNK(80,76,84,69)
#define CHUNK_IDAT CHUNK(73,68,65,84)
#define CHUNK_IEND CHUNK(73,69,78,68)
#define CHUNK_cHRM CHUNK(99,72,82,77)
#define CHUNK_gAMA CHUNK(103,65,77,65)
#define CHUNK_sBIT CHUNK(115,66,73,84)
#define CHUNK_sRGB CHUNK(115,82,71,66)

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

/***************************** EXCEPTION HANDLING *****************************/
#ifdef PNG_FREESTANDING_TESTS
#  include <cexcept.h>
#else
#  include "../visupng/cexcept.h"
#endif

#ifdef __cplusplus
#  define this not_the_cpp_this
#  define new not_the_cpp_new
#  define voidcast(type, value) static_cast<type>(value)
#else
#  define voidcast(type, value) (value)
#endif /* __cplusplus */

struct png_store;
define_exception_type(struct png_store*);

/* The following are macros to reduce typing everywhere where the well known
 * name 'the_exception_context' must be defined.
 */
#define anon_context(ps) struct exception_context *the_exception_context = \
   &(ps)->exception_context
#define context(ps,fault) anon_context(ps); png_store *fault

/* This macro returns the number of elements in an array as an (unsigned int),
 * it is necessary to avoid the inability of certain versions of GCC to use
 * the value of a compile-time constant when performing range checks.  It must
 * be passed an array name.
 */
#define ARRAY_SIZE(a) ((unsigned int)((sizeof (a))/(sizeof (a)[0])))

/* GCC BUG 66447 (https://gcc.gnu.org/bugzilla/show_bug.cgi?id=66447) requires
 * some broken GCC versions to be fixed up to avoid invalid whining about auto
 * variables that are *not* changed within the scope of a setjmp being changed.
 *
 * Feel free to extend the list of broken versions.
 */
#define is_gnu(major,minor)\
   (defined __GNUC__) && __GNUC__ == (major) && __GNUC_MINOR__ == (minor)
#define is_gnu_patch(major,minor,patch)\
   is_gnu(major,minor) && __GNUC_PATCHLEVEL__ == 0
/* For the moment just do it always; all versions of GCC seem to be broken: */
#ifdef __GNUC__
   const void * volatile make_volatile_for_gnu;
#  define gnu_volatile(x) make_volatile_for_gnu = &x;
#else /* !GNUC broken versions */
#  define gnu_volatile(x)
#endif /* !GNUC broken versions */

/******************************* UTILITIES ************************************/
/* Error handling is particularly problematic in production code - error
 * handlers often themselves have bugs which lead to programs that detect
 * minor errors crashing.  The following functions deal with one very
 * common class of errors in error handlers - attempting to format error or
 * warning messages into buffers that are too small.
 */
static size_t safecat(char *buffer, size_t bufsize, size_t pos,
   const char *cat)
{
   while (pos < bufsize && cat != NULL && *cat != 0)
      buffer[pos++] = *cat++;

   if (pos >= bufsize)
      pos = bufsize-1;

   buffer[pos] = 0;
   return pos;
}
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#if defined PNG_READ_SUPPORTED || defined PNG_WRITE_tRNS_SUPPORTED ||\
#define R8(this) randomize(&(this), sizeof (this))
#ifdef PNG_READ_SUPPORTED
#endif /* READ */
#if defined PNG_READ_RGB_TO_GRAY_SUPPORTED ||\
#endif /* READ_FILLER || READ_RGB_TO_GRAY */
#endif /* READ || WRITE_tRNS || WRITE_FILTER */
#if defined PNG_READ_TRANSFORMS_SUPPORTED ||\
#endif /* READ_TRANSFORMS || WRITE_FILTER */
#if (defined PNG_READ_RGB_TO_GRAY_SUPPORTED) ||\
#endif /* READ_RGB_TO_GRAY || READ_FILLER */
#define FILEID(col, depth, palette, interlace, width, height, do_interlace) \
#define COL_FROM_ID(id) ((png_byte)((id)& 0x7U))
#define DEPTH_FROM_ID(id) ((png_byte)(((id) >> 3) & 0x1fU))
#define PALETTE_FROM_ID(id) (((id) >> 8) & 0x1f)
#define INTERLACE_FROM_ID(id) ((png_byte)(((id) >> 13) & 0x3))
#define DO_INTERLACE_FROM_ID(id) ((int)(((id)>>15) & 1))
#define WIDTH_FROM_ID(id) (((id)>>16) & 0xff)
#define HEIGHT_FROM_ID(id) (((id)>>24) & 0xff)
#ifdef PNG_WRITE_16BIT_SUPPORTED
#  define WRITE_BDHI 4
#  ifdef PNG_READ_16BIT_SUPPORTED
#     define READ_BDHI 4
#     define DO_16BIT
#  endif
#else
#  define WRITE_BDHI 3
#endif
#ifndef DO_16BIT
#  define READ_BDHI 3
#endif
#define PALETTE_COUNT(bit_depth) ((bit_depth) > 4 ? 1U : 16U)
#ifdef DO_16BIT
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif /* PNG_READ_TRANSFORMS_SUPPORTED */
#ifdef PNG_READ_SUPPORTED
#if PNG_LIBPNG_VER < 10506
#else
#endif
#endif /* PNG_READ_SUPPORTED */
#define STORE_BUFFER_SIZE 500 /* arbitrary */
typedef struct png_store_buffer
{
   struct png_store_buffer*  prev;    /* NOTE: stored in reverse order */
   png_byte                  buffer[STORE_BUFFER_SIZE];
} png_store_buffer;
#define FILE_NAME_SIZE 64
typedef struct store_palette_entry /* record of a single palette entry */
{
   png_byte red;
   png_byte green;
   png_byte blue;
   png_byte alpha;
} store_palette_entry, store_palette[256];
typedef struct png_store_file
{
   struct png_store_file*  next;      /* as many as you like... */
   char                    name[FILE_NAME_SIZE];
   unsigned int            IDAT_bits; /* Number of bits in IDAT size */
   png_uint_32             IDAT_size; /* Total size of IDAT data */
   png_uint_32             id;        /* must be correct (see FILEID) */
   size_t                  datacount; /* In this (the last) buffer */
   png_store_buffer        data;      /* Last buffer in file */
   int                     npalette;  /* Number of entries in palette */
   store_palette_entry*    palette;   /* May be NULL */
} png_store_file;
typedef struct store_pool
{
   struct png_store    *store;   /* Back pointer */
   struct store_memory *list;    /* List of allocated memory */
   png_byte             mark[4]; /* Before and after data */

   /* Statistics for this run. */
   png_alloc_size_t     max;     /* Maximum single allocation */
   png_alloc_size_t     current; /* Current allocation */
   png_alloc_size_t     limit;   /* Highest current allocation */
   png_alloc_size_t     total;   /* Total allocation */

   /* Overall statistics (retained across successive runs). */
   png_alloc_size_t     max_max;
   png_alloc_size_t     max_limit;
   png_alloc_size_t     max_total;
} store_pool;
typedef struct png_store
{
   /* For cexcept.h exception handling - simply store one of these;
    * the context is a self pointer but it may point to a different
    * png_store (in fact it never does in this program.)
    */
   struct exception_context
                      exception_context;

   unsigned int       verbose :1;
   unsigned int       treat_warnings_as_errors :1;
   unsigned int       expect_error :1;
   unsigned int       expect_warning :1;
   unsigned int       saw_warning :1;
   unsigned int       speed :1;
   unsigned int       progressive :1; /* use progressive read */
   unsigned int       validated :1;   /* used as a temporary flag */
   int                nerrors;
   int                nwarnings;
   int                noptions;       /* number of options below: */
   struct {
      unsigned char   option;         /* option number, 0..30 */
      unsigned char   setting;        /* setting (unset,invalid,on,off) */
   }                  options[16];
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
store_image_free(png_store *ps, png_const_structp pp)
{
   if (ps->image != NULL)
   {
      png_bytep image = ps->image;

      if (image[-1] != 0xed || image[ps->cb_image] != 0xfe)
      {
         if (pp != NULL)
            png_error(pp, "png_store image overwrite (1)");
         else
            store_log(ps, NULL, "png_store image overwrite (2)", 1);
      }

      ps->image = NULL;
      ps->cb_image = 0;
      --image;
      free(image);
   }
}
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#ifdef PNG_USER_MEM_SUPPORTED
typedef struct store_memory
{
   store_pool          *pool;    /* Originating pool */
   struct store_memory *next;    /* Singly linked list */
   png_alloc_size_t     size;    /* Size of memory allocated */
   png_byte             mark[4]; /* ID marker */
} store_memory;
store_memory_free(png_const_structp pp, store_pool *pool, store_memory *memory)
{
   /* Note that pp may be NULL (see store_pool_delete below), the caller has
    * found 'memory' in pool->list *and* unlinked this entry, so this is a valid
    * pointer (for sure), but the contents may have been trashed.
    */
   if (memory->pool != pool)
      store_pool_error(pool->store, pp, "memory corrupted (pool)");

   else if (memcmp(memory->mark, pool->mark, sizeof memory->mark) != 0)
      store_pool_error(pool->store, pp, "memory corrupted (start)");

   /* It should be safe to read the size field now. */
   else
   {
      png_alloc_size_t cb = memory->size;

      if (cb > pool->max)
         store_pool_error(pool->store, pp, "memory corrupted (size)");

      else if (memcmp((png_bytep)(memory+1)+cb, pool->mark, sizeof pool->mark)
         != 0)
         store_pool_error(pool->store, pp, "memory corrupted (end)");

      /* Finally give the library a chance to find problems too: */
      else
         {
         pool->current -= cb;
         free(memory);
         }
   }
}
store_malloc(png_structp ppIn, png_alloc_size_t cb)
{
   png_const_structp pp = ppIn;
   store_pool *pool = voidcast(store_pool*, png_get_mem_ptr(pp));
   store_memory *new = voidcast(store_memory*, malloc(cb + (sizeof *new) +
      (sizeof pool->mark)));

   if (new != NULL)
   {
      if (cb > pool->max)
         pool->max = cb;

      pool->current += cb;

      if (pool->current > pool->limit)
         pool->limit = pool->current;

      pool->total += cb;

      new->size = cb;
      memcpy(new->mark, pool->mark, sizeof new->mark);
      memcpy((png_byte*)(new+1) + cb, pool->mark, sizeof pool->mark);
      new->pool = pool;
      new->next = pool->list;
      pool->list = new;
      ++new;
   }

   else
   {
      /* NOTE: the PNG user malloc function cannot use the png_ptr it is passed
       * other than to retrieve the allocation pointer!  libpng calls the
       * store_malloc callback in two basic cases:
       *
       * 1) From png_malloc; png_malloc will do a png_error itself if NULL is
       *    returned.
       * 2) From png_struct or png_info structure creation; png_malloc is
       *    to return so cleanup can be performed.
       *
       * To handle this store_malloc can log a message, but can't do anything
       * else.
       */
      store_log(pool->store, pp, "out of memory", 1 /* is_error */);
   }

   return new;
}
store_free(png_structp ppIn, png_voidp memory)
{
   png_const_structp pp = ppIn;
   store_pool *pool = voidcast(store_pool*, png_get_mem_ptr(pp));
   store_memory *this = voidcast(store_memory*, memory), **test;

   /* Because libpng calls store_free with a dummy png_struct when deleting
    * png_struct or png_info via png_destroy_struct_2 it is necessary to check
    * the passed in png_structp to ensure it is valid, and not pass it to
    * png_error if it is not.
    */
   if (pp != pool->store->pread && pp != pool->store->pwrite)
      pp = NULL;

   /* First check that this 'memory' really is valid memory - it must be in the
    * pool list.  If it is, use the shared memory_free function to free it.
    */
   --this;
   for (test = &pool->list; *test != this; test = &(*test)->next)
   {
      if (*test == NULL)
      {
         store_pool_error(pool->store, pp, "bad pointer to free");
         return;
      }
   }

   /* Unlink this entry, *test == this. */
   *test = this->next;
   this->next = NULL;
   store_memory_free(pp, pool, this);
}
#endif /* PNG_USER_MEM_SUPPORTED */
#  ifdef PNG_USER_MEM_SUPPORTED
#  endif
#     ifdef PNG_USER_MEM_SUPPORTED
#     endif
#     ifdef PNG_SET_OPTION_SUPPORTED
#     endif
#  ifdef PNG_READ_SUPPORTED
#  endif
#  ifdef PNG_USER_MEM_SUPPORTED
#  endif
#ifdef PNG_READ_SUPPORTED
#  ifdef PNG_USER_MEM_SUPPORTED
#  endif
#  ifdef PNG_SET_OPTION_SUPPORTED
#  endif
#endif /* PNG_READ_SUPPORTED */
typedef enum modifier_state
{
   modifier_start,                        /* Initial value */
   modifier_signature,                    /* Have a signature */
   modifier_IHDR                          /* Have an IHDR */
} modifier_state;
typedef struct CIE_color
{
   /* A single CIE tristimulus value, representing the unique response of a
    * standard observer to a variety of light spectra.  The observer recognizes
    * all spectra that produce this response as the same color, therefore this
    * is effectively a description of a color.
    */
   double X, Y, Z;
} CIE_color;
typedef struct color_encoding
{
   /* A description of an (R,G,B) encoding of color (as defined above); this
    * includes the actual colors of the (R,G,B) triples (1,0,0), (0,1,0) and
    * (0,0,1) plus an encoding value that is used to encode the linear
    * components R, G and B to give the actual values R^gamma, G^gamma and
    * B^gamma that are stored.
    */
   double    gamma;            /* Encoding (file) gamma of space */
   CIE_color red, green, blue; /* End points */
} color_encoding;
#ifdef PNG_READ_SUPPORTED
#if defined PNG_READ_TRANSFORMS_SUPPORTED && defined PNG_READ_cHRM_SUPPORTED
#endif /* READ_TRANSFORMS && READ_cHRM */
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif /* READ_TRANSFORMS */
#endif /* PNG_READ_SUPPORTED */
typedef struct png_modifier
{
   png_store               this;             /* I am a png_store */
   struct png_modification *modifications;   /* Changes to make */

   modifier_state           state;           /* My state */

   /* Information from IHDR: */
   png_byte                 bit_depth;       /* From IHDR */
   png_byte                 colour_type;     /* From IHDR */

   /* While handling PLTE, IDAT and IEND these chunks may be pended to allow
    * other chunks to be inserted.
    */
   png_uint_32              pending_len;
   png_uint_32              pending_chunk;

   /* Test values */
   double                   *gammas;
   unsigned int              ngammas;
   unsigned int              ngamma_tests;     /* Number of gamma tests to run*/
   double                    current_gamma;    /* 0 if not set */
   const color_encoding *encodings;
   unsigned int              nencodings;
   const color_encoding *current_encoding; /* If an encoding has been set */
   unsigned int              encoding_counter; /* For iteration */
   int                       encoding_ignored; /* Something overwrote it */

   /* Control variables used to iterate through possible encodings, the
    * following must be set to 0 and tested by the function that uses the
    * png_modifier because the modifier only sets it to 1 (true.)
    */
   unsigned int              repeat :1;   /* Repeat this transform test. */
   unsigned int              test_uses_encoding :1;

   /* Lowest sbit to test (pre-1.7 libpng fails for sbit < 8) */
   png_byte                 sbitlow;

   /* Error control - these are the limits on errors accepted by the gamma tests
    * below.
    */
   double                   maxout8;  /* Maximum output value error */
   double                   maxabs8;  /* Absolute sample error 0..1 */
   double                   maxcalc8; /* Absolute sample error 0..1 */
   double                   maxpc8;   /* Percentage sample error 0..100% */
   double                   maxout16; /* Maximum output value error */
   double                   maxabs16; /* Absolute sample error 0..1 */
   double                   maxcalc16;/* Absolute sample error 0..1 */
   double                   maxcalcG; /* Absolute sample error 0..1 */
   double                   maxpc16;  /* Percentage sample error 0..100% */

   /* This is set by transforms that need to allow a higher limit, it is an
    * internal check on pngvalid to ensure that the calculated error limits are
    * not ridiculous; without this it is too easy to make a mistake in pngvalid
    * that allows any value through.
    *
    * NOTE: this is not checked in release builds.
    */
   double                   limit;    /* limit on error values, normally 4E-3 */

   /* Log limits - values above this are logged, but not necessarily
    * warned.
    */
   double                   log8;     /* Absolute error in 8 bits to log */
   double                   log16;    /* Absolute error in 16 bits to log */

   /* Logged 8 and 16 bit errors ('output' values): */
   double                   error_gray_2;
   double                   error_gray_4;
   double                   error_gray_8;
   double                   error_gray_16;
   double                   error_color_8;
   double                   error_color_16;
   double                   error_indexed;

   /* Flags: */
   /* Whether to call png_read_update_info, not png_read_start_image, and how
    * many times to call it.
    */
   int                      use_update_info;

   /* Whether or not to interlace. */
   int                      interlace_type :9; /* int, but must store '1' */

   /* Run the standard tests? */
   unsigned int             test_standard :1;

   /* Run the odd-sized image and interlace read/write tests? */
   unsigned int             test_size :1;

   /* Run tests on reading with a combination of transforms, */
   unsigned int             test_transform :1;
   unsigned int             test_tRNS :1; /* Includes tRNS images */

   /* When to use the use_input_precision option, this controls the gamma
    * validation code checks.  If set any value that is within the transformed
    * range input-.5 to input+.5 will be accepted, otherwise the value must be
    * within the normal limits.  It should not be necessary to set this; the
    * result should always be exact within the permitted error limits.
    */
   unsigned int             use_input_precision :1;
   unsigned int             use_input_precision_sbit :1;
   unsigned int             use_input_precision_16to8 :1;

   /* If set assume that the calculation bit depth is set by the input
    * precision, not the output precision.
    */
   unsigned int             calculations_use_input_precision :1;

   /* If set assume that the calculations are done in 16 bits even if the sample
    * depth is 8 bits.
    */
   unsigned int             assume_16_bit_calculations :1;

   /* Which gamma tests to run: */
   unsigned int             test_gamma_threshold :1;
   unsigned int             test_gamma_transform :1; /* main tests */
   unsigned int             test_gamma_sbit :1;
   unsigned int             test_gamma_scale16 :1;
   unsigned int             test_gamma_background :1;
   unsigned int             test_gamma_alpha_mode :1;
   unsigned int             test_gamma_expand16 :1;
   unsigned int             test_exhaustive :1;

   /* Whether or not to run the low-bit-depth grayscale tests.  This fails on
    * gamma images in some cases because of gross inaccuracies in the grayscale
    * gamma handling for low bit depth.
    */
   unsigned int             test_lbg :1;
   unsigned int             test_lbg_gamma_threshold :1;
   unsigned int             test_lbg_gamma_transform :1;
   unsigned int             test_lbg_gamma_sbit :1;
   unsigned int             test_lbg_gamma_composition :1;

   unsigned int             log :1;   /* Log max error */

   /* Buffer information, the buffer size limits the size of the chunks that can
    * be modified - they must fit (including header and CRC) into the buffer!
    */
   size_t                   flush;           /* Count of bytes to flush */
   size_t                   buffer_count;    /* Bytes in buffer */
   size_t                   buffer_position; /* Position in buffer */
   png_byte                 buffer[1024];
} png_modifier;
#  ifdef PNG_WRITE_tRNS_SUPPORTED
#  else
#  endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#define DIGITIZE PNG_LIBPNG_VER < 10700
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#if DIGITIZE
#endif
#endif /* RGB_TO_GRAY */
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif /* PNG_READ_GAMMA_SUPPORTED */
typedef struct png_modification
{
   struct png_modification *next;
   png_uint_32              chunk;

   /* If the following is NULL all matching chunks will be removed: */
   int                    (*modify_fn)(struct png_modifier *pm,
                               struct png_modification *me, int add);

   /* If the following is set to PLTE, IDAT or IEND and the chunk has not been
    * found and modified (and there is a modify_fn) the modify_fn will be called
    * to add the chunk before the relevant chunk.
    */
   png_uint_32              add;
   unsigned int             modified :1;     /* Chunk was modified */
   unsigned int             added    :1;     /* Chunk was added */
   unsigned int             removed  :1;     /* Chunk was removed */
} png_modification;
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif
typedef struct gama_modification
{
   png_modification this;
   png_fixed_point  gamma;
} gama_modification;
typedef struct chrm_modification
{
   png_modification          this;
   const color_encoding *encoding;
   png_fixed_point           wx, wy, rx, ry, gx, gy, bx, by;
} chrm_modification;
typedef struct srgb_modification
{
   png_modification this;
   png_byte         intent;
} srgb_modification;
#ifdef PNG_READ_GAMMA_SUPPORTED
typedef struct sbit_modification
{
   png_modification this;
   png_byte         sbit;
} sbit_modification;
#endif /* PNG_READ_GAMMA_SUPPORTED */
#endif /* PNG_READ_TRANSFORMS_SUPPORTED */
#ifdef PNG_WRITE_tRNS_SUPPORTED
#endif
#ifdef PNG_WRITE_tRNS_SUPPORTED
#endif
#define TRANSFORM_WIDTH  128U
#define TRANSFORM_ROWMAX (TRANSFORM_WIDTH*8U)
#define SIZE_ROWMAX (16*8U) /* 16 pixels, max 8 bytes each - 128 bytes */
#define STANDARD_ROWMAX TRANSFORM_ROWMAX /* The larger of the two */
#define SIZE_HEIGHTMAX 16 /* Maximum range of size images */
#define transform_width(pp, colour_type, bit_depth) TRANSFORM_WIDTH
#        define TRANSFORM_HEIGHTMAX 2048
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#define DEPTH(bd) ((png_byte)(1U << (bd)))
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#  define INTERLACE_LAST PNG_INTERLACE_LAST
#  define check_interlace_type(type) ((void)(type))
#  define set_write_interlace_handling(pp,type) png_set_interlace_handling(pp)
#  define do_own_interlace 0
#elif PNG_LIBPNG_VER < 10700
#  define set_write_interlace_handling(pp,type) (1)
#  define INTERLACE_LAST (PNG_INTERLACE_NONE+1)
#  define do_own_interlace 0
#else /* libpng 1.7+ */
#  define set_write_interlace_handling(pp,type)\
#  define check_interlace_type(type) ((void)(type))
#  define INTERLACE_LAST PNG_INTERLACE_LAST
#  define do_own_interlace 1
#endif /* WRITE_INTERLACING tests */
#if PNG_LIBPNG_VER >= 10700 || defined PNG_WRITE_INTERLACING_SUPPORTED
#   define CAN_WRITE_INTERLACE 1
#else
#   define CAN_WRITE_INTERLACE 0
#endif
#ifdef PNG_READ_INTERLACING_SUPPORTED
#  define do_read_interlace 0
#else /* no libpng read interlace support */
#  define do_read_interlace 1
#endif
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#ifdef PNG_WRITE_FILTER_SUPPORTED
#else /* !WRITE_FILTER */
#  define choose_random_filter(pp, start) ((void)0)
#endif /* !WRITE_FILTER */
#ifdef PNG_TEXT_SUPPORTED
#  if defined(PNG_READ_zTXt_SUPPORTED) && defined(PNG_WRITE_zTXt_SUPPORTED)
#     define TEXT_COMPRESSION PNG_TEXT_COMPRESSION_zTXt
#  else
#     define TEXT_COMPRESSION PNG_TEXT_COMPRESSION_NONE
#  endif
#endif
#     ifdef PNG_WRITE_tRNS_SUPPORTED
#     endif
#              if do_own_interlace
#              endif /* do_own_interlace */
#ifdef PNG_TEXT_SUPPORTED
#endif
#ifdef PNG_TEXT_SUPPORTED
#endif
#           ifdef PNG_WRITE_FILTER_SUPPORTED
#           endif
#ifdef PNG_TEXT_SUPPORTED
#endif
#        ifdef PNG_WRITE_INTERLACING_SUPPORTED
#        endif
#        if CAN_WRITE_INTERLACE
#        endif
#ifdef PNG_READ_SUPPORTED
#endif /* PNG_READ_SUPPORTED */
#ifdef PNG_WARNINGS_SUPPORTED
#     define exception__prev exception_prev_1
#     define exception__env exception_env_1
#undef exception__prev
#undef exception__env
#                 if do_own_interlace
#                 endif /* do_own_interlace */
#endif /* PNG_WARNINGS_SUPPORTED */
#ifdef PNG_WARNINGS_SUPPORTED /* else there are no cases that work! */
#else
#endif
#ifdef PNG_TIME_RFC1123_SUPPORTED
#     if PNG_LIBPNG_VER >= 10600
#     endif
#     if PNG_LIBPNG_VER < 10600
#     else
#     endif
#else
#endif
#ifdef PNG_READ_SUPPORTED
typedef struct standard_display
{
   png_store*  ps;             /* Test parameters (passed to the function) */
   png_byte    colour_type;
   png_byte    bit_depth;
   png_byte    red_sBIT;       /* Input data sBIT values. */
   png_byte    green_sBIT;
   png_byte    blue_sBIT;
   png_byte    alpha_sBIT;
   png_byte    interlace_type;
   png_byte    filler;         /* Output has a filler */
   png_uint_32 id;             /* Calculated file ID */
   png_uint_32 w;              /* Width of image */
   png_uint_32 h;              /* Height of image */
   int         npasses;        /* Number of interlaced passes */
   png_uint_32 pixel_size;     /* Width of one pixel in bits */
   png_uint_32 bit_width;      /* Width of output row in bits */
   size_t      cbRow;          /* Bytes in a row of the output image */
   int         do_interlace;   /* Do interlacing internally */
   int         littleendian;   /* App (row) data is little endian */
   int         is_transparent; /* Transparency information was present. */
   int         has_tRNS;       /* color type GRAY or RGB with a tRNS chunk. */
   int         speed;          /* Doing a speed test */
   int         use_update_info;/* Call update_info, not start_image */
   struct
   {
      png_uint_16 red;
      png_uint_16 green;
      png_uint_16 blue;
   }           transparent;    /* The transparent color, if set. */
#     ifdef __GNUC__
#     else
#     endif
#     ifdef PNG_READ_INTERLACING_SUPPORTED
#     else /* !READ_INTERLACING */
#     endif /* !READ_INTERLACING */
#ifdef PNG_USER_TRANSFORM_INFO_SUPPORTED
#endif /* USER_TRANSFORM_INFO */
#ifdef PNG_READ_INTERLACING_SUPPORTED
#endif /* READ_INTERLACING */
#ifdef PNG_READ_INTERLACING_SUPPORTED
#endif /* PNG_READ_INTERLACING_SUPPORTED */
#ifdef PNG_TEXT_SUPPORTED
#else
#  define standard_text_validate(dp,pp,pi,check_end) ((void)0)
#endif
#     if CAN_WRITE_INTERLACE
#     endif
#     ifdef PNG_READ_INTERLACING_SUPPORTED
#     if CAN_WRITE_INTERLACE
#     endif
#     endif /* READ_INTERLACING */
#     ifdef PNG_WRITE_INTERLACING_SUPPORTED
#     endif
#     ifdef PNG_READ_INTERLACING_SUPPORTED
#     ifdef PNG_WRITE_INTERLACING_SUPPORTED
#     endif
#     endif /* READ_INTERLACING */
#if 0
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
typedef struct image_pixel
{
   /* A local (pngvalid) representation of a PNG pixel, in all its
    * various forms.
    */
   unsigned int red, green, blue, alpha; /* For non-palette images. */
   unsigned int palette_index;           /* For a palette image. */
   png_byte     colour_type;             /* As in the spec. */
   png_byte     bit_depth;               /* Defines bit size in row */
   png_byte     sample_depth;            /* Scale of samples */
   unsigned int have_tRNS :1;            /* tRNS chunk may need processing */
   unsigned int swap_rgb :1;             /* RGB swapped to BGR */
   unsigned int alpha_first :1;          /* Alpha at start, not end */
   unsigned int alpha_inverted :1;       /* Alpha channel inverted */
   unsigned int mono_inverted :1;        /* Gray channel inverted */
   unsigned int swap16 :1;               /* Byte swap 16-bit components */
   unsigned int littleendian :1;         /* High bits on right */
   unsigned int sig_bits :1;             /* Pixel shifted (sig bits only) */

   /* For checking the code calculates double precision floating point values
    * along with an error value, accumulated from the transforms.  Because an
    * sBIT setting allows larger error bounds (indeed, by the spec, apparently
    * up to just less than +/-1 in the scaled value) the *lowest* sBIT for each
    * channel is stored.  This sBIT value is folded in to the stored error value
    * at the end of the application of the transforms to the pixel.
    *
    * If sig_bits is set above the red, green, blue and alpha values have been
    * scaled so they only contain the significant bits of the component values.
    */
   double   redf, greenf, bluef, alphaf;
   double   rede, greene, bluee, alphae;
   png_byte red_sBIT, green_sBIT, blue_sBIT, alpha_sBIT;
} image_pixel;
#if defined PNG_READ_EXPAND_SUPPORTED || defined PNG_READ_GRAY_TO_RGB_SUPPORTED\
#        if PNG_LIBPNG_VER < 10700
#        endif
#           if PNG_LIBPNG_VER >= 10700
#           endif
#endif /* transforms that need image_pixel_add_alpha */
typedef struct image_transform
{
   /* The name of this transform: a string. */
   const char *name;

   /* Each transform can be disabled from the command line: */
   int enable;

   /* The global list of transforms; read only. */
   struct image_transform *const list;

   /* The global count of the number of times this transform has been set on an
    * image.
    */
   unsigned int global_use;

   /* The local count of the number of times this transform has been set. */
   unsigned int local_use;

   /* The next transform in the list, each transform must call its own next
    * transform after it has processed the pixel successfully.
    */
   const struct image_transform *next;

   /* A single transform for the image, expressed as a series of function
    * callbacks and some space for values.
    *
    * First a callback to add any required modifications to the png_modifier;
    * this gets called just before the modifier is set up for read.
    */
   void (*ini)(const struct image_transform *this,
      struct transform_display *that);

   /* And a callback to set the transform on the current png_read_struct:
    */
   void (*set)(const struct image_transform *this,
      struct transform_display *that, png_structp pp, png_infop pi);

   /* Then a transform that takes an input pixel in one PNG format or another
    * and modifies it by a pngvalid implementation of the transform (thus
    * duplicating the libpng intent without, we hope, duplicating the bugs
    * in the libpng implementation!)  The png_structp is solely to allow error
    * reporting via png_error and png_warning.
    */
   void (*mod)(const struct image_transform *this, image_pixel *that,
      png_const_structp pp, const struct transform_display *display);

   /* Add this transform to the list and return true if the transform is
    * meaningful for this colour type and bit depth - if false then the
    * transform should have no effect on the image so there's not a lot of
    * point running it.
    */
   int (*add)(struct image_transform *this,
      const struct image_transform **that, png_byte colour_type,
      png_byte bit_depth);
} image_transform;
typedef struct transform_display
{
   standard_display this;

   /* Parameters */
   png_modifier*              pm;
   const image_transform* transform_list;
   unsigned int max_gamma_8;

   /* Local variables */
   png_byte output_colour_type;
   png_byte output_bit_depth;
   png_byte unpacked;

   /* Modifications (not necessarily used.) */
   gama_modification gama_mod;
   chrm_modification chrm_mod;
   srgb_modification srgb_mod;
} transform_display;
#     if 0
#     endif
#define ITSTRUCT(name) image_transform_##name
#define ITDATA(name) image_transform_data_##name
#define image_transform_ini image_transform_default_ini
#define IT(name)\
#define PT ITSTRUCT(end) /* stores the previous transform */
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_SUPPORTED
#undef PT
#define PT ITSTRUCT(palette_to_rgb)
#endif /* PNG_READ_EXPAND_SUPPORTED */
#ifdef PNG_READ_EXPAND_SUPPORTED
#if PNG_LIBPNG_VER < 10700
#endif
#     if PNG_LIBPNG_VER >= 10700
#     endif
#if PNG_LIBPNG_VER < 10700
#endif
#  if PNG_LIBPNG_VER >= 10700
#  endif
#undef PT
#define PT ITSTRUCT(tRNS_to_alpha)
#endif /* PNG_READ_EXPAND_SUPPORTED */
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#undef PT
#define PT ITSTRUCT(gray_to_rgb)
#endif /* PNG_READ_GRAY_TO_RGB_SUPPORTED */
#ifdef PNG_READ_EXPAND_SUPPORTED
#undef PT
#define PT ITSTRUCT(expand)
#endif /* PNG_READ_EXPAND_SUPPORTED */
#ifdef PNG_READ_EXPAND_SUPPORTED
#if PNG_LIBPNG_VER < 10700
#else
#endif /* 1.7 or later */
#if PNG_LIBPNG_VER < 10700
#else
#endif /* 1.7 or later */
#undef PT
#define PT ITSTRUCT(expand_gray_1_2_4_to_8)
#endif /* PNG_READ_EXPAND_SUPPORTED */
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#  if PNG_LIBPNG_VER < 10700
#  endif
#undef PT
#define PT ITSTRUCT(expand_16)
#endif /* PNG_READ_EXPAND_16_SUPPORTED */
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED  /* API added in 1.5.4 */
#  if PNG_LIBPNG_VER < 10700
#  endif
#undef PT
#define PT ITSTRUCT(scale_16)
#endif /* PNG_READ_SCALE_16_TO_8_SUPPORTED (1.5.4 on) */
#ifdef PNG_READ_16_TO_8_SUPPORTED /* the default before 1.5.4 */
#  if PNG_LIBPNG_VER < 10700
#  endif
#     ifdef PNG_READ_ACCURATE_SCALE_SUPPORTED
#        if PNG_LIBPNG_VER >= 10504
#           error PNG_READ_ACCURATE_SCALE should not be set
#        endif
#     endif
#undef PT
#define PT ITSTRUCT(strip_16)
#endif /* PNG_READ_16_TO_8_SUPPORTED */
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#undef PT
#define PT ITSTRUCT(strip_alpha)
#endif /* PNG_READ_STRIP_ALPHA_SUPPORTED */
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#define data ITDATA(rgb_to_gray)
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  else
#  endif
#undef image_transform_ini
#define image_transform_ini image_transform_png_set_rgb_to_gray_ini
#     if PNG_LIBPNG_VER < 10700
#     else
#     endif
#     ifdef PNG_FLOATING_POINT_SUPPORTED
#     else
#     endif
#        if PNG_LIBPNG_VER < 10700
#        endif
#if DIGITIZE
#else
#endif
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  else
#  endif
#  ifdef PNG_READ_cHRM_SUPPORTED
#        ifdef PNG_FLOATING_POINT_SUPPORTED
#           define API_function png_get_cHRM_XYZ
#           define API_form "FP"
#           define API_type double
#           define API_cvt(x) (x)
#        else
#           define API_function png_get_cHRM_XYZ_fixed
#           define API_form "fixed"
#           define API_type png_fixed_point
#           define API_cvt(x) ((double)(x)/PNG_FP_1)
#        endif
#           define CHECK(col,x)\
#  endif /* READ_cHRM */
#     if PNG_LIBPNG_VER < 10700
#     endif
#  if DIGITIZE
#        define DD(v,d,r) (digitize(v*(1-DBL_EPSILON), d, r) * (1-DBL_EPSILON))
#        define DU(v,d,r) (digitize(v*(1+DBL_EPSILON), d, r) * (1+DBL_EPSILON))
#        undef DD
#        undef DU
#if !RELEASE_BUILD
#endif /* !RELEASE_BUILD */
#  else  /* !DIGITIZE */
#        if PNG_LIBPNG_VER < 10700
#        endif /* before 1.7 */
#if !RELEASE_BUILD
#endif /* !RELEASE_BUILD */
#  endif /* !DIGITIZE */
#undef data
#undef PT
#define PT ITSTRUCT(rgb_to_gray)
#undef image_transform_ini
#define image_transform_ini image_transform_default_ini
#endif /* PNG_READ_RGB_TO_GRAY_SUPPORTED */
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#define data ITDATA(background)
#ifdef PNG_FLOATING_POINT_SUPPORTED
#else
#endif
#define image_transform_png_set_background_add image_transform_default_add
#undef data
#undef PT
#define PT ITSTRUCT(background)
#endif /* PNG_READ_BACKGROUND_SUPPORTED */
#ifdef PNG_READ_INVERT_ALPHA_SUPPORTED
#undef PT
#define PT ITSTRUCT(invert_alpha)
#endif /* PNG_READ_INVERT_ALPHA_SUPPORTED */
#ifdef PNG_READ_BGR_SUPPORTED
#undef PT
#define PT ITSTRUCT(bgr)
#endif /* PNG_READ_BGR_SUPPORTED */
#ifdef PNG_READ_SWAP_ALPHA_SUPPORTED
#undef PT
#define PT ITSTRUCT(swap_alpha)
#endif /* PNG_READ_SWAP_ALPHA_SUPPORTED */
#ifdef PNG_READ_SWAP_SUPPORTED
#undef PT
#define PT ITSTRUCT(swap)
#endif /* PNG_READ_SWAP_SUPPORTED */
#ifdef PNG_READ_FILLER_SUPPORTED
#define data ITDATA(filler)
#undef data
#undef PT
#define PT ITSTRUCT(filler)
#define data ITDATA(add_alpha)
#undef data
#undef PT
#define PT ITSTRUCT(add_alpha)
#endif /* PNG_READ_FILLER_SUPPORTED */
#ifdef PNG_READ_PACK_SUPPORTED
#undef PT
#define PT ITSTRUCT(packing)
#endif /* PNG_READ_PACK_SUPPORTED */
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#undef PT
#define PT ITSTRUCT(packswap)
#endif /* PNG_READ_PACKSWAP_SUPPORTED */
#ifdef PNG_READ_INVERT_MONO_SUPPORTED
#undef PT
#define PT ITSTRUCT(invert_mono)
#endif /* PNG_READ_INVERT_MONO_SUPPORTED */
#ifdef PNG_READ_SHIFT_SUPPORTED
#define data ITDATA(shift)
#undef PT
#define PT ITSTRUCT(shift)
#endif /* PNG_READ_SHIFT_SUPPORTED */
#ifdef THIS_IS_THE_PROFORMA
#endif
#endif /* PNG_READ_TRANSFORMS_SUPPORTED */
#ifdef PNG_READ_GAMMA_SUPPORTED
typedef struct gamma_display
{
   standard_display this;

   /* Parameters */
   png_modifier*    pm;
   double           file_gamma;
   double           screen_gamma;
   double           background_gamma;
   png_byte         sbit;
   int              threshold_test;
   int              use_input_precision;
   int              scale16;
   int              expand16;
   int              do_background;
   png_color_16     background_color;

   /* Local variables */
   double       maxerrout;
   double       maxerrpc;
   double       maxerrabs;
} gamma_display;
#define ALPHA_MODE_OFFSET 4
#     ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#     else
#        ifdef PNG_READ_16_TO_8_SUPPORTED
#        else
#        endif
#     endif
#     ifdef PNG_READ_EXPAND_16_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#        ifndef PNG_FLOATING_POINT_SUPPORTED
#        endif
#        ifdef PNG_FLOATING_POINT_SUPPORTED
#        else
#        endif
#           ifdef PNG_FLOATING_POINT_SUPPORTED
#           else
#           endif
#     else
#     endif
#     ifdef PNG_FLOATING_POINT_SUPPORTED
#     else
#     endif
#     ifdef PNG_READ_BACKGROUND_SUPPORTED
#        ifndef PNG_FLOATING_POINT_SUPPORTED
#        endif
#        ifdef PNG_FLOATING_POINT_SUPPORTED
#        else
#        endif
#     else
#     endif
typedef struct validate_info
{
   png_const_structp  pp;
   gamma_display *dp;
   png_byte sbit;
   int use_input_precision;
   int do_background;
   int scale16;
   unsigned int sbit_max;
   unsigned int isbit_shift;
   unsigned int outmax;

   double gamma_correction; /* Overall correction required. */
   double file_inverse;     /* Inverse of file gamma. */
   double screen_gamma;
   double screen_inverse;   /* Inverse of screen gamma. */

   double background_red;   /* Linear background value, red or gray. */
   double background_green;
   double background_blue;

   double maxabs;
   double maxpc;
   double maxcalc;
   double maxout;
   double maxout_total;     /* Total including quantization error */
   double outlog;
   int    outquant;
}
#     if 0
#     endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#           if PNG_LIBPNG_VER < 10700
#              define SBIT_ERROR .5
#           else
#              define SBIT_ERROR 1.
#           endif
#           ifndef PNG_READ_16_TO_8_ACCURATE_SCALE_SUPPORTED
#              if PNG_LIBPNG_VER < 10504
#              endif
#           endif
#           ifdef PNG_READ_BACKGROUND_SUPPORTED
#           endif
#           ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#           endif /* ALPHA_MODE_SUPPORTED */
#              ifdef PNG_WARNINGS_SUPPORTED
#              else
#              endif
#ifdef DO_16BIT
#  ifndef PNG_MAX_GAMMA_8
#     define PNG_MAX_GAMMA_8 11
#  endif
#  if defined PNG_MAX_GAMMA_8 || PNG_LIBPNG_VER < 10700
#     define SBIT_16_TO_8 PNG_MAX_GAMMA_8
#  else
#     define SBIT_16_TO_8 16
#  endif
#endif /* 16 to 8 bit conversion */
#if defined(PNG_READ_BACKGROUND_SUPPORTED) ||\
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#     if DIGITIZE
#     endif
#if 0 /* TODO: FIXME */
#endif
#endif /* READ_BACKGROUND || READ_ALPHA_MODE */
#  ifdef PNG_READ_BACKGROUND_SUPPORTED
#  endif
#ifdef DO_16BIT /* Should be READ_16BIT_SUPPORTED */
#endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#endif /* PNG_READ_GAMMA_SUPPORTED */
#endif /* PNG_READ_SUPPORTED */
#ifdef HAVE_FEENABLEEXCEPT
#endif
#  ifdef PNG_WRITE_tRNS_SUPPORTED
#  endif
#  if PNG_LIBPNG_VER < 10700
#  else
#  endif
#  if PNG_LIBPNG_VER < 10700
#  else
#  endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif /* PNG_READ_TRANSFORMS_SUPPORTED */
#     ifdef PNG_WRITE_tRNS_SUPPORTED
#     endif
#        if CAN_WRITE_INTERLACE
#        else /* !CAN_WRITE_INTERLACE */
#        endif /* !CAN_WRITE_INTERLACE */
#ifdef PNG_SET_OPTION_SUPPORTED
#ifdef PNG_ARM_NEON
#endif
#ifdef PNG_EXTENSIONS
#endif
#ifdef PNG_MAXIMUM_INFLATE_WINDOW
#endif
#endif /* PNG_SET_OPTION_SUPPORTED */
#        ifdef PNG_READ_SUPPORTED
#        endif
#        ifdef PNG_READ_SUPPORTED
#        endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif /* PNG_READ_TRANSFORMS_SUPPORTED */
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#if defined(PNG_FLOATING_ARITHMETIC_SUPPORTED) || PNG_LIBPNG_VER < 10500
#else
#endif
#else /* write or low level APIs not supported */
#endif
