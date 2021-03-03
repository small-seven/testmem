#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/dct.h"
#include "libavcodec/mpegvideo.h"
#if HAVE_6REGS
#if HAVE_MMX_INLINE
#define COMPILE_TEMPLATE_MMXEXT 0
#define COMPILE_TEMPLATE_SSE2   0
#define COMPILE_TEMPLATE_SSSE3  0
#define RENAME(a)      a ## _mmx
#define RENAME_FDCT(a) a ## _mmx
#include "mpegvideoenc_template.c"
#endif /* HAVE_MMX_INLINE */
#if HAVE_MMXEXT_INLINE
#undef COMPILE_TEMPLATE_SSSE3
#undef COMPILE_TEMPLATE_SSE2
#undef COMPILE_TEMPLATE_MMXEXT
#define COMPILE_TEMPLATE_MMXEXT 1
#define COMPILE_TEMPLATE_SSE2   0
#define COMPILE_TEMPLATE_SSSE3  0
#undef RENAME
#undef RENAME_FDCT
#define RENAME(a)      a ## _mmxext
#define RENAME_FDCT(a) a ## _mmxext
#include "mpegvideoenc_template.c"
#endif /* HAVE_MMXEXT_INLINE */
#if HAVE_SSE2_INLINE
#undef COMPILE_TEMPLATE_MMXEXT
#undef COMPILE_TEMPLATE_SSE2
#undef COMPILE_TEMPLATE_SSSE3
#define COMPILE_TEMPLATE_MMXEXT 0
#define COMPILE_TEMPLATE_SSE2   1
#define COMPILE_TEMPLATE_SSSE3  0
#undef RENAME
#undef RENAME_FDCT
#define RENAME(a)      a ## _sse2
#define RENAME_FDCT(a) a ## _sse2
#include "mpegvideoenc_template.c"
#endif /* HAVE_SSE2_INLINE */
#if HAVE_SSSE3_INLINE
#undef COMPILE_TEMPLATE_MMXEXT
#undef COMPILE_TEMPLATE_SSE2
#undef COMPILE_TEMPLATE_SSSE3
#define COMPILE_TEMPLATE_MMXEXT 0
#define COMPILE_TEMPLATE_SSE2   1
#define COMPILE_TEMPLATE_SSSE3  1
#undef RENAME
#undef RENAME_FDCT
#define RENAME(a)      a ## _ssse3
#define RENAME_FDCT(a) a ## _sse2
#include "mpegvideoenc_template.c"
#endif /* HAVE_SSSE3_INLINE */
#endif /* HAVE_6REGS */
#if HAVE_INLINE_ASM
#if HAVE_MMX_INLINE
#endif /* HAVE_MMX_INLINE */
#if HAVE_SSE2_INLINE
#endif /* HAVE_SSE2_INLINE */
#endif /* HAVE_INLINE_ASM */
#if HAVE_MMX_INLINE
#if HAVE_6REGS
#endif
#endif
#if HAVE_6REGS && HAVE_MMXEXT_INLINE
#endif
#if HAVE_SSE2_INLINE
#if HAVE_6REGS
#endif
#endif
#if HAVE_6REGS && HAVE_SSSE3_INLINE
#endif
