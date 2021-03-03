#include <inttypes.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "libavutil/dict.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "avio_internal.h"
#include "avlanguage.h"
#include "id3v2.h"
#include "internal.h"
#include "riff.h"
#include "asf.h"
#include "asfcrypt.h"
typedef struct ASFPayload {
    uint8_t type;
    uint16_t size;
} ASFPayload;
typedef struct ASFStream {
    int num;
    unsigned char seq;
    /* use for reading */
    AVPacket pkt;
    int frag_offset;
    int packet_obj_size;
    int timestamp;
    int64_t duration;
    int skip_to_key;
    int pkt_clean;

    int ds_span;                /* descrambling  */
    int ds_packet_size;
    int ds_chunk_size;

    int64_t packet_pos;

    uint16_t stream_language_index;

    int      palette_changed;
    uint32_t palette[256];

    int payload_ext_ct;
    ASFPayload payload[8];
} ASFStream;
typedef struct ASFContext {
    const AVClass *class;
    int asfid2avid[128];                 ///< conversion table from asf ID 2 AVStream ID
    ASFStream streams[128];              ///< it's max number and it's not that big
    uint32_t stream_bitrates[128];       ///< max number of streams, bitrate for each (for streaming)
    AVRational dar[128];
    char stream_languages[128][6];       ///< max number of streams, language for each (RFC1766, e.g. en-US)
    /* non streamed additonnal info */
    /* packet filling */
    int packet_size_left;
    /* only for reading */
    uint64_t data_offset;                ///< beginning of the first data packet
    uint64_t data_object_offset;         ///< data object offset (excl. GUID & size)
    uint64_t data_object_size;           ///< size of the data object
    int index_read;

    ASFMainHeader hdr;

    int packet_flags;
    int packet_property;
    int packet_timestamp;
    int packet_segsizetype;
    int packet_segments;
    int packet_seq;
    int packet_replic_size;
    int packet_key_frame;
    int packet_padsize;
    unsigned int packet_frag_offset;
    unsigned int packet_frag_size;
    int64_t packet_frag_timestamp;
    int ts_is_pts;
    int packet_multi_size;
    int packet_time_delta;
    int packet_time_start;
    int64_t packet_pos;

    int stream_index;

    ASFStream *asf_st;                   ///< currently decoded stream

    int no_resync_search;
    int export_xmp;

    int uses_std_ecc;
} ASFContext;
#undef NDEBUG
#include <assert.h>
#define ASF_MAX_STREAMS 127
#define FRAME_HEADER_SIZE 6
#ifdef DEBUG
#define PRINT_IF_GUID(g, cmp) \
#undef PRINT_IF_GUID
#else
#define print_guid(g) while(0)
#endif
#define LEN 22
#if HAVE_BIGENDIAN
#else
#endif
#define DO_2BITS(bits, var, defval)             \
