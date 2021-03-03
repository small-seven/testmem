#include "libavutil/avstring.h"
#include "libavutil/display.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_h264.h"
#include "h264.h"
#include "h264_levels.h"
#include "h264_sei.h"
typedef struct H264MetadataContext {
    const AVClass *class;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment access_unit;

    int done_first_au;

    int aud;

    AVRational sample_aspect_ratio;

    int video_format;
    int video_full_range_flag;
    int colour_primaries;
    int transfer_characteristics;
    int matrix_coefficients;

    int chroma_sample_loc_type;

    AVRational tick_rate;
    int fixed_frame_rate_flag;

    int crop_left;
    int crop_right;
    int crop_top;
    int crop_bottom;

    const char *sei_user_data;

    int delete_filler;

    int display_orientation;
    double rotate;
    int flip;

    int level;
} H264MetadataContext;
#define SET_OR_INFER(field, value, present_flag, infer) do { \
#define CROP(border, unit) do { \
#undef CROP
#define OFFSET(x) offsetof(H264MetadataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
#define LEVEL(name, value) name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef LEVEL
