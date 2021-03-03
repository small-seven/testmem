#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "bsf.h"
typedef struct ProresMetadataContext {
    const AVClass *class;

    int color_primaries;
    int transfer_characteristics;
    int matrix_coefficients;
} ProresMetadataContext;
#define OFFSET(x) offsetof(ProresMetadataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_BSF_PARAM)
