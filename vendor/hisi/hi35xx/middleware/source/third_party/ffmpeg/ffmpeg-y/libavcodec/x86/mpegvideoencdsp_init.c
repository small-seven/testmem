#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/mpegvideoencdsp.h"
#if HAVE_INLINE_ASM
#define PHADDD(a, t)                            \
#define PMULHRW(x, y, s, o)                     \
#define DEF(x) x ## _mmx
#define SET_RND MOVQ_WONE
#define SCALE_OFFSET 1
#include "mpegvideoenc_qns_template.c"
#undef DEF
#undef SET_RND
#undef SCALE_OFFSET
#undef PMULHRW
#define DEF(x) x ## _3dnow
#define SET_RND(x)
#define SCALE_OFFSET 0
#define PMULHRW(x, y, s, o)                     \
#include "mpegvideoenc_qns_template.c"
#undef DEF
#undef SET_RND
#undef SCALE_OFFSET
#undef PMULHRW
#if HAVE_SSSE3_INLINE
#undef PHADDD
#define DEF(x) x ## _ssse3
#define SET_RND(x)
#define SCALE_OFFSET -1
#define PHADDD(a, t)                            \
#define PMULHRW(x, y, s, o)                     \
#include "mpegvideoenc_qns_template.c"
#undef DEF
#undef SET_RND
#undef SCALE_OFFSET
#undef PMULHRW
#undef PHADDD
#endif /* HAVE_SSSE3_INLINE */
#endif /* HAVE_INLINE_ASM */
#if ARCH_X86_32
#endif
#if HAVE_INLINE_ASM
#if HAVE_SSSE3_INLINE
#endif /* HAVE_SSSE3_INLINE */
#endif /* HAVE_INLINE_ASM */
