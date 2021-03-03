#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavresample/avresample.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct ResampleContext {
    const AVClass *class;
    AVAudioResampleContext *avr;
    AVDictionary *options;

    int resampling;
    int64_t next_pts;
    int64_t next_in_pts;

    /* set by filter_frame() to signal an output frame to request_frame() */
    int got_output;
} ResampleContext;
