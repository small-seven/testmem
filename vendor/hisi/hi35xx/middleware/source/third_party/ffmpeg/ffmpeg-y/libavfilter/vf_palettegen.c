#include "libavutil/avassert.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/qsort.h"
#include "libavutil/intreadwrite.h"
#include "avfilter.h"
#include "internal.h"
#define NBITS 5
#define HIST_SIZE (1<<(3*NBITS))
typedef struct PaletteGenContext {
    const AVClass *class;

    int max_colors;
    int reserve_transparent;
    int stats_mode;

    AVFrame *prev_frame;                    // previous frame used for the diff stats_mode
    struct hist_node histogram[HIST_SIZE];  // histogram/hashtable of the colors
    struct color_ref **refs;                // references of all the colors used in the stream
    int nb_refs;                            // number of color references (or number of different colors)
    struct range_box boxes[256];            // define the segmentation of the colorspace (the final palette)
    int nb_boxes;                           // number of boxes (increase will segmenting them)
    int palette_pushed;                     // if the palette frame is pushed into the outlink or not
    uint8_t transparency_color[4];          // background color for transparency
} PaletteGenContext;
#define OFFSET(x) offsetof(PaletteGenContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef int (*cmp_func)(const void *, const void *);

#define DECLARE_CMP_FUNC(name, pos)                     \
static int cmp_##name(const void *pa, const void *pb)   \
{                                                       \
    const struct color_ref * const *a = pa;             \
    const struct color_ref * const *b = pb;             \
    return   ((*a)->color >> (8 * (2 - (pos))) & 0xff)  \
           - ((*b)->color >> (8 * (2 - (pos))) & 0xff); \
}
