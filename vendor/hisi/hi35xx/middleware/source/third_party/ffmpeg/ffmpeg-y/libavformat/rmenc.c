#include "avformat.h"
#include "avio_internal.h"
#include "rm.h"
#include "libavutil/dict.h"
typedef struct StreamInfo {
    int nb_packets;
    int packet_total_size;
    int packet_max_size;
    /* codec related output */
    int bit_rate;
    AVRational frame_rate;
    int nb_frames;    /* current frame number */
    int total_frames; /* total number of frames */
    int num;
    AVCodecParameters *par;
} StreamInfo;
typedef struct RMMuxContext {
    StreamInfo streams[2];
    StreamInfo *audio_stream, *video_stream;
    int data_pos; /* position of the data after the header */
} RMMuxContext;
#define BUFFER_DURATION 0
#define MAX_HEADER_SIZE (7 + 4 + 12)
#define MAX_PACKET_SIZE (UINT16_MAX - MAX_HEADER_SIZE)
