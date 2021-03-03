#include <inttypes.h>
#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
#define MVI_FRAC_BITS 10
#define MVI_AUDIO_STREAM_INDEX 0
#define MVI_VIDEO_STREAM_INDEX 1
typedef struct MviDemuxContext {
    unsigned int (*get_int)(AVIOContext *);
    uint32_t audio_data_size;
    uint64_t audio_size_counter;
    uint64_t audio_frame_size;
    int audio_size_left;
    int video_frame_size;
} MviDemuxContext;
