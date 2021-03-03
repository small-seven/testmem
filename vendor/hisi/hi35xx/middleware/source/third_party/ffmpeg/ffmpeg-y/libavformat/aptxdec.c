#include "avformat.h"
#include "rawdec.h"
#define APTX_BLOCK_SIZE   4
#define APTX_PACKET_SIZE  (256*APTX_BLOCK_SIZE)
#define APTX_HD_BLOCK_SIZE   6
#define APTX_HD_PACKET_SIZE  (256*APTX_HD_BLOCK_SIZE)
typedef struct AptXDemuxerContext {
    AVClass *class;
    int sample_rate;
} AptXDemuxerContext;
#if CONFIG_APTX_DEMUXER
#endif
#if CONFIG_APTX_HD_DEMUXER
#endif
