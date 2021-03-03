#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef enum CinVideoBitmapIndex {
    CIN_CUR_BMP = 0, /* current */
    CIN_PRE_BMP = 1, /* previous */
    CIN_INT_BMP = 2  /* intermediate */
} CinVideoBitmapIndex;
typedef struct CinVideoContext {
    AVCodecContext *avctx;
    AVFrame *frame;
    unsigned int bitmap_size;
    uint32_t palette[256];
    uint8_t *bitmap_table[3];
} CinVideoContext;
