#include "libavutil/file.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lfg.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/random_seed.h"
#include "libavutil/avstring.h"
#include "avfilter.h"
#include "internal.h"
#include "formats.h"
#include "video.h"
typedef struct LifeContext {
    const AVClass *class;
    int w, h;
    char *filename;
    char *rule_str;
    uint8_t *file_buf;
    size_t file_bufsize;

    /**
     * The two grid state buffers.
     *
     * A 0xFF (ALIVE_CELL) value means the cell is alive (or new born), while
     * the decreasing values from 0xFE to 0 means the cell is dead; the range
     * of values is used for the slow death effect, or mold (0xFE means dead,
     * 0xFD means very dead, 0xFC means very very dead... and 0x00 means
     * definitely dead/mold).
     */
    uint8_t *buf[2];

    uint8_t  buf_idx;
    uint16_t stay_rule;         ///< encode the behavior for filled cells
    uint16_t born_rule;         ///< encode the behavior for empty cells
    uint64_t pts;
    AVRational frame_rate;
    double   random_fill_ratio;
    uint32_t random_seed;
    int stitch;
    int mold;
    uint8_t  life_color[4];
    uint8_t death_color[4];
    uint8_t  mold_color[4];
    AVLFG lfg;
    void (*draw)(AVFilterContext*, AVFrame*);
} LifeContext;
#define ALIVE_CELL 0xFF
#define OFFSET(x) offsetof(LifeContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#ifdef DEBUG
#endif
#define FAST_DIV255(x) ((((x) + 128) * 257) >> 16)
#ifdef DEBUG
#endif
