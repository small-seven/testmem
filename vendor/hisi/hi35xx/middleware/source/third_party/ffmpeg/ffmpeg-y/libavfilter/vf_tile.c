#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "video.h"
#include "internal.h"
typedef struct TileContext {
    const AVClass *class;
    unsigned w, h;
    unsigned margin;
    unsigned padding;
    unsigned overlap;
    unsigned init_padding;
    unsigned current;
    unsigned nb_frames;
    FFDrawContext draw;
    FFDrawColor blank;
    AVFrame *out_ref;
    AVFrame *prev_out_ref;
    uint8_t rgba_color[4];
} TileContext;
#define OFFSET(x) offsetof(TileContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
