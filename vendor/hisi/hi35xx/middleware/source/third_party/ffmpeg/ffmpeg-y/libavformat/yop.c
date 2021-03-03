#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
typedef struct yop_dec_context {
    AVPacket video_packet;

    int odd_frame;
    int frame_size;
    int audio_block_length;
    int palette_size;
} YopDecContext;
