#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/fifo.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct LoopContext {
    const AVClass *class;

    AVAudioFifo *fifo;
    AVAudioFifo *left;
    AVFrame **frames;
    int nb_frames;
    int current_frame;
    int64_t start_pts;
    int64_t duration;
    int64_t current_sample;
    int64_t nb_samples;
    int64_t ignored_samples;

    int loop;
    int eof;
    int64_t size;
    int64_t start;
    int64_t pts;
} LoopContext;
#define AFLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define VFLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define OFFSET(x) offsetof(LoopContext, x)
#if CONFIG_ALOOP_FILTER
#endif /* CONFIG_ALOOP_FILTER */
#if CONFIG_LOOP_FILTER
#endif /* CONFIG_LOOP_FILTER */
