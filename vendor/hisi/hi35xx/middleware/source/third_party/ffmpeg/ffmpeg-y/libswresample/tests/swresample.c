#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libswresample/swresample.h"
#undef time
#include <time.h>
#undef fprintf
#define SAMPLES 1000
#define SWR_CH_MAX 32
#define ASSERT_LEVEL 2
#define PUT_SAMPLE set(data, ch, k, channels, sample_fmt, v);
#define uint_rand(x) ((x) = (x) * 1664525 + 1013904223)
#define dbl_rand(x) (uint_rand(x)*2.0 / (double)UINT_MAX - 1)
#if 0
#else
#endif
