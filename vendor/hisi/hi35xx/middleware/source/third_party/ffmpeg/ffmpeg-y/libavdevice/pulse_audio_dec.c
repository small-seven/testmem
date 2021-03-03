#include <pulse/rtclock.h>
#include <pulse/error.h>
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
#include "pulse_audio_common.h"
#include "timefilter.h"
#define DEFAULT_CODEC_ID AV_NE(AV_CODEC_ID_PCM_S16BE, AV_CODEC_ID_PCM_S16LE)
typedef struct PulseData {
    AVClass *class;
    char *server;
    char *name;
    char *stream_name;
    int  sample_rate;
    int  channels;
    int  frame_size;
    int  fragment_size;

    pa_threaded_mainloop *mainloop;
    pa_context *context;
    pa_stream *stream;

    TimeFilter *timefilter;
    int last_period;
    int wallclock;
} PulseData;
#define CHECK_SUCCESS_GOTO(rerror, expression, label)        \
#define CHECK_DEAD_GOTO(p, rerror, label)                               \
#define OFFSET(a) offsetof(PulseData, a)
#define D AV_OPT_FLAG_DECODING_PARAM
