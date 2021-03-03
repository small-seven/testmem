#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/xga_font_data.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DatascopeContext {
    const AVClass *class;
    int ow, oh;
    int x, y;
    int mode;
    int axis;
    float opacity;

    int nb_planes;
    int nb_comps;
    int chars;
    FFDrawContext draw;
    FFDrawColor yellow;
    FFDrawColor white;
    FFDrawColor black;
    FFDrawColor gray;

    void (*pick_color)(FFDrawContext *draw, FFDrawColor *color, AVFrame *in, int x, int y, int *value);
    void (*reverse_color)(FFDrawContext *draw, FFDrawColor *color, FFDrawColor *reverse);
    int (*filter)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} DatascopeContext;
#define OFFSET(x) offsetof(DatascopeContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    AVFrame *in, *out;
    int xoff, yoff;
} ThreadData;
typedef struct PixscopeContext {
    const AVClass *class;

    float xpos, ypos;
    float wx, wy;
    int w, h;
    float o;

    int x, y;
    int ww, wh;

    int nb_planes;
    int nb_comps;
    int is_rgb;
    uint8_t rgba_map[4];
    FFDrawContext draw;
    FFDrawColor   dark;
    FFDrawColor   black;
    FFDrawColor   white;
    FFDrawColor   green;
    FFDrawColor   blue;
    FFDrawColor   red;
    FFDrawColor  *colors[4];

    void (*pick_color)(FFDrawContext *draw, FFDrawColor *color, AVFrame *in, int x, int y, int *value);
} PixscopeContext;
#define POFFSET(x) offsetof(PixscopeContext, x)
typedef struct PixelValues {
    uint16_t p[4];
} PixelValues;
typedef struct OscilloscopeContext {
    const AVClass *class;

    float xpos, ypos;
    float tx, ty;
    float size;
    float tilt;
    float theight, twidth;
    float o;
    int components;
    int grid;
    int statistics;
    int scope;

    int x1, y1, x2, y2;
    int ox, oy;
    int height, width;

    int max;
    int nb_planes;
    int nb_comps;
    int is_rgb;
    uint8_t rgba_map[4];
    FFDrawContext draw;
    FFDrawColor   dark;
    FFDrawColor   black;
    FFDrawColor   white;
    FFDrawColor   green;
    FFDrawColor   blue;
    FFDrawColor   red;
    FFDrawColor   cyan;
    FFDrawColor   magenta;
    FFDrawColor   gray;
    FFDrawColor  *colors[4];

    int nb_values;
    PixelValues  *values;

    void (*pick_color)(FFDrawContext *draw, FFDrawColor *color, AVFrame *in, int x, int y, int *value);
    void (*draw_trace)(struct OscilloscopeContext *s, AVFrame *frame);
} OscilloscopeContext;
#define OOFFSET(x) offsetof(OscilloscopeContext, x)
