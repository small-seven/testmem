#include "config.h"
#include "libavutil/cpu.h"
#include "libavutil/avassert.h"
#include "libavutil/aarch64/cpu.h"
#include "libswresample/resample.h"
#define DECLARE_RESAMPLE_COMMON_TEMPLATE(TYPE, DELEM, FELEM, FELEM2, OUT)                         \
#define OUT(d, v) d = v
#undef OUT
#define OUT(d, v) (v) = ((v) + (1<<(14)))>>15; (d) = av_clip_int16(v)
#undef OUT
