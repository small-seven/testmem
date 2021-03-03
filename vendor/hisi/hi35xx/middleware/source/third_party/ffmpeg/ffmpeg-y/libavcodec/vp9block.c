#include "libavutil/avassert.h"
#include "avcodec.h"
#include "internal.h"
#include "videodsp.h"
#include "vp56.h"
#include "vp9.h"
#include "vp9data.h"
#include "vp9dec.h"
#if HAVE_FAST_64BIT
#else
#endif
#if HAVE_FAST_64BIT
#define SPLAT_CTX(var, val, n) \
#else
#define SPLAT_CTX(var, val, n) \
#endif
#define SET_CTXS(perf, dir, off, n) \
#undef SPLAT_CTX
#undef SET_CTXS
#define STORE_COEF(c, i, v) do { \
#define MERGE(la, end, step, rd) \
#define MERGE_CTX(step, rd) \
#define DECODE_Y_COEF_LOOP(step, mode_index, v) \
#define SPLAT(la, end, step, cond) \
#define SPLAT_CTX(step) \
#define DECODE_UV_COEF_LOOP(step, v) \
#define SPLAT_ZERO_CTX(v, n) \
#define SPLAT_ZERO_YUV(dir, var, off, n, dir2) \
