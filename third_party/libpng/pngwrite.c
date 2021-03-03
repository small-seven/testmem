#include "pngpriv.h"
#ifdef PNG_SIMPLIFIED_WRITE_STDIO_SUPPORTED
#  include <errno.h>
#endif /* SIMPLIFIED_WRITE_STDIO */
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
#endif
#endif /* WRITE_UNKNOWN_CHUNKS */
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#else
#endif
#ifdef PNG_GAMMA_SUPPORTED
#  ifdef PNG_WRITE_gAMA_SUPPORTED
#  endif
#endif
#ifdef PNG_COLORSPACE_SUPPORTED
#  ifdef PNG_WRITE_iCCP_SUPPORTED
#    ifdef PNG_WRITE_sRGB_SUPPORTED
#     endif
#     ifdef PNG_WRITE_sRGB_SUPPORTED
#     endif
#  endif
#  ifdef PNG_WRITE_sRGB_SUPPORTED
#  endif /* WRITE_sRGB */
#endif /* COLORSPACE */
#ifdef PNG_WRITE_sBIT_SUPPORTED
#endif
#ifdef PNG_COLORSPACE_SUPPORTED
#  ifdef PNG_WRITE_cHRM_SUPPORTED
#  endif
#endif
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#endif
#if defined(PNG_WRITE_TEXT_SUPPORTED) || defined(PNG_WRITE_sPLT_SUPPORTED)
#endif
#ifdef PNG_WRITE_tRNS_SUPPORTED
#ifdef PNG_WRITE_INVERT_ALPHA_SUPPORTED
#endif
#endif
#ifdef PNG_WRITE_bKGD_SUPPORTED
#endif
#ifdef PNG_WRITE_eXIf_SUPPORTED
#endif
#ifdef PNG_WRITE_hIST_SUPPORTED
#endif
#ifdef PNG_WRITE_oFFs_SUPPORTED
#endif
#ifdef PNG_WRITE_pCAL_SUPPORTED
#endif
#ifdef PNG_WRITE_sCAL_SUPPORTED
#endif /* sCAL */
#ifdef PNG_WRITE_pHYs_SUPPORTED
#endif /* pHYs */
#ifdef PNG_WRITE_tIME_SUPPORTED
#endif /* tIME */
#ifdef PNG_WRITE_sPLT_SUPPORTED
#endif /* sPLT */
#ifdef PNG_WRITE_TEXT_SUPPORTED
#ifdef PNG_WRITE_iTXt_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_zTXt_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_tEXt_SUPPORTED
#else
#endif
#endif /* tEXt */
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#endif
#ifdef PNG_WRITE_CHECK_FOR_INVALID_INDEX_SUPPORTED
#endif
#ifdef PNG_WRITE_TEXT_SUPPORTED
#endif
#ifdef PNG_WRITE_tIME_SUPPORTED
#endif
#ifdef PNG_WRITE_TEXT_SUPPORTED
#ifdef PNG_WRITE_iTXt_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_zTXt_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_tEXt_SUPPORTED
#else
#endif
#endif
#ifdef PNG_WRITE_eXIf_SUPPORTED
#endif
#ifdef PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#endif
#ifdef PNG_WRITE_FLUSH_SUPPORTED
#  ifdef PNG_WRITE_FLUSH_AFTER_IEND_SUPPORTED
#  endif
#endif
#ifdef PNG_CONVERT_tIME_SUPPORTED
#endif
#ifndef PNG_USER_MEM_SUPPORTED
#else
#endif /* USER_MEM */
#ifdef PNG_WRITE_COMPRESSED_TEXT_SUPPORTED
#endif /* WRITE_COMPRESSED_TEXT */
#ifdef PNG_BENIGN_WRITE_ERRORS_SUPPORTED
#endif
#if PNG_RELEASE_BUILD
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#else
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#ifdef PNG_WRITE_16BIT_SUPPORTED
#endif /* WRITE_16BIT */
#endif /* MNG_FEATURES */
#if !defined(PNG_WRITE_INVERT_SUPPORTED) && defined(PNG_READ_INVERT_SUPPORTED)
#endif
#if !defined(PNG_WRITE_FILLER_SUPPORTED) && defined(PNG_READ_FILLER_SUPPORTED)
#endif
#if !defined(PNG_WRITE_PACKSWAP_SUPPORTED) && \
#endif
#if !defined(PNG_WRITE_PACK_SUPPORTED) && defined(PNG_READ_PACK_SUPPORTED)
#endif
#if !defined(PNG_WRITE_SHIFT_SUPPORTED) && defined(PNG_READ_SHIFT_SUPPORTED)
#endif
#if !defined(PNG_WRITE_BGR_SUPPORTED) && defined(PNG_READ_BGR_SUPPORTED)
#endif
#if !defined(PNG_WRITE_SWAP_SUPPORTED) && defined(PNG_READ_SWAP_SUPPORTED)
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_WRITE_CHECK_FOR_INVALID_INDEX_SUPPORTED
#endif
#ifdef PNG_WRITE_FLUSH_SUPPORTED
#endif /* WRITE_FLUSH */
png_write_destroy(png_structrp png_ptr)
{
   png_debug(1, "in png_write_destroy");

   /* Free any memory zlib uses */
   if ((png_ptr->flags & PNG_FLAG_ZSTREAM_INITIALIZED) != 0)
      deflateEnd(&png_ptr->zstream);

   /* Free our memory.  png_free checks NULL for us. */
   png_free_buffer_list(png_ptr, &png_ptr->zbuffer_list);
   png_free(png_ptr, png_ptr->row_buf);
   png_ptr->row_buf = NULL;
#ifdef PNG_WRITE_FILTER_SUPPORTED
   png_free(png_ptr, png_ptr->prev_row);
   png_free(png_ptr, png_ptr->try_row);
   png_free(png_ptr, png_ptr->tst_row);
   png_ptr->prev_row = NULL;
   png_ptr->try_row = NULL;
   png_ptr->tst_row = NULL;
#endif

#ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
   png_free(png_ptr, png_ptr->chunk_list);
   png_ptr->chunk_list = NULL;
#endif

   /* The error handling and memory handling information is left intact at this
    * point: the jmp_buf may still have to be freed.  See png_destroy_png_struct
    * for how this happens.
    */
}
png_destroy_write_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr)
{
   png_debug(1, "in png_destroy_write_struct");

   if (png_ptr_ptr != NULL)
   {
      png_structrp png_ptr = *png_ptr_ptr;

      if (png_ptr != NULL) /* added in libpng 1.6.0 */
      {
         png_destroy_info_struct(png_ptr, info_ptr_ptr);

         *png_ptr_ptr = NULL;
         png_write_destroy(png_ptr);
         png_destroy_png_struct(png_ptr);
      }
   }
}
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif /* WRITE_FILTER */
#ifdef PNG_WRITE_FILTER_SUPPORTED
#else
#endif /* WRITE_FILTER */
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif
#ifdef PNG_WRITE_WEIGHTED_FILTER_SUPPORTED /* DEPRECATED */
#ifdef PNG_FLOATING_POINT_SUPPORTED
#endif /* FLOATING_POINT */
#ifdef PNG_FIXED_POINT_SUPPORTED
#endif /* FIXED_POINT */
#endif /* WRITE_WEIGHTED_FILTER */
#ifdef PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
png_set_compression_mem_level(png_structrp png_ptr, int mem_level)
{
   png_debug(1, "in png_set_compression_mem_level");

   if (png_ptr == NULL)
      return;

   png_ptr->zlib_mem_level = mem_level;
}
#endif /* WRITE_CUSTOMIZE_COMPRESSION */
#ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
png_set_text_compression_mem_level(png_structrp png_ptr, int mem_level)
{
   png_debug(1, "in png_set_text_compression_mem_level");

   if (png_ptr == NULL)
      return;

   png_ptr->zlib_text_mem_level = mem_level;
}
#endif /* WRITE_CUSTOMIZE_ZTXT_COMPRESSION */
#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
#endif
#ifdef PNG_INFO_IMAGE_SUPPORTED
#ifdef PNG_WRITE_INVERT_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_SHIFT_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_PACK_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_SWAP_ALPHA_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_FILLER_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_BGR_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_SWAP_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_PACKSWAP_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_INVERT_ALPHA_SUPPORTED
#else
#endif
#endif
#ifdef PNG_SIMPLIFIED_WRITE_SUPPORTED
typedef struct
{
   /* Arguments: */
   png_imagep      image;
   png_const_voidp buffer;
   png_int_32      row_stride;
   png_const_voidp colormap;
   int             convert_to_8bit;
   /* Local variables: */
   png_const_voidp first_row;
   ptrdiff_t       row_bytes;
   png_voidp       local_row;
   /* Byte count for memory writing */
   png_bytep        memory;
   png_alloc_size_t memory_bytes; /* not used for STDIO */
   png_alloc_size_t output_bytes; /* running total */
} png_image_write_control;
#   ifdef PNG_SIMPLIFIED_WRITE_AFIRST_SUPPORTED
#     else
#     endif
#   define UNP_RECIPROCAL(alpha) ((((0xffff*0xff)<<7)+((alpha)>>1))/(alpha))
#   ifdef PNG_SIMPLIFIED_WRITE_AFIRST_SUPPORTED
#   endif
#   if defined(PNG_FORMAT_BGR_SUPPORTED) &&\
#   else
#     define afirst 0
#   endif
#   ifdef PNG_FORMAT_BGR_SUPPORTED
#   else
#     define bgr 0
#   endif
#   ifdef afirst
#     undef afirst
#   endif
#   ifdef bgr
#     undef bgr
#   endif
#   ifdef PNG_BENIGN_ERRORS_SUPPORTED
#   endif
#   ifdef PNG_SIMPLIFIED_WRITE_BGR_SUPPORTED
#   endif
#   ifdef PNG_SIMPLIFIED_WRITE_AFIRST_SUPPORTED
#   endif
#   ifdef PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
#   endif
png_image_write_memory(png_voidp argument)
{
   png_image_write_control *display = png_voidcast(png_image_write_control*,
       argument);

   /* The rest of the memory-specific init and write_main in an error protected
    * environment.  This case needs to use callbacks for the write operations
    * since libpng has no built in support for writing to memory.
    */
   png_set_write_fn(display->image->opaque->png_ptr, display/*io_ptr*/,
       image_memory_write, image_memory_flush);

   return png_image_write_main(display);
}
png_image_write_to_memory(png_imagep image, void *memory,
    png_alloc_size_t * PNG_RESTRICT memory_bytes, int convert_to_8bit,
    const void *buffer, png_int_32 row_stride, const void *colormap)
{
   /* Write the image to the given buffer, or count the bytes if it is NULL */
   if (image != NULL && image->version == PNG_IMAGE_VERSION)
   {
      if (memory_bytes != NULL && buffer != NULL)
      {
         /* This is to give the caller an easier error detection in the NULL
          * case and guard against uninitialized variable problems:
          */
         if (memory == NULL)
            *memory_bytes = 0;

         if (png_image_write_init(image) != 0)
         {
            png_image_write_control display;
            int result;

            memset(&display, 0, (sizeof display));
            display.image = image;
            display.buffer = buffer;
            display.row_stride = row_stride;
            display.colormap = colormap;
            display.convert_to_8bit = convert_to_8bit;
            display.memory = png_voidcast(png_bytep, memory);
            display.memory_bytes = *memory_bytes;
            display.output_bytes = 0;

            result = png_safe_execute(image, png_image_write_memory, &display);
            png_image_free(image);

            /* write_memory returns true even if we ran out of buffer. */
            if (result)
            {
               /* On out-of-buffer this function returns '0' but still updates
                * memory_bytes:
                */
               if (memory != NULL && display.output_bytes > *memory_bytes)
                  result = 0;

               *memory_bytes = display.output_bytes;
            }

            return result;
         }

         else
            return 0;
      }

      else
         return png_image_error(image,
             "png_image_write_to_memory: invalid argument");
   }

   else if (image != NULL)
      return png_image_error(image,
          "png_image_write_to_memory: incorrect PNG_IMAGE_VERSION");

   else
      return 0;
}
#ifdef PNG_SIMPLIFIED_WRITE_STDIO_SUPPORTED
#endif /* SIMPLIFIED_WRITE_STDIO */
#endif /* SIMPLIFIED_WRITE */
#endif /* WRITE */
