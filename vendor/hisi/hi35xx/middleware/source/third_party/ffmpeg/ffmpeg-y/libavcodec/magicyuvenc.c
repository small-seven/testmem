#include <stdlib.h>
#include <string.h>
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/qsort.h"
#include "avcodec.h"
#include "bytestream.h"
#include "put_bits.h"
#include "internal.h"
#include "thread.h"
#include "lossless_videoencdsp.h"
typedef enum Prediction {
    LEFT = 1,
    GRADIENT,
    MEDIAN,
} Prediction;
typedef struct HuffEntry {
    uint8_t  sym;
    uint8_t  len;
    uint32_t code;
} HuffEntry;
typedef struct PTable {
    int     value;  ///< input value
    int64_t prob;   ///< number of occurences of this value in input
} PTable;
typedef struct MagicYUVContext {
    const AVClass       *class;
    int                  frame_pred;
    PutBitContext        pb;
    int                  planes;
    uint8_t              format;
    AVFrame             *p;
    int                  slice_height;
    int                  nb_slices;
    int                  correlate;
    int                  hshift[4];
    int                  vshift[4];
    uint8_t             *slices[4];
    unsigned             slice_pos[4];
    unsigned             tables_size;
    HuffEntry            he[4][256];
    LLVidEncDSPContext   llvidencdsp;
    void (*predict)(struct MagicYUVContext *s, uint8_t *src, uint8_t *dst,
                    ptrdiff_t stride, int width, int height);
} MagicYUVContext;
typedef struct PackageMergerList {
    int nitems;             ///< number of items in the list and probability      ex. 4
    int item_idx[515];      ///< index range for each item in items                   0, 2, 5, 9, 13
    int probability[514];   ///< probability of each item                             3, 8, 18, 46
    int items[257 * 16];    ///< chain of all individual values that make up items    A, B, A, B, C, A, B, C, D, C, D, D, E
} PackageMergerList;
#define OFFSET(x) offsetof(MagicYUVContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
