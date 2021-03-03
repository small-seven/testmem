#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "avformat.h"
#include "internal.h"
typedef struct ThpDemuxContext {
    int              version;
    unsigned         first_frame;
    unsigned         first_framesz;
    unsigned         last_frame;
    int              compoff;
    unsigned         framecnt;
    AVRational       fps;
    unsigned         frame;
    int64_t          next_frame;
    unsigned         next_framesz;
    int              video_stream_index;
    int              audio_stream_index;
    int              compcount;
    unsigned char    components[16];
    AVStream*        vst;
    int              has_audio;
    unsigned         audiosize;
} ThpDemuxContext;
