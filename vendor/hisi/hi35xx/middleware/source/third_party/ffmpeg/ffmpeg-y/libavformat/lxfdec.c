#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "libavcodec/bytestream.h"
#include "avformat.h"
#include "internal.h"
#define LXF_MAX_PACKET_HEADER_SIZE 256
#define LXF_HEADER_DATA_SIZE    120
#define LXF_IDENT               "LEITCH\0"
#define LXF_IDENT_LENGTH        8
#define LXF_SAMPLERATE          48000
typedef struct LXFDemuxContext {
    int channels;                       ///< number of audio channels. zero means no audio
    int frame_number;                   ///< current video frame
    uint32_t video_format, packet_type, extended_size;
} LXFDemuxContext;
