#include "avcodec.h"
#include "get_bits.h"
#include "huffman.h"
#include "bytestream.h"
#include "bswapdsp.h"
#include "internal.h"
#include "thread.h"
#define FPS_TAG MKTAG('F', 'P', 'S', 'x')
#define VLC_BITS 11
typedef struct FrapsContext {
    AVCodecContext *avctx;
    BswapDSPContext bdsp;
    uint8_t *tmpbuf;
    int tmpbuf_size;
} FrapsContext;
