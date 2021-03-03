#include "libavutil/parseutils.h"
#include "avio_internal.h"
#include "avformat.h"
#include "internal.h"
typedef struct DHAVContext {
    unsigned type;
    unsigned subtype;
    unsigned channel;
    unsigned frame_subnumber;
    unsigned frame_number;
    unsigned date;
    unsigned timestamp;
    int width, height;
    int video_codec;
    int frame_rate;
    int audio_channels;
    int audio_codec;
    int sample_rate;

    int video_stream_index;
    int audio_stream_index;
} DHAVContext;
typedef struct DHAVStream {
    int64_t last_timestamp;
    int64_t pts;
} DHAVStream;
