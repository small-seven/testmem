#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define CHUNK_PREAMBLE_SIZE 4
#define OPCODE_PREAMBLE_SIZE 4
#define CHUNK_INIT_AUDIO   0x0000
#define CHUNK_AUDIO_ONLY   0x0001
#define CHUNK_INIT_VIDEO   0x0002
#define CHUNK_VIDEO        0x0003
#define CHUNK_SHUTDOWN     0x0004
#define CHUNK_END          0x0005
#define CHUNK_DONE         0xFFFC
#define CHUNK_NOMEM        0xFFFD
#define CHUNK_EOF          0xFFFE
#define CHUNK_BAD          0xFFFF
#define OPCODE_END_OF_STREAM           0x00
#define OPCODE_END_OF_CHUNK            0x01
#define OPCODE_CREATE_TIMER            0x02
#define OPCODE_INIT_AUDIO_BUFFERS      0x03
#define OPCODE_START_STOP_AUDIO        0x04
#define OPCODE_INIT_VIDEO_BUFFERS      0x05
#define OPCODE_VIDEO_DATA_06           0x06
#define OPCODE_SEND_BUFFER             0x07
#define OPCODE_AUDIO_FRAME             0x08
#define OPCODE_SILENCE_FRAME           0x09
#define OPCODE_INIT_VIDEO_MODE         0x0A
#define OPCODE_CREATE_GRADIENT         0x0B
#define OPCODE_SET_PALETTE             0x0C
#define OPCODE_SET_PALETTE_COMPRESSED  0x0D
#define OPCODE_SET_SKIP_MAP            0x0E
#define OPCODE_SET_DECODING_MAP        0x0F
#define OPCODE_VIDEO_DATA_10           0x10
#define OPCODE_VIDEO_DATA_11           0x11
#define OPCODE_UNKNOWN_12              0x12
#define OPCODE_UNKNOWN_13              0x13
#define OPCODE_UNKNOWN_14              0x14
#define OPCODE_UNKNOWN_15              0x15
#define PALETTE_COUNT 256
typedef struct IPMVEContext {
    AVFormatContext *avf;
    unsigned char *buf;
    int buf_size;

    uint64_t frame_pts_inc;

    unsigned int video_bpp;
    unsigned int video_width;
    unsigned int video_height;
    int64_t video_pts;
    uint32_t     palette[256];
    int          has_palette;
    int          changed;
    uint8_t      send_buffer;
    uint8_t      frame_format;

    unsigned int audio_bits;
    unsigned int audio_channels;
    unsigned int audio_sample_rate;
    enum AVCodecID audio_type;
    unsigned int audio_frame_count;

    int video_stream_index;
    int audio_stream_index;

    int64_t audio_chunk_offset;
    int audio_chunk_size;
    int64_t video_chunk_offset;
    int video_chunk_size;
    int64_t skip_map_chunk_offset;
    int skip_map_chunk_size;
    int64_t decode_map_chunk_offset;
    int decode_map_chunk_size;

    int64_t next_chunk_offset;

} IPMVEContext;
