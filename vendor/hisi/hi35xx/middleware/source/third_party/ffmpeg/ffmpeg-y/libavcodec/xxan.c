#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct XanContext {
    AVCodecContext *avctx;
    AVFrame *pic;

    uint8_t *y_buffer;
    uint8_t *scratch_buffer;
    int     buffer_size;
    GetByteContext gb;
} XanContext;
