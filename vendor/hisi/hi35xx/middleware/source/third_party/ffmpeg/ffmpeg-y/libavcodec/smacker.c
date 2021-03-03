#include <stdio.h>
#include <stdlib.h>
#include "libavutil/channel_layout.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "mathops.h"
#define SMKTREE_BITS 9
#define SMK_NODE 0x80000000
#define SMKTREE_DECODE_MAX_RECURSION 32
#define SMKTREE_DECODE_BIG_MAX_RECURSION 500
typedef struct SmackVContext {
    AVCodecContext *avctx;
    AVFrame *pic;

    int *mmap_tbl, *mclr_tbl, *full_tbl, *type_tbl;
    int mmap_last[3], mclr_last[3], full_last[3], type_last[3];
} SmackVContext;
typedef struct HuffContext {
    int length;
    int maxlength;
    int current;
    uint32_t *bits;
    int *lengths;
    int *values;
} HuffContext;
typedef struct DBCtx {
    VLC *v1, *v2;
    int *recode1, *recode2;
    int escapes[3];
    int *last;
    int lcur;
} DBCtx;
