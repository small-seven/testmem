#include <inttypes.h>
#include <math.h>
#include <time.h>
#include "libavutil/opt.h"
#include "libavutil/random_seed.h"
#include "libavutil/timecode.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time_internal.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/dnxhddata.h"
#include "libavcodec/dv_profile.h"
#include "libavcodec/h264_ps.h"
#include "libavcodec/golomb.h"
#include "libavcodec/internal.h"
#include "audiointerleave.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "avc.h"
#include "mxf.h"
#include "config.h"
#define EDIT_UNITS_PER_BODY 250
#define KAG_SIZE 512
typedef struct MXFLocalTagPair {
    int local_tag;
    UID uid;
} MXFLocalTagPair;
typedef struct MXFIndexEntry {
    uint8_t flags;
    uint64_t offset;
    unsigned slice_offset; ///< offset of audio slice
    uint16_t temporal_ref;
} MXFIndexEntry;
typedef struct MXFStreamContext {
    AudioInterleaveContext aic;
    UID track_essence_element_key;
    int index;               ///< index in mxf_essence_container_uls table
    const UID *codec_ul;
    int order;               ///< interleaving order if dts are equal
    int interlaced;          ///< whether picture is interlaced
    int field_dominance;     ///< tff=1, bff=2
    int component_depth;
    int color_siting;
    int signal_standard;
    int h_chroma_sub_sample;
    int v_chroma_sub_sample;
    int temporal_reordering;
    AVRational aspect_ratio; ///< display aspect ratio
    int closed_gop;          ///< gop is closed, used in mpeg-2 frame parsing
    int video_bit_rate;
    int slice_offset;
    int frame_size;          ///< frame size in bytes
    int seq_closed_gop;      ///< all gops in sequence are closed, used in mpeg-2 descriptor
    int max_gop;             ///< maximum gop size, used by mpeg-2 descriptor
    int b_picture_count;     ///< maximum number of consecutive b pictures, used in mpeg-2 descriptor
    int low_delay;           ///< low delay, used in mpeg-2 descriptor
    int avc_intra;
} MXFStreamContext;
typedef struct MXFContainerEssenceEntry {
    UID container_ul;
    UID element_ul;
    UID codec_ul;
    void (*write_desc)(AVFormatContext *, AVStream *);
} MXFContainerEssenceEntry;
typedef struct MXFPackage {
    char *name;
    enum MXFMetadataSetType type;
    int instance;
    struct MXFPackage *ref;
} MXFPackage;
typedef struct MXFContext {
    AVClass *av_class;
    int64_t footer_partition_offset;
    int essence_container_count;
    AVRational time_base;
    int header_written;
    MXFIndexEntry *index_entries;
    unsigned edit_units_count;
    uint64_t timestamp;   ///< timestamp, as year(16),month(8),day(8),hour(8),minutes(8),msec/4(8)
    uint8_t slice_count;  ///< index slice count minus 1 (1 if no audio, 0 otherwise)
    int last_indexed_edit_unit;
    uint64_t *body_partition_offset;
    unsigned body_partitions_count;
    int last_key_index;  ///< index of last key frame
    uint64_t duration;
    AVTimecode tc;       ///< timecode context
    AVStream *timecode_track;
    int timecode_base;       ///< rounded time code base (25 or 30)
    int edit_unit_byte_count; ///< fixed edit unit byte count
    int content_package_rate; ///< content package rate in system element, see SMPTE 326M
    uint64_t body_offset;
    uint32_t instance_number;
    uint8_t umid[16];        ///< unique material identifier
    int channel_count;
    int signal_standard;
    uint32_t tagged_value_count;
    AVRational audio_edit_rate;
    int store_user_comments;
    int track_instance_count; // used to generate MXFTrack uuids
    int cbr_index;           ///< use a constant bitrate index
} MXFContext;
static void mxf_free(AVFormatContext *s)
{
    int i;

    for (i = 0; i < s->nb_streams; i++) {
        AVStream *st = s->streams[i];
        av_freep(&st->priv_data);
    }
}
#define DESCRIPTOR_COUNT(essence_container_count) \
#define MXF_COMMON_OPTIONS \
