#include <string.h>
#include <va/va.h>
#include <va/va_enc_hevc.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "libavutil/mastering_display_metadata.h"
#include "avcodec.h"
#include "cbs.h"
#include "cbs_h265.h"
#include "h265_profile_level.h"
#include "hevc.h"
#include "hevc_sei.h"
#include "internal.h"
#include "put_bits.h"
#include "vaapi_encode.h"
typedef struct VAAPIEncodeH265Picture {
    int pic_order_cnt;

    int64_t last_idr_frame;

    int slice_nal_unit;
    int slice_type;
    int pic_type;
} VAAPIEncodeH265Picture;
typedef struct VAAPIEncodeH265Context {
    VAAPIEncodeContext common;

    // User options.
    int qp;
    int aud;
    int profile;
    int tier;
    int level;
    int sei;

    // Derived settings.
    int fixed_qp_idr;
    int fixed_qp_p;
    int fixed_qp_b;

    // Writer structures.
    H265RawAUD   raw_aud;
    H265RawVPS   raw_vps;
    H265RawSPS   raw_sps;
    H265RawPPS   raw_pps;
    H265RawSEI   raw_sei;
    H265RawSlice raw_slice;

    H265RawSEIMasteringDisplayColourVolume sei_mastering_display;
    H265RawSEIContentLightLevelInfo        sei_content_light_level;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment current_access_unit;
    int aud_needed;
    int sei_needed;
} VAAPIEncodeH265Context;
#if VA_CHECK_VERSION(0, 37, 0)
#endif
#define OFFSET(x) offsetof(VAAPIEncodeH265Context, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM)
#define PROFILE(name, value)  name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef PROFILE
#define LEVEL(name, value) name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef LEVEL
