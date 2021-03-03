#include <ass/ass.h>
#include "config.h"
#if CONFIG_SUBTITLES_FILTER
# include "libavcodec/avcodec.h"
# include "libavformat/avformat.h"
#endif
#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "drawutils.h"
#include "avfilter.h"
#include "internal.h"
#include "formats.h"
#include "video.h"
typedef struct AssContext {
    const AVClass *class;
    ASS_Library  *library;
    ASS_Renderer *renderer;
    ASS_Track    *track;
    char *filename;
    char *fontsdir;
    char *charenc;
    char *force_style;
    int stream_index;
    int alpha;
    uint8_t rgba_map[4];
    int     pix_step[4];       ///< steps per pixel for each plane of the main output
    int original_w, original_h;
    int shaping;
    FFDrawContext draw;
} AssContext;
#define OFFSET(x) offsetof(AssContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define COMMON_OPTIONS \
#define AR(c)  ( (c)>>24)
#define AG(c)  (((c)>>16)&0xFF)
#define AB(c)  (((c)>>8) &0xFF)
#define AA(c)  ((0xFF-(c)) &0xFF)
#if CONFIG_ASS_FILTER
#endif
#if CONFIG_SUBTITLES_FILTER
#endif
