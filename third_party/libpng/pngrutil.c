#include "pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if defined(PNG_READ_gAMA_SUPPORTED) || defined(PNG_READ_cHRM_SUPPORTED)
#define PNG_FIXED_ERROR (-1)
#endif
#ifdef PNG_READ_INT_FUNCTIONS_SUPPORTED
#endif /* READ_INT_FUNCTIONS */
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#ifdef PNG_IO_STATE_SUPPORTED
#endif
#if defined(PNG_READ_iCCP_SUPPORTED) || defined(PNG_READ_iTXt_SUPPORTED) ||\
#endif /* READ_iCCP|iTXt|pCAL|sCAL|sPLT|tEXt|zTXt|SEQUENTIAL_READ */
#if PNG_RELEASE_BUILD
#else
#endif
#if ZLIB_VERNUM >= 0x1240
# if defined(PNG_SET_OPTION_SUPPORTED) && defined(PNG_MAXIMUM_INFLATE_WINDOW)
# endif
#endif /* ZLIB_VERNUM >= 0x1240 */
#if ZLIB_VERNUM >= 0x1240
#else
#endif
#if ZLIB_VERNUM >= 0x1240
#else
#endif
#if ZLIB_VERNUM >= 0x1290 && \
#endif
#ifdef window_bits
# undef window_bits
#endif
#if ZLIB_VERNUM >= 0x1240
#endif /* Zlib >= 1.2.4 */
#ifdef PNG_READ_COMPRESSED_TEXT_SUPPORTED
#if defined(PNG_READ_zTXt_SUPPORTED) || defined (PNG_READ_iTXt_SUPPORTED)
# ifdef PNG_SET_USER_LIMITS_SUPPORTED
# elif PNG_USER_CHUNK_MALLOC_MAX > 0
# endif
#endif /* READ_zTXt || READ_iTXt */
#endif /* READ_COMPRESSED_TEXT */
#ifdef PNG_READ_iCCP_SUPPORTED
#endif /* READ_iCCP */
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_POINTER_INDEXING_SUPPORTED
#endif
#ifndef PNG_READ_OPT_PLTE_SUPPORTED
#endif
#ifdef PNG_POINTER_INDEXING_SUPPORTED
#else
#endif
#ifndef PNG_READ_OPT_PLTE_SUPPORTED
#endif
#ifndef PNG_READ_OPT_PLTE_SUPPORTED
#endif
#ifdef PNG_READ_tRNS_SUPPORTED
#endif
#ifdef PNG_READ_hIST_SUPPORTED
#endif
#ifdef PNG_READ_bKGD_SUPPORTED
#endif
#ifdef PNG_READ_gAMA_SUPPORTED
#endif
#ifdef PNG_READ_sBIT_SUPPORTED
#endif
#ifdef PNG_READ_cHRM_SUPPORTED
#endif
#ifdef PNG_READ_sRGB_SUPPORTED
#endif /* READ_sRGB */
#ifdef PNG_READ_iCCP_SUPPORTED
# if defined(PNG_sRGB_SUPPORTED) && PNG_sRGB_PROFILE_CHECKS >= 0
# endif
#endif /* READ_iCCP */
#ifdef PNG_READ_sPLT_SUPPORTED
#ifdef PNG_USER_LIMITS_SUPPORTED
#endif
#ifdef PNG_MAX_MALLOC_64K
#endif
#ifdef PNG_POINTER_INDEXING_SUPPORTED
#else
#endif
#endif /* READ_sPLT */
#ifdef PNG_READ_tRNS_SUPPORTED
#endif
#ifdef PNG_READ_bKGD_SUPPORTED
#endif
#ifdef PNG_READ_eXIf_SUPPORTED
#endif
#ifdef PNG_READ_hIST_SUPPORTED
#endif
#ifdef PNG_READ_pHYs_SUPPORTED
#endif
#ifdef PNG_READ_oFFs_SUPPORTED
#endif
#ifdef PNG_READ_pCAL_SUPPORTED
#endif
#ifdef PNG_READ_sCAL_SUPPORTED
#endif
#ifdef PNG_READ_tIME_SUPPORTED
#endif
#ifdef PNG_READ_tEXt_SUPPORTED
#ifdef PNG_USER_LIMITS_SUPPORTED
#endif
#ifdef PNG_MAX_MALLOC_64K
#endif
#endif
#ifdef PNG_READ_zTXt_SUPPORTED
#ifdef PNG_USER_LIMITS_SUPPORTED
#endif
#endif
#ifdef PNG_READ_iTXt_SUPPORTED
#ifdef PNG_USER_LIMITS_SUPPORTED
#endif
#endif
#ifdef PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
#  ifdef PNG_SET_USER_LIMITS_SUPPORTED
#  elif PNG_USER_CHUNK_MALLOC_MAX > 0
#  endif
#endif /* READ_UNKNOWN_CHUNKS */
#ifdef PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
#  ifndef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#     ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
#     endif
#  endif
#  ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#              ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
#              endif
#  endif /* READ_USER_CHUNKS */
#  ifdef PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
#  else
#     ifndef PNG_READ_USER_CHUNKS_SUPPORTED
#        error no method to support READ_UNKNOWN_CHUNKS
#     endif
#  endif
#  ifdef PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
#     ifdef PNG_USER_LIMITS_SUPPORTED
#  endif /* USER_LIMITS */
#  ifdef PNG_USER_LIMITS_SUPPORTED
#  endif
#  else /* no store support: the chunk must be handled by the user callback */
#  endif
#else /* !PNG_READ_UNKNOWN_CHUNKS_SUPPORTED */
#endif /* !READ_UNKNOWN_CHUNKS */
# ifdef PNG_SET_USER_LIMITS_SUPPORTED
# elif PNG_USER_CHUNK_MALLOC_MAX > 0
# endif
#     ifdef PNG_READ_PACKSWAP_SUPPORTED
#     endif
#ifdef PNG_READ_INTERLACING_SUPPORTED
#        if PNG_USE_COMPILE_TIME_MASKS
#           define PNG_LSR(x,s) ((x)>>((s) & 0x1f))
#           define PNG_LSL(x,s) ((x)<<((s) & 0x1f))
#        else
#           define PNG_LSR(x,s) ((x)>>(s))
#           define PNG_LSL(x,s) ((x)<<(s))
#        endif
#        define S_COPY(p,x) (((p)<4 ? PNG_LSR(0x80088822,(3-(p))*8+(7-(x))) :\
#        define B_COPY(p,x) (((p)<4 ? PNG_LSR(0xff0fff33,(3-(p))*8+(7-(x))) :\
#        define PIXEL_MASK(p,x,d,s) \
#        define S_MASKx(p,x,d,s) (S_COPY(p,x)?PIXEL_MASK(p,x,d,s):0)
#        define B_MASKx(p,x,d,s) (B_COPY(p,x)?PIXEL_MASK(p,x,d,s):0)
#        define MASK_EXPAND(m,d) ((m)*((d)==1?0x01010101:((d)==2?0x00010001:1)))
#        define S_MASK(p,d,s) MASK_EXPAND(S_MASKx(p,0,d,s) + S_MASKx(p,1,d,s) +\
#        define B_MASK(p,d,s) MASK_EXPAND(B_MASKx(p,0,d,s) + B_MASKx(p,1,d,s) +\
#if PNG_USE_COMPILE_TIME_MASKS
#        define S_MASKS(d,s) { S_MASK(0,d,s), S_MASK(1,d,s), S_MASK(2,d,s),\
#        define B_MASKS(d,s) { B_MASK(1,d,s), B_MASK(3,d,s), B_MASK(5,d,s) }
#        define DEPTH_INDEX(d) ((d)==1?0:((d)==2?1:2))
#        define MASK(pass,depth,display,png)\
#else /* !PNG_USE_COMPILE_TIME_MASKS */
#        define MASK(pass,depth,display,png)\
#endif /* !USE_COMPILE_TIME_MASKS */
#        ifdef PNG_READ_PACKSWAP_SUPPORTED
#        endif
#if PNG_ALIGN_TYPE != PNG_ALIGN_NONE
#endif /* ALIGN_TYPE code */
#endif /* READ_INTERLACING */
#ifdef PNG_READ_INTERLACING_SUPPORTED
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#endif
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#endif
#ifdef PNG_READ_PACKSWAP_SUPPORTED
#endif
#ifndef PNG_READ_PACKSWAP_SUPPORTED
#endif
#endif /* READ_INTERLACING */
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_USE_ABS
#else
#endif
#ifdef PNG_FILTER_OPTIMIZATIONS
#endif
#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#endif /* SEQUENTIAL_READ */
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_READ_PACK_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_SUPPORTED
#endif
#ifdef PNG_READ_EXPAND_16_SUPPORTED
#  ifdef PNG_READ_EXPAND_SUPPORTED
#  endif
#endif
#ifdef PNG_READ_FILLER_SUPPORTED
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
#ifdef PNG_READ_EXPAND_SUPPORTED
#endif
#ifdef PNG_READ_FILLER_SUPPORTED
#endif
#endif
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) && \
#endif
#ifdef PNG_MAX_MALLOC_64K
#endif
#ifdef PNG_ALIGNED_MEMORY_SUPPORTED
#else
#endif
#ifdef PNG_MAX_MALLOC_64K
#endif
#endif /* READ */
