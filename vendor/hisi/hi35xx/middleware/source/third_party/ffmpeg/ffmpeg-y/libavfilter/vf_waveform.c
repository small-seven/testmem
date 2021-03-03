#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/xga_font_data.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct ThreadData {
    AVFrame *in;
    AVFrame *out;
    int component;
    int offset_y;
    int offset_x;
} ThreadData;
typedef struct GraticuleLine {
    const char *name;
    uint16_t pos;
} GraticuleLine;
typedef struct GraticuleLines {
    struct GraticuleLine line[4];
} GraticuleLines;
typedef struct WaveformContext {
    const AVClass *class;
    int            mode;
    int            acomp;
    int            dcomp;
    int            ncomp;
    int            pcomp;
    uint8_t        bg_color[4];
    float          fintensity;
    int            intensity;
    int            mirror;
    int            display;
    int            envelope;
    int            graticule;
    float          opacity;
    float          bgopacity;
    int            estart[4];
    int            eend[4];
    int            *emax[4][4];
    int            *emin[4][4];
    int            *peak;
    int            filter;
    int            flags;
    int            bits;
    int            max;
    int            size;
    int            scale;
    uint8_t        grat_yuva_color[4];
    int            shift_w[4], shift_h[4];
    GraticuleLines *glines;
    int            nb_glines;
    int            rgb;

    int (*waveform_slice)(AVFilterContext *ctx, void *arg,
                          int jobnr, int nb_jobs);
    void (*graticulef)(struct WaveformContext *s, AVFrame *out);
    const AVPixFmtDescriptor *desc;
    const AVPixFmtDescriptor *odesc;
} WaveformContext;
#define OFFSET(x) offsetof(WaveformContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define LOWPASS16_FUNC(name, column, mirror)        \
#define LOWPASS_FUNC(name, column, mirror)        \
#define FLAT16_FUNC(name, column, mirror)        \
#define FLAT_FUNC(name, column, mirror)        \
#define AFLAT16(name, update_cr, column, mirror)                                                                   \
#define AFLAT(name, update_cr, column, mirror)                                                        \
#define CHROMA16_FUNC(name, column, mirror)      \
#define CHROMA_FUNC(name, column, mirror)        \
#define COLOR16_FUNC(name, column, mirror)       \
#define COLOR_FUNC(name, column, mirror)       \
#define ACOLOR16_FUNC(name, column, mirror)      \
#define ACOLOR_FUNC(name, column, mirror)        \
