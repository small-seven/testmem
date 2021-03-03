#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "mss34dsp.h"
#include "unary.h"
#define HEADER_SIZE 8
#define MAX_ENTRIES  162
typedef struct MSS4Context {
    AVFrame    *pic;

    VLC        dc_vlc[2], ac_vlc[2];
    VLC        vec_entry_vlc[2];
    int        block[64];
    uint8_t    imgbuf[3][16 * 16];

    int        quality;
    uint16_t   quant_mat[2][64];

    int        *prev_dc[3];
    ptrdiff_t  dc_stride[3];
    int        dc_cache[4][4];

    int        prev_vec[3][4];
} MSS4Context;
#define MKVAL(vals)  ((vals)[0] | ((vals)[1] << 3) | ((vals)[2] << 6))
