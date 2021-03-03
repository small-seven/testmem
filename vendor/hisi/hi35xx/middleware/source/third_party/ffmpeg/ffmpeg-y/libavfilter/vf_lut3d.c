#include "libavutil/opt.h"
#include "libavutil/file.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avstring.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
#define R 0
#define G 1
#define B 2
#define A 3
#define MAX_LEVEL 128
typedef struct LUT3DContext {
    const AVClass *class;
    int interpolation;          ///<interp_mode
    char *file;
    uint8_t rgba_map[4];
    int step;
    avfilter_action_func *interp;
    struct rgbvec scale;
    struct rgbvec lut[MAX_LEVEL][MAX_LEVEL][MAX_LEVEL];
    int lutsize;
#if CONFIG_HALDCLUT_FILTER
    uint8_t clut_rgba_map[4];
    int clut_step;
    int clut_bits;
    int clut_planar;
    int clut_width;
    FFFrameSync fs;
#endif
} LUT3DContext;
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
#define OFFSET(x) offsetof(LUT3DContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define COMMON_OPTIONS \
#define NEAR(x) ((int)((x) + .5))
#define PREV(x) ((int)(x))
#define NEXT(x) (FFMIN((int)(x) + 1, lut3d->lutsize - 1))
#define DEFINE_INTERP_FUNC_PLANAR(name, nbits, depth)                                                  \
#define DEFINE_INTERP_FUNC(name, nbits)                                                             \
#define MAX_LINE_SIZE 512
#define NEXT_LINE(loop_cond) do {                           \
#define SET_COLOR(id) do {                  \
#define SET_FUNC(name) do {                                     \
#if CONFIG_LUT3D_FILTER
#endif
#if CONFIG_HALDCLUT_FILTER
#define LOAD_CLUT(nbits) do {                                           \
#define LOAD_CLUT_PLANAR(nbits, depth) do {                             \
#endif
#if CONFIG_LUT1D_FILTER
#define MAX_1D_LEVEL 65536
typedef struct LUT1DContext {
    const AVClass *class;
    char *file;
    int interpolation;          ///<interp_1d_mode
    struct rgbvec scale;
    uint8_t rgba_map[4];
    int step;
    float lut[3][MAX_1D_LEVEL];
    int lutsize;
    avfilter_action_func *interp;
} LUT1DContext;
#undef OFFSET
#define OFFSET(x) offsetof(LUT1DContext, x)
#define NEXT1D(x) (FFMIN((int)(x) + 1, lut1d->lutsize - 1))
#define DEFINE_INTERP_FUNC_PLANAR_1D(name, nbits, depth)                     \
#define DEFINE_INTERP_FUNC_1D(name, nbits)                                   \
#define SET_FUNC_1D(name) do {                                     \
#endif
