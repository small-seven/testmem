#include "pngpriv.h"
typedef png_libpng_version_1_6_37 Your_png_h_is_not_version_1_6_37;

#ifdef __GNUC__
/* The version tests may need to be added to, but the problem warning has
 * consistently been fixed in GCC versions which obtain wide-spread release.
 * The problem is that many versions of GCC rearrange comparison expressions in
 * the optimizer in such a way that the results of the comparison will change
 * if signed integer overflow occurs.  Such comparisons are not permitted in
 * ANSI C90, however GCC isn't clever enough to work out that that do not occur
 * below in png_ascii_from_fp and png_muldiv, so it produces a warning with
 * -Wextra.  Unfortunately this is highly dependent on the optimizer and the
 * machine architecture so the warning comes and goes unpredictably and is
 * impossible to "fix", even were that a good idea.
 */
#if __GNUC__ == 7 && __GNUC_MINOR__ == 1
#define GCC_STRICT_OVERFLOW 1
#endif /* GNU 7.1.x */
#endif /* GNU */
#ifndef GCC_STRICT_OVERFLOW
#define GCC_STRICT_OVERFLOW 0
#endif

/* Tells libpng that we have already handled the first "num_bytes" bytes
 * of the PNG file signature.  If the PNG data is embedded into another
 * stream we can set num_bytes = 8 so that libpng will not attempt to read
 * or write any of the magic bytes before it starts on the IHDR.
 */

