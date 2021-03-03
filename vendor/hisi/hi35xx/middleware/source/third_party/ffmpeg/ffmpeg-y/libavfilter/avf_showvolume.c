#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/xga_font_data.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "audio.h"
#include "video.h"
#include "internal.h"
typedef struct ShowVolumeContext {
    const AVClass *class;
    int w, h;
    int b;
    double f;
    AVRational frame_rate;
    char *color;
    int orientation;
    int step;
    float bgopacity;
    int mode;

    int nb_samples;
    AVFrame *out;
    AVExpr *c_expr;
    int draw_text;
    int draw_volume;
    double *values;
    uint32_t *color_lut;
    float *max;
    float rms_factor;
    int display_scale;

    double draw_persistent_duration; /* in second */
    uint8_t persistant_max_rgba[4];
    int persistent_max_frames; /* number of frames to check max value */
    float *max_persistent; /* max value for draw_persistent_max for each channel */
    int *nb_frames_max_display; /* number of frame for each channel, for displaying the max value */

    void (*meter)(float *src, int nb_samples, float *max, float factor);
} ShowVolumeContext;
#define OFFSET(x) offsetof(ShowVolumeContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
