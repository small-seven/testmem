#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/hpeldsp.h"
#include "libavcodec/pixels.h"
#include "fpel.h"
#include "hpeldsp.h"
#define avg_pixels8_mmx         ff_avg_pixels8_mmx
#define avg_pixels8_x2_mmx      ff_avg_pixels8_x2_mmx
#define avg_pixels16_mmx        ff_avg_pixels16_mmx
#define avg_pixels8_xy2_mmx     ff_avg_pixels8_xy2_mmx
#define avg_pixels16_xy2_mmx    ff_avg_pixels16_xy2_mmx
#define put_pixels8_mmx         ff_put_pixels8_mmx
#define put_pixels16_mmx        ff_put_pixels16_mmx
#define put_pixels8_xy2_mmx     ff_put_pixels8_xy2_mmx
#define put_pixels16_xy2_mmx    ff_put_pixels16_xy2_mmx
#define avg_no_rnd_pixels16_mmx ff_avg_pixels16_mmx
#define put_no_rnd_pixels8_mmx  ff_put_pixels8_mmx
#define put_no_rnd_pixels16_mmx ff_put_pixels16_mmx
#if HAVE_INLINE_ASM
#define DEF(x, y) x ## _no_rnd_ ## y ## _mmx
#define SET_RND  MOVQ_WONE
#define PAVGBP(a, b, c, d, e, f)        PAVGBP_MMX_NO_RND(a, b, c, d, e, f)
#define PAVGB(a, b, c, e)               PAVGB_MMX_NO_RND(a, b, c, e)
#define STATIC static
#include "rnd_template.c"
#include "hpeldsp_rnd_template.c"
#undef DEF
#undef SET_RND
#undef PAVGBP
#undef PAVGB
#undef STATIC
#if HAVE_MMX
#endif
#define DEF(x, y) x ## _ ## y ## _mmx
#define SET_RND  MOVQ_WTWO
#define PAVGBP(a, b, c, d, e, f)        PAVGBP_MMX(a, b, c, d, e, f)
#define PAVGB(a, b, c, e)               PAVGB_MMX(a, b, c, e)
#include "hpeldsp_rnd_template.c"
#undef DEF
#define DEF(x, y) ff_ ## x ## _ ## y ## _mmx
#define STATIC
#include "rnd_template.c"
#undef DEF
#undef SET_RND
#undef PAVGBP
#undef PAVGB
#if HAVE_MMX
#endif
#endif /* HAVE_INLINE_ASM */
#if HAVE_X86ASM
#define HPELDSP_AVG_PIXELS16(CPUEXT)                      \
#endif /* HAVE_X86ASM */
#define SET_HPEL_FUNCS_EXT(PFX, IDX, SIZE, CPU)                             \
#if HAVE_MMX_INLINE
#define SET_HPEL_FUNCS(PFX, IDX, SIZE, CPU)                                     \
#else
#define SET_HPEL_FUNCS(PFX, IDX, SIZE, CPU)                                     \
#endif
#if HAVE_MMX_INLINE
#endif
#if HAVE_MMXEXT_EXTERNAL
#endif /* HAVE_MMXEXT_EXTERNAL */
#if HAVE_AMD3DNOW_EXTERNAL
#endif /* HAVE_AMD3DNOW_EXTERNAL */
#if HAVE_SSE2_EXTERNAL
#endif /* HAVE_SSE2_EXTERNAL */
#if HAVE_SSSE3_EXTERNAL
#endif
