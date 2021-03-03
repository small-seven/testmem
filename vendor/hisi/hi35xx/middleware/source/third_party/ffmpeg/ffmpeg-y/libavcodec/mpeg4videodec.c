#define UNCHECKED_BITSTREAM_READER 1
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "error_resilience.h"
#include "hwaccel.h"
#include "idctdsp.h"
#include "internal.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "mpegvideodata.h"
#include "mpeg4video.h"
#include "h263.h"
#include "profiles.h"
#include "thread.h"
#include "xvididct.h"
#include "unary.h"
#define SPRITE_TRAJ_VLC_BITS 6
#define DC_VLC_BITS 9
#define MB_TYPE_B_VLC_BITS 4
#define STUDIO_INTRA_BITS 9
#if 0
#endif
#define SET_QPEL_FUNC(postfix1, postfix2)                           \
#if HAVE_THREADS
#endif
#if CONFIG_MPEG4_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG4_VAAPI_HWACCEL
#endif
#if CONFIG_MPEG4_VDPAU_HWACCEL
#endif
#if CONFIG_MPEG4_VIDEOTOOLBOX_HWACCEL
#endif
