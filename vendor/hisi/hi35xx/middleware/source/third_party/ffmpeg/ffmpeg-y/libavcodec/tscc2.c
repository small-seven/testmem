#include <inttypes.h>
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "mathops.h"
#include "tscc2data.h"
typedef struct TSCC2Context {
    AVCodecContext *avctx;
    AVFrame       *pic;
    int            mb_width, mb_height;
    uint8_t        *slice_quants;
    int            quant[2];
    int            q[2][3];
    GetBitContext  gb;

    VLC            dc_vlc, nc_vlc[NUM_VLC_SETS], ac_vlc[NUM_VLC_SETS];
    int            block[16];
} TSCC2Context;
#define DEQUANT(val, q) (((q) * (val) + 0x80) >> 8)
#define DCT1D(d0, d1, d2, d3, s0, s1, s2, s3, OP) \
#define COL_OP(a, b)  a = (b)
#define ROW_OP(a, b)  a = ((b) + 0x20) >> 6
