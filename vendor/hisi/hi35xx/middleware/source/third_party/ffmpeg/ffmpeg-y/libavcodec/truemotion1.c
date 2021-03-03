#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "truemotion1data.h"
typedef struct TrueMotion1Context {
    AVCodecContext *avctx;
    AVFrame *frame;

    const uint8_t *buf;
    int size;

    const uint8_t *mb_change_bits;
    int mb_change_bits_row_size;
    const uint8_t *index_stream;
    int index_stream_size;

    int flags;
    int x, y, w, h;

    uint32_t y_predictor_table[1024];
    uint32_t c_predictor_table[1024];
    uint32_t fat_y_predictor_table[1024];
    uint32_t fat_c_predictor_table[1024];

    int compression;
    int block_type;
    int block_width;
    int block_height;

    int16_t ydt[8];
    int16_t cdt[8];
    int16_t fat_ydt[8];
    int16_t fat_cdt[8];

    int last_deltaset, last_vectable;

    unsigned int *vert_pred;
    int vert_pred_size;

} TrueMotion1Context;
#define FLAG_SPRITE         32
#define FLAG_KEYFRAME       16
#define FLAG_INTERFRAME      8
#define FLAG_INTERPOLATED    4
#define ALGO_NOP        0
#define ALGO_RGB16V     1
#define ALGO_RGB16H     2
#define ALGO_RGB24H     3
#define BLOCK_2x2  0
#define BLOCK_2x4  1
#define BLOCK_4x2  2
#define BLOCK_4x4  3
typedef struct comp_types {
    int algorithm;
    int block_width; // vres
    int block_height; // hres
    int block_type;
} comp_types;
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#define GET_NEXT_INDEX() \
#define INC_INDEX                                                   \
#define APPLY_C_PREDICTOR() \
#define APPLY_C_PREDICTOR_24() \
#define APPLY_Y_PREDICTOR() \
#define APPLY_Y_PREDICTOR_24() \
#define OUTPUT_PIXEL_PAIR() \
