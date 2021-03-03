#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "unsharp.h"
typedef struct TheadData {
    UnsharpFilterParam *fp;
    uint8_t       *dst;
    const uint8_t *src;
    int dst_stride;
    int src_stride;
    int width;
    int height;
} ThreadData;
#define OFFSET(x) offsetof(UnsharpContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define MIN_SIZE 3
#define MAX_SIZE 23
