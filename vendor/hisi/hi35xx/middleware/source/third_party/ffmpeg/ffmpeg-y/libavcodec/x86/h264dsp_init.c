#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/h264dsp.h"
#define IDCT_ADD_FUNC(NUM, DEPTH, OPT)                                  \
#define IDCT_ADD_REP_FUNC(NUM, REP, DEPTH, OPT)                         \
#define IDCT_ADD_REP_FUNC2(NUM, REP, DEPTH, OPT)                      \
#define LF_FUNC(DIR, TYPE, DEPTH, OPT)                                        \
#define LF_IFUNC(DIR, TYPE, DEPTH, OPT) \
#define LF_FUNCS(type, depth)                   \
#if ARCH_X86_32 && HAVE_MMXEXT_EXTERNAL
#endif /* ARCH_X86_32 && HAVE_MMXEXT_EXTERNAL */
#define H264_WEIGHT(W, OPT)                                             \
#define H264_BIWEIGHT(W, OPT)                                           \
#define H264_BIWEIGHT_MMX(W)                    \
#define H264_BIWEIGHT_MMX_SSE(W)                \
#define H264_WEIGHT_10(W, DEPTH, OPT)                                   \
#define H264_BIWEIGHT_10(W, DEPTH, OPT)                                 \
#define H264_BIWEIGHT_10_SSE(W, DEPTH)          \
#if HAVE_X86ASM
#if ARCH_X86_32 && HAVE_MMXEXT_EXTERNAL
#endif /* ARCH_X86_32 && HAVE_MMXEXT_EXTERNAL */
#if ARCH_X86_64
#endif
#if ARCH_X86_64
#endif
#if ARCH_X86_32
#endif /* ARCH_X86_32 */
#if HAVE_ALIGNED_STACK
#endif /* HAVE_ALIGNED_STACK */
#if HAVE_ALIGNED_STACK
#endif /* HAVE_ALIGNED_STACK */
#if HAVE_ALIGNED_STACK
#endif /* HAVE_ALIGNED_STACK */
#if HAVE_ALIGNED_STACK
#endif /* HAVE_ALIGNED_STACK */
#endif
