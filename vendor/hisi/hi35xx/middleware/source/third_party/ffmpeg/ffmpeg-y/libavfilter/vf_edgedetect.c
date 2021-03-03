#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define PLANE_R 0x4
#define PLANE_G 0x1
#define PLANE_B 0x2
#define PLANE_Y 0x1
#define PLANE_U 0x2
#define PLANE_V 0x4
#define PLANE_A 0x8
typedef struct EdgeDetectContext {
    const AVClass *class;
    struct plane_info planes[3];
    int filter_planes;
    int nb_planes;
    double   low, high;
    uint8_t  low_u8, high_u8;
    int mode;
} EdgeDetectContext;
#define OFFSET(x) offsetof(EdgeDetectContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define COPY_MAXIMA(ay, ax, by, bx) do {                \
