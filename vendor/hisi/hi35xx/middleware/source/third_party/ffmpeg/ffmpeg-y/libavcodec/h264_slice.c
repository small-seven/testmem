#include "libavutil/avassert.h"
#include "libavutil/display.h"
#include "libavutil/imgutils.h"
#include "libavutil/stereo3d.h"
#include "libavutil/timer.h"
#include "internal.h"
#include "cabac.h"
#include "cabac_functions.h"
#include "error_resilience.h"
#include "avcodec.h"
#include "h264.h"
#include "h264dec.h"
#include "h264data.h"
#include "h264chroma.h"
#include "h264_mvpred.h"
#include "h264_ps.h"
#include "golomb.h"
#include "mathops.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "rectangle.h"
#include "thread.h"
#define IN_RANGE(a, b, size) (((void*)(a) >= (void*)(b)) && ((void*)(a) < (void*)((b) + (size))))
#define REBASE_PICTURE(pic, new_ctx, old_ctx)             \
#define TRANSPOSE(x) ((x) >> 2) | (((x) << 2) & 0xF)
#undef TRANSPOSE
#define TRANSPOSE(x) ((x) >> 3) | (((x) & 7) << 3)
#undef TRANSPOSE
#define HWACCEL_MAX (CONFIG_H264_DXVA2_HWACCEL + \
#if CONFIG_H264_VDPAU_HWACCEL
#endif
#if CONFIG_H264_NVDEC_HWACCEL
#endif
#if CONFIG_H264_DXVA2_HWACCEL
#endif
#if CONFIG_H264_D3D11VA_HWACCEL
#endif
#if CONFIG_H264_VAAPI_HWACCEL
#endif
#if CONFIG_H264_VIDEOTOOLBOX_HWACCEL
#endif
#if 1
#else
#endif
