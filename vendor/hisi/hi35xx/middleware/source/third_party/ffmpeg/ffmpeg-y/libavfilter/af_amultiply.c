#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "filters.h"
#include "internal.h"
typedef struct AudioMultiplyContext {
    const AVClass *class;

    AVFrame *frames[2];
    int planes;
    int channels;
    int samples_align;

    AVFloatDSPContext *fdsp;
} AudioMultiplyContext;
