#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
typedef struct CinFileHeader {
    int video_frame_size;
    int video_frame_width;
    int video_frame_height;
    int audio_frequency;
    int audio_bits;
    int audio_stereo;
    int audio_frame_size;
} CinFileHeader;
typedef struct CinFrameHeader {
    int audio_frame_type;
    int video_frame_type;
    int pal_colors_count;
    int audio_frame_size;
    int video_frame_size;
} CinFrameHeader;
typedef struct CinDemuxContext {
    int audio_stream_index;
    int video_stream_index;
    CinFileHeader file_header;
    int64_t audio_stream_pts;
    int64_t video_stream_pts;
    CinFrameHeader frame_header;
    int audio_buffer_size;
} CinDemuxContext;
