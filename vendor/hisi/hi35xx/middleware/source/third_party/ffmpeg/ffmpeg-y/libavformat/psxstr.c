#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define RIFF_TAG MKTAG('R', 'I', 'F', 'F')
#define CDXA_TAG MKTAG('C', 'D', 'X', 'A')
#define RAW_CD_SECTOR_SIZE      2352
#define RAW_CD_SECTOR_DATA_SIZE 2304
#define VIDEO_DATA_CHUNK_SIZE   0x7E0
#define VIDEO_DATA_HEADER_SIZE  0x38
#define RIFF_HEADER_SIZE        0x2C
#define CDXA_TYPE_MASK     0x0E
#define CDXA_TYPE_DATA     0x08
#define CDXA_TYPE_AUDIO    0x04
#define CDXA_TYPE_VIDEO    0x02
#define STR_MAGIC (0x80010160)
typedef struct StrChannel {
    /* video parameters */
    int video_stream_index;
    AVPacket tmp_pkt;

    /* audio parameters */
    int audio_stream_index;
} StrChannel;
typedef struct StrDemuxContext {

    /* a STR file can contain up to 32 channels of data */
    StrChannel channels[32];
} StrDemuxContext;
