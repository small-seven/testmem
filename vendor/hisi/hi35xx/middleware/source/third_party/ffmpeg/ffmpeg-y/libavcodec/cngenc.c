#include <math.h>
#include "libavutil/common.h"
#include "avcodec.h"
#include "internal.h"
#include "lpc.h"
typedef struct CNGContext {
    LPCContext lpc;
    int order;
    int32_t *samples32;
    double *ref_coef;
} CNGContext;
