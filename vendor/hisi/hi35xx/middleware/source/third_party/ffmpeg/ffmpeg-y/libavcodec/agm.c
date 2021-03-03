#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "copy_block.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
typedef struct MotionVector {
    int16_t x, y;
} MotionVector;
typedef struct AGMContext {
    const AVClass  *class;
    AVCodecContext *avctx;
    GetBitContext   gb;
    GetByteContext  gbyte;

    int key_frame;
    int bitstream_size;
    int compression;
    int blocks_w;
    int blocks_h;
    int size[3];
    int plus;
    int dct;
    int rgb;
    unsigned flags;
    unsigned fflags;

    uint8_t *output;
    unsigned padded_output_size;
    unsigned output_size;

    MotionVector *mvectors;
    unsigned      mvectors_size;

    VLC vlc;

    AVFrame *prev_frame;

    int luma_quant_matrix[64];
    int chroma_quant_matrix[64];

    ScanTable scantable;
    DECLARE_ALIGNED(32, int16_t, block)[64];

    int16_t *wblocks;
    unsigned wblocks_size;

    int      *map;
    unsigned  map_size;

    IDCTDSPContext idsp;
} AGMContext;
typedef struct Node {
    int parent;
    int child[2];
} Node;
