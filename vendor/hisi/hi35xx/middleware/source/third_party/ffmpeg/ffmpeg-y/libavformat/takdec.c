#include "libavutil/crc.h"
#define BITSTREAM_READER_LE
#include "libavcodec/tak.h"
#include "apetag.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "rawdec.h"
typedef struct TAKDemuxContext {
    AVClass *class;
    int     raw_packet_size;
    int     mlast_frame;
    int64_t data_end;
} TAKDemuxContext;
