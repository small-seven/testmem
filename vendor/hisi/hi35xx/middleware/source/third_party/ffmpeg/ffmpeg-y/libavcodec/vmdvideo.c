#include <string.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include "bytestream.h"
#define VMD_HEADER_SIZE 0x330
#define PALETTE_COUNT 256
typedef struct VmdVideoContext {

    AVCodecContext *avctx;
    AVFrame *prev_frame;

    const unsigned char *buf;
    int size;

    unsigned char palette[PALETTE_COUNT * 4];
    unsigned char *unpack_buffer;
    int unpack_buffer_size;

    int x_off, y_off;
} VmdVideoContext;
#define QUEUE_SIZE 0x1000
#define QUEUE_MASK 0x0FFF
