#include "libavutil/intmath.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "snow_dwt.h"
#include "internal.h"
#include "snow.h"
#include "rangecoder.h"
#include "mathops.h"
#include "mpegvideo.h"
#include "h263.h"
#define GET_S(dst, check) \