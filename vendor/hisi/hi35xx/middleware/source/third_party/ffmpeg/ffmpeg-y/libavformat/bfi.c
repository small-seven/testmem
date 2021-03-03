#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
typedef struct BFIContext {
    int nframes;
    int audio_frame;
    int video_frame;
    int video_size;
    int avflag;
} BFIContext;
