#define BITSTREAM_READER_LE
#include "aandcttab.h"
#include "avcodec.h"
#include "bytestream.h"
#include "eaidct.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
typedef struct TgqContext {
    AVCodecContext *avctx;
    int width, height;
    ScanTable scantable;
    int qtable[64];
    DECLARE_ALIGNED(16, int16_t, block)[6][64];
    GetByteContext gb;
} TgqContext;
