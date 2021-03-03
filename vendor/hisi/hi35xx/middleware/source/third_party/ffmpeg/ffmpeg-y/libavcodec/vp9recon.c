#include "libavutil/avassert.h"
#include "avcodec.h"
#include "internal.h"
#include "videodsp.h"
#include "vp9data.h"
#include "vp9dec.h"
#define memset_bpp(c, i1, v, i2, num) do { \
#define memset_val(c, val, num) do { \
#define assign_bpp(c, i1, v, i2) do { \
#define assign_val(c, i, v) do { \
#define mc_luma_dir(td, mc, dst, dst_ls, src, src_ls, tref, row, col, mv, \
#define mc_chroma_dir(td, mc, dstu, dstv, dst_ls, srcu, srcu_ls, srcv, srcv_ls, tref, \
#define SCALED 0
#define FN(x) x##_8bpp
#define BYTES_PER_PIXEL 1
#include "vp9_mc_template.c"
#undef FN
#undef BYTES_PER_PIXEL
#define FN(x) x##_16bpp
#define BYTES_PER_PIXEL 2
#include "vp9_mc_template.c"
#undef mc_luma_dir
#undef mc_chroma_dir
#undef FN
#undef BYTES_PER_PIXEL
#undef SCALED
#define scale_mv(n, dim) (((int64_t)(n) * scale[dim]) >> 14)
#undef scale_mv
#define mc_luma_dir(td, mc, dst, dst_ls, src, src_ls, tref, row, col, mv, \
#define mc_chroma_dir(td, mc, dstu, dstv, dst_ls, srcu, srcu_ls, srcv, srcv_ls, tref, \
#define SCALED 1
#define FN(x) x##_scaled_8bpp
#define BYTES_PER_PIXEL 1
#include "vp9_mc_template.c"
#undef FN
#undef BYTES_PER_PIXEL
#define FN(x) x##_scaled_16bpp
#define BYTES_PER_PIXEL 2
#include "vp9_mc_template.c"
#undef mc_luma_dir
#undef mc_chroma_dir
#undef FN
#undef BYTES_PER_PIXEL
#undef SCALED
