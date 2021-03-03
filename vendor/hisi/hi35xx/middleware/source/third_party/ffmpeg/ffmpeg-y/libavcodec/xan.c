#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#define RUNTIME_GAMMA 0
#define VGA__TAG MKTAG('V', 'G', 'A', ' ')
#define PALT_TAG MKTAG('P', 'A', 'L', 'T')
#define SHOT_TAG MKTAG('S', 'H', 'O', 'T')
#define PALETTE_COUNT 256
#define PALETTE_SIZE (PALETTE_COUNT * 3)
#define PALETTES_MAX 256
typedef struct XanContext {

    AVCodecContext *avctx;
    AVFrame *last_frame;

    const uint8_t *buf;
    int size;

    /* scratch space */
    uint8_t *buffer1;
    int buffer1_size;
    uint8_t *buffer2;
    int buffer2_size;

    unsigned *palettes;
    int palettes_count;
    int cur_palette;

    int frame_size;

} XanContext;
#if RUNTIME_GAMMA
#else
#endif
#if RUNTIME_GAMMA
#else
#endif
