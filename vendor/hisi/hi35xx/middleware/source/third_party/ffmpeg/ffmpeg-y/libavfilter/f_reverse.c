#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define DEFAULT_LENGTH 300
typedef struct ReverseContext {
    int nb_frames;
    AVFrame **frames;
    unsigned int frames_size;
    unsigned int pts_size;
    int64_t *pts;
    int flush_idx;
} ReverseContext;
#if CONFIG_REVERSE_FILTER
#endif /* CONFIG_REVERSE_FILTER */
#if CONFIG_AREVERSE_FILTER
#endif /* CONFIG_AREVERSE_FILTER */
