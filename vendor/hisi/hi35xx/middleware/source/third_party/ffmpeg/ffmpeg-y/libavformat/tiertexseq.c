#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
#define SEQ_FRAME_SIZE         6144
#define SEQ_FRAME_W            256
#define SEQ_FRAME_H            128
#define SEQ_NUM_FRAME_BUFFERS  30
#define SEQ_AUDIO_BUFFER_SIZE  882
#define SEQ_SAMPLE_RATE        22050
#define SEQ_FRAME_RATE         25
typedef struct TiertexSeqFrameBuffer {
    int fill_size;
    int data_size;
    unsigned char *data;
} TiertexSeqFrameBuffer;
typedef struct SeqDemuxContext {
    int audio_stream_index;
    int video_stream_index;
    int current_frame_pts;
    int current_frame_offs;
    TiertexSeqFrameBuffer frame_buffers[SEQ_NUM_FRAME_BUFFERS];
    int frame_buffers_count;
    unsigned int current_audio_data_size;
    unsigned int current_audio_data_offs;
    unsigned int current_pal_data_size;
    unsigned int current_pal_data_offs;
    unsigned int current_video_data_size;
    unsigned char *current_video_data_ptr;
    int audio_buffer_full;
} SeqDemuxContext;
