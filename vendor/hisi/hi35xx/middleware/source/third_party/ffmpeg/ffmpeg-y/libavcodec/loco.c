#include "avcodec.h"
#include "get_bits.h"
#include "golomb.h"
#include "internal.h"
#include "mathops.h"
typedef struct LOCOContext {
    AVCodecContext *avctx;
    int lossy;
    enum LOCO_MODE mode;
} LOCOContext;
typedef struct RICEContext {
    GetBitContext gb;
    int save, run, run2; /* internal rice decoder state */
    int sum, count; /* sum and count for getting rice parameter */
    int lossy;
} RICEContext;
#define ADVANCE_BY_DECODED do { \
