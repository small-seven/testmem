#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/thread.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "copy_block.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
typedef struct IMM4Context {
    BswapDSPContext bdsp;
    GetBitContext  gb;

    AVFrame *prev_frame;
    uint8_t *bitstream;
    int bitstream_size;

    int factor;
    unsigned lo;
    unsigned hi;

    ScanTable intra_scantable;
    DECLARE_ALIGNED(32, int16_t, block)[6][64];
    IDCTDSPContext idsp;
} IMM4Context;
