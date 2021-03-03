#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#define RoQ_MAGIC_NUMBER 0x1084
#define RoQ_CHUNK_PREAMBLE_SIZE 8
#define RoQ_AUDIO_SAMPLE_RATE 22050
#define RoQ_CHUNKS_TO_SCAN 30
#define RoQ_INFO           0x1001
#define RoQ_QUAD_CODEBOOK  0x1002
#define RoQ_QUAD_VQ        0x1011
#define RoQ_SOUND_MONO     0x1020
#define RoQ_SOUND_STEREO   0x1021
typedef struct RoqDemuxContext {

    int frame_rate;
    int width;
    int height;
    int audio_channels;

    int video_stream_index;
    int audio_stream_index;

    int64_t video_pts;
    unsigned int audio_frame_count;

} RoqDemuxContext;
