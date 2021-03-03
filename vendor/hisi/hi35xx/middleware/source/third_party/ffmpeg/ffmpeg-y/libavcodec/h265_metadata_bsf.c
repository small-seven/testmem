#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_h265.h"
#include "hevc.h"
#include "h265_profile_level.h"
typedef struct H265MetadataContext {
    const AVClass *class;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment access_unit;

    H265RawAUD aud_nal;

    int aud;

    AVRational sample_aspect_ratio;

    int video_format;
    int video_full_range_flag;
    int colour_primaries;
    int transfer_characteristics;
    int matrix_coefficients;

    int chroma_sample_loc_type;

    AVRational tick_rate;
    int poc_proportional_to_timing_flag;
    int num_ticks_poc_diff_one;

    int crop_left;
    int crop_right;
    int crop_top;
    int crop_bottom;

    int level;
    int level_guess;
    int level_warned;
} H265MetadataContext;
#define SET_OR_INFER(field, value, present_flag, infer) do { \
#define CROP(border, unit) do { \
#undef CROP
#define OFFSET(x) offsetof(H265MetadataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
#define LEVEL(name, value) name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef LEVEL
