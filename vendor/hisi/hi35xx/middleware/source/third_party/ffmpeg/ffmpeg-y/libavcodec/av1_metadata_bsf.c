#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_av1.h"
typedef struct AV1MetadataContext {
    const AVClass *class;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment access_unit;

    int td;

    int color_primaries;
    int transfer_characteristics;
    int matrix_coefficients;

    int color_range;
    int chroma_sample_position;

    AVRational tick_rate;
    int num_ticks_per_picture;

    int delete_padding;
} AV1MetadataContext;
#define OFFSET(x) offsetof(AV1MetadataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
