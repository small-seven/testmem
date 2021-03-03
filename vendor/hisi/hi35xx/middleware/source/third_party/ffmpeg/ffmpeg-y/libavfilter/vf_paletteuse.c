#include "libavutil/bprint.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/qsort.h"
#include "avfilter.h"
#include "filters.h"
#include "framesync.h"
#include "internal.h"
#define NBITS 5
#define CACHE_SIZE (1<<(3*NBITS))
typedef int (*set_frame_func)(struct PaletteUseContext *s, AVFrame *out, AVFrame *in,
                              int x_start, int y_start, int width, int height);

typedef struct PaletteUseContext {
    const AVClass *class;
    FFFrameSync fs;
    struct cache_node cache[CACHE_SIZE];    /* lookup cache */
    struct color_node map[AVPALETTE_COUNT]; /* 3D-Tree (KD-Tree with K=3) for reverse colormap */
    uint32_t palette[AVPALETTE_COUNT];
    int transparency_index; /* index in the palette of transparency. -1 if there is no transparency in the palette. */
    int trans_thresh;
    int palette_loaded;
    int dither;
    int new;
    set_frame_func set_frame;
    int bayer_scale;
    int ordered_dither[8*8];
    int diff_mode;
    AVFrame *last_in;
    AVFrame *last_out;

    /* debug options */
    char *dot_filename;
    int color_search_method;
    int calc_mean_err;
    uint64_t total_mean_err;
    int debug_accuracy;
} PaletteUseContext;
#define OFFSET(x) offsetof(PaletteUseContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define COLORMAP_NEAREST(search, palette, root, target, trans_thresh)                                    \
#define INDENT 4
typedef int (*cmp_func)(const void *, const void *);

#define DECLARE_CMP_FUNC(name, pos)                     \
static int cmp_##name(const void *pa, const void *pb)   \
{                                                       \
    const struct color *a = pa;                         \
    const struct color *b = pb;                         \
    return   (a->value >> (8 * (3 - (pos))) & 0xff)     \
           - (b->value >> (8 * (3 - (pos))) & 0xff);    \
}
#define DEFINE_SET_FRAME(color_search, name, value)                             \
#define DEFINE_SET_FRAME_COLOR_SEARCH(color_search, color_search_macro)                                 \
#define DITHERING_ENTRIES(color_search) {       \
