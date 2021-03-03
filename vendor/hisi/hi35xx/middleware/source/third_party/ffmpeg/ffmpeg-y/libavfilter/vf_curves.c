#include "libavutil/opt.h"
#include "libavutil/bprint.h"
#include "libavutil/eval.h"
#include "libavutil/file.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define R 0
#define G 1
#define B 2
#define A 3
#define NB_COMP 3
typedef struct CurvesContext {
    const AVClass *class;
    int preset;
    char *comp_points_str[NB_COMP + 1];
    char *comp_points_str_all;
    uint16_t *graph[NB_COMP + 1];
    int lut_size;
    char *psfile;
    uint8_t rgba_map[4];
    int step;
    char *plot_filename;
    int is_16bit;
    int depth;

    int (*filter_slice)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} CurvesContext;
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
#define OFFSET(x) offsetof(CurvesContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define CLIP(v) (nbits == 8 ? av_clip_uint8(v) : av_clip_uintp2_c(v, nbits))
#define BD 0 /* sub  diagonal (below main) */
#define MD 1 /* main diagonal (center) */
#define AD 2 /* sup  diagonal (above main) */
#define DECLARE_INTERPOLATE_FUNC(nbits)                                     \
#define READ16(dst) do {                \
#define SET_COMP_IF_NOT_SET(n, name) do {                           \
