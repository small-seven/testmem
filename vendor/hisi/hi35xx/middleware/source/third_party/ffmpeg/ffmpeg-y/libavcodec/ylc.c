#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "get_bits.h"
#include "huffyuvdsp.h"
#include "internal.h"
#include "thread.h"
#include "unary.h"
typedef struct YLCContext {
    VLC vlc[4];
    uint32_t table[1024];
    uint8_t *table_bits;
    uint8_t *bitstream_bits;
    int table_bits_size;
    int bitstream_bits_size;
    BswapDSPContext bdsp;
} YLCContext;
typedef struct Node {
    int16_t  sym;
    int16_t  n0;
    uint32_t count;
    int16_t  l, r;
} Node;
#if HAVE_THREADS
#endif
