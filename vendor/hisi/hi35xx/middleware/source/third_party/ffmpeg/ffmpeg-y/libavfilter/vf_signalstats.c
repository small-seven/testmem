#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
typedef struct SignalstatsContext {
    const AVClass *class;
    int chromah;    // height of chroma plane
    int chromaw;    // width of chroma plane
    int hsub;       // horizontal subsampling
    int vsub;       // vertical subsampling
    int depth;      // pixel depth
    int fs;         // pixel count per frame
    int cfs;        // pixel count per frame of chroma planes
    int outfilter;  // FilterMode
    int filters;
    AVFrame *frame_prev;
    uint8_t rgba_color[4];
    int yuv_color[3];
    int nb_jobs;
    int *jobs_rets;

    int *histy, *histu, *histv, *histsat;

    AVFrame *frame_sat;
    AVFrame *frame_hue;
} SignalstatsContext;
typedef struct ThreadData {
    const AVFrame *in;
    AVFrame *out;
} ThreadData;
typedef struct ThreadDataHueSatMetrics {
    const AVFrame *src;
    AVFrame *dst_sat, *dst_hue;
} ThreadDataHueSatMetrics;
#define OFFSET(x) offsetof(SignalstatsContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define FILTER(i, j) \
#define FILTER3(j) (FILTER(-1, j) && FILTER(0, j) && FILTER(1, j))
#define VREP_START 4
#define DEPTH 256
#define SET_META(key, fmt, val) do {                                \
