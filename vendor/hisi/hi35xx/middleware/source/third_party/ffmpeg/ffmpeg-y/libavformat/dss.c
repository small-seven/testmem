#include "libavutil/attributes.h"
#include "libavutil/bswap.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define DSS_HEAD_OFFSET_AUTHOR        0xc
#define DSS_AUTHOR_SIZE               16
#define DSS_HEAD_OFFSET_START_TIME    0x26
#define DSS_HEAD_OFFSET_END_TIME      0x32
#define DSS_TIME_SIZE                 12
#define DSS_HEAD_OFFSET_ACODEC        0x2a4
#define DSS_ACODEC_DSS_SP             0x0    /* SP mode */
#define DSS_ACODEC_G723_1             0x2    /* LP mode */
#define DSS_HEAD_OFFSET_COMMENT       0x31e
#define DSS_COMMENT_SIZE              64
#define DSS_BLOCK_SIZE                512
#define DSS_AUDIO_BLOCK_HEADER_SIZE   6
#define DSS_FRAME_SIZE                42
typedef struct DSSDemuxContext {
    unsigned int audio_codec;
    int counter;
    int swap;
    int dss_sp_swap_byte;
    int8_t *dss_sp_buf;

    int packet_size;
    int dss_header_size;
} DSSDemuxContext;
