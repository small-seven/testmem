#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/mlpdsp.h"
#include "libavcodec/mlp.h"
#define REMATRIX_CHANNEL_FUNC(opt) \
#if HAVE_7REGS && HAVE_INLINE_ASM && HAVE_INLINE_ASM_NONLOCAL_LABELS
#if ARCH_X86_64
#define MLPMUL(label, offset, offs, offc)   \
#define FIRMULREG(label, offset, firc)\
#define CLEAR_ACCUM                   \
#define SHIFT_ACCUM                   \
#define ACCUM    "%%rdx"
#define RESULT   "%%rsi"
#define RESULT32 "%%esi"
#else /* if ARCH_X86_32 */
#define MLPMUL(label, offset, offs, offc)  \
#define FIRMULREG(label, offset, firc)  \
#define CLEAR_ACCUM                  \
#define SHIFT_ACCUM                  \
#define ACCUM    "%%edx"
#define RESULT   "%%eax"
#define RESULT32 "%%eax"
#endif /* !ARCH_X86_64 */
#define BINC  AV_STRINGIFY(4* MAX_CHANNELS)
#define IOFFS AV_STRINGIFY(4*(MAX_FIR_ORDER + MAX_BLOCKSIZE))
#define IOFFC AV_STRINGIFY(4* MAX_FIR_ORDER)
#define FIRMUL(label, offset) MLPMUL(label, #offset,   "0",   "0")
#define IIRMUL(label, offset) MLPMUL(label, #offset, IOFFS, IOFFC)
#if ARCH_X86_64
#else /* ARCH_X86_32 */
#endif /* !ARCH_X86_64 */
#endif /* HAVE_7REGS && HAVE_INLINE_ASM */
#if HAVE_7REGS && HAVE_INLINE_ASM && HAVE_INLINE_ASM_NONLOCAL_LABELS
#endif
