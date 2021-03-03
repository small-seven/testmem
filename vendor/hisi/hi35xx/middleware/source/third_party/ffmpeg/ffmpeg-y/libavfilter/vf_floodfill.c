#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct Points {
    uint16_t x, y;
} Points;
typedef struct FloodfillContext {
    const AVClass *class;

    int x, y;
    int s0, s1, s2, s3;
    int d0, d1, d2, d3;

    int back, front;
    Points *points;

    int (*is_same)(AVFrame *frame, int x, int y,
                   unsigned s0, unsigned s1, unsigned s2, unsigned s3);
    void (*set_pixel)(AVFrame *frame, int x, int y,
                      unsigned d0, unsigned d1, unsigned d2, unsigned d3);
    void (*pick_pixel)(AVFrame *frame, int x, int y,
                       int *s0, int *s1, int *s2, int *s3);
} FloodfillContext;
#define OFFSET(x) offsetof(FloodfillContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
