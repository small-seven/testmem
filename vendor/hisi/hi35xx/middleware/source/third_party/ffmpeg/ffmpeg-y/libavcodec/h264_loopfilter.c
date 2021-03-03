#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "internal.h"
#include "avcodec.h"
#include "h264dec.h"
#include "h264_ps.h"
#include "mathops.h"
#include "mpegutils.h"
#include "rectangle.h"
#define FILTER(hv,dir,edge,intra)\
#undef FILTER
#if CONFIG_SMALL
#else
#endif
#if CONFIG_SMALL
#else
#endif
