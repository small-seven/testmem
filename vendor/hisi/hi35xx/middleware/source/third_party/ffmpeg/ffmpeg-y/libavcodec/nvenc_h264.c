#include "libavutil/internal.h"
#include "avcodec.h"
#include "internal.h"
#include "nvenc.h"
#define OFFSET(x) offsetof(NvencContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#ifdef NVENC_HAVE_BFRAME_REF_MODE
#else
#endif
#if FF_API_NVENC_OLD_NAME
#if CONFIG_NVENC_ENCODER
#endif
#if CONFIG_NVENC_H264_ENCODER
#endif
#endif
