#include "libavutil/attributes.h"
#include "libavutil/mem.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef struct Escape130Context {
    uint8_t *old_y_avg;

    uint8_t *new_y, *old_y;
    uint8_t *new_u, *old_u;
    uint8_t *new_v, *old_v;

    uint8_t *buf1, *buf2;
    int     linesize[3];
} Escape130Context;
