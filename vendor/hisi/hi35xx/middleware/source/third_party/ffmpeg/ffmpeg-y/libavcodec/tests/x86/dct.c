#include "config.h"
#include "libavcodec/x86/fdct.h"
#include "libavcodec/x86/xvididct.h"
#include "libavcodec/x86/simple_idct.h"
#if (CONFIG_PRORES_DECODER || CONFIG_PRORES_LGPL_DECODER) && ARCH_X86_64 && HAVE_X86ASM
#define PR_WRAP(INSN) \
# if HAVE_AVX_EXTERNAL
# endif
#endif
#if HAVE_MMX_INLINE
#endif
#if HAVE_MMXEXT_INLINE
#endif
#if HAVE_SSE2_INLINE
#endif
#if HAVE_MMX_EXTERNAL
#endif
#if CONFIG_MPEG4_DECODER && HAVE_X86ASM
#if ARCH_X86_32
#endif
#if HAVE_SSE2_EXTERNAL
#endif
#endif /* CONFIG_MPEG4_DECODER && HAVE_X86ASM */
#if (CONFIG_PRORES_DECODER || CONFIG_PRORES_LGPL_DECODER) && ARCH_X86_64 && HAVE_X86ASM
# if HAVE_AVX_EXTERNAL
# endif
#endif
#if HAVE_X86ASM
#if ARCH_X86_64
#if HAVE_SSE2_EXTERNAL
#endif
#if HAVE_AVX_EXTERNAL
#endif
#endif
#endif
