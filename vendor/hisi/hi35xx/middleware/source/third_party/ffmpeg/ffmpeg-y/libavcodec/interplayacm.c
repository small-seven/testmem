#include "libavutil/intreadwrite.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef struct InterplayACMContext {
    GetBitContext gb;
    uint8_t *bitstream;
    int max_framesize;
    int bitstream_size;
    int bitstream_index;

    int level;
    int rows;
    int cols;
    int wrapbuf_len;
    int block_len;
    int skip;

    int *block;
    int *wrapbuf;
    int *ampbuf;
    int *midbuf;
} InterplayACMContext;
#define set_pos(s, r, c, idx) do {               \
typedef int (*filler)(InterplayACMContext *s, unsigned ind, unsigned col);

static const filler filler_list[] = {
    zero,   bad,    bad,    linear,
    linear, linear, linear, linear,
    linear, linear, linear, linear,
    linear, linear, linear, linear,
    linear, k13,    k12,    t15,
    k24,    k23,    t27,    k35,
    k34,    bad,    k45,    k44,
    bad,    t37,    bad,    bad,
};
