#include <math.h>
#include "libavutil/common.h"
#include "libavutil/ffmath.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "celp_filters.h"
#include "internal.h"
#include "libavutil/lfg.h"
typedef struct CNGContext {
    float *refl_coef, *target_refl_coef;
    float *lpc_coef;
    int order;
    int energy, target_energy;
    int inited;
    float *filter_out;
    float *excitation;
    AVLFG lfg;
} CNGContext;
