#include <string.h>
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define FALL 0
#define RISE 1
typedef struct ReadEIA608Context {
    const AVClass *class;
    int start, end;
    int min_range;
    int max_peak_diff;
    int max_period_diff;
    int max_start_diff;
    int nb_found;
    int white;
    int black;
    float mpd, mhd, msd, mac, spw, bhd, wth, bth;
    int chp;
    int lp;
    uint8_t *temp;
} ReadEIA608Context;
#define OFFSET(x) offsetof(ReadEIA608Context, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
