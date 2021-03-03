#include <stdint.h>
#include <stdio.h>
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/lfg.h"
#include "libavutil/libm.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "libavresample/avresample.h"
#define PUT_FUNC(name, fmt, type, expr)                                     \
#define PUT_SAMPLE put_sample(data, sample_fmt, channels, k, ch, v);
