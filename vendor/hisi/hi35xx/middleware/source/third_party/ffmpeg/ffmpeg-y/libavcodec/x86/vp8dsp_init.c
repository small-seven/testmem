#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/vp8dsp.h"
#if HAVE_X86ASM
#define TAP_W16(OPT, FILTERTYPE, TAPTYPE) \
#define TAP_W8(OPT, FILTERTYPE, TAPTYPE) \
#if ARCH_X86_32
#endif
#define HVTAP(OPT, ALIGN, TAPNUMX, TAPNUMY, SIZE, MAXHEIGHT) \
#if ARCH_X86_32
#define HVTAPMMX(x, y) \
#else
#define HVTAPMMX(x, y) \
#endif
#define HVTAPSSE2(x, y, w) \
#define HVBILIN(OPT, ALIGN, SIZE, MAXHEIGHT) \
#if ARCH_X86_32
#endif
#define DECLARE_LOOP_FILTER(NAME)                                       \
#endif /* HAVE_X86ASM */
#define VP8_LUMA_MC_FUNC(IDX, SIZE, OPT) \
#define VP8_MC_FUNC(IDX, SIZE, OPT) \
#define VP8_BILINEAR_MC_FUNC(IDX, SIZE, OPT) \
#if HAVE_X86ASM
#if ARCH_X86_32
#endif
#if ARCH_X86_32
#endif
#endif /* HAVE_X86ASM */
#if HAVE_X86ASM
#if ARCH_X86_32
#endif
#if ARCH_X86_32
#endif
#endif /* HAVE_X86ASM */
