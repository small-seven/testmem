#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/vp9dsp.h"
#include "libavcodec/x86/vp9dsp_init.h"
#if HAVE_X86ASM
#if HAVE_AVX2_EXTERNAL
#endif
#if HAVE_AVX2_EXTERNAL
#endif
#if HAVE_AVX2_EXTERNAL
#endif
#define decl_lpf_func(dir, wd, bpp, opt) \
#define decl_lpf_funcs(dir, wd, bpp) \
#define decl_lpf_funcs_wd(dir) \
#define lpf_16_wrapper(dir, off, bpp, opt) \
#define lpf_16_wrappers(bpp, opt) \
#define lpf_mix2_wrapper(dir, off, wd1, wd2, bpp, opt) \
#define lpf_mix2_wrappers(wd1, wd2, bpp, opt) \
#define lpf_mix2_wrappers_set(bpp, opt) \
#if BPC == 10
#else
#endif
#endif /* HAVE_X86ASM */
#if HAVE_X86ASM
#define init_lpf_8_func(idx1, idx2, dir, wd, bpp, opt) \
#define init_lpf_16_func(idx, dir, bpp, opt) \
#define init_lpf_mix2_func(idx1, idx2, idx3, dir, wd1, wd2, bpp, opt) \
#define init_lpf_funcs(bpp, opt) \
#define init_itx_func(idxa, idxb, typea, typeb, size, bpp, opt) \
#define init_itx_func_one(idx, typea, typeb, size, bpp, opt) \
#define init_itx_funcs(idx, size, bpp, opt) \
#if BPC == 10
#endif
#if BPC == 10
#else
#endif
#if BPC == 10
#endif
#if HAVE_AVX2_EXTERNAL
#endif
#endif /* HAVE_X86ASM */
