#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timecode.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#define LINE_DATA_SIZE 9
typedef struct ReadVitcContext {
    const AVClass *class;

    int scan_max;
    double thr_b;
    double thr_w;

    int threshold_black;
    int threshold_white;
    int threshold_gray;
    int grp_width;
    uint8_t line_data[LINE_DATA_SIZE];
    char tcbuf[AV_TIMECODE_STR_SIZE];
} ReadVitcContext;
#define OFFSET(x) offsetof(ReadVitcContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
