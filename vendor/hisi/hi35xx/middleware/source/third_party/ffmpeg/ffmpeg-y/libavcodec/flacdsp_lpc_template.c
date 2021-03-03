#include <stdint.h>
#include "libavutil/avutil.h"
#include "mathops.h"
#undef FUNC
#undef sum_type
#undef MUL
#undef CLIP
#undef FSUF
#define FUNC(n) AV_JOIN(n ## _, SAMPLE_SIZE)
#if SAMPLE_SIZE == 32
#   define sum_type  int64_t
#   define MUL(a, b) MUL64(a, b)
#   define CLIP(x) av_clipl_int32(x)
#else
#   define sum_type  int32_t
#   define MUL(a, b) ((a) * (b))
#   define CLIP(x) (x)
#endif
#define LPC1(x) {           \
#if CONFIG_SMALL
#else
#endif
