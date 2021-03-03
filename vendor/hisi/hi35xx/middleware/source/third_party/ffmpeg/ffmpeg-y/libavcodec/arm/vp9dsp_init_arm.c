#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "libavutil/arm/cpu.h"
#include "libavcodec/vp9dsp.h"
#include "vp9dsp_init.h"
#define declare_fpel(type, sz)                                          \
#define declare_copy_avg(sz) \
#define decl_mc_func(op, filter, dir, sz)                                                \
#define define_8tap_2d_fn(op, filter, sz)                                         \
#define decl_filter_funcs(op, dir, sz)  \
#define decl_mc_funcs(sz)           \
#define define_8tap_2d_funcs(sz)        \
#define init_fpel(idx1, idx2, sz, type)              \
#define init_copy_avg(idx, sz)   \
#define init_mc_func(idx1, idx2, op, filter, fname, dir, mx, my, sz, pfx) \
#define init_mc_funcs(idx, dir, mx, my, sz, pfx)                                   \
#define init_mc_funcs_dirs(idx, sz)            \
#define define_itxfm(type_a, type_b, sz)                                   \
#define define_itxfm_funcs(sz)      \
#define init_itxfm(tx, sz)                                             \
#define init_idct(tx, nm)           \
#define define_loop_filter(dir, wd, size) \
#define define_loop_filters(wd, size) \
#define lf_mix_fn(dir, wd1, wd2, stridea)                                                         \
#define lf_mix_fns(wd1, wd2)       \
