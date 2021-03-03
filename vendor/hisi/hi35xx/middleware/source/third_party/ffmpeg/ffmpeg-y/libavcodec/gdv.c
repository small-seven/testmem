#include "libavutil/common.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct GDVContext {
    AVCodecContext *avctx;

    GetByteContext gb;
    GetByteContext g2;
    PutByteContext pb;

    uint32_t pal[256];
    uint8_t *frame;
    unsigned frame_size;
    unsigned scale_h, scale_v;
} GDVContext;
typedef struct Bits8 {
    uint8_t queue;
    uint8_t fill;
} Bits8;
typedef struct Bits32 {
    uint32_t queue;
    uint8_t  fill;
} Bits32;
#define PREAMBLE_SIZE 4096
