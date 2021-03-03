#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "libavutil/avassert.h"
#include "libavutil/avutil.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/rational.h"
#include "libavutil/time.h"
#include "libavutil/time_internal.h"
#include "av1.h"
#include "avc.h"
#include "avformat.h"
#include "avio_internal.h"
#include "hlsplaylist.h"
#if CONFIG_HTTP_PROTOCOL
#include "http.h"
#endif
#include "internal.h"
#include "isom.h"
#include "os_support.h"
#include "url.h"
#include "vpcc.h"
#include "dash.h"
typedef enum {
    SEGMENT_TYPE_AUTO = 0,
    SEGMENT_TYPE_MP4,
    SEGMENT_TYPE_WEBM,
    SEGMENT_TYPE_NB
} SegmentType;
typedef struct Segment {
    char file[1024];
    int64_t start_pos;
    int range_length, index_length;
    int64_t time;
    double prog_date_time;
    int64_t duration;
    int n;
} Segment;
typedef struct AdaptationSet {
    char id[10];
    enum AVMediaType media_type;
    AVDictionary *metadata;
    AVRational min_frame_rate, max_frame_rate;
    int ambiguous_frame_rate;
} AdaptationSet;
typedef struct OutputStream {
    AVFormatContext *ctx;
    int ctx_inited, as_idx;
    AVIOContext *out;
    int packets_written;
    char initfile[1024];
    int64_t init_start_pos, pos;
    int init_range_length;
    int nb_segments, segments_size, segment_index;
    Segment **segments;
    int64_t first_pts, start_pts, max_pts;
    int64_t last_dts, last_pts;
    int bit_rate;
    SegmentType segment_type;  /* segment type selected for this particular stream */
    const char *format_name;
    const char *extension_name;
    const char *single_file_name;  /* file names selected for this particular stream */
    const char *init_seg_name;
    const char *media_seg_name;

    char codec_str[100];
    int written_len;
    char filename[1024];
    char full_path[1024];
    char temp_path[1024];
    double availability_time_offset;
    int total_pkt_size;
    int muxer_overhead;
} OutputStream;
typedef struct DASHContext {
    const AVClass *class;  /* Class for private options. */
    char *adaptation_sets;
    AdaptationSet *as;
    int nb_as;
    int window_size;
    int extra_window_size;
#if FF_API_DASH_MIN_SEG_DURATION
    int min_seg_duration;
#endif
    int64_t seg_duration;
    int remove_at_exit;
    int use_template;
    int use_timeline;
    int single_file;
    OutputStream *streams;
    int has_video;
    int64_t last_duration;
    int64_t total_duration;
    char availability_start_time[100];
    time_t start_time_s;
    char dirname[1024];
    const char *single_file_name;  /* file names as specified in options */
    const char *init_seg_name;
    const char *media_seg_name;
    const char *utc_timing_url;
    const char *method;
    const char *user_agent;
    int hls_playlist;
    int http_persistent;
    int master_playlist_created;
    AVIOContext *mpd_out;
    AVIOContext *m3u8_out;
    int streaming;
    int64_t timeout;
    int index_correction;
    char *format_options_str;
    int global_sidx;
    SegmentType segment_type_option;  /* segment type as specified in options */
    int ignore_io_errors;
    int lhls;
    int master_publish_rate;
    int nr_of_streams_to_flush;
    int nr_of_streams_flushed;
} DASHContext;
#if CONFIG_HTTP_PROTOCOL
#endif
#if CONFIG_HTTP_PROTOCOL
#endif
static void dash_free(AVFormatContext *s)
{
    DASHContext *c = s->priv_data;
    int i, j;

    if (c->as) {
        for (i = 0; i < c->nb_as; i++)
            av_dict_free(&c->as[i].metadata);
        av_freep(&c->as);
        c->nb_as = 0;
    }

    if (!c->streams)
        return;
    for (i = 0; i < s->nb_streams; i++) {
        OutputStream *os = &c->streams[i];
        if (os->ctx && os->ctx->pb) {
            if (!c->single_file)
                ffio_free_dyn_buf(&os->ctx->pb);
            else
                avio_close(os->ctx->pb);
        }
        ff_format_io_close(s, &os->out);
        if (os->ctx)
            avformat_free_context(os->ctx);
        for (j = 0; j < os->nb_segments; j++)
            av_free(os->segments[j]);
        av_free(os->segments);
        av_freep(&os->single_file_name);
        av_freep(&os->init_seg_name);
        av_freep(&os->media_seg_name);
    }
    av_freep(&c->streams);

    ff_format_io_close(s, &c->mpd_out);
    ff_format_io_close(s, &c->m3u8_out);
}
#if FF_API_DASH_MIN_SEG_DURATION
#endif
#define OFFSET(x) offsetof(DASHContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_DASH_MIN_SEG_DURATION
#endif
