#include "libavutil/file.h"
#include "libavutil/internal.h"
#include "libavutil/lfg.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/random_seed.h"
#include "libavutil/avstring.h"
#include "avfilter.h"
#include "internal.h"
#include "formats.h"
#include "video.h"
typedef struct CellAutoContext {
    const AVClass *class;
    int w, h;
    char *filename;
    char *rule_str;
    uint8_t *file_buf;
    size_t file_bufsize;
    uint8_t *buf;
    int buf_prev_row_idx, buf_row_idx;
    uint8_t rule;
    uint64_t pts;
    AVRational frame_rate;
    double   random_fill_ratio;
    uint32_t random_seed;
    int stitch, scroll, start_full;
    int64_t generation;         ///< the generation number, starting from 0
    AVLFG lfg;
    char *pattern;
} CellAutoContext;
#define OFFSET(x) offsetof(CellAutoContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
