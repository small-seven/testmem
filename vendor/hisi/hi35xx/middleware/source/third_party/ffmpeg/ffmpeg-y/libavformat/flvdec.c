#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "libavutil/intfloat.h"
#include "libavutil/mathematics.h"
#include "libavutil/time_internal.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/mpeg4audio.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#include "flv.h"
#define VALIDATE_INDEX_TS_THRESH 2500
#define RESYNC_BUFFER_SIZE (1<<20)
typedef struct FLVContext {
    const AVClass *class; ///< Class for private options.
    int trust_metadata;   ///< configure streams according onMetaData
    int trust_datasize;   ///< trust data size of FLVTag
    int dump_full_metadata;   ///< Dump full metadata of the onMetadata
    int wrong_dts;        ///< wrong dts due to negative cts
    uint8_t *new_extradata[FLV_STREAM_TYPE_NB];
    int new_extradata_size[FLV_STREAM_TYPE_NB];
    int last_sample_rate;
    int last_channels;
    struct {
        int64_t dts;
        int64_t pos;
    } validate_index[2];
typedef struct amf_date {
    double   milliseconds;
    int16_t  timezone;
} amf_date;
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#define TYPE_ONTEXTDATA 1
#define TYPE_ONCAPTION 2
#define TYPE_ONCAPTIONINFO 3
#define TYPE_UNKNOWN 9
#define OFFSET(x) offsetof(FLVContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
