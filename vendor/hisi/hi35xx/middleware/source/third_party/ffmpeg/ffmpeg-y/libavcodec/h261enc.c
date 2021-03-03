#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "h263.h"
#include "h261.h"
#include "mpegvideodata.h"
#define UNI_ENC_INDEX(last,run,level) ((last)*128*64 + (run)*128 + (level))
