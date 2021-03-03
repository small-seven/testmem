#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#define VMD_HEADER_SIZE 0x0330
#define BYTES_PER_FRAME_RECORD 16
typedef struct vmd_frame {
  int stream_index;
  int64_t frame_offset;
  unsigned int frame_size;
  int64_t pts;
  int keyframe;
  unsigned char frame_record[BYTES_PER_FRAME_RECORD];
} vmd_frame;
typedef struct VmdDemuxContext {
    int video_stream_index;
    int audio_stream_index;

    unsigned int frame_count;
    unsigned int frames_per_block;
    vmd_frame *frame_table;
    unsigned int current_frame;
    int is_indeo3;

    int sample_rate;
    int64_t audio_sample_counter;
    int skiphdr;

    unsigned char vmd_header[VMD_HEADER_SIZE];
} VmdDemuxContext;
