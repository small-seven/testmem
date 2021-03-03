#include "libavutil/avassert.h"
#include "libavutil/intfloat.h"
#include "libavutil/opt.h"
#include "libavutil/mathematics.h"
#include "libavutil/timecode.h"
#include "avformat.h"
#include "internal.h"
#include "gxf.h"
#include "audiointerleave.h"
#define GXF_AUDIO_PACKET_SIZE 65536
#define GXF_TIMECODE(c, d, h, m, s, f) \
typedef struct GXFTimecode{
    int hh;
    int mm;
    int ss;
    int ff;
    int color;
    int drop;
} GXFTimecode;
typedef struct GXFStreamContext {
    AudioInterleaveContext aic;
    uint32_t track_type;
    uint32_t sample_size;
    uint32_t sample_rate;
    uint16_t media_type;
    uint16_t media_info;
    int frame_rate_index;
    int lines_index;
    int fields;
    int iframes;
    int pframes;
    int bframes;
    int p_per_gop;
    int b_per_i_or_p; ///< number of B-frames per I-frame or P-frame
    int first_gop_closed;
    unsigned order;   ///< interleaving order
} GXFStreamContext;
typedef struct GXFContext {
    AVClass *av_class;
    uint32_t nb_fields;
    uint16_t audio_tracks;
    uint16_t mpeg_tracks;
    int64_t creation_time;
    uint32_t umf_start_offset;
    uint32_t umf_track_offset;
    uint32_t umf_media_offset;
    uint32_t umf_length;
    uint16_t umf_track_size;
    uint16_t umf_media_size;
    AVRational time_base;
    int flags;
    GXFStreamContext timecode_track;
    unsigned *flt_entries;    ///< offsets of packets /1024, starts after 2nd video field
    unsigned flt_entries_nb;
    uint64_t *map_offsets;    ///< offset of map packets
    unsigned map_offsets_nb;
    unsigned packet_count;
    GXFTimecode tc;
} GXFContext;
#define SERVER_PATH "EXT:/PDR/default/"
#define ES_NAME_PATTERN "EXT:/PDR/default/ES."
