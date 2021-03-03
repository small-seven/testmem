#include "libavutil/internal.h"
#include "avcodec.h"
#include "internal.h"
#include "nvenc.h"
#define OFFSET(x) offsetof(NvencContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#ifdef NVENC_HAVE_HEVC_BFRAME_REF_MODE
#else
#endif
#if FF_API_NVENC_OLD_NAME
#endif
