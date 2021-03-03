#include "libavutil/channel_layout.h"
#include "libavcodec/paf.h"
#include "avformat.h"
#include "internal.h"
#define MAGIC "Packed Animation File V1.0\n(c) 1992-96 Amazing Studio\x0a\x1a"
typedef struct PAFDemuxContext {
    uint32_t buffer_size;
    uint32_t frame_blks;
    uint32_t nb_frames;
    uint32_t start_offset;
    uint32_t preload_count;
    uint32_t max_video_blks;
    uint32_t max_audio_blks;

    uint32_t current_frame;
    uint32_t current_frame_count;
    uint32_t current_frame_block;

    uint32_t *blocks_count_table;
    uint32_t *frames_offset_table;
    uint32_t *blocks_offset_table;

    uint8_t  *video_frame;
    int video_size;

    uint8_t  *audio_frame;
    uint8_t  *temp_audio_frame;
    int audio_size;

    int got_audio;
} PAFDemuxContext;
