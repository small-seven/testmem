#include <math.h>
#include <pulse/pulseaudio.h>
#include <pulse/error.h>
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/log.h"
#include "libavutil/attributes.h"
#include "pulse_audio_common.h"
typedef struct PulseData {
    AVClass *class;
    const char *server;
    const char *name;
    const char *stream_name;
    const char *device;
    int64_t timestamp;
    int buffer_size;               /**< Buffer size in bytes */
    int buffer_duration;           /**< Buffer size in ms, recalculated to buffer_size */
    int prebuf;
    int minreq;
    int last_result;
    pa_threaded_mainloop *mainloop;
    pa_context *ctx;
    pa_stream *stream;
    int nonblocking;
    int mute;
    pa_volume_t base_volume;
    pa_volume_t last_volume;
} PulseData;
#define OFFSET(a) offsetof(PulseData, a)
#define E AV_OPT_FLAG_ENCODING_PARAM
