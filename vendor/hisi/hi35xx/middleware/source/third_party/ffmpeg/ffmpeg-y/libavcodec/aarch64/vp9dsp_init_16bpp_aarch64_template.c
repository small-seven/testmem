#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "libavutil/aarch64/cpu.h"
#include "vp9dsp_init.h"
#define declare_fpel(type, sz, suffix)                                          \
#define decl_mc_func(op, filter, dir, sz, bpp)                                                   \
#define define_8tap_2d_fn(op, filter, sz, bpp)                                      \
#define decl_filter_funcs(op, dir, sz, bpp)  \
#define decl_mc_funcs(sz, bpp)           \
#define ff_vp9_copy32_neon  ff_vp9_copy32_aarch64
#define ff_vp9_copy64_neon  ff_vp9_copy64_aarch64
#define ff_vp9_copy128_neon ff_vp9_copy128_aarch64
#define define_8tap_2d_funcs(sz, bpp)        \
#define init_fpel(idx1, idx2, sz, type, suffix)      \
#define init_copy(idx, sz, suffix) \
#define init_avg(idx, sz, suffix) \
#define init_copy_avg(idx, sz1, sz2) \
#define init_mc_func(idx1, idx2, op, filter, fname, dir, mx, my, sz, pfx, bpp) \
#define init_mc_funcs(idx, dir, mx, my, sz, pfx, bpp)                                   \
#define init_mc_funcs_dirs(idx, sz, bpp)            \
#define define_itxfm2(type_a, type_b, sz, bpp)                                     \
#define define_itxfm(type_a, type_b, sz, bpp) define_itxfm2(type_a, type_b, sz, bpp)
#define define_itxfm_funcs(sz, bpp)      \
#define init_itxfm2(tx, sz, bpp)                                               \
#define init_itxfm(tx, sz, bpp) init_itxfm2(tx, sz, bpp)
#define init_idct2(tx, nm, bpp)     \
#define init_idct(tx, nm, bpp) init_idct2(tx, nm, bpp)
#define define_loop_filter(dir, wd, size, bpp) \
#define define_loop_filters(wd, size, bpp) \
#define init_lpf_func_8(idx1, idx2, dir, wd, bpp) \
#define init_lpf_func_16(idx, dir, bpp) \
#define init_lpf_func_mix2(idx1, idx2, idx3, dir, wd, bpp) \
#define init_lpf_funcs_8_wd(idx, wd, bpp) \
#define init_lpf_funcs_16(bpp)   \
#define init_lpf_funcs_mix2_wd(idx1, idx2, wd, bpp) \
#define init_lpf_funcs_8(bpp)        \
#define init_lpf_funcs_mix2(bpp)           \
