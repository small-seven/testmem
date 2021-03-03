#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "get_bits.h"
#include "internal.h"
typedef struct JvContext {
    BlockDSPContext bdsp;
    AVFrame   *frame;
    uint32_t   palette[AVPALETTE_COUNT];
    int        palette_has_changed;
} JvContext;
