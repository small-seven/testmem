#include "libavutil/channel_layout.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define HUFFMAN_TABLE_SIZE (64 * 1024)
#define IDCIN_FPS 14
typedef struct IdcinDemuxContext {
    int video_stream_index;
    int audio_stream_index;
    int audio_chunk_size1;
    int audio_chunk_size2;
    int block_align;

    /* demux state variables */
    int current_audio_chunk;
    int next_chunk_is_video;
    int audio_present;
    int64_t first_pkt_pos;
} IdcinDemuxContext;
