#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define SCREEN_WIDE 640
#define SCREEN_HIGH 429
typedef struct BMVDecContext {
    AVCodecContext *avctx;

    uint8_t *frame, frame_base[SCREEN_WIDE * (SCREEN_HIGH + 1)];
    uint32_t pal[256];
    const uint8_t *stream;
} BMVDecContext;
#define NEXT_BYTE(v) (v) = forward ? (v) + 1 : (v) - 1;
