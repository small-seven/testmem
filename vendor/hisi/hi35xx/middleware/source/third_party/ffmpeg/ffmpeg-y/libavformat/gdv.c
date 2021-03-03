#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "avio.h"
#include "internal.h"
typedef struct GDVContext {
    int is_first_video;
    int is_audio;
    int audio_size;
    int audio_stream_index;
    int video_stream_index;
    unsigned pal[256];
} GDVContext;
