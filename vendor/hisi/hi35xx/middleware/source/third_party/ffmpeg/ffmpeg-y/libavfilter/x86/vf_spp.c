#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/crc.h"
#include "libavutil/mem.h"
#include "libavutil/x86/asm.h"
#include "libavfilter/vf_spp.h"
#if HAVE_MMX_INLINE
#define REQUANT_CORE(dst0, dst1, dst2, dst3, src0, src1, src2, src3)    \
#undef REQUANT_CORE
#define REQUANT_CORE(dst0, dst1, dst2, dst3, src0, src1, src2, src3)    \
#endif /* HAVE_MMX_INLINE */
#if HAVE_MMX_INLINE
#endif
