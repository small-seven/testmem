#include "pngpriv.h"
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNG_WRITE_INT_FUNCTIONS_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#if defined(PNG_DEBUG) && (PNG_DEBUG > 0)
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_WRITE_OPTIMIZE_CMF_SUPPORTED
#endif /* WRITE_OPTIMIZE_CMF */
#if defined(PNG_WARNINGS_SUPPORTED) || defined(PNG_ERROR_TEXT_SUPPORTED)
#endif
#if PNG_RELEASE_BUILD
#else
#endif
#ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
#else
#endif
png_free_buffer_list(png_structrp png_ptr, png_compression_bufferp *listp)
{
   png_compression_bufferp list = *listp;

   if (list != NULL)
   {
      *listp = NULL;

      do
      {
         png_compression_bufferp next = list->next;

         png_free(png_ptr, list);
         list = next;
      }
      while (list != NULL);
   }
}
#ifdef PNG_WRITE_COMPRESSED_TEXT_SUPPORTED
typedef struct
{
   png_const_bytep      input;        /* The uncompressed input data */
   png_alloc_size_t     input_len;    /* Its length */
   png_uint_32          output_len;   /* Final compressed length */
   png_byte             output[1024]; /* First block of output */
} compression_state;
#ifdef PNG_WRITE_OPTIMIZE_CMF_SUPPORTED
#endif
#endif /* WRITE_COMPRESSED_TEXT */
#ifdef PNG_WRITE_16BIT_SUPPORTED
#endif
#ifdef PNG_WRITE_16BIT_SUPPORTED
#endif
#ifdef PNG_WRITE_16BIT_SUPPORTED
#endif
#ifdef PNG_WRITE_16BIT_SUPPORTED
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#else
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_POINTER_INDEXING_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_OPTIMIZE_CMF_SUPPORTED
#endif
#ifdef PNG_WRITE_OPTIMIZE_CMF_SUPPORTED
#endif
#ifdef PNG_WRITE_gAMA_SUPPORTED
#endif
#ifdef PNG_WRITE_sRGB_SUPPORTED
#endif
#ifdef PNG_WRITE_iCCP_SUPPORTED
#endif
#ifdef PNG_WRITE_sPLT_SUPPORTED
#ifndef PNG_POINTER_INDEXING_SUPPORTED
#endif
#ifdef PNG_POINTER_INDEXING_SUPPORTED
#else
#endif
#endif
#ifdef PNG_WRITE_sBIT_SUPPORTED
#endif
#ifdef PNG_WRITE_cHRM_SUPPORTED
#endif
#ifdef PNG_WRITE_tRNS_SUPPORTED
#ifdef PNG_WRITE_16BIT_SUPPORTED
#else
#endif
#endif
#ifdef PNG_WRITE_bKGD_SUPPORTED
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_WRITE_16BIT_SUPPORTED
#else
#endif
#endif
#ifdef PNG_WRITE_eXIf_SUPPORTED
#endif
#ifdef PNG_WRITE_hIST_SUPPORTED
#endif
#ifdef PNG_WRITE_tEXt_SUPPORTED
#endif
#ifdef PNG_WRITE_zTXt_SUPPORTED
#endif
#ifdef PNG_WRITE_iTXt_SUPPORTED
#endif
#ifdef PNG_WRITE_oFFs_SUPPORTED
#endif
#ifdef PNG_WRITE_pCAL_SUPPORTED
#endif
#ifdef PNG_WRITE_sCAL_SUPPORTED
#endif
#ifdef PNG_WRITE_pHYs_SUPPORTED
#endif
#ifdef PNG_WRITE_tIME_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif /* WRITE_FILTER */
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_INTERLACING_SUPPORTED
#endif
#ifdef PNG_WRITE_FILTER_SUPPORTED
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#endif /* WRITE_FILTER */
#ifndef PNG_WRITE_FILTER_SUPPORTED
#else
#ifdef PNG_USE_ABS
#else
#endif
#endif /* WRITE_FILTER */
#ifdef PNG_WRITE_FILTER_SUPPORTED
#endif /* WRITE_FILTER */
#ifdef PNG_WRITE_FLUSH_SUPPORTED
#endif /* WRITE_FLUSH */
#endif /* WRITE */
