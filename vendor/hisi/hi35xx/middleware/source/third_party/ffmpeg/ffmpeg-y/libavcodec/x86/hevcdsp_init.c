#include "config.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/get_bits.h" /* required for hevcdsp.h GetBitContext */
#include "libavcodec/hevcdsp.h"
#include "libavcodec/x86/hevcdsp.h"
#define LFC_FUNC(DIR, DEPTH, OPT) \
#define LFL_FUNC(DIR, DEPTH, OPT) \
#define LFC_FUNCS(type, depth, opt) \
#define LFL_FUNCS(type, depth, opt) \
#define IDCT_DC_FUNCS(W, opt) \
#define IDCT_FUNCS(opt)                                             \
#define mc_rep_func(name, bitd, step, W, opt) \
#define mc_rep_uni_func(name, bitd, step, W, opt) \
#define mc_rep_bi_func(name, bitd, step, W, opt) \
#define mc_rep_funcs(name, bitd, step, W, opt)        \
#define mc_rep_func2(name, bitd, step1, step2, W, opt) \
#define mc_rep_uni_func2(name, bitd, step1, step2, W, opt) \
#define mc_rep_bi_func2(name, bitd, step1, step2, W, opt) \
#define mc_rep_funcs2(name, bitd, step1, step2, W, opt) \
#if ARCH_X86_64 && HAVE_SSE4_EXTERNAL
#define mc_rep_mix_10(name, width1, width2, width3, opt1, opt2, width4)                                       \
#define mc_bi_rep_mix_10(name, width1, width2, width3, opt1, opt2, width4)                                    \
#define mc_uni_rep_mix_10(name, width1, width2, width3, opt1, opt2, width4)                                   \
#define mc_rep_mixs_10(name, width1, width2, width3, opt1, opt2, width4)   \
#define mc_rep_mix_8(name, width1, width2, width3, opt1, opt2)                                                \
#define mc_bi_rep_mix_8(name, width1, width2, width3, opt1, opt2)                                             \
#define mc_uni_rep_mix_8(name, width1, width2, width3, opt1, opt2)                                            \
#define mc_rep_mixs_8(name, width1, width2, width3, opt1, opt2)   \
#if HAVE_AVX2_EXTERNAL
#endif //AVX2
#define mc_rep_uni_w(bitd, step, W, opt) \
#define mc_rep_bi_w(bitd, step, W, opt) \
#define mc_uni_w_func(name, bitd, W, opt) \
#define mc_uni_w_funcs(name, bitd, opt)      \
#define mc_bi_w_func(name, bitd, W, opt) \
#define mc_bi_w_funcs(name, bitd, opt)      \
#endif //ARCH_X86_64 && HAVE_SSE4_EXTERNAL
#define SAO_BAND_FILTER_FUNCS(bitd, opt)                                                                                   \
#define SAO_BAND_INIT(bitd, opt) do {                                       \
#define SAO_EDGE_FILTER_FUNCS(bitd, opt)                                                                                    \
#define SAO_EDGE_INIT(bitd, opt) do {                                       \
#define EPEL_LINKS(pointer, my, mx, fname, bitd, opt )           \
#define QPEL_LINKS(pointer, my, mx, fname, bitd, opt)           \
