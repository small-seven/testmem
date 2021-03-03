#include "config.h"
#include "libavutil/samplefmt.h"
#define USE_FLOATS 0
#include "mpegaudio.h"
#define SHR(a,b)       (((int)(a))>>(b))
#define FIXR_OLD(a)    ((int)((a) * FRAC_ONE + 0.5))
#define FIXR(a)        ((int)((a) * FRAC_ONE + 0.5))
#define FIXHR(a)       ((int)((a) * (1LL<<32) + 0.5))
#define MULH3(x, y, s) MULH((s)*(x), y)
#define MULLx(x, y, s) MULL((int)(x),(y),s)
#define RENAME(a)      a ## _fixed
#define OUT_FMT   AV_SAMPLE_FMT_S16
#define OUT_FMT_P AV_SAMPLE_FMT_S16P
#include "mpegaudiodec_template.c"
#if CONFIG_MP1_DECODER
#endif
#if CONFIG_MP2_DECODER
#endif
#if CONFIG_MP3_DECODER
#endif
#if CONFIG_MP3ADU_DECODER
#endif
#if CONFIG_MP3ON4_DECODER
#endif
