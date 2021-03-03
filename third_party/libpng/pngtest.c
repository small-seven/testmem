#define _POSIX_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STDERR stdout   /* For DOS */
#include "png.h"
#if defined PNG_READ_SUPPORTED && /* else nothing can be done */\
#ifdef PNG_ZLIB_HEADER
#  include PNG_ZLIB_HEADER /* defined by pnglibconf.h from 1.7 */
#else
#  include "zlib.h"
#endif
#ifndef PNG_ZBUF_SIZE
#  define PNG_ZBUF_SIZE 8192
#endif
#define FCLOSE(file) fclose(file)
#ifndef PNG_STDIO_SUPPORTED
typedef FILE                * png_FILE_p;
#endif

/* Makes pngtest verbose so we can find problems. */
#ifndef PNG_DEBUG
#  define PNG_DEBUG 0
#endif

#if PNG_DEBUG > 1
#  define pngtest_debug(m)        ((void)fprintf(stderr, m "\n"))
#  define pngtest_debug1(m,p1)    ((void)fprintf(stderr, m "\n", p1))
#  define pngtest_debug2(m,p1,p2) ((void)fprintf(stderr, m "\n", p1, p2))
#else
#  define pngtest_debug(m)        ((void)0)
#  define pngtest_debug1(m,p1)    ((void)0)
#  define pngtest_debug2(m,p1,p2) ((void)0)
#endif

#if !PNG_DEBUG
#  define SINGLE_ROWBUF_ALLOC  /* Makes buffer overruns easier to nail */
#endif

#ifndef PNG_UNUSED
#  define PNG_UNUSED(param) (void)param;
#endif

/* Turn on CPU timing
#define PNGTEST_TIMING
*/

#ifndef PNG_FLOATING_POINT_SUPPORTED
#undef PNGTEST_TIMING
#endif

#ifdef PNGTEST_TIMING
static float t_start, t_stop, t_decode, t_encode, t_misc;
#include <time.h>
#endif

#ifdef PNG_TIME_RFC1123_SUPPORTED
#define PNG_tIME_STRING_LENGTH 29
static int tIME_chunk_present = 0;
static char tIME_string[PNG_tIME_STRING_LENGTH] = "tIME chunk is not present";

#if PNG_LIBPNG_VER < 10619
#define png_convert_to_rfc1123_buffer(ts, t) tIME_to_str(read_ptr, ts, t)

static int
tIME_to_str(png_structp png_ptr, png_charp ts, png_const_timep t)
{
   png_const_charp str = png_convert_to_rfc1123(png_ptr, t);

   if (str == NULL)
       return 0;

   strcpy(ts, str);
   return 1;
}
#endif /* older libpng */
#endif
#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) png_ptr->jmpbuf
#endif
#ifndef PNG_HANDLE_CHUNK_ALWAYS
#  define PNG_HANDLE_CHUNK_ALWAYS       3
#endif
#ifndef PNG_HANDLE_CHUNK_IF_SAFE
#  define PNG_HANDLE_CHUNK_IF_SAFE      2
#endif
#define MEMZERO(var) ((void)memset(&var, 0, sizeof var))
#ifdef PNG_WRITE_SUPPORTED
#endif
#ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
#endif
#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
#endif /* WRITE_USER_TRANSFORM */
#ifndef PNG_STDIO_SUPPORTED
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_WRITE_FLUSH_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#endif /* !STDIO */
typedef struct
{
   const char *file_name;
}  pngtest_error_parameters;
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
typedef struct memory_information
{
   png_alloc_size_t          size;
   png_voidp                 pointer;
   struct memory_information *next;
} memory_information;
typedef memory_information *memory_infop;

static memory_infop pinformation = NULL;
static int current_allocation = 0;
static int maximum_allocation = 0;
static int total_allocation = 0;
static int num_allocations = 0;

png_voidp PNGCBAPI png_debug_malloc PNGARG((png_structp png_ptr,
    png_alloc_size_t size));
void PNGCBAPI png_debug_free PNGARG((png_structp png_ptr, png_voidp ptr));

