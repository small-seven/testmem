#include <string.h>
#include <va/va.h>
#include <va/va_enc_h264.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "cbs.h"
#include "cbs_h264.h"
#include "h264.h"
#include "h264_levels.h"
#include "h264_sei.h"
#include "internal.h"
#include "vaapi_encode.h"
typedef struct VAAPIEncodeH264Picture {
    int frame_num;
    int pic_order_cnt;

    int64_t last_idr_frame;
    uint16_t idr_pic_id;

    int primary_pic_type;
    int slice_type;

    int cpb_delay;
    int dpb_delay;
} VAAPIEncodeH264Picture;
typedef struct VAAPIEncodeH264Context {
    VAAPIEncodeContext common;

    // User options.
    int qp;
    int quality;
    int coder;
    int aud;
    int sei;
    int profile;
    int level;

    // Derived settings.
    int mb_width;
    int mb_height;

    int fixed_qp_idr;
    int fixed_qp_p;
    int fixed_qp_b;

    int dpb_frames;

    // Writer structures.
    CodedBitstreamContext *cbc;
    CodedBitstreamFragment current_access_unit;

    H264RawAUD   raw_aud;
    H264RawSPS   raw_sps;
    H264RawPPS   raw_pps;
    H264RawSEI   raw_sei;
    H264RawSlice raw_slice;

    H264RawSEIBufferingPeriod      sei_buffering_period;
    H264RawSEIPicTiming            sei_pic_timing;
    H264RawSEIRecoveryPoint        sei_recovery_point;
    H264RawSEIUserDataUnregistered sei_identifier;
    char                          *sei_identifier_string;

    int aud_needed;
    int sei_needed;
    int sei_cbr_workaround_needed;
} VAAPIEncodeH264Context;
#if !CONFIG_VAAPI_1
#endif
#if !CONFIG_VAAPI_1
#endif
#define OFFSET(x) offsetof(VAAPIEncodeH264Context, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM)
#define PROFILE(name, value)  name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef PROFILE
#define LEVEL(name, value) name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef LEVEL
