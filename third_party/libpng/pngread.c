#include "pngpriv.h"
#if defined(PNG_SIMPLIFIED_READ_SUPPORTED) && defined(PNG_STDIO_SUPPORTED)
#  include <errno.h>
#endif
#ifdef PNG_READ_SUPPORTED
#ifndef PNG_USER_MEM_SUPPORTED
#else
#endif /* USER_MEM */
#     ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#     endif
#     ifdef PNG_BENIGN_READ_ERRORS_SUPPORTED
#        if PNG_RELEASE_BUILD
#        endif
#     endif
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif
#ifdef PNG_READ_bKGD_SUPPORTED
#endif
#ifdef PNG_READ_cHRM_SUPPORTED
#endif
#ifdef PNG_READ_eXIf_SUPPORTED
#endif
#ifdef PNG_READ_gAMA_SUPPORTED
#endif
#ifdef PNG_READ_hIST_SUPPORTED
#endif
#ifdef PNG_READ_oFFs_SUPPORTED
#endif
#ifdef PNG_READ_pCAL_SUPPORTED
#endif
#ifdef PNG_READ_sCAL_SUPPORTED
#endif
#ifdef PNG_READ_pHYs_SUPPORTED
#endif
#ifdef PNG_READ_sBIT_SUPPORTED
#endif
#ifdef PNG_READ_sRGB_SUPPORTED
#endif
#ifdef PNG_READ_iCCP_SUPPORTED
#endif
#ifdef PNG_READ_sPLT_SUPPORTED
#endif
#ifdef PNG_READ_tEXt_SUPPORTED
#endif
#ifdef PNG_READ_tIME_SUPPORTED
#endif
#ifdef PNG_READ_tRNS_SUPPORTED
#endif
#ifdef PNG_READ_zTXt_SUPPORTED
#endif
#ifdef PNG_READ_iTXt_SUPPORTED
#endif
#endif /* SEQUENTIAL_READ */
#        ifdef PNG_READ_TRANSFORMS_SUPPORTED
#        else
#        endif
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#endif /* SEQUENTIAL_READ */
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif /* MNG_FEATURES */
#ifdef PNG_WARNINGS_SUPPORTED
#if defined(PNG_WRITE_INVERT_SUPPORTED) && !defined(PNG_READ_INVERT_SUPPORTED)
#endif
#if defined(PNG_WRITE_FILLER_SUPPORTED) && !defined(PNG_READ_FILLER_SUPPORTED)
#endif
#if defined(PNG_WRITE_PACKSWAP_SUPPORTED) && \
#endif
#if defined(PNG_WRITE_PACK_SUPPORTED) && !defined(PNG_READ_PACK_SUPPORTED)
#endif
#if defined(PNG_WRITE_SHIFT_SUPPORTED) && !defined(PNG_READ_SHIFT_SUPPORTED)
#endif
#if defined(PNG_WRITE_BGR_SUPPORTED) && !defined(PNG_READ_BGR_SUPPORTED)
#endif
#if defined(PNG_WRITE_SWAP_SUPPORTED) && !defined(PNG_READ_SWAP_SUPPORTED)
#endif
#endif /* WARNINGS */
#ifdef PNG_READ_INTERLACING_SUPPORTED
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_READ_INTERLACING_SUPPORTED
#endif
#endif /* SEQUENTIAL_READ */
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#endif /* SEQUENTIAL_READ */
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#ifdef PNG_READ_INTERLACING_SUPPORTED
#else
#endif
#endif /* SEQUENTIAL_READ */
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif
#ifdef PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif
#ifdef PNG_READ_bKGD_SUPPORTED
#endif
#ifdef PNG_READ_cHRM_SUPPORTED
#endif
#ifdef PNG_READ_eXIf_SUPPORTED
#endif
#ifdef PNG_READ_gAMA_SUPPORTED
#endif
#ifdef PNG_READ_hIST_SUPPORTED
#endif
#ifdef PNG_READ_oFFs_SUPPORTED
#endif
#ifdef PNG_READ_pCAL_SUPPORTED
#endif
#ifdef PNG_READ_sCAL_SUPPORTED
#endif
#ifdef PNG_READ_pHYs_SUPPORTED
#endif
#ifdef PNG_READ_sBIT_SUPPORTED
#endif
#ifdef PNG_READ_sRGB_SUPPORTED
#endif
#ifdef PNG_READ_iCCP_SUPPORTED
#endif
#ifdef PNG_READ_sPLT_SUPPORTED
#endif
#ifdef PNG_READ_tEXt_SUPPORTED
#endif
#ifdef PNG_READ_tIME_SUPPORTED
#endif
#ifdef PNG_READ_tRNS_SUPPORTED
#endif
#ifdef PNG_READ_zTXt_SUPPORTED
#endif
#ifdef PNG_READ_iTXt_SUPPORTED
#endif
#endif /* SEQUENTIAL_READ */
png_read_destroy(png_structrp png_ptr)
{
   png_debug(1, "in png_read_destroy");

#ifdef PNG_READ_GAMMA_SUPPORTED
   png_destroy_gamma_table(png_ptr);
#endif

   png_free(png_ptr, png_ptr->big_row_buf);
   png_ptr->big_row_buf = NULL;
   png_free(png_ptr, png_ptr->big_prev_row);
   png_ptr->big_prev_row = NULL;
   png_free(png_ptr, png_ptr->read_buffer);
   png_ptr->read_buffer = NULL;

#ifdef PNG_READ_QUANTIZE_SUPPORTED
   png_free(png_ptr, png_ptr->palette_lookup);
   png_ptr->palette_lookup = NULL;
   png_free(png_ptr, png_ptr->quantize_index);
   png_ptr->quantize_index = NULL;
#endif

   if ((png_ptr->free_me & PNG_FREE_PLTE) != 0)
   {
      png_zfree(png_ptr, png_ptr->palette);
      png_ptr->palette = NULL;
   }
   png_ptr->free_me &= ~PNG_FREE_PLTE;

#if defined(PNG_tRNS_SUPPORTED) || \
    defined(PNG_READ_EXPAND_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
   if ((png_ptr->free_me & PNG_FREE_TRNS) != 0)
   {
      png_free(png_ptr, png_ptr->trans_alpha);
      png_ptr->trans_alpha = NULL;
   }
   png_ptr->free_me &= ~PNG_FREE_TRNS;
#endif

   inflateEnd(&png_ptr->zstream);

#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
   png_free(png_ptr, png_ptr->save_buffer);
   png_ptr->save_buffer = NULL;
#endif

#if defined(PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED) && \
   defined(PNG_READ_UNKNOWN_CHUNKS_SUPPORTED)
   png_free(png_ptr, png_ptr->unknown_chunk.data);
   png_ptr->unknown_chunk.data = NULL;
#endif

#ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
   png_free(png_ptr, png_ptr->chunk_list);
   png_ptr->chunk_list = NULL;
#endif

#if defined(PNG_READ_EXPAND_SUPPORTED) && \
    defined(PNG_ARM_NEON_IMPLEMENTATION)
   png_free(png_ptr, png_ptr->riffled_palette);
   png_ptr->riffled_palette = NULL;
#endif

   /* NOTE: the 'setjmp' buffer may still be allocated and the memory and error
    * callbacks are still set at this point.  They are required to complete the
    * destruction of the png_struct itself.
    */
}
png_destroy_read_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr,
    png_infopp end_info_ptr_ptr)
{
   png_structrp png_ptr = NULL;

   png_debug(1, "in png_destroy_read_struct");

   if (png_ptr_ptr != NULL)
      png_ptr = *png_ptr_ptr;

   if (png_ptr == NULL)
      return;

   /* libpng 1.6.0: use the API to destroy info structs to ensure consistent
    * behavior.  Prior to 1.6.0 libpng did extra 'info' destruction in this API.
    * The extra was, apparently, unnecessary yet this hides memory leak bugs.
    */
   png_destroy_info_struct(png_ptr, end_info_ptr_ptr);
   png_destroy_info_struct(png_ptr, info_ptr_ptr);

   *png_ptr_ptr = NULL;
   png_read_destroy(png_ptr);
   png_destroy_png_struct(png_ptr);
}
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#ifdef PNG_INFO_IMAGE_SUPPORTED
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#else
#endif
#ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#else
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#else
#endif
#ifdef PNG_READ_PACK_SUPPORTED
#else
#endif
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#else
#endif
#ifdef PNG_READ_EXPAND_SUPPORTED
#else
#endif
#ifdef PNG_READ_INVERT_SUPPORTED
#else
#endif
#ifdef PNG_READ_SHIFT_SUPPORTED
#else
#endif
#ifdef PNG_READ_BGR_SUPPORTED
#else
#endif
#ifdef PNG_READ_SWAP_ALPHA_SUPPORTED
#else
#endif
#ifdef PNG_READ_SWAP_SUPPORTED
#else
#endif
#ifdef PNG_READ_INVERT_ALPHA_SUPPORTED
#else
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#else
#endif
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#else
#endif
#endif /* INFO_IMAGE */
#endif /* SEQUENTIAL_READ */
#ifdef PNG_SIMPLIFIED_READ_SUPPORTED
#  define P_NOTSET  0 /* File encoding not yet known */
#  define P_sRGB    1 /* 8-bit encoded to sRGB gamma */
#  define P_LINEAR  2 /* 16-bit linear: not encoded, NOT pre-multiplied! */
#  define P_FILE    3 /* 8-bit encoded to file gamma, not sRGB or linear */
#  define P_LINEAR8 4 /* 8-bit linear: only from a file value */
#define PNG_CMAP_NONE      0
#define PNG_CMAP_GA        1 /* Process GA data to a color-map with alpha */
#define PNG_CMAP_TRANS     2 /* Process GA data to a background index */
#define PNG_CMAP_RGB       3 /* Process RGB data */
#define PNG_CMAP_RGB_ALPHA 4 /* Process RGBA data */
#define PNG_CMAP_NONE_BACKGROUND      256
#define PNG_CMAP_GA_BACKGROUND        231
#define PNG_CMAP_TRANS_BACKGROUND     254
#define PNG_CMAP_RGB_BACKGROUND       256
#define PNG_CMAP_RGB_ALPHA_BACKGROUND 216
typedef struct
{
   /* Arguments: */
   png_imagep image;
   png_voidp  buffer;
   png_int_32 row_stride;
   png_voidp  colormap;
   png_const_colorp background;
   /* Local variables: */
   png_voidp       local_row;
   png_voidp       first_row;
   ptrdiff_t       row_bytes;           /* step between rows */
   int             file_encoding;       /* E_ values above */
   png_fixed_point gamma_to_linear;     /* For P_FILE, reciprocal of gamma */
   int             colormap_processing; /* PNG_CMAP_ values above */
} png_image_read_control;
#ifdef PNG_BENIGN_ERRORS_SUPPORTED
#endif
#ifdef PNG_COLORSPACE_SUPPORTED
#endif
#ifdef PNG_STDIO_SUPPORTED
#endif /* STDIO */
png_image_memory_read(png_structp png_ptr, png_bytep out, size_t need)
{
   if (png_ptr != NULL)
   {
      png_imagep image = png_voidcast(png_imagep, png_ptr->io_ptr);
      if (image != NULL)
      {
         png_controlp cp = image->opaque;
         if (cp != NULL)
         {
            png_const_bytep memory = cp->memory;
            size_t size = cp->size;

            if (memory != NULL && size >= need)
            {
               memcpy(out, memory, need);
               cp->memory = memory + need;
               cp->size = size - need;
               return;
            }

            png_error(png_ptr, "read beyond end of data");
         }
      }

      png_error(png_ptr, "invalid memory read");
   }
}
int PNGAPI png_image_begin_read_from_memory(png_imagep image,
    png_const_voidp memory, size_t size)
{
   if (image != NULL && image->version == PNG_IMAGE_VERSION)
   {
      if (memory != NULL && size > 0)
      {
         if (png_image_read_init(image) != 0)
         {
            /* Now set the IO functions to read from the memory buffer and
             * store it into io_ptr.  Again do this in-place to avoid calling a
             * libpng function that requires error handling.
             */
            image->opaque->memory = png_voidcast(png_const_bytep, memory);
            image->opaque->size = size;
            image->opaque->png_ptr->io_ptr = image;
            image->opaque->png_ptr->read_data_fn = png_image_memory_read;

            return png_safe_execute(image, png_image_read_header, image);
         }
      }

      else
         return png_image_error(image,
             "png_image_begin_read_from_memory: invalid argument");
   }

   else if (image != NULL)
      return png_image_error(image,
          "png_image_begin_read_from_memory: incorrect PNG_IMAGE_VERSION");

   return 0;
}
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#        ifdef PNG_READ_iCCP_SUPPORTED
#        endif
#  define PNG_SKIP_CHUNKS(p) png_image_skip_unused_chunks(p)
#else
#  define PNG_SKIP_CHUNKS(p) ((void)0)
#endif /* HANDLE_AS_UNKNOWN */
#define PNG_DIV51(v8) (((v8) * 5 + 130) >> 8)
#ifdef __GNUC__
#endif
png_create_colormap_entry(png_image_read_control *display,
    png_uint_32 ip, png_uint_32 red, png_uint_32 green, png_uint_32 blue,
    png_uint_32 alpha, int encoding)
{
   png_imagep image = display->image;
   int output_encoding = (image->format & PNG_FORMAT_FLAG_LINEAR) != 0 ?
       P_LINEAR : P_sRGB;
   int convert_to_Y = (image->format & PNG_FORMAT_FLAG_COLOR) == 0 &&
       (red != green || green != blue);

   if (ip > 255)
      png_error(image->opaque->png_ptr, "color-map index out of range");

   /* Update the cache with whether the file gamma is significantly different
    * from sRGB.
    */
   if (encoding == P_FILE)
   {
      if (display->file_encoding == P_NOTSET)
         set_file_encoding(display);

      /* Note that the cached value may be P_FILE too, but if it is then the
       * gamma_to_linear member has been set.
       */
      encoding = display->file_encoding;
   }

   if (encoding == P_FILE)
   {
      png_fixed_point g = display->gamma_to_linear;

      red = png_gamma_16bit_correct(red*257, g);
      green = png_gamma_16bit_correct(green*257, g);
      blue = png_gamma_16bit_correct(blue*257, g);

      if (convert_to_Y != 0 || output_encoding == P_LINEAR)
      {
         alpha *= 257;
         encoding = P_LINEAR;
      }

      else
      {
         red = PNG_sRGB_FROM_LINEAR(red * 255);
         green = PNG_sRGB_FROM_LINEAR(green * 255);
         blue = PNG_sRGB_FROM_LINEAR(blue * 255);
         encoding = P_sRGB;
      }
   }

   else if (encoding == P_LINEAR8)
   {
      /* This encoding occurs quite frequently in test cases because PngSuite
       * includes a gAMA 1.0 chunk with most images.
       */
      red *= 257;
      green *= 257;
      blue *= 257;
      alpha *= 257;
      encoding = P_LINEAR;
   }

   else if (encoding == P_sRGB &&
       (convert_to_Y  != 0 || output_encoding == P_LINEAR))
   {
      /* The values are 8-bit sRGB values, but must be converted to 16-bit
       * linear.
       */
      red = png_sRGB_table[red];
      green = png_sRGB_table[green];
      blue = png_sRGB_table[blue];
      alpha *= 257;
      encoding = P_LINEAR;
   }

   /* This is set if the color isn't gray but the output is. */
   if (encoding == P_LINEAR)
   {
      if (convert_to_Y != 0)
      {
         /* NOTE: these values are copied from png_do_rgb_to_gray */
         png_uint_32 y = (png_uint_32)6968 * red  + (png_uint_32)23434 * green +
            (png_uint_32)2366 * blue;

         if (output_encoding == P_LINEAR)
            y = (y + 16384) >> 15;

         else
         {
            /* y is scaled by 32768, we need it scaled by 255: */
            y = (y + 128) >> 8;
            y *= 255;
            y = PNG_sRGB_FROM_LINEAR((y + 64) >> 7);
            alpha = PNG_DIV257(alpha);
            encoding = P_sRGB;
         }

         blue = red = green = y;
      }

      else if (output_encoding == P_sRGB)
      {
         red = PNG_sRGB_FROM_LINEAR(red * 255);
         green = PNG_sRGB_FROM_LINEAR(green * 255);
         blue = PNG_sRGB_FROM_LINEAR(blue * 255);
         alpha = PNG_DIV257(alpha);
         encoding = P_sRGB;
      }
   }

   if (encoding != output_encoding)
      png_error(image->opaque->png_ptr, "bad encoding (internal error)");

   /* Store the value. */
   {
#     ifdef PNG_FORMAT_AFIRST_SUPPORTED
         int afirst = (image->format & PNG_FORMAT_FLAG_AFIRST) != 0 &&
            (image->format & PNG_FORMAT_FLAG_ALPHA) != 0;
#     else
#        define afirst 0
#     endif
#     ifdef PNG_FORMAT_BGR_SUPPORTED
         int bgr = (image->format & PNG_FORMAT_FLAG_BGR) != 0 ? 2 : 0;
#     else
#        define bgr 0
#     endif

      if (output_encoding == P_LINEAR)
      {
         png_uint_16p entry = png_voidcast(png_uint_16p, display->colormap);

         entry += ip * PNG_IMAGE_SAMPLE_CHANNELS(image->format);

         /* The linear 16-bit values must be pre-multiplied by the alpha channel
          * value, if less than 65535 (this is, effectively, composite on black
          * if the alpha channel is removed.)
          */
         switch (PNG_IMAGE_SAMPLE_CHANNELS(image->format))
         {
            case 4:
               entry[afirst ? 0 : 3] = (png_uint_16)alpha;
               /* FALLTHROUGH */

            case 3:
               if (alpha < 65535)
               {
                  if (alpha > 0)
                  {
                     blue = (blue * alpha + 32767U)/65535U;
                     green = (green * alpha + 32767U)/65535U;
                     red = (red * alpha + 32767U)/65535U;
                  }

                  else
                     red = green = blue = 0;
               }
               entry[afirst + (2 ^ bgr)] = (png_uint_16)blue;
               entry[afirst + 1] = (png_uint_16)green;
               entry[afirst + bgr] = (png_uint_16)red;
               break;

            case 2:
               entry[1 ^ afirst] = (png_uint_16)alpha;
               /* FALLTHROUGH */

            case 1:
               if (alpha < 65535)
               {
                  if (alpha > 0)
                     green = (green * alpha + 32767U)/65535U;

                  else
                     green = 0;
               }
               entry[afirst] = (png_uint_16)green;
               break;

            default:
               break;
         }
      }

      else /* output encoding is P_sRGB */
      {
         png_bytep entry = png_voidcast(png_bytep, display->colormap);

         entry += ip * PNG_IMAGE_SAMPLE_CHANNELS(image->format);

         switch (PNG_IMAGE_SAMPLE_CHANNELS(image->format))
         {
            case 4:
               entry[afirst ? 0 : 3] = (png_byte)alpha;
               /* FALLTHROUGH */
            case 3:
               entry[afirst + (2 ^ bgr)] = (png_byte)blue;
               entry[afirst + 1] = (png_byte)green;
               entry[afirst + bgr] = (png_byte)red;
               break;

            case 2:
               entry[1 ^ afirst] = (png_byte)alpha;
               /* FALLTHROUGH */
            case 1:
               entry[afirst] = (png_byte)green;
               break;

            default:
               break;
         }
      }

#     ifdef afirst
#        undef afirst
#     endif
#     ifdef bgr
#        undef bgr
#     endif
   }
}
#define PNG_GRAY_COLORMAP_ENTRIES 256
#define PNG_GA_COLORMAP_ENTRIES 256
#define PNG_RGB_COLORMAP_ENTRIES 216
#define PNG_RGB_INDEX(r,g,b) \
#ifdef __COVERITY__
#else
#endif
#ifdef __COVERITY__
#else
#endif
#ifdef __GNUC__
#endif
#           ifdef PNG_SIMPLIFIED_READ_AFIRST_SUPPORTED
#           endif
#ifdef __GNUC__
#endif
#ifdef PNG_FORMAT_AFIRST_SUPPORTED
#endif
#     ifdef PNG_FORMAT_BGR_SUPPORTED
#     endif
#     ifdef PNG_FORMAT_AFIRST_SUPPORTED
#     endif
#ifdef PNG_FORMAT_BGR_SUPPORTED
#endif
#ifdef PNG_FORMAT_AFIRST_SUPPORTED
#     endif
#endif /* SIMPLIFIED_READ */
#endif /* READ */