#ifdef PNG_READ_SUPPORTED
void PNGAPI
png_set_sig_bytes(png_structrp png_ptr, int num_bytes)
{
   unsigned int nb = (unsigned int)num_bytes;

   png_debug(1, "in png_set_sig_bytes");

   if (png_ptr == NULL)
      return;

   if (num_bytes < 0)
      nb = 0;

   if (nb > 8)
      png_error(png_ptr, "Too many bytes for PNG signature");

   png_ptr->sig_bytes = (png_byte)nb;
}
#endif /* READ */
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
png_zfree(voidpf png_ptr, voidpf ptr)
{
   png_free(png_voidcast(png_const_structrp,png_ptr), ptr);
}
#ifndef __COVERITY__
#endif
#ifdef PNG_WARNINGS_SUPPORTED
#endif
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
#endif
#  ifdef PNG_SETJMP_SUPPORTED
#  endif
#  ifdef PNG_USER_LIMITS_SUPPORTED
#     ifdef PNG_USER_CHUNK_CACHE_MAX
#     endif
#     ifdef PNG_USER_CHUNK_MALLOC_MAX
#     endif
#  endif
#  ifdef PNG_USER_MEM_SUPPORTED
#  else
#  endif
#  ifdef PNG_SETJMP_SUPPORTED
#  endif
#  ifdef PNG_SETJMP_SUPPORTED
#  endif
#              ifdef PNG_SETJMP_SUPPORTED
#              endif
png_destroy_info_struct(png_const_structrp png_ptr, png_infopp info_ptr_ptr)
{
   png_inforp info_ptr = NULL;

   png_debug(1, "in png_destroy_info_struct");

   if (png_ptr == NULL)
      return;

   if (info_ptr_ptr != NULL)
      info_ptr = *info_ptr_ptr;

   if (info_ptr != NULL)
   {
      /* Do this first in case of an error below; if the app implements its own
       * memory management this can lead to png_free calling png_error, which
       * will abort this routine and return control to the app error handler.
       * An infinite loop may result if it then tries to free the same info
       * ptr.
       */
      *info_ptr_ptr = NULL;

      png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
      memset(info_ptr, 0, (sizeof *info_ptr));
      png_free(png_ptr, info_ptr);
   }
}
png_data_freer(png_const_structrp png_ptr, png_inforp info_ptr,
    int freer, png_uint_32 mask)
{
   png_debug(1, "in png_data_freer");

   if (png_ptr == NULL || info_ptr == NULL)
      return;

   if (freer == PNG_DESTROY_WILL_FREE_DATA)
      info_ptr->free_me |= mask;

   else if (freer == PNG_USER_WILL_FREE_DATA)
      info_ptr->free_me &= ~mask;

   else
      png_error(png_ptr, "Unknown freer parameter in png_data_freer");
}
png_free_data(png_const_structrp png_ptr, png_inforp info_ptr, png_uint_32 mask,
    int num)
{
   png_debug(1, "in png_free_data");

   if (png_ptr == NULL || info_ptr == NULL)
      return;

#ifdef PNG_TEXT_SUPPORTED
   /* Free text item num or (if num == -1) all text items */
   if (info_ptr->text != NULL &&
       ((mask & PNG_FREE_TEXT) & info_ptr->free_me) != 0)
   {
      if (num != -1)
      {
         png_free(png_ptr, info_ptr->text[num].key);
         info_ptr->text[num].key = NULL;
      }

      else
      {
         int i;

         for (i = 0; i < info_ptr->num_text; i++)
            png_free(png_ptr, info_ptr->text[i].key);

         png_free(png_ptr, info_ptr->text);
         info_ptr->text = NULL;
         info_ptr->num_text = 0;
         info_ptr->max_text = 0;
      }
   }
#endif

#ifdef PNG_tRNS_SUPPORTED
   /* Free any tRNS entry */
   if (((mask & PNG_FREE_TRNS) & info_ptr->free_me) != 0)
   {
      info_ptr->valid &= ~PNG_INFO_tRNS;
      png_free(png_ptr, info_ptr->trans_alpha);
      info_ptr->trans_alpha = NULL;
      info_ptr->num_trans = 0;
   }
#endif

#ifdef PNG_sCAL_SUPPORTED
   /* Free any sCAL entry */
   if (((mask & PNG_FREE_SCAL) & info_ptr->free_me) != 0)
   {
      png_free(png_ptr, info_ptr->scal_s_width);
      png_free(png_ptr, info_ptr->scal_s_height);
      info_ptr->scal_s_width = NULL;
      info_ptr->scal_s_height = NULL;
      info_ptr->valid &= ~PNG_INFO_sCAL;
   }
#endif

#ifdef PNG_pCAL_SUPPORTED
   /* Free any pCAL entry */
   if (((mask & PNG_FREE_PCAL) & info_ptr->free_me) != 0)
   {
      png_free(png_ptr, info_ptr->pcal_purpose);
      png_free(png_ptr, info_ptr->pcal_units);
      info_ptr->pcal_purpose = NULL;
      info_ptr->pcal_units = NULL;

      if (info_ptr->pcal_params != NULL)
         {
            int i;

            for (i = 0; i < info_ptr->pcal_nparams; i++)
               png_free(png_ptr, info_ptr->pcal_params[i]);

            png_free(png_ptr, info_ptr->pcal_params);
            info_ptr->pcal_params = NULL;
         }
      info_ptr->valid &= ~PNG_INFO_pCAL;
   }
#endif

#ifdef PNG_iCCP_SUPPORTED
   /* Free any profile entry */
   if (((mask & PNG_FREE_ICCP) & info_ptr->free_me) != 0)
   {
      png_free(png_ptr, info_ptr->iccp_name);
      png_free(png_ptr, info_ptr->iccp_profile);
      info_ptr->iccp_name = NULL;
      info_ptr->iccp_profile = NULL;
      info_ptr->valid &= ~PNG_INFO_iCCP;
   }
#endif

#ifdef PNG_sPLT_SUPPORTED
   /* Free a given sPLT entry, or (if num == -1) all sPLT entries */
   if (info_ptr->splt_palettes != NULL &&
       ((mask & PNG_FREE_SPLT) & info_ptr->free_me) != 0)
   {
      if (num != -1)
      {
         png_free(png_ptr, info_ptr->splt_palettes[num].name);
         png_free(png_ptr, info_ptr->splt_palettes[num].entries);
         info_ptr->splt_palettes[num].name = NULL;
         info_ptr->splt_palettes[num].entries = NULL;
      }

      else
      {
         int i;

         for (i = 0; i < info_ptr->splt_palettes_num; i++)
         {
            png_free(png_ptr, info_ptr->splt_palettes[i].name);
            png_free(png_ptr, info_ptr->splt_palettes[i].entries);
         }

         png_free(png_ptr, info_ptr->splt_palettes);
         info_ptr->splt_palettes = NULL;
         info_ptr->splt_palettes_num = 0;
         info_ptr->valid &= ~PNG_INFO_sPLT;
      }
   }
#endif

#ifdef PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
   if (info_ptr->unknown_chunks != NULL &&
       ((mask & PNG_FREE_UNKN) & info_ptr->free_me) != 0)
   {
      if (num != -1)
      {
          png_free(png_ptr, info_ptr->unknown_chunks[num].data);
          info_ptr->unknown_chunks[num].data = NULL;
      }

      else
      {
         int i;

         for (i = 0; i < info_ptr->unknown_chunks_num; i++)
            png_free(png_ptr, info_ptr->unknown_chunks[i].data);

         png_free(png_ptr, info_ptr->unknown_chunks);
         info_ptr->unknown_chunks = NULL;
         info_ptr->unknown_chunks_num = 0;
      }
   }
#endif

#ifdef PNG_eXIf_SUPPORTED
   /* Free any eXIf entry */
   if (((mask & PNG_FREE_EXIF) & info_ptr->free_me) != 0)
   {
# ifdef PNG_READ_eXIf_SUPPORTED
      if (info_ptr->eXIf_buf)
      {
         png_free(png_ptr, info_ptr->eXIf_buf);
         info_ptr->eXIf_buf = NULL;
      }
# endif
      if (info_ptr->exif)
      {
         png_free(png_ptr, info_ptr->exif);
         info_ptr->exif = NULL;
      }
      info_ptr->valid &= ~PNG_INFO_eXIf;
   }
#endif

#ifdef PNG_hIST_SUPPORTED
   /* Free any hIST entry */
   if (((mask & PNG_FREE_HIST) & info_ptr->free_me) != 0)
   {
      png_free(png_ptr, info_ptr->hist);
      info_ptr->hist = NULL;
      info_ptr->valid &= ~PNG_INFO_hIST;
   }
#endif

   /* Free any PLTE entry that was internally allocated */
   if (((mask & PNG_FREE_PLTE) & info_ptr->free_me) != 0)
   {
      png_free(png_ptr, info_ptr->palette);
      info_ptr->palette = NULL;
      info_ptr->valid &= ~PNG_INFO_PLTE;
      info_ptr->num_palette = 0;
   }

#ifdef PNG_INFO_IMAGE_SUPPORTED
   /* Free any image bits attached to the info structure */
   if (((mask & PNG_FREE_ROWS) & info_ptr->free_me) != 0)
   {
      if (info_ptr->row_pointers != NULL)
      {
         png_uint_32 row;
         for (row = 0; row < info_ptr->height; row++)
            png_free(png_ptr, info_ptr->row_pointers[row]);

         png_free(png_ptr, info_ptr->row_pointers);
         info_ptr->row_pointers = NULL;
      }
      info_ptr->valid &= ~PNG_INFO_IDAT;
   }
#endif

   if (num != -1)
      mask &= ~PNG_FREE_MUL;

   info_ptr->free_me &= ~mask;
}
#endif /* READ || WRITE */
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
#  ifdef PNG_STDIO_SUPPORTED
#  endif
#  ifdef PNG_SAVE_INT_32_SUPPORTED
#  endif
#  ifdef PNG_TIME_RFC1123_SUPPORTED
#     define APPEND_STRING(string) pos = png_safecat(out, 29, pos, (string))
#     define APPEND_NUMBER(format, value)\
#     define APPEND(ch) if (pos < 28) out[pos++] = (ch)
#     undef APPEND
#     undef APPEND_NUMBER
#     undef APPEND_STRING
#    if PNG_LIBPNG_VER < 10700
#    endif /* LIBPNG_VER < 10700 */
#  endif /* TIME_RFC1123 */
#endif /* READ || WRITE */
#ifdef PNG_STRING_COPYRIGHT
#else
#endif
 * png_get_header_ver().  Due to the version_nn_nn_nn typedef guard,
 * it is guaranteed that png.c uses the correct version of png.h.
 */
