#include "config.h"
#include "libavutil/common.h"
#include "libavcodec/vp9dsp.h"
#include "vp9dsp_mips.h"
#if HAVE_MSA
#define init_intra_pred_msa(tx, sz)                             \
#undef init_intra_pred_msa
#define init_intra_pred_msa(tx, sz)                             \
#undef init_intra_pred_msa
#define init_itxfm(tx, sz)                                         \
#define init_idct(tx, nm)                        \
#undef init_itxfm
#undef init_idct
#define init_fpel(idx1, idx2, sz, type)                                    \
#define init_copy_avg(idx, sz)    \
#define init_avg(idx, sz)  \
#undef init_copy_avg
#undef init_avg
#undef init_fpel
#define init_subpel1(idx1, idx2, idxh, idxv, sz, dir, type)  \
#define init_subpel2(idx, idxh, idxv, dir, type)      \
#define init_subpel3(idx, type)         \
#undef init_subpel1
#undef init_subpel2
#undef init_subpel3
#endif  // #if HAVE_MSA
#if HAVE_MMI
#define init_subpel1(idx1, idx2, idxh, idxv, sz, dir, type)  \
#define init_subpel2(idx, idxh, idxv, dir, type)      \
#define init_subpel3(idx, type)         \
#undef init_subpel1
#undef init_subpel2
#undef init_subpel3
#endif  // #if HAVE_MMI
#if HAVE_MMI
#endif  // #if HAVE_MMI
#if HAVE_MSA
#endif  // #if HAVE_MSA
