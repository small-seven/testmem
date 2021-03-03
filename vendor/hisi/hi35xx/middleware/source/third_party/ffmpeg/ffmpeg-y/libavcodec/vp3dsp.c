#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "rnd_avg.h"
#include "vp3dsp.h"
#define IdctAdjustBeforeShift 8
#define xC1S7 64277
#define xC2S6 60547
#define xC3S5 54491
#define xC4S4 46341
#define xC5S3 36410
#define xC6S2 25080
#define xC7S1 12785
#define M(a, b) ((int)((SUINT)(a) * (b)) >> 16)
#define LOOP_FILTER(prefix, suffix, dim, count) \
