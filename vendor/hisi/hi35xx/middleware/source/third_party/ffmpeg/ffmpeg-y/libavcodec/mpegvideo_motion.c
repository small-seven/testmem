#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "h261.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "mjpegenc.h"
#include "msmpeg4.h"
#include "qpeldsp.h"
#include "wmv2.h"
#include <limits.h>
#if !CONFIG_SMALL
#endif
#if !CONFIG_SMALL
#endif
#define OBMC_FILTER(x, t, l, m, r, b)\
#define OBMC_FILTER4(x, t, l, m, r, b)\
#define MID    0
#if !CONFIG_SMALL
#endif
