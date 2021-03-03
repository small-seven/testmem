#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
#include "bytestream.h"
typedef struct FlashSVContext {
    AVCodecContext *avctx;
    uint8_t        *previous_frame;
    int             image_width, image_height;
    int             block_width, block_height;
    uint8_t        *tmpblock;
    uint8_t        *encbuffer;
    int             block_size;
    z_stream        zstream;
    int             last_key_frame;
} FlashSVContext;
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
