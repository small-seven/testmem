#include <inttypes.h>
#include "avcodec.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#define TM2_ESCAPE 0x80000000
#define TM2_DELTAS 64
typedef struct TM2Context {
    AVCodecContext *avctx;
    AVFrame *pic;

    GetBitContext gb;
    int error;
    BswapDSPContext bdsp;

    uint8_t *buffer;
    int buffer_size;

    /* TM2 streams */
    int *tokens[TM2_NUM_STREAMS];
    int tok_lens[TM2_NUM_STREAMS];
    int tok_ptrs[TM2_NUM_STREAMS];
    int deltas[TM2_NUM_STREAMS][TM2_DELTAS];
    /* for blocks decoding */
    int D[4];
    int CD[4];
    int *last;
    int *clast;

    /* data for current and previous frame */
    int *Y1_base, *U1_base, *V1_base, *Y2_base, *U2_base, *V2_base;
    int *Y1, *U1, *V1, *Y2, *U2, *V2;
    int y_stride, uv_stride;
    int cur;
} TM2Context;
typedef struct TM2Codes {
    VLC vlc; ///< table for FFmpeg bitstream reader
    int bits;
    int *recode; ///< table for converting from code indexes to values
    int length;
} TM2Codes;
typedef struct TM2Huff {
    int val_bits; ///< length of literal
    int max_bits; ///< maximum length of code
    int min_bits; ///< minimum length of code
    int nodes; ///< total number of nodes in tree
    int num; ///< current number filled
    int max_num; ///< total number of codes
    int *nums; ///< literals
    uint32_t *bits; ///< codes
    int *lens; ///< codelengths
} TM2Huff;
#define TM2_OLD_HEADER_MAGIC 0x00000100
#define TM2_NEW_HEADER_MAGIC 0x00000101
#define TM2_INIT_POINTERS() \
#define TM2_INIT_POINTERS_2() \
#define TM2_RECALC_BLOCK(CHR, stride, last, CD) {\
#define TM2_HEADER_SIZE 40
