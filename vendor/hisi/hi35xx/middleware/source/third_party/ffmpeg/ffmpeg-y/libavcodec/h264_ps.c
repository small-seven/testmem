#include <inttypes.h>
#include "libavutil/imgutils.h"
#include "internal.h"
#include "mathops.h"
#include "avcodec.h"
#include "h264data.h"
#include "h264_ps.h"
#include "golomb.h"
#define MIN_LOG2_MAX_FRAME_NUM    4
#define EXTENDED_SAR       255
#if 0
#endif
#ifndef ALLOW_INTERLACE
#endif
