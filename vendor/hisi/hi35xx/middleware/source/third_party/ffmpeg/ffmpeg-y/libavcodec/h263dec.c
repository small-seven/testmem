#define UNCHECKED_BITSTREAM_READER 1
#include "libavutil/cpu.h"
#include "avcodec.h"
#include "error_resilience.h"
#include "flv.h"
#include "h263.h"
#include "h263_parser.h"
#include "hwaccel.h"
#include "internal.h"
#include "mpeg_er.h"
#include "mpeg4video.h"
#include "mpeg4video_parser.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "msmpeg4.h"
#include "qpeldsp.h"
#include "thread.h"
#include "wmv2.h"
#if CONFIG_H263_VAAPI_HWACCEL || CONFIG_MPEG4_VAAPI_HWACCEL
#endif
#if CONFIG_MPEG4_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG4_VDPAU_HWACCEL
#endif
#if CONFIG_H263_VIDEOTOOLBOX_HWACCEL || CONFIG_MPEG4_VIDEOTOOLBOX_HWACCEL
#endif
#if CONFIG_H263_VAAPI_HWACCEL
#endif
#if CONFIG_MPEG4_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG4_VDPAU_HWACCEL
#endif
#if CONFIG_H263_VIDEOTOOLBOX_HWACCEL
#endif
