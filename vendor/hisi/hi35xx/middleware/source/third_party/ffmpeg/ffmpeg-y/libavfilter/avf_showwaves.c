#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "audio.h"
#include "video.h"
#include "internal.h"
typedef struct ShowWavesContext {
    const AVClass *class;
    int w, h;
    AVRational rate;
    char *colors;
    int buf_idx;
    int16_t *buf_idy;    /* y coordinate of previous sample for each channel */
    AVFrame *outpicref;
    int n;
    int pixstep;
    int sample_count_mod;
    int mode;                   ///< ShowWavesMode
    int scale;                  ///< ShowWavesScale
    int draw_mode;              ///< ShowWavesDrawMode
    int split_channels;
    uint8_t *fg;

    int (*get_h)(int16_t sample, int height);
    void (*draw_sample)(uint8_t *buf, int height, int linesize,
                        int16_t *prev_y, const uint8_t color[4], int h);

    /* single picture */
    int single_pic;
    struct frame_node *audio_frames;
    struct frame_node *last_frame;
    int64_t total_samples;
    int64_t *sum; /* abs sum of the samples per channel */
} ShowWavesContext;
#define OFFSET(x) offsetof(ShowWavesContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_SHOWWAVES_FILTER
#endif // CONFIG_SHOWWAVES_FILTER
#if CONFIG_SHOWWAVESPIC_FILTER
#define OFFSET(x) offsetof(ShowWavesContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#endif // CONFIG_SHOWWAVESPIC_FILTER
