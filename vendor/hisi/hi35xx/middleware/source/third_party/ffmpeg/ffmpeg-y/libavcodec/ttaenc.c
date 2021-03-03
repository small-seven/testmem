#define BITSTREAM_WRITER_LE
#include "ttadata.h"
#include "ttaencdsp.h"
#include "avcodec.h"
#include "put_bits.h"
#include "internal.h"
#include "libavutil/crc.h"
typedef struct TTAEncContext {
    const AVCRC *crc_table;
    int bps;
    TTAChannel *ch_ctx;
    TTAEncDSPContext dsp;
} TTAEncContext;
#define PRED(x, k) (int32_t)((((uint64_t)(x) << (k)) - (x)) >> (k))
