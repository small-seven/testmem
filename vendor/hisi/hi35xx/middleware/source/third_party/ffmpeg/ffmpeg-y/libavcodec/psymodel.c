#include <string.h>
#include "avcodec.h"
#include "psymodel.h"
#include "iirfilter.h"
#include "libavutil/mem.h"
typedef struct FFPsyPreprocessContext{
    AVCodecContext *avctx;
    float stereo_att;
    struct FFIIRFilterCoeffs *fcoeffs;
    struct FFIIRFilterState **fstate;
    struct FFIIRFilterContext fiir;
}FFPsyPreprocessContext;
#define FILT_ORDER 4
