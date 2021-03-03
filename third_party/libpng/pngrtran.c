#include "pngpriv.h"
#ifdef PNG_ARM_NEON_IMPLEMENTATION
#  if PNG_ARM_NEON_IMPLEMENTATION == 1
#    define PNG_ARM_NEON_INTRINSICS_AVAILABLE
#    if defined(_MSC_VER) && defined(_M_ARM64)
#      include <arm64_neon.h>
#    else
#      include <arm_neon.h>
#    endif
#  endif
#endif
#ifdef PNG_READ_SUPPORTED
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif /* FLOATING_POINT */
#endif /* READ_BACKGROUND */
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#endif
#if defined(PNG_READ_ALPHA_MODE_SUPPORTED) || defined(PNG_READ_GAMMA_SUPPORTED)
#     ifdef PNG_READ_sRGB_SUPPORTED
#     else
#     endif
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif
#endif /* READ_ALPHA_MODE || READ_GAMMA */
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif
#endif
#ifdef PNG_READ_QUANTIZE_SUPPORTED
typedef struct png_dsort_struct
{
   struct png_dsort_struct * next;
   png_byte left;
   png_byte right;
} png_dsort;
typedef png_dsort *   png_dsortp;
typedef png_dsort * * png_dsortpp;

void PNGAPI
png_set_quantize(png_structrp png_ptr, png_colorp palette,
    int num_palette, int maximum_colors, png_const_uint_16p histogram,
    int full_quantize)
{
   png_debug(1, "in png_set_quantize");

   if (png_rtran_ok(png_ptr, 0) == 0)
      return;

   png_ptr->transformations |= PNG_QUANTIZE;

   if (full_quantize == 0)
   {
      int i;

      png_ptr->quantize_index = (png_bytep)png_malloc(png_ptr,
          (png_alloc_size_t)((png_uint_32)num_palette * (sizeof (png_byte))));
      for (i = 0; i < num_palette; i++)
         png_ptr->quantize_index[i] = (png_byte)i;
   }
#endif /* READ_QUANTIZE */
#ifdef PNG_READ_GAMMA_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif /* FLOATING_POINT */
#endif /* READ_GAMMA */
#ifdef PNG_READ_EXPAND_SUPPORTED
#endif /* READ_EXPAND */
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#endif
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#ifdef PNG_READ_EXPAND_SUPPORTED
#else
#endif
#ifdef PNG_FLOATING_POINT_SUPPORTED
#endif /* FLOATING POINT */
#endif /* RGB_TO_GRAY */
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
#ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
#endif
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#if defined(PNG_READ_EXPAND_SUPPORTED) && defined(PNG_READ_BACKGROUND_SUPPORTED)
#ifdef PNG_READ_INVERT_ALPHA_SUPPORTED
#endif /* READ_INVERT_ALPHA */
#endif /* READ_EXPAND && READ_BACKGROUND */
#     ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#     endif
#if defined(PNG_READ_EXPAND_SUPPORTED) && defined(PNG_READ_BACKGROUND_SUPPORTED)
#endif /* READ_EXPAND && READ_BACKGROUND */
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#endif /* STRIP_ALPHA supported, no COMPOSE */
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#if defined(PNG_READ_EXPAND_SUPPORTED) && defined(PNG_READ_BACKGROUND_SUPPORTED)
#endif /* READ_EXPAND && READ_BACKGROUND */
#endif /* READ_GRAY_TO_RGB */
#if defined(PNG_READ_BACKGROUND_SUPPORTED) && \
#     define CHOP(x) (x)=((png_uint_16)PNG_DIV257(x))
#     undef CHOP
#endif /* READ_BACKGROUND && READ_EXPAND_16 */
#if defined(PNG_READ_BACKGROUND_SUPPORTED) && \
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#  ifdef PNG_READ_BACKGROUND_SUPPORTED
#  endif
#  ifdef PNG_READ_BACKGROUND_SUPPORTED
#  endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#endif /* READ_BACKGROUND */
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#endif
#endif /* READ_GAMMA */
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#endif /* READ_BACKGROUND */
#ifdef PNG_READ_SHIFT_SUPPORTED
#endif /* READ_SHIFT */
#ifdef PNG_READ_EXPAND_SUPPORTED
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED) ||\
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#  ifdef PNG_READ_16BIT_SUPPORTED
#     ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#     endif
#     ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#     endif
#  else
#     ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#     else
#        ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#        else
#        endif
#    endif
#endif /* !READ_16BIT */
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#endif
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#ifdef PNG_READ_QUANTIZE_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#endif
#ifdef PNG_READ_PACK_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#endif
#ifdef PNG_READ_FILLER_SUPPORTED
#endif
#if defined(PNG_USER_TRANSFORM_PTR_SUPPORTED) && \
#endif
#ifndef PNG_READ_EXPAND_SUPPORTED
#endif
#ifdef PNG_READ_PACK_SUPPORTED
#endif
#ifdef PNG_READ_SHIFT_SUPPORTED
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#endif
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_SWAP_ALPHA_SUPPORTED
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#endif
#ifdef PNG_READ_INVERT_ALPHA_SUPPORTED
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#endif
#ifdef PNG_READ_FILLER_SUPPORTED
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#ifdef PNG_READ_16BIT_SUPPORTED
#endif
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#endif
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED) ||\
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#endif /* READ_BACKGROUND || READ_ALPHA_MODE */
#ifdef PNG_READ_GAMMA_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_SUPPORTED
#ifdef PNG_ARM_NEON_INTRINSICS_AVAILABLE
#else
#endif
#ifdef PNG_ARM_NEON_INTRINSICS_AVAILABLE
#else
#endif
#endif
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#endif
#ifdef PNG_READ_QUANTIZE_SUPPORTED
#endif /* READ_QUANTIZE */
#ifdef PNG_READ_EXPAND_SUPPORTED
#ifdef PNG_ARM_NEON_INTRINSICS_AVAILABLE
#endif
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#endif
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED) ||\
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED) ||\
#endif
#endif
#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#endif
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#endif
#ifdef PNG_READ_QUANTIZE_SUPPORTED
#endif /* READ_QUANTIZE */
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#endif
#ifdef PNG_READ_INVERT_SUPPORTED
#endif
#ifdef PNG_READ_INVERT_ALPHA_SUPPORTED
#endif
#ifdef PNG_READ_SHIFT_SUPPORTED
#endif
#ifdef PNG_READ_PACK_SUPPORTED
#endif
#ifdef PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED
#endif
#ifdef PNG_READ_BGR_SUPPORTED
#endif
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#endif
#ifdef PNG_READ_FILLER_SUPPORTED
#endif
#ifdef PNG_READ_SWAP_ALPHA_SUPPORTED
#endif
#ifdef PNG_READ_16BIT_SUPPORTED
#ifdef PNG_READ_SWAP_SUPPORTED
#endif
#endif
#ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
#ifdef PNG_USER_TRANSFORM_PTR_SUPPORTED
#endif
#endif
#endif /* READ_TRANSFORMS */
#endif /* READ */
