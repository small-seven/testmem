#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/internal.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/mpegaudiodsp.h"
#define DECL(CPU)\
#if HAVE_X86ASM
#if ARCH_X86_32
#endif
#endif /* HAVE_X86ASM */
#if HAVE_6REGS && HAVE_SSE_INLINE
#define MACS(rt, ra, rb) rt+=(ra)*(rb)
#define MLSS(rt, ra, rb) rt-=(ra)*(rb)
#define SUM8(op, sum, w, p)               \
#define MULT(a, b)                                 \
#undef MULT
#define SUMS(suma, sumb, sumc, sumd, out1, out2)               \
#endif /* HAVE_6REGS && HAVE_SSE_INLINE */
#if HAVE_X86ASM
#define DECL_IMDCT_BLOCKS(CPU1, CPU2)                                       \
#if HAVE_SSE
#if ARCH_X86_32
#endif
#endif
#if HAVE_AVX_EXTERNAL
#endif
#endif /* HAVE_X86ASM */
#if HAVE_6REGS && HAVE_SSE_INLINE
#endif /* HAVE_SSE_INLINE */
#if HAVE_X86ASM
#if HAVE_SSE
#if ARCH_X86_32
#endif
#endif
#if HAVE_AVX_EXTERNAL
#endif
#endif /* HAVE_X86ASM */
