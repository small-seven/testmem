#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_mpeg2.h"
#include "mpeg12.h"
typedef struct MPEG2MetadataContext {
    const AVClass *class;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment fragment;

    MPEG2RawExtensionData sequence_display_extension;

    AVRational display_aspect_ratio;

    AVRational frame_rate;

    int video_format;
    int colour_primaries;
    int transfer_characteristics;
    int matrix_coefficients;

    int mpeg1_warned;
} MPEG2MetadataContext;
#define VALIDITY_CHECK(name) do { \
#undef VALIDITY_CHECK
#define OFFSET(x) offsetof(MPEG2MetadataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