png_const_charp PNGAPI
png_get_libpng_ver(png_const_structrp png_ptr)
{
   /* Version of *.c files used when building libpng */
   return png_get_header_ver(png_ptr);
}
#ifdef __STDC__
#  ifndef PNG_READ_SUPPORTED
#  endif
#else
#endif
#ifdef PNG_BUILD_GRAYSCALE_PALETTE_SUPPORTED
#endif
#ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
#if defined(PNG_READ_UNKNOWN_CHUNKS_SUPPORTED) ||\
#endif /* READ_UNKNOWN_CHUNKS || HANDLE_AS_UNKNOWN */
#endif /* SET_UNKNOWN_CHUNKS */
#ifdef PNG_READ_SUPPORTED
#endif /* READ */
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
#ifdef PNG_GAMMA_SUPPORTED /* always set if COLORSPACE */
#  ifdef PNG_READ_gAMA_SUPPORTED
#  endif
#     ifdef PNG_COLORSPACE_SUPPORTED
#     else
#     endif
#     ifdef PNG_COLORSPACE_SUPPORTED
#     endif
#ifdef PNG_READ_SUPPORTED
#endif
#endif /* GAMMA */
#ifdef PNG_COLORSPACE_SUPPORTED
#if defined(PNG_sRGB_SUPPORTED) || defined(PNG_iCCP_SUPPORTED)
#  ifdef PNG_WARNINGS_SUPPORTED
#  endif
#endif /* sRGB || iCCP */
#ifdef PNG_sRGB_SUPPORTED
#endif /* sRGB */
#ifdef PNG_iCCP_SUPPORTED
#ifdef PNG_READ_iCCP_SUPPORTED
#  ifdef PNG_SET_USER_LIMITS_SUPPORTED
#  elif PNG_USER_CHUNK_MALLOC_MAX > 0
#  else /* !SET_USER_LIMITS */
#  endif /* !SET_USER_LIMITS */
#endif /* READ_iCCP */
#ifdef PNG_sRGB_SUPPORTED
#if PNG_sRGB_PROFILE_CHECKS >= 0
#  define PNG_MD5(a,b,c,d) { a, b, c, d }, (a!=0)||(b!=0)||(c!=0)||(d!=0)
#  define PNG_ICC_CHECKSUM(adler, crc, md5, intent, broke, date, length, fname)\
#if PNG_sRGB_PROFILE_CHECKS > 1
#endif
#ifdef PNG_SET_OPTION_SUPPORTED
#endif
#        if PNG_sRGB_PROFILE_CHECKS == 0
#        endif
#              if PNG_sRGB_PROFILE_CHECKS > 1
#              endif
# if PNG_sRGB_PROFILE_CHECKS > 0
# endif
#endif /* PNG_sRGB_PROFILE_CHECKS >= 0 */
#endif /* sRGB */
#     if defined(PNG_sRGB_SUPPORTED) && PNG_sRGB_PROFILE_CHECKS >= 0
#     endif
#endif /* iCCP */
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif /* READ_RGB_TO_GRAY */
#endif /* COLORSPACE */
#ifdef __GNUC__
#else
#   define png_gt(a,b) ((a) > (b))
#endif
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
#else
#endif
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
#else
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#else
#endif
#if defined(PNG_sCAL_SUPPORTED) || defined(PNG_pCAL_SUPPORTED)
#define png_fp_add(state, flags) ((state) |= (flags))
#define png_fp_set(state, value) ((state) = (value) | ((state) & PNG_FP_STICKY))
#endif /* pCAL || sCAL */
#ifdef PNG_sCAL_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#if GCC_STRICT_OVERFLOW
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wstrict-overflow=2"
#endif /* GCC_STRICT_OVERFLOW */
#if GCC_STRICT_OVERFLOW
#pragma GCC diagnostic pop
#endif /* GCC_STRICT_OVERFLOW */
#  endif /* FLOATING_POINT */
#  ifdef PNG_FIXED_POINT_SUPPORTED
#   endif /* FIXED_POINT */
#endif /* SCAL */
#if defined(PNG_FLOATING_POINT_SUPPORTED) && \
#  ifndef PNG_ERROR_TEXT_SUPPORTED
#  endif
#endif
#if defined(PNG_GAMMA_SUPPORTED) || defined(PNG_COLORSPACE_SUPPORTED) ||\
#if GCC_STRICT_OVERFLOW /* from above */
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wstrict-overflow=2"
#endif /* GCC_STRICT_OVERFLOW */
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#else
#endif
#if GCC_STRICT_OVERFLOW
#pragma GCC diagnostic pop
#endif /* GCC_STRICT_OVERFLOW */
#endif /* READ_GAMMA || INCH_CONVERSIONS */
#if defined(PNG_READ_GAMMA_SUPPORTED) || defined(PNG_INCH_CONVERSIONS_SUPPORTED)
#endif
#ifdef PNG_GAMMA_SUPPORTED /* more fixed point functions for gamma */
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#else
#endif
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#ifdef PNG_16BIT_SUPPORTED
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#else
#endif
#endif /* 16BIT */
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#else
#endif
#endif /* READ_GAMMA */
#ifdef PNG_READ_GAMMA_SUPPORTED /* gamma table code */
#ifndef PNG_FLOATING_ARITHMETIC_SUPPORTED
#if 0
#endif
#ifdef PNG_16BIT_SUPPORTED
#endif /* 16BIT */
#if 0
#endif
#ifdef PNG_16BIT_SUPPORTED
#endif /* 16BIT */
#endif /* FLOATING_ARITHMETIC */
#     ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#     else
#     endif
#ifdef PNG_16BIT_SUPPORTED
# ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
# else
# endif
#endif /* 16BIT */
#ifdef PNG_16BIT_SUPPORTED
#else
#endif /* 16BIT */
#ifdef PNG_16BIT_SUPPORTED
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#endif
#           ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#           else
#           endif
#endif /* 16BIT */
png_destroy_gamma_table(png_structrp png_ptr)
{
   png_free(png_ptr, png_ptr->gamma_table);
   png_ptr->gamma_table = NULL;

#ifdef PNG_16BIT_SUPPORTED
   if (png_ptr->gamma_16_table != NULL)
   {
      int i;
      int istop = (1 << (8 - png_ptr->gamma_shift));
      for (i = 0; i < istop; i++)
      {
         png_free(png_ptr, png_ptr->gamma_16_table[i]);
      }
   png_free(png_ptr, png_ptr->gamma_16_table);
   png_ptr->gamma_16_table = NULL;
   }
#endif /* 16BIT */

#if defined(PNG_READ_BACKGROUND_SUPPORTED) || \
   defined(PNG_READ_ALPHA_MODE_SUPPORTED) || \
   defined(PNG_READ_RGB_TO_GRAY_SUPPORTED)
   png_free(png_ptr, png_ptr->gamma_from_1);
   png_ptr->gamma_from_1 = NULL;
   png_free(png_ptr, png_ptr->gamma_to_1);
   png_ptr->gamma_to_1 = NULL;

#ifdef PNG_16BIT_SUPPORTED
   if (png_ptr->gamma_16_from_1 != NULL)
   {
      int i;
      int istop = (1 << (8 - png_ptr->gamma_shift));
      for (i = 0; i < istop; i++)
      {
         png_free(png_ptr, png_ptr->gamma_16_from_1[i]);
      }
   png_free(png_ptr, png_ptr->gamma_16_from_1);
   png_ptr->gamma_16_from_1 = NULL;
   }
   if (png_ptr->gamma_16_to_1 != NULL)
   {
      int i;
      int istop = (1 << (8 - png_ptr->gamma_shift));
      for (i = 0; i < istop; i++)
      {
         png_free(png_ptr, png_ptr->gamma_16_to_1[i]);
      }
   png_free(png_ptr, png_ptr->gamma_16_to_1);
   png_ptr->gamma_16_to_1 = NULL;
   }
#endif /* 16BIT */
#endif /* READ_BACKGROUND || READ_ALPHA_MODE || RGB_TO_GRAY */
}
#if defined(PNG_READ_BACKGROUND_SUPPORTED) || \
#endif /* READ_BACKGROUND || READ_ALPHA_MODE || RGB_TO_GRAY */
#ifdef PNG_16BIT_SUPPORTED
#if defined(PNG_READ_BACKGROUND_SUPPORTED) || \
#endif /* READ_BACKGROUND || READ_ALPHA_MODE || RGB_TO_GRAY */
#endif /* 16BIT */
#endif /* READ_GAMMA */
#ifdef PNG_SET_OPTION_SUPPORTED
#endif
#if defined(PNG_SIMPLIFIED_READ_SUPPORTED) ||\
#ifdef PNG_SIMPLIFIED_READ_SUPPORTED
#endif /* SIMPLIFIED_READ */
#endif /* SIMPLIFIED READ/WRITE sRGB support */
#if defined(PNG_SIMPLIFIED_READ_SUPPORTED) ||\
png_image_free_function(png_voidp argument)
{
   png_imagep image = png_voidcast(png_imagep, argument);
   png_controlp cp = image->opaque;
   png_control c;

   /* Double check that we have a png_ptr - it should be impossible to get here
    * without one.
    */
   if (cp->png_ptr == NULL)
      return 0;

   /* First free any data held in the control structure. */
#  ifdef PNG_STDIO_SUPPORTED
      if (cp->owned_file != 0)
      {
         FILE *fp = png_voidcast(FILE*, cp->png_ptr->io_ptr);
         cp->owned_file = 0;

         /* Ignore errors here. */
         if (fp != NULL)
         {
            cp->png_ptr->io_ptr = NULL;
            (void)fclose(fp);
         }
      }
#  endif

   /* Copy the control structure so that the original, allocated, version can be
    * safely freed.  Notice that a png_error here stops the remainder of the
    * cleanup, but this is probably fine because that would indicate bad memory
    * problems anyway.
    */
   c = *cp;
   image->opaque = &c;
   png_free(c.png_ptr, cp);

   /* Then the structures, calling the correct API. */
   if (c.for_write != 0)
   {
#     ifdef PNG_SIMPLIFIED_WRITE_SUPPORTED
         png_destroy_write_struct(&c.png_ptr, &c.info_ptr);
#     else
         png_error(c.png_ptr, "simplified write not supported");
#     endif
   }
   else
   {
#     ifdef PNG_SIMPLIFIED_READ_SUPPORTED
         png_destroy_read_struct(&c.png_ptr, &c.info_ptr, NULL);
#     else
         png_error(c.png_ptr, "simplified read not supported");
#     endif
   }

   /* Success. */
   return 1;
}
png_image_free(png_imagep image)
{
   /* Safely call the real function, but only if doing so is safe at this point
    * (if not inside an error handling context).  Otherwise assume
    * png_safe_execute will call this API after the return.
    */
   if (image != NULL && image->opaque != NULL &&
      image->opaque->error_buf == NULL)
   {
      png_image_free_function(image);
      image->opaque = NULL;
   }
}
#endif /* SIMPLIFIED READ/WRITE */
#endif /* READ || WRITE */
