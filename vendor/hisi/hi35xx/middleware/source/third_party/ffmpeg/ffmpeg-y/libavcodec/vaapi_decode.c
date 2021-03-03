#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "decode.h"
#include "internal.h"
#include "vaapi_decode.h"
#define MAP(va, av) { VA_FOURCC_ ## va, AV_PIX_FMT_ ## av }
#ifdef VA_FOURCC_I420
#endif
#ifdef VA_FOURCC_YV16
#endif
#ifdef VA_FOURCC_P010
#endif
#ifdef VA_FOURCC_I010
#endif
#undef MAP
#define MAP(c, p, v) { AV_CODEC_ID_ ## c, FF_PROFILE_ ## p, VAProfile ## v }
#if VA_CHECK_VERSION(0, 37, 0)
#endif
#if VA_CHECK_VERSION(0, 38, 0)
#endif
#if VA_CHECK_VERSION(0, 39, 0)
#endif
#undef MAP
#if FF_API_STRUCT_VAAPI_CONTEXT
#endif
#if FF_API_STRUCT_VAAPI_CONTEXT
#endif
#if FF_API_STRUCT_VAAPI_CONTEXT
#endif
#if FF_API_STRUCT_VAAPI_CONTEXT
#endif
#if FF_API_STRUCT_VAAPI_CONTEXT
#endif
