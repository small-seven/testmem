#include <limits.h>
#include "avcodec.h"
#include "decode.h"
#include "internal.h"
#include "h264dec.h"
#include "vc1.h"
#include "vdpau.h"
#include "vdpau_internal.h"
#ifdef VDP_DECODER_PROFILE_H264_CONSTRAINED_BASELINE
#endif
#if CONFIG_MPEG1_VDPAU_HWACCEL || \
#endif
#if FF_API_VDPAU_PROFILE
#define PROFILE(prof)                      \
#ifdef VDP_DECODER_PROFILE_H264_EXTENDED
#endif
#undef PROFILE
#endif /* FF_API_VDPAU_PROFILE */
