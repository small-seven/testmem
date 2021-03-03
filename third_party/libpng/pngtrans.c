#include "pngpriv.h"
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
#endif
#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
#endif
#if defined(PNG_READ_PACK_SUPPORTED) || defined(PNG_WRITE_PACK_SUPPORTED)
#     ifdef PNG_WRITE_SUPPORTED
#     endif
#endif
#if defined(PNG_READ_PACKSWAP_SUPPORTED)||defined(PNG_WRITE_PACKSWAP_SUPPORTED)
#endif
#if defined(PNG_READ_SHIFT_SUPPORTED) || defined(PNG_WRITE_SHIFT_SUPPORTED)
#endif
#if defined(PNG_READ_INTERLACING_SUPPORTED) || \
#endif
#if defined(PNG_READ_FILLER_SUPPORTED) || defined(PNG_WRITE_FILLER_SUPPORTED)
#     ifdef PNG_READ_FILLER_SUPPORTED
#     else
#     endif
#     ifdef PNG_WRITE_FILLER_SUPPORTED
#     else
#     endif
#endif
#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED) || \
#endif
#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED) || \
#endif
#if defined(PNG_READ_INVERT_SUPPORTED) || defined(PNG_WRITE_INVERT_SUPPORTED)
#ifdef PNG_16BIT_SUPPORTED
#endif
#endif
#ifdef PNG_16BIT_SUPPORTED
#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
#ifdef PNG_BUILTIN_BSWAP16_SUPPORTED
#else
#endif
#endif
#endif
#if defined(PNG_READ_PACKSWAP_SUPPORTED)||defined(PNG_WRITE_PACKSWAP_SUPPORTED)
#endif /* PACKSWAP || WRITE_PACKSWAP */
#if defined(PNG_WRITE_FILLER_SUPPORTED) || \
#endif
#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
#ifdef PNG_16BIT_SUPPORTED
#endif
#endif /* READ_BGR || WRITE_BGR */
#if defined(PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED) || \
#endif /* CHECK_FOR_INVALID_INDEX */
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
#ifdef PNG_USER_TRANSFORM_PTR_SUPPORTED
#ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
#endif
#endif
#ifdef PNG_USER_TRANSFORM_PTR_SUPPORTED
#endif
#ifdef PNG_USER_TRANSFORM_INFO_SUPPORTED
#endif /* USER_TRANSFORM_INFO */
#endif /* READ_USER_TRANSFORM || WRITE_USER_TRANSFORM */
#endif /* READ || WRITE */
