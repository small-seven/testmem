#include "libavutil/common.h"
#include "bit_depth_template.c"
#include "vp9dsp.h"
#if BIT_DEPTH != 12
#endif /* BIT_DEPTH != 12 */
#if BIT_DEPTH != 12
#endif /* BIT_DEPTH != 12 */
#if BIT_DEPTH != 12
#if BIT_DEPTH == 8
#define memset_bpc memset
#else
#endif
#define DST(x, y) dst[(x) + (y) * stride]
#define def_diag_downleft(size) \
#define def_diag_downright(size) \
#define def_vert_right(size) \
#define def_hor_down(size) \
#define def_vert_left(size) \
#define def_hor_up(size) \
#undef DST
#endif /* BIT_DEPTH != 12 */
#if BIT_DEPTH != 8
#endif
#if BIT_DEPTH != 10
#endif
#define init_intra_pred_bd_aware(tx, sz) \
#if BIT_DEPTH == 12
#define init_intra_pred(tx, sz) \
#else
#endif
#undef init_intra_pred
#undef init_intra_pred_bd_aware
#define itxfm_wrapper(type_a, type_b, sz, bits, has_dconly) \
#define itxfm_wrap(sz, bits) \
#define IN(x) ((dctint) in[(x) * stride])
#undef IN
#undef itxfm_wrapper
#undef itxfm_wrap
#define init_itxfm(tx, sz) \
#define init_idct(tx, nm) \
#undef init_itxfm
#undef init_idct
#define lf_8_fn(dir, wd, stridea, strideb) \
#define lf_8_fns(wd) \
#undef lf_8_fn
#undef lf_8_fns
#define lf_16_fn(dir, stridea) \
#undef lf_16_fn
#define lf_mix_fn(dir, wd1, wd2, stridea) \
#define lf_mix_fns(wd1, wd2) \
#undef lf_mix_fn
#undef lf_mix_fns
#if BIT_DEPTH != 12
#define fpel_fn(type, sz) \
#define copy_avg_fn(sz) \
#undef fpel_fn
#undef copy_avg_fn
#endif /* BIT_DEPTH != 12 */
#define FILTER_8TAP(src, x, F, stride) \
#define filter_8tap_1d_fn(opn, opa, dir, ds) \
#undef filter_8tap_1d_fn
#define filter_8tap_2d_fn(opn, opa) \
#undef filter_8tap_2d_fn
#define filter_fn_1d(sz, dir, dir_m, type, type_idx, avg) \
#define filter_fn_2d(sz, type, type_idx, avg) \
#if BIT_DEPTH != 12
#define FILTER_BILIN(src, x, mxy, stride) \
#define bilin_1d_fn(opn, opa, dir, ds) \
#undef bilin_1d_fn
#define bilin_2d_fn(opn, opa) \
#undef bilin_2d_fn
#define bilinf_fn_1d(sz, dir, dir_m, avg) \
#define bilinf_fn_2d(sz, avg) \
#else
#define bilinf_fn_1d(a, b, c, d)
#define bilinf_fn_2d(a, b)
#endif
#define filter_fn(sz, avg) \
#define filter_fn_set(avg) \
#undef filter_fn
#undef filter_fn_set
#undef filter_fn_1d
#undef filter_fn_2d
#undef bilinf_fn_1d
#undef bilinf_fn_2d
#if BIT_DEPTH != 8
#endif
#if BIT_DEPTH != 10
#endif
#if BIT_DEPTH == 12
#else /* BIT_DEPTH == 12 */
#define init_fpel(idx1, idx2, sz, type) \
#define init_copy_avg(idx, sz) \
#undef init_copy_avg
#undef init_fpel
#endif /* BIT_DEPTH == 12 */
#define init_subpel1_bd_aware(idx1, idx2, idxh, idxv, sz, dir, type) \
#if BIT_DEPTH == 12
#define init_subpel1 init_subpel1_bd_aware
#else
#define init_subpel1(idx1, idx2, idxh, idxv, sz, dir, type) \
#endif
#define init_subpel2(idx, idxh, idxv, dir, type) \
#define init_subpel3(idx, type) \
#undef init_subpel1
#undef init_subpel2
#undef init_subpel3
#undef init_subpel1_bd_aware
#define scaled_filter_8tap_fn(opn, opa) \
#undef scaled_filter_8tap_fn
#undef FILTER_8TAP
#define scaled_filter_fn(sz, type, type_idx, avg) \
#if BIT_DEPTH != 12
#define scaled_bilin_fn(opn, opa) \
#undef scaled_bilin_fn
#undef FILTER_BILIN
#define scaled_bilinf_fn(sz, avg) \
#else
#define scaled_bilinf_fn(a, b)
#endif
#define scaled_filter_fns(sz, avg) \
#define scaled_filter_fn_set(avg) \
#undef scaled_filter_fns
#undef scaled_filter_fn_set
#undef scaled_filter_fn
#undef scaled_bilinf_fn
#if BIT_DEPTH != 8
#endif
#if BIT_DEPTH != 10
#endif
#define init_scaled_bd_aware(idx1, idx2, sz, type) \
#if BIT_DEPTH == 12
#define init_scaled(a,b,c,d) init_scaled_bd_aware(a,b,c,d)
#else
#define init_scaled(idx1, idx2, sz, type) \
#endif
#define init_scaled_put_avg(idx, sz) \
#undef init_scaled_put_avg
#undef init_scaled
#undef init_scaled_bd_aware
