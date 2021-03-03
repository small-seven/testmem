#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/vp9dsp.h"
#include "libavcodec/x86/vp9dsp_init.h"
#if HAVE_X86ASM
#if ARCH_X86_64
#endif
#if ARCH_X86_32
#endif
#if ARCH_X86_64 && HAVE_AVX2_EXTERNAL
#endif
#if ARCH_X86_64 && HAVE_AVX2_EXTERNAL
#endif
#if ARCH_X86_64 && HAVE_AVX2_EXTERNAL
#endif
#define itxfm_func(typea, typeb, size, opt) \
#define itxfm_funcs(size, opt) \
#undef itxfm_func
#undef itxfm_funcs
#define lpf_funcs(size1, size2, opt) \
#undef lpf_funcs
#define ipred_func(size, type, opt) \
#define ipred_dc_funcs(size, opt) \
#define ipred_dir_tm_funcs(size, opt) \
#define ipred_dir_tm_h_funcs(size, opt) \
#define ipred_all_funcs(size, opt) \
#undef ipred_func
#undef ipred_dir_tm_h_funcs
#undef ipred_dir_tm_funcs
#undef ipred_dc_funcs
#endif /* HAVE_X86ASM */
#if HAVE_X86ASM
#define init_lpf(opt) do { \
#define init_ipred(sz, opt, t, e) \
#define ff_vp9_ipred_hd_4x4_ssse3 ff_vp9_ipred_hd_4x4_mmxext
#define ff_vp9_ipred_vl_4x4_ssse3 ff_vp9_ipred_vl_4x4_mmxext
#define init_dir_tm_ipred(sz, opt) do { \
#define init_dir_tm_h_ipred(sz, opt) do { \
#define init_dc_ipred(sz, opt) do { \
#define init_all_ipred(sz, opt) do { \
#if ARCH_X86_64 && HAVE_AVX2_EXTERNAL
#endif
#undef init_fpel
#undef init_subpel1
#undef init_subpel2
#undef init_subpel3
#endif /* HAVE_X86ASM */
