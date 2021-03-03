#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define MM_PREAMBLE_SIZE    6
#define MM_TYPE_INTER       0x5
#define MM_TYPE_INTRA       0x8
#define MM_TYPE_INTRA_HH    0xc
#define MM_TYPE_INTER_HH    0xd
#define MM_TYPE_INTRA_HHV   0xe
#define MM_TYPE_INTER_HHV   0xf
#define MM_TYPE_PALETTE     0x31
typedef struct MmContext {
    AVCodecContext *avctx;
    AVFrame *frame;
    unsigned int palette[AVPALETTE_COUNT];
    GetByteContext gb;
} MmContext;
