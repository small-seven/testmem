#include "libavutil/channel_layout.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#define GSM_BLOCK_SIZE    33
#define GSM_BLOCK_SAMPLES 160
#define GSM_SAMPLE_RATE   8000
typedef struct GSMDemuxerContext {
    AVClass *class;
    int sample_rate;
} GSMDemuxerContext;
