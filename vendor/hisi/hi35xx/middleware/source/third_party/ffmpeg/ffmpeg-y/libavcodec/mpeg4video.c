#include "mpegutils.h"
#include "mpegvideo.h"
#include "mpeg4video.h"
#include "mpeg4data.h"
#define tab_size ((signed)FF_ARRAY_ELEMS(s->direct_scale_mv[0]))
#define tab_bias (tab_size / 2)
#undef tab_size
#undef tab_bias
