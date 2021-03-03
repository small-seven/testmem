#include "config.h"
#include <float.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "os_support.h"
#include "libavutil/avstring.h"
#include "libavutil/base64.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
typedef struct Fragment {
    char file[1024];
    int64_t start_time, duration;
    int n;
} Fragment;
typedef struct OutputStream {
    int bitrate;
    int first_stream;
    AVFormatContext *ctx;
    int ctx_inited;
    uint8_t iobuf[32768];
    char temp_filename[1024];
    int64_t frag_start_ts, last_ts;
    AVIOContext *out;
    int packets_written;
    int nb_fragments, fragments_size, fragment_index;
    Fragment **fragments;

    int has_audio, has_video;

    uint8_t *metadata;
    int metadata_size;

    uint8_t *extra_packets[2];
    int extra_packet_sizes[2];
    int nb_extra_packets;
} OutputStream;
typedef struct HDSContext {
    const AVClass *class;  /* Class for private options. */
    int window_size;
    int extra_window_size;
    int min_frag_duration;
    int remove_at_exit;

    OutputStream *streams;
    int nb_streams;
} HDSContext;
static void hds_free(AVFormatContext *s)
{
    HDSContext *c = s->priv_data;
    int i, j;
    if (!c->streams)
        return;
    for (i = 0; i < s->nb_streams; i++) {
        OutputStream *os = &c->streams[i];
        if (os->out)
            ff_format_io_close(s, &os->out);
        if (os->ctx && os->ctx_inited)
            av_write_trailer(os->ctx);
        if (os->ctx)
            avio_context_free(&os->ctx->pb);
        if (os->ctx)
            avformat_free_context(os->ctx);
        av_freep(&os->metadata);
        for (j = 0; j < os->nb_extra_packets; j++)
            av_freep(&os->extra_packets[j]);
        for (j = 0; j < os->nb_fragments; j++)
            av_freep(&os->fragments[j]);
        av_freep(&os->fragments);
    }
    av_freep(&c->streams);
}
#define OFFSET(x) offsetof(HDSContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