png_voidp
PNGCBAPI png_debug_malloc(png_structp png_ptr, png_alloc_size_t size)
{

   /* png_malloc has already tested for NULL; png_create_struct calls
    * png_debug_malloc directly, with png_ptr == NULL which is OK
    */

   if (size == 0)
      return (NULL);

   /* This calls the library allocator twice, once to get the requested
      buffer and once to get a new free list entry. */
   {
      /* Disable malloc_fn and free_fn */
      memory_infop pinfo;
      png_set_mem_fn(png_ptr, NULL, NULL, NULL);
      pinfo = (memory_infop)png_malloc(png_ptr,
          (sizeof *pinfo));
      pinfo->size = size;
      current_allocation += size;
      total_allocation += size;
      num_allocations ++;

      if (current_allocation > maximum_allocation)
         maximum_allocation = current_allocation;

      pinfo->pointer = png_malloc(png_ptr, size);
      /* Restore malloc_fn and free_fn */

      png_set_mem_fn(png_ptr,
          NULL, png_debug_malloc, png_debug_free);

      if (size != 0 && pinfo->pointer == NULL)
      {
         current_allocation -= size;
         total_allocation -= size;
         png_error(png_ptr,
           "out of memory in pngtest->png_debug_malloc");
      }
png_debug_free(png_structp png_ptr, png_voidp ptr)
{
   if (png_ptr == NULL)
      fprintf(STDERR, "NULL pointer to png_debug_free.\n");

   if (ptr == 0)
   {
#if 0 /* This happens all the time. */
      fprintf(STDERR, "WARNING: freeing NULL pointer\n");
#endif
      return;
   }

   /* Unlink the element from the list. */
   if (pinformation != NULL)
   {
      memory_infop *ppinfo = &pinformation;

      for (;;)
      {
         memory_infop pinfo = *ppinfo;

         if (pinfo->pointer == ptr)
         {
            *ppinfo = pinfo->next;
            current_allocation -= pinfo->size;
            if (current_allocation < 0)
               fprintf(STDERR, "Duplicate free of memory\n");
            /* We must free the list element too, but first kill
               the memory that is to be freed. */
            memset(ptr, 0x55, pinfo->size);
            free(pinfo);
            pinfo = NULL;
            break;
         }

         if (pinfo->next == NULL)
         {
            fprintf(STDERR, "Pointer %p not found\n", ptr);
            break;
         }

         ppinfo = &pinfo->next;
      }
   }

   /* Finally free the data. */
   if (verbose != 0)
      printf("Freeing %p\n", ptr);

   if (ptr != NULL)
      free(ptr);
   ptr = NULL;
}
#endif /* USER_MEM && DEBUG */
#ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#define have_sTER   0x01
#define have_vpAg   0x02
#define before_PLTE 0x10
#define before_IDAT 0x20
#define after_IDAT  0x40
#ifdef PNG_WRITE_SUPPORTED
#endif /* WRITE */
#else /* !READ_USER_CHUNKS */
#  define write_chunks(pp,loc) ((void)0)
#endif
#ifdef PNG_TEXT_SUPPORTED
#           ifndef PNG_WRITE_zTXt_SUPPORTED
#           endif
#           ifndef PNG_WRITE_iTXt_SUPPORTED
#           endif
#endif
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif /* WRITE_FILTER */
#else /* !WRITE */
#endif /* !WRITE */
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#else
#endif
#ifdef PNG_WRITE_SUPPORTED
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#else
#endif
#endif
#ifdef PNG_WRITE_SUPPORTED
#endif
#ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#endif
#ifdef PNG_SETJMP_SUPPORTED
#ifdef PNG_WRITE_SUPPORTED
#endif
#ifdef PNG_WRITE_SUPPORTED
#endif
#endif
#ifdef PNG_BENIGN_ERRORS_SUPPORTED
# ifdef PNG_WRITE_SUPPORTED
# endif
#ifdef PNG_IGNORE_ADLER32
#endif
# ifdef PNG_WRITE_SUPPORTED
# endif
#endif /* BENIGN_ERRORS */
#ifdef PNG_STDIO_SUPPORTED
#  ifdef PNG_WRITE_SUPPORTED
#  endif
#else
#  ifdef PNG_WRITE_SUPPORTED
#    ifdef PNG_WRITE_FLUSH_SUPPORTED
#    else
#    endif
#  endif
#endif
#ifdef PNG_WRITE_SUPPORTED
#endif
#ifdef PNG_WRITE_SUPPORTED
#endif
#ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
#endif
#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
#endif
#ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
#ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#endif
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#endif
#endif
#ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
#ifdef PNG_cHRM_SUPPORTED
#endif
#ifdef PNG_gAMA_SUPPORTED
#endif
#else /* Use floating point versions */
#ifdef PNG_FLOATING_POINT_SUPPORTED
#ifdef PNG_cHRM_SUPPORTED
#endif
#ifdef PNG_gAMA_SUPPORTED
#endif
#endif /* Floating point */
#endif /* Fixed point */
#ifdef PNG_iCCP_SUPPORTED
#endif
#ifdef PNG_sRGB_SUPPORTED
#endif
#ifdef PNG_bKGD_SUPPORTED
#endif
#ifdef PNG_READ_eXIf_SUPPORTED
# ifdef PNG_WRITE_eXIf_SUPPORTED
# endif
#endif
#ifdef PNG_hIST_SUPPORTED
#endif
#ifdef PNG_oFFs_SUPPORTED
#endif
#ifdef PNG_pCAL_SUPPORTED
#endif
#ifdef PNG_pHYs_SUPPORTED
#endif
#ifdef PNG_sBIT_SUPPORTED
#endif
#ifdef PNG_sCAL_SUPPORTED
#if defined(PNG_FLOATING_POINT_SUPPORTED) && \
#else
#ifdef PNG_FIXED_POINT_SUPPORTED
#endif
#endif
#endif
#ifdef PNG_sPLT_SUPPORTED
#endif
#ifdef PNG_TEXT_SUPPORTED
#endif
#ifdef PNG_tIME_SUPPORTED
#ifdef PNG_TIME_RFC1123_SUPPORTED
#endif /* TIME_RFC1123 */
#endif
#ifdef PNG_tRNS_SUPPORTED
#endif
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#if PNG_LIBPNG_VER < 10600
#endif
#endif
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNG_COMPRESSION_COMPAT
#endif
#endif
#ifdef SINGLE_ROWBUF_ALLOC
#endif /* SINGLE_ROWBUF_ALLOC */
#if defined(PNG_READ_INTERLACING_SUPPORTED) &&\
#else /* png_set_interlace_handling not called on either read or write */
#  define calc_pass_height
#endif /* not using libpng interlace handling */
#ifdef PNGTEST_TIMING
#endif
#     ifdef calc_pass_height
#     else
#        define pass_height height
#     endif
#ifndef SINGLE_ROWBUF_ALLOC
#endif /* !SINGLE_ROWBUF_ALLOC */
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNGTEST_TIMING
#endif
#ifdef PNGTEST_TIMING
#endif
#endif /* WRITE */
#ifndef SINGLE_ROWBUF_ALLOC
#endif /* !SINGLE_ROWBUF_ALLOC */
#ifdef PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
#  ifdef PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
#  endif
#  ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#  endif
#endif
#ifdef PNG_TEXT_SUPPORTED
#endif
#ifdef PNG_READ_eXIf_SUPPORTED
# ifdef PNG_WRITE_eXIf_SUPPORTED
# endif
#endif
#ifdef PNG_tIME_SUPPORTED
#ifdef PNG_TIME_RFC1123_SUPPORTED
#endif /* TIME_RFC1123 */
#endif
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#if PNG_LIBPNG_VER < 10600
#endif
#endif
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
#endif
#endif
#ifdef PNG_EASY_ACCESS_SUPPORTED
#endif
#ifdef SINGLE_ROWBUF_ALLOC
#endif /* SINGLE_ROWBUF_ALLOC */
#ifdef PNG_WRITE_SUPPORTED
#endif
#  ifdef PNG_WRITE_SUPPORTED
#  endif
#if defined (PNG_WRITE_SUPPORTED) /* else nothing was written */ &&\
#endif /* WRITE && WRITE_FILTER */
#ifdef RISCOS
#else
#endif
#if defined(MAXSEG_64K) && !defined(PNG_MAX_MALLOC_64K)
#endif
#if !defined(MAXSEG_64K) && defined(PNG_MAX_MALLOC_64K)
#endif
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#endif
#if PNG_DEBUG > 0
#endif
#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
#else
#endif
#ifdef PNG_TIME_RFC1123_SUPPORTED
#endif /* TIME_RFC1123 */
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#endif
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#endif
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#endif
#if PNG_DEBUG > 0
#endif
#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
#else
#endif
#ifdef PNG_TIME_RFC1123_SUPPORTED
#endif /* TIME_RFC1123 */
#if PNG_DEBUG > 0
#endif
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#endif
#if defined(PNG_USER_MEM_SUPPORTED) && PNG_DEBUG
#endif
#ifdef PNGTEST_TIMING
#endif
#else
#endif
