#include <math.h>
#include <stdint.h>
#include "libavutil/common.h"
#include "internal.h"
#if defined(CONFIG_RESAMPLE_DBL)
#define SET_TYPE(func)  func ## _dbl
#define FELEM         double
#define FELEM2        double
#define FELEML        double
#define OUT(d, v) d = v
#define DBL_TO_FELEM(d, v) d = v
#elif defined(CONFIG_RESAMPLE_FLT)
#define SET_TYPE(func)  func ## _flt
#define FELEM         float
#define FELEM2        float
#define FELEML        float
#define OUT(d, v) d = v
#define DBL_TO_FELEM(d, v) d = v
#elif defined(CONFIG_RESAMPLE_S32)
#define SET_TYPE(func)  func ## _s32
#define FELEM         int32_t
#define FELEM2        int64_t
#define FELEML        int64_t
#define OUT(d, v) d = av_clipl_int32((v + (1 << 29)) >> 30)
#define DBL_TO_FELEM(d, v) d = av_clipl_int32(llrint(v * (1 << 30)));
#else
#define SET_TYPE(func)  func ## _s16
#define FELEM         int16_t
#define FELEM2        int32_t
#define FELEML        int64_t
#define OUT(d, v) d = av_clip_int16((v + (1 << 14)) >> 15)
#define DBL_TO_FELEM(d, v) d = av_clip_int16(lrint(v * (1 << 15)))
#endif
#undef SET_TYPE
#undef FELEM
#undef FELEM2
#undef FELEML
#undef OUT
#undef DBL_TO_FELEM
