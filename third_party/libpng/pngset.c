#include "pngpriv.h"
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
#ifdef PNG_bKGD_SUPPORTED
#endif
#ifdef PNG_cHRM_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif /* FLOATING_POINT */
#endif /* cHRM */
#ifdef PNG_eXIf_SUPPORTED
#endif /* eXIf */
#ifdef PNG_gAMA_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif
#endif
#ifdef PNG_hIST_SUPPORTED
#endif
#ifdef PNG_oFFs_SUPPORTED
#endif
#ifdef PNG_pCAL_SUPPORTED
#endif
#ifdef PNG_sCAL_SUPPORTED
#  ifdef PNG_FLOATING_POINT_SUPPORTED
#  endif
#  ifdef PNG_FIXED_POINT_SUPPORTED
#  endif
#endif
#ifdef PNG_pHYs_SUPPORTED
#endif
#        ifdef PNG_MNG_FEATURES_SUPPORTED
#        endif
#ifdef PNG_sBIT_SUPPORTED
#endif
#ifdef PNG_sRGB_SUPPORTED
#endif /* sRGB */
#ifdef PNG_iCCP_SUPPORTED
#endif
#ifdef PNG_TEXT_SUPPORTED
#  ifdef PNG_iTXt_SUPPORTED
#  else /* iTXt */
#  endif
#  ifdef PNG_iTXt_SUPPORTED
#  endif
#  ifdef PNG_iTXt_SUPPORTED
#  endif
#endif
#ifdef PNG_tIME_SUPPORTED
#endif
#ifdef PNG_tRNS_SUPPORTED
#ifdef PNG_WARNINGS_SUPPORTED
#endif
#endif
#ifdef PNG_sPLT_SUPPORTED
#endif /* sPLT */
#ifdef PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
#  if !defined(PNG_READ_UNKNOWN_CHUNKS_SUPPORTED) && \
#  endif
#  if !defined(PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED) && \
#  endif
#endif /* STORE_UNKNOWN_CHUNKS */
#ifdef PNG_MNG_FEATURES_SUPPORTED
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#endif
#ifdef PNG_READ_USER_CHUNKS_SUPPORTED
#endif
#ifdef PNG_INFO_IMAGE_SUPPORTED
#endif
#  ifdef PNG_SEQUENTIAL_READ_SUPPORTED
#  endif
#  ifdef PNG_WRITE_SUPPORTED
#ifndef __COVERITY__
#endif
#  endif
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
#endif /* ?SET_USER_LIMITS */
#ifdef PNG_BENIGN_ERRORS_SUPPORTED
#endif /* BENIGN_ERRORS */
#ifdef PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED
#endif
#if defined(PNG_TEXT_SUPPORTED) || defined(PNG_pCAL_SUPPORTED) || \
#ifdef PNG_WARNINGS_SUPPORTED
#endif
#ifdef PNG_WARNINGS_SUPPORTED
#else /* !WARNINGS */
#endif /* !WARNINGS */
#endif /* TEXT || pCAL || iCCP || sPLT */
#endif /* READ || WRITE */
