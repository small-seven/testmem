#include <stdint.h>
#include "libavutil/crc.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/random_seed.h"
#include "libavcodec/xiph.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/flac.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "vorbiscomment.h"
#define MAX_PAGE_SIZE 65025
typedef struct OGGPage {
    int64_t start_granule;
    int64_t granule;
    int stream_index;
    uint8_t flags;
    uint8_t segments_count;
    uint8_t segments[255];
    uint8_t data[MAX_PAGE_SIZE];
    uint16_t size;
} OGGPage;
typedef struct OGGStreamContext {
    unsigned page_counter;
    uint8_t *header[3];
    int header_len[3];
    /** for theora granule */
    int kfgshift;
    int64_t last_kf_pts;
    int vrev;
    /* for VP8 granule */
    int isvp8;
    int eos;
    unsigned page_count; ///< number of page buffered
    OGGPage page; ///< current page
    unsigned serial_num; ///< serial number
    int64_t last_granule; ///< last packet granule
} OGGStreamContext;
typedef struct OGGPageList {
    OGGPage page;
    struct OGGPageList *next;
} OGGPageList;
typedef struct OGGContext {
    const AVClass *class;
    OGGPageList *page_list;
    int pref_size; ///< preferred page size (0 => fill all segments)
    int64_t pref_duration;      ///< preferred page duration (0 => fill all segments)
    int serial_offset;
} OGGContext;
#define OFFSET(x) offsetof(OGGContext, x)
#define PARAM AV_OPT_FLAG_ENCODING_PARAM
#define OGG_CLASS(flavor, name)\
#define SPEEX_HEADER_SIZE 80
#define OPUS_HEADER_SIZE 19
#define VP8_HEADER_SIZE 26
static void ogg_free(AVFormatContext *s)
{
    int i;

    for (i = 0; i < s->nb_streams; i++) {
        AVStream *st = s->streams[i];
        OGGStreamContext *oggstream = st->priv_data;
        if (!oggstream)
            continue;
        if (st->codecpar->codec_id == AV_CODEC_ID_FLAC ||
            st->codecpar->codec_id == AV_CODEC_ID_SPEEX ||
            st->codecpar->codec_id == AV_CODEC_ID_OPUS ||
            st->codecpar->codec_id == AV_CODEC_ID_VP8) {
            av_freep(&oggstream->header[0]);
        }
        av_freep(&oggstream->header[1]);
        av_freep(&st->priv_data);
    }
}
#if CONFIG_OGG_MUXER
#if !CONFIG_OGV_MUXER
#endif
#if !CONFIG_SPX_MUXER
#endif
#if !CONFIG_OPUS_MUXER
#endif
#endif
#if CONFIG_OGA_MUXER
#endif
#if CONFIG_OGV_MUXER
#endif
#if CONFIG_SPX_MUXER
#endif
#if CONFIG_OPUS_MUXER
#endif
