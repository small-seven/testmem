#include "config.h"
#include <inttypes.h>
#include <stdio.h>
#include "libavutil/avstring.h"
#include "libavutil/base64.h"
#include "libavutil/dict.h"
#include "libavutil/intfloat.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lzo.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/time_internal.h"
#include "libavutil/spherical.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/flac.h"
#include "libavcodec/mpeg4audio.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "isom.h"
#include "matroska.h"
#include "oggdec.h"
#include "riff.h"
#include "rmsipr.h"
#if CONFIG_BZLIB
#include <bzlib.h>
#endif
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#include "qtpalette.h"
#define EBML_UNKNOWN_LENGTH  UINT64_MAX /* EBML unknown length, in uint64_t */
#define NEEDS_CHECKING                2 /* Indicates that some error checks
#define LEVEL_ENDED                   3 /* return value of ebml_parse when the
#define SKIP_THRESHOLD      1024 * 1024 /* In non-seekable mode, if more than SKIP_THRESHOLD
#define UNKNOWN_EQUIV         50 * 1024 /* An unknown element is considered equivalent
typedef enum {
    EBML_NONE,
    EBML_UINT,
    EBML_SINT,
    EBML_FLOAT,
    EBML_STR,
    EBML_UTF8,
    EBML_BIN,
    EBML_NEST,
    EBML_LEVEL1,
    EBML_STOP,
    EBML_TYPE_COUNT
} EbmlType;
typedef const struct EbmlSyntax {
    uint32_t id;
    EbmlType type;
    size_t list_elem_size;
    size_t data_offset;
    union {
        int64_t     i;
        uint64_t    u;
        double      f;
        const char *s;
        const struct EbmlSyntax *n;
    } def;
typedef struct EbmlList {
    int nb_elem;
    unsigned int alloc_elem_size;
    void *elem;
} EbmlList;
typedef struct EbmlBin {
    int      size;
    AVBufferRef *buf;
    uint8_t *data;
    int64_t  pos;
} EbmlBin;
typedef struct Ebml {
    uint64_t version;
    uint64_t max_size;
    uint64_t id_length;
    char    *doctype;
    uint64_t doctype_version;
} Ebml;
typedef struct MatroskaTrackCompression {
    uint64_t algo;
    EbmlBin  settings;
} MatroskaTrackCompression;
typedef struct MatroskaTrackEncryption {
    uint64_t algo;
    EbmlBin  key_id;
} MatroskaTrackEncryption;
typedef struct MatroskaTrackEncoding {
    uint64_t scope;
    uint64_t type;
    MatroskaTrackCompression compression;
    MatroskaTrackEncryption encryption;
} MatroskaTrackEncoding;
typedef struct MatroskaMasteringMeta {
    double r_x;
    double r_y;
    double g_x;
    double g_y;
    double b_x;
    double b_y;
    double white_x;
    double white_y;
    double max_luminance;
    double min_luminance;
} MatroskaMasteringMeta;
typedef struct MatroskaTrackVideoColor {
    uint64_t matrix_coefficients;
    uint64_t bits_per_channel;
    uint64_t chroma_sub_horz;
    uint64_t chroma_sub_vert;
    uint64_t cb_sub_horz;
    uint64_t cb_sub_vert;
    uint64_t chroma_siting_horz;
    uint64_t chroma_siting_vert;
    uint64_t range;
    uint64_t transfer_characteristics;
    uint64_t primaries;
    uint64_t max_cll;
    uint64_t max_fall;
    MatroskaMasteringMeta mastering_meta;
} MatroskaTrackVideoColor;
typedef struct MatroskaTrackVideoProjection {
    uint64_t type;
    EbmlBin private;
    double yaw;
    double pitch;
    double roll;
} MatroskaTrackVideoProjection;
typedef struct MatroskaTrackVideo {
    double   frame_rate;
    uint64_t display_width;
    uint64_t display_height;
    uint64_t pixel_width;
    uint64_t pixel_height;
    EbmlBin  color_space;
    uint64_t display_unit;
    uint64_t interlaced;
    uint64_t field_order;
    uint64_t stereo_mode;
    uint64_t alpha_mode;
    EbmlList color;
    MatroskaTrackVideoProjection projection;
} MatroskaTrackVideo;
typedef struct MatroskaTrackAudio {
    double   samplerate;
    double   out_samplerate;
    uint64_t bitdepth;
    uint64_t channels;

    /* real audio header (extracted from extradata) */
    int      coded_framesize;
    int      sub_packet_h;
    int      frame_size;
    int      sub_packet_size;
    int      sub_packet_cnt;
    int      pkt_cnt;
    uint64_t buf_timecode;
    uint8_t *buf;
} MatroskaTrackAudio;
typedef struct MatroskaTrackPlane {
    uint64_t uid;
    uint64_t type;
} MatroskaTrackPlane;
typedef struct MatroskaTrackOperation {
    EbmlList combine_planes;
} MatroskaTrackOperation;
typedef struct MatroskaTrack {
    uint64_t num;
    uint64_t uid;
    uint64_t type;
    char    *name;
    char    *codec_id;
    EbmlBin  codec_priv;
    char    *language;
    double time_scale;
    uint64_t default_duration;
    uint64_t flag_default;
    uint64_t flag_forced;
    uint64_t seek_preroll;
    MatroskaTrackVideo video;
    MatroskaTrackAudio audio;
    MatroskaTrackOperation operation;
    EbmlList encodings;
    uint64_t codec_delay;
    uint64_t codec_delay_in_track_tb;

    AVStream *stream;
    int64_t end_timecode;
    int ms_compat;
    uint64_t max_block_additional_id;

    uint32_t palette[AVPALETTE_COUNT];
    int has_palette;
} MatroskaTrack;
typedef struct MatroskaAttachment {
    uint64_t uid;
    char *filename;
    char *mime;
    EbmlBin bin;

    AVStream *stream;
} MatroskaAttachment;
typedef struct MatroskaChapter {
    uint64_t start;
    uint64_t end;
    uint64_t uid;
    char    *title;

    AVChapter *chapter;
} MatroskaChapter;
typedef struct MatroskaIndexPos {
    uint64_t track;
    uint64_t pos;
} MatroskaIndexPos;
typedef struct MatroskaIndex {
    uint64_t time;
    EbmlList pos;
} MatroskaIndex;
typedef struct MatroskaTag {
    char *name;
    char *string;
    char *lang;
    uint64_t def;
    EbmlList sub;
} MatroskaTag;
typedef struct MatroskaTagTarget {
    char    *type;
    uint64_t typevalue;
    uint64_t trackuid;
    uint64_t chapteruid;
    uint64_t attachuid;
} MatroskaTagTarget;
typedef struct MatroskaTags {
    MatroskaTagTarget target;
    EbmlList tag;
} MatroskaTags;
typedef struct MatroskaSeekhead {
    uint64_t id;
    uint64_t pos;
} MatroskaSeekhead;
typedef struct MatroskaLevel {
    uint64_t start;
    uint64_t length;
} MatroskaLevel;
typedef struct MatroskaBlock {
    uint64_t duration;
    int64_t  reference;
    uint64_t non_simple;
    EbmlBin  bin;
    uint64_t additional_id;
    EbmlBin  additional;
    int64_t  discard_padding;
} MatroskaBlock;
typedef struct MatroskaCluster {
    MatroskaBlock block;
    uint64_t timecode;
    int64_t pos;
} MatroskaCluster;
typedef struct MatroskaLevel1Element {
    int64_t  pos;
    uint32_t id;
    int parsed;
} MatroskaLevel1Element;
typedef struct MatroskaDemuxContext {
    const AVClass *class;
    AVFormatContext *ctx;

    /* EBML stuff */
    MatroskaLevel levels[EBML_MAX_DEPTH];
    int      num_levels;
    uint32_t current_id;
    int64_t  resync_pos;
    int      unknown_count;

    uint64_t time_scale;
    double   duration;
    char    *title;
    char    *muxingapp;
    EbmlBin  date_utc;
    EbmlList tracks;
    EbmlList attachments;
    EbmlList chapters;
    EbmlList index;
    EbmlList tags;
    EbmlList seekhead;

    /* byte position of the segment inside the stream */
    int64_t segment_start;

    /* the packet queue */
    AVPacketList *queue;
    AVPacketList *queue_end;

    int done;

    /* What to skip before effectively reading a packet. */
    int skip_to_keyframe;
    uint64_t skip_to_timecode;

    /* File has a CUES element, but we defer parsing until it is needed. */
    int cues_parsing_deferred;

    /* Level1 elements and whether they were read yet */
    MatroskaLevel1Element level1_elems[64];
    int num_level1_elems;

    MatroskaCluster current_cluster;

    /* WebM DASH Manifest live flag */
    int is_live;

    /* Bandwidth value for WebM DASH Manifest */
    int bandwidth;
} MatroskaDemuxContext;
#define CHILD_OF(parent) { .def = { .n = parent } }
#undef CHILD_OF
static void ebml_free(EbmlSyntax *syntax, void *data)
{
    int i, j;
    for (i = 0; syntax[i].id; i++) {
        void *data_off = (char *) data + syntax[i].data_offset;
        switch (syntax[i].type) {
        case EBML_STR:
        case EBML_UTF8:
            av_freep(data_off);
            break;
        case EBML_BIN:
            av_buffer_unref(&((EbmlBin *) data_off)->buf);
            break;
        case EBML_LEVEL1:
        case EBML_NEST:
            if (syntax[i].list_elem_size) {
                EbmlList *list = data_off;
                char *ptr = list->elem;
                for (j = 0; j < list->nb_elem;
                     j++, ptr += syntax[i].list_elem_size)
                    ebml_free(syntax[i].def.n, ptr);
                av_freep(&list->elem);
                list->nb_elem = 0;
                list->alloc_elem_size = 0;
            } else
                ebml_free(syntax[i].def.n, data_off);
        default:
            break;
        }
    }
}
#if CONFIG_LZO
#endif
#if CONFIG_ZLIB
#endif
#if CONFIG_BZLIB
#endif
#if CONFIG_ZLIB
#endif
#if CONFIG_BZLIB
#endif
#if CONFIG_LZO
#endif
#if FF_API_R_FRAME_RATE
#endif
#if FF_API_CONVERGENCE_DURATION
#endif
typedef struct {
    int64_t start_time_ns;
    int64_t end_time_ns;
    int64_t start_offset;
    int64_t end_offset;
} CueDesc;
#define OFFSET(x) offsetof(MatroskaDemuxContext, x)
