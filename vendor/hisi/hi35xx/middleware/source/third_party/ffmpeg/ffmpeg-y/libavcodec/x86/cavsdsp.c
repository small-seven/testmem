#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/cavsdsp.h"
#include "libavcodec/idctdsp.h"
#include "constants.h"
#include "fpel.h"
#include "idctdsp.h"
#include "config.h"
#if HAVE_MMX_EXTERNAL
#endif /* HAVE_MMX_EXTERNAL */
#if (HAVE_MMXEXT_INLINE || HAVE_AMD3DNOW_INLINE)
#define QPEL_CAVSV1(A,B,C,D,E,F,OP,ADD, MUL1, MUL2) \
#define QPEL_CAVSV2(A,B,C,D,E,F,OP,ADD, MUL1, MUL2) \
#define QPEL_CAVSV3(A,B,C,D,E,F,OP,ADD, MUL1, MUL2) \
#define QPEL_CAVSVNUM(VOP,OP,ADD,MUL1,MUL2)\
#define QPEL_CAVS(OPNAME, OP, MMX)\
#define CAVS_MC(OPNAME, SIZE, MMX) \
#define PUT_OP(a,b,temp, size) "mov" #size " " #a ", " #b "    \n\t"
#define AVG_3DNOW_OP(a,b,temp, size) \
#define AVG_MMXEXT_OP(a, b, temp, size) \
#endif /* (HAVE_MMXEXT_INLINE || HAVE_AMD3DNOW_INLINE) */
#if HAVE_MMX_EXTERNAL
#endif
#if HAVE_MMX_EXTERNAL
#endif /* HAVE_MMX_EXTERNAL */
#define DSPFUNC(PFX, IDX, NUM, EXT)                                                       \
#if HAVE_MMXEXT_INLINE
#endif /* HAVE_MMXEXT_INLINE */
#if HAVE_AMD3DNOW_INLINE
#endif /* HAVE_AMD3DNOW_INLINE */
#if HAVE_AMD3DNOW_INLINE
#endif /* HAVE_AMD3DNOW_INLINE */
#if HAVE_MMXEXT_INLINE
#endif
#if HAVE_MMX_EXTERNAL
#endif
#if HAVE_SSE2_EXTERNAL
#endif
