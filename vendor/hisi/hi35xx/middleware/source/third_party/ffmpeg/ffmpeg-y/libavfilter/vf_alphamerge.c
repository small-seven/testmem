#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/pixfmt.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "filters.h"
#include "internal.h"
#include "video.h"
typedef struct AlphaMergeContext {
    int is_packed_rgb;
    uint8_t rgba_map[4];
    AVFrame *main_frame;
    AVFrame *alpha_frame;
} AlphaMergeContext;
