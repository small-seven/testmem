#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
typedef struct IFVContext {
    uint32_t next_video_index;
    uint32_t next_audio_index;
    uint32_t total_vframes;
    uint32_t total_aframes;

    int width, height;
    int is_audio_present;
    int sample_rate;

    int video_stream_index;
    int audio_stream_index;
} IFVContext;
