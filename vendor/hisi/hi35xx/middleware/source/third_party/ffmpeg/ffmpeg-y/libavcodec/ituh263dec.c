#define UNCHECKED_BITSTREAM_READER 1
#include <limits.h>
#include "libavutil/attributes.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "avcodec.h"
#include "mpegvideo.h"
#include "h263.h"
#include "h263data.h"
#include "internal.h"
#include "mathops.h"
#include "mpegutils.h"
#include "unary.h"
#include "flv.h"
#include "rv10.h"
#include "mpeg4video.h"
#include "mpegvideodata.h"
#define MV_VLC_BITS 9
#define H263_MBTYPE_B_VLC_BITS 6
#define CBPC_B_VLC_BITS 3
#define tab_size ((signed)FF_ARRAY_ELEMS(s->direct_scale_mv[0]))
#define tab_bias (tab_size / 2)
