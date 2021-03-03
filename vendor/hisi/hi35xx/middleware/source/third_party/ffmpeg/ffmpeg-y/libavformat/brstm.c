#include "libavutil/intreadwrite.h"
#include "libavcodec/bytestream.h"
#include "avformat.h"
#include "internal.h"
typedef struct BRSTMDemuxContext {
    uint32_t    block_size;
    uint32_t    block_count;
    uint32_t    current_block;
    uint32_t    samples_per_block;
    uint32_t    last_block_used_bytes;
    uint32_t    last_block_size;
    uint32_t    last_block_samples;
    uint32_t    data_start;
    uint8_t     *table;
    uint8_t     *adpc;
    int         little_endian;
} BRSTMDemuxContext;
