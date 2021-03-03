#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef struct SeqVideoContext {
    AVCodecContext *avctx;
    AVFrame *frame;
} SeqVideoContext;
