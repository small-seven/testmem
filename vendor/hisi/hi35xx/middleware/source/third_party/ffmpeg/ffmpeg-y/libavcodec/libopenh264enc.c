#include <wels/codec_api.h>
#include <wels/codec_ver.h>
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "avcodec.h"
#include "internal.h"
#include "libopenh264.h"
#if !OPENH264_VER_AT_LEAST(1, 6)
#define SM_SIZELIMITED_SLICE SM_DYN_SLICE
#endif
typedef struct SVCContext {
    const AVClass *av_class;
    ISVCEncoder *encoder;
    int slice_mode;
    int loopfilter;
    char *profile;
    int max_nal_size;
    int skip_frames;
    int skipped;
    int cabac;
} SVCContext;
#define OFFSET(x) offsetof(SVCContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if OPENH264_VER_AT_LEAST(1, 6)
#else
#endif
#if OPENH264_VER_AT_LEAST(1, 6)
#else
#endif
#if FF_API_CODER_TYPE
#endif
#if OPENH264_VER_AT_LEAST(1, 4)
#else
#endif
#if OPENH264_VER_AT_LEAST(1, 7)
#endif
#if OPENH264_VER_AT_LEAST(1, 6)
#else
#endif
#if OPENH264_VER_AT_LEAST(1, 6)
#else
#endif
