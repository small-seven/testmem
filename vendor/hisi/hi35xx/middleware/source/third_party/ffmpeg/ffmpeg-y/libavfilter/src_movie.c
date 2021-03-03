#include <float.h>
#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/avstring.h"
#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/timestamp.h"
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct MovieStream {
    AVStream *st;
    AVCodecContext *codec_ctx;
    int done;
    int64_t discontinuity_threshold;
    int64_t last_pts;
} MovieStream;
typedef struct MovieContext {
    /* common A/V fields */
    const AVClass *class;
    int64_t seek_point;   ///< seekpoint in microseconds
    double seek_point_d;
    char *format_name;
    char *file_name;
    char *stream_specs; /**< user-provided list of streams, separated by + */
    int stream_index; /**< for compatibility */
    int loop_count;
    int64_t discontinuity_threshold;
    int64_t ts_offset;

    AVFormatContext *format_ctx;
    int eof;
    AVPacket pkt, pkt0;

    int max_stream_index; /**< max stream # actually used for output */
    MovieStream *st; /**< array of all streams, one per output */
    int *out_index; /**< stream number -> output number map, or -1 */
} MovieContext;
#define OFFSET(x) offsetof(MovieContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_MOVIE_FILTER
#endif  /* CONFIG_MOVIE_FILTER */
#if CONFIG_AMOVIE_FILTER
#define amovie_options movie_options
#endif /* CONFIG_AMOVIE_FILTER */
