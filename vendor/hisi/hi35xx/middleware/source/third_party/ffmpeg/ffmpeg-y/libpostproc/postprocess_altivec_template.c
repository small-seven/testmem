#include "libavutil/avutil.h"
#define ALTIVEC_TRANSPOSE_8x8_SHORT(src_a,src_b,src_c,src_d,src_e,src_f,src_g,src_h) \
#define LOAD_LINE(i)                                                    \
#define LOAD_LINE_ALIGNED(i)                                            \
#undef LOAD_LINE
#undef LOAD_LINE_ALIGNED
#define ITER(i, j)                                                      \
#undef ITER
#define LOAD_LINE(i)                                                    \
#define LOAD_LINE_ALIGNED(i)                                            \
#undef LOAD_LINE
#undef LOAD_LINE_ALIGNED
#define PACK_AND_STORE(i)                                       \
#define PACK_AND_STORE_ALIGNED(i)                               \
#define LOAD_LINE(i)                                                    \
#undef LOAD_LINE
#define STORE(i)                                                \
#define LOAD_LINE(i)                                                  \
#undef LOAD_LINE
#define EXTRACT(op) do {                                                \
#undef EXTRACT
#define COMPARE(i)                                                      \
#undef COMPARE
#define F_INIT()                                       \
#define F2(i, j, k, l)                                                  \
#define ITER(i, j, k) do {                      \
#define STORE_LINE(i) do {                              \
#undef STORE_LINE
#undef ITER
#undef F2
#define doHorizLowPass_altivec(a...) doHorizLowPass_C(a)
#define doHorizDefFilter_altivec(a...) doHorizDefFilter_C(a)
#define do_a_deblock_altivec(a...) do_a_deblock_C(a)
#define LOAD_LINE(src, i)                                               \
#undef LOAD_LINE
#define ACCUMULATE_DIFFS(i) do {                                \
#undef ACCUMULATE_DIFFS
#define OP(i) v_tempBlurredAss##i = vec_avg(v_tempBlurredAss##i, v_srcAss##i);
#undef OP
#define OP(i) v_tempBlurredAss##i = v_srcAss##i;
#undef OP
#define OP(i) do {                                                      \
#undef OP
#define OP(i) do {                                              \
#undef OP
#define PACK_AND_STORE(src, i) do {                                      \
#undef PACK_AND_STORE
#define LOAD_DOUBLE_LINE(i, j)                                          \
#undef LOAD_DOUBLE_LINE
#define LOAD_DOUBLE_LINE(i, j)                                  \
#undef LOAD_DOUBLE_LINE
#define STORE_DOUBLE_LINE(i, j) do {                                    \
