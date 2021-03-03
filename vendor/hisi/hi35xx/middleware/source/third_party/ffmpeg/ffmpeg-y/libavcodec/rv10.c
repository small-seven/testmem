#include <inttypes.h>
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "error_resilience.h"
#include "h263.h"
#include "h263data.h"
#include "internal.h"
#include "mpeg_er.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "mpeg4video.h"
#include "mpegvideodata.h"
#include "rv10.h"
#define RV_GET_MAJOR_VER(x)  ((x) >> 28)
#define RV_GET_MINOR_VER(x) (((x) >> 20) & 0xFF)
#define RV_GET_MICRO_VER(x) (((x) >> 12) & 0xFF)
#define DC_VLC_BITS 14 // FIXME find a better solution
typedef struct RVDecContext {
    MpegEncContext m;
    int sub_id;
    int orig_width, orig_height;
} RVDecContext;
#define ERROR_SKIP_FRAME -123
