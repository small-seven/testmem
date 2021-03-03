#undef FUNC
#undef PIXEL_SHIFT
#if SIMPLE
#   define FUNC(n) AV_JOIN(n ## _simple_, BITS)
#   define PIXEL_SHIFT (BITS >> 4)
#else
#   define FUNC(n) n ## _complex
#   define PIXEL_SHIFT h->pixel_shift
#endif
#undef  CHROMA_IDC
#define CHROMA_IDC 1
#include "h264_mc_template.c"
#undef  CHROMA_IDC
#define CHROMA_IDC 2
#include "h264_mc_template.c"
#if !SIMPLE || BITS == 8
#undef  CHROMA_IDC
#define CHROMA_IDC 3
#include "h264_mc_template.c"
#endif
