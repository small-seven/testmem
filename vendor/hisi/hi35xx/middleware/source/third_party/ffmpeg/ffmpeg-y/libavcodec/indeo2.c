#include "libavutil/attributes.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "indeo2data.h"
#include "internal.h"
#include "mathops.h"
typedef struct Ir2Context{
    AVCodecContext *avctx;
    AVFrame *picture;
    GetBitContext gb;
    int decode_delta;
} Ir2Context;
#define CODE_VLC_BITS 14
#ifndef BITSTREAM_READER_LE
#endif
#ifdef BITSTREAM_READER_LE
#else
#endif
