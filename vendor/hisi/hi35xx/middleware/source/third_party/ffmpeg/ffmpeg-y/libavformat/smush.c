#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "avio.h"
#include "internal.h"
typedef struct SMUSHContext {
    int version;
    int audio_stream_index;
    int video_stream_index;
} SMUSHContext;
