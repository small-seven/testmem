#define UNCHECKED_BITSTREAM_READER 1
#include "libavutil/avassert.h"
#include "libavutil/display.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/stereo3d.h"
#include "libavutil/timer.h"
#include "internal.h"
#include "bytestream.h"
#include "cabac.h"
#include "cabac_functions.h"
#include "error_resilience.h"
#include "avcodec.h"
#include "h264.h"
#include "h264dec.h"
#include "h2645_parse.h"
#include "h264data.h"
#include "h264chroma.h"
#include "h264_mvpred.h"
#include "h264_ps.h"
#include "golomb.h"
#include "hwaccel.h"
#include "mathops.h"
#include "me_cmp.h"
#include "mpegutils.h"
#include "profiles.h"
#include "rectangle.h"
#include "thread.h"
#if HAVE_THREADS
#endif
#if CONFIG_ERROR_RESILIENCE
#endif /* CONFIG_ERROR_RESILIENCE */
#define OFFSET(x) offsetof(H264Context, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_H264_DXVA2_HWACCEL
#endif
#if CONFIG_H264_D3D11VA_HWACCEL
#endif
#if CONFIG_H264_D3D11VA2_HWACCEL
#endif
#if CONFIG_H264_NVDEC_HWACCEL
#endif
#if CONFIG_H264_VAAPI_HWACCEL
#endif
#if CONFIG_H264_VDPAU_HWACCEL
#endif
#if CONFIG_H264_VIDEOTOOLBOX_HWACCEL
#endif
