#include "avfilter.h"
#include "formats.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/avstring.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "internal.h"
#include "drawutils.h"
#include "framesync.h"
#include "video.h"
#include "vf_overlay.h"
typedef struct ThreadData {
    AVFrame *dst, *src;
} ThreadData;
#define MAIN    0
#define OVERLAY 1
#define R 0
#define G 1
#define B 2
#define A 3
#define Y 0
#define U 1
#define V 2
#define FAST_DIV255(x) ((((x) + 128) * 257) >> 16)
#define UNPREMULTIPLY_ALPHA(x, y) ((((x) << 16) - ((x) << 9) + (x)) / ((((x) + (y)) << 8) - ((x) + (y)) - (y) * (x)))
#define OFFSET(x) offsetof(OverlayContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
