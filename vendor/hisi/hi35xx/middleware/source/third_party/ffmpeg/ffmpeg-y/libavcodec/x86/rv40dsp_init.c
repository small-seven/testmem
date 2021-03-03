#include "libavcodec/rv34dsp.h"
#include "libavutil/attributes.h"
#include "libavutil/mem.h"
#include "libavutil/x86/cpu.h"
#include "hpeldsp.h"
#define DEFINE_FN(op, size, insn) \
#if HAVE_X86ASM
#define DECLARE_WEIGHT(opt) \
#define QPEL_FUNC_DECL(OP, SIZE, PH, PV, OPT)                           \
#define QPEL_FUNCS_DECL(OP, PH, PV, OPT) \
#define QPEL_MC_DECL(OP, OPT)                                           \
#define LOOPSIZE  8
#define HCOFF(x)  (32 * ((x) - 1))
#define VCOFF(x)  (32 * ((x) - 1))
#undef LOOPSIZE
#undef HCOFF
#undef VCOFF
#define LOOPSIZE  8
#define HCOFF(x)  (64 * ((x) - 1))
#define VCOFF(x)  (64 * ((x) - 1))
#if ARCH_X86_32
#undef LOOPSIZE
#undef HCOFF
#undef VCOFF
#define LOOPSIZE  4
#define HCOFF(x)  (64 * ((x) - 1))
#define VCOFF(x)  (64 * ((x) - 1))
#define ff_put_rv40_qpel_h_mmxext  ff_put_rv40_qpel_h_mmx
#define ff_put_rv40_qpel_v_mmxext  ff_put_rv40_qpel_v_mmx
#define ff_put_rv40_qpel_h_3dnow  ff_put_rv40_qpel_h_mmx
#define ff_put_rv40_qpel_v_3dnow  ff_put_rv40_qpel_v_mmx
#endif
#define QPEL_FUNC_SET(OP, SIZE, PH, PV, OPT)                            \
#define QPEL_FUNCS_SET(OP, PH, PV, OPT)         \
#define QPEL_MC_SET(OP, OPT)   \
#endif /* HAVE_X86ASM */
#if HAVE_MMX_INLINE
#endif
#if HAVE_MMX_INLINE
#endif /* HAVE_MMX_INLINE */
#if HAVE_X86ASM
#if ARCH_X86_32
#endif
#if ARCH_X86_32
#endif
#if ARCH_X86_32
#endif
#endif /* HAVE_X86ASM */
