#include "bytestream.h"
#include "internal.h"
typedef struct PSDContext {
    AVClass *class;
    AVFrame *picture;
    AVCodecContext *avctx;
    GetByteContext gb;

    uint8_t * tmp;

    uint16_t channel_count;
    uint16_t channel_depth;

    uint64_t uncompressed_size;
    unsigned int pixel_size;/* 1 for 8 bits, 2 for 16 bits */
    uint64_t line_size;/* length of src data (even width) */

    int width;
    int height;

    enum PsdCompr compression;
    enum PsdColorMode color_mode;

    uint8_t palette[AVPALETTE_SIZE];
} PSDContext;
