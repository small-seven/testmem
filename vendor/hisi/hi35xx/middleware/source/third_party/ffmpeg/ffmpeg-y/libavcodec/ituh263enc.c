#include <limits.h>
#include "libavutil/attributes.h"
#include "avcodec.h"
#include "mpegvideo.h"
#include "mpegvideodata.h"
#include "h263.h"
#include "h263data.h"
#include "mathops.h"
#include "mpegutils.h"
#include "flv.h"
#include "mpeg4video.h"
#include "internal.h"
#define UNI_MPEG4_ENC_INDEX(last,run,level) ((last)*128*64 + (run)*128 + (level))
