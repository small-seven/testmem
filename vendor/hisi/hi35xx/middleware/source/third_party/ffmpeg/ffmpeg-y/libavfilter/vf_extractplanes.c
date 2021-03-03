#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "filters.h"
#include "internal.h"
#define PLANE_R 0x01
#define PLANE_G 0x02
#define PLANE_B 0x04
#define PLANE_A 0x08
#define PLANE_Y 0x10
#define PLANE_U 0x20
#define PLANE_V 0x40
typedef struct ExtractPlanesContext {
    const AVClass *class;
    int requested_planes;
    int map[4];
    int linesize[4];
    int is_packed;
    int depth;
    int step;
} ExtractPlanesContext;
#define OFFSET(x) offsetof(ExtractPlanesContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define EIGHTBIT_FORMATS                           \
#define HIGHDEPTH_FORMATS(suf)                                 \
#if CONFIG_ALPHAEXTRACT_FILTER
#endif  /* CONFIG_ALPHAEXTRACT_FILTER */
