#include "config.h"
#include <float.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "os_support.h"
#include "avc.h"
#include "url.h"
#include "isom.h"
#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/file.h"
#include "libavutil/mathematics.h"
#include "libavutil/intreadwrite.h"
typedef struct Fragment {
    char file[1024];
    char infofile[1024];
    int64_t start_time, duration;
    int n;
    int64_t start_pos, size;
} Fragment;
typedef struct OutputStream {
    AVFormatContext *ctx;
    int ctx_inited;
    char dirname[1024];
    uint8_t iobuf[32768];
    URLContext *out;  // Current output stream where all output is written
    URLContext *out2; // Auxiliary output stream where all output is also written
    URLContext *tail_out; // The actual main output stream, if we're currently seeked back to write elsewhere
    int64_t tail_pos, cur_pos, cur_start_pos;
    int packets_written;
    const char *stream_type_tag;
    int nb_fragments, fragments_size, fragment_index;
    Fragment **fragments;

    const char *fourcc;
    char *private_str;
    int packet_size;
    int audio_tag;
} OutputStream;
typedef struct SmoothStreamingContext {
    const AVClass *class;  /* Class for private options. */
    int window_size;
    int extra_window_size;
    int lookahead_count;
    int min_frag_duration;
    int remove_at_exit;
    OutputStream *streams;
    int has_video, has_audio;
    int nb_fragments;
} SmoothStreamingContext;
static void ism_free(AVFormatContext *s)
{
    SmoothStreamingContext *c = s->priv_data;
    int i, j;
    if (!c->streams)
        return;
    for (i = 0; i < s->nb_streams; i++) {
        OutputStream *os = &c->streams[i];
        ffurl_close(os->out);
        ffurl_close(os->out2);
        ffurl_close(os->tail_out);
        os->out = os->out2 = os->tail_out = NULL;
        if (os->ctx && os->ctx_inited)
            av_write_trailer(os->ctx);
        if (os->ctx && os->ctx->pb)
            avio_context_free(&os->ctx->pb);
        if (os->ctx)
            avformat_free_context(os->ctx);
        av_freep(&os->private_str);
        for (j = 0; j < os->nb_fragments; j++)
            av_freep(&os->fragments[j]);
        av_freep(&os->fragments);
    }
    av_freep(&c->streams);
}
#define OFFSET(x) offsetof(SmoothStreamingContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
