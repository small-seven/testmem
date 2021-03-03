#include "avcodec.h"
#include "internal.h"
#include "bytestream.h"
#include "libavutil/lfg.h"
#include "elbg.h"
#include "libavutil/imgutils.h"
typedef struct Msvideo1EncContext {
    AVCodecContext *avctx;
    AVLFG rnd;
    uint8_t *prev;

    int block[16*3];
    int block2[16*3];
    int codebook[8*3];
    int codebook2[8*3];
    int output[16*3];
    int output2[16*3];
    int avg[3];
    int bestpos;
    int keyint;
} Msvideo1EncContext;
#define SKIP_PREFIX 0x8400
#define SKIPS_MAX 0x03FF
#define MKRGB555(in, off) (((in)[off] << 10) | ((in)[(off) + 1] << 5) | ((in)[(off) + 2]))
