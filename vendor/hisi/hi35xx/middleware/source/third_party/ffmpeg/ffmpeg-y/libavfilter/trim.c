#include <stdint.h>
#include "config.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/log.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct TrimContext {
    const AVClass *class;

    /*
     * AVOptions
     */
    int64_t duration;
    int64_t start_time, end_time;
    int64_t start_frame, end_frame;
    /*
     * in the link timebase for video,
     * in 1/samplerate for audio
     */
    int64_t start_pts, end_pts;
    int64_t start_sample, end_sample;

    /*
     * number of video frames that arrived on this filter so far
     */
    int64_t nb_frames;
    /*
     * number of audio samples that arrived on this filter so far
     */
    int64_t nb_samples;
    /*
     * timestamp of the first frame in the output, in the timebase units
     */
    int64_t first_pts;
    /*
     * duration in the timebase units
     */
    int64_t duration_tb;

    int64_t next_pts;

    int eof;
} TrimContext;
#define OFFSET(x) offsetof(TrimContext, x)
#define COMMON_OPTS                                                                                                                                                         \
#if CONFIG_TRIM_FILTER
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#undef FLAGS
#endif // CONFIG_TRIM_FILTER
#if CONFIG_ATRIM_FILTER
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#undef FLAGS
#endif // CONFIG_ATRIM_FILTER
