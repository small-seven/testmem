#include <inttypes.h>
#include "libavutil/aes.h"
#include "libavutil/avassert.h"
#include "libavutil/mathematics.h"
#include "libavcodec/bytestream.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/parseutils.h"
#include "libavutil/timecode.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "mxf.h"
#define MXF_MAX_CHUNK_SIZE (32 << 20)
typedef enum {
    Header,
    BodyPartition,
    Footer
} MXFPartitionType;
typedef enum {
    OP1a = 1,
    OP1b,
    OP1c,
    OP2a,
    OP2b,
    OP2c,
    OP3a,
    OP3b,
    OP3c,
    OPAtom,
    OPSONYOpt,  /* FATE sample, violates the spec in places */
} MXFOP;
typedef enum {
    UnknownWrapped = 0,
    FrameWrapped,
    ClipWrapped,
} MXFWrappingScheme;
typedef struct MXFPartition {
    int closed;
    int complete;
    MXFPartitionType type;
    uint64_t previous_partition;
    int index_sid;
    int body_sid;
    int64_t this_partition;
    int64_t essence_offset;         ///< absolute offset of essence
    int64_t essence_length;
    int32_t kag_size;
    int64_t header_byte_count;
    int64_t index_byte_count;
    int pack_length;
    int64_t pack_ofs;               ///< absolute offset of pack in file, including run-in
    int64_t body_offset;
    KLVPacket first_essence_klv;
} MXFPartition;
typedef struct MXFCryptoContext {
    UID uid;
    enum MXFMetadataSetType type;
    UID source_container_ul;
} MXFCryptoContext;
typedef struct MXFStructuralComponent {
    UID uid;
    enum MXFMetadataSetType type;
    UID source_package_ul;
    UID source_package_uid;
    UID data_definition_ul;
    int64_t duration;
    int64_t start_position;
    int source_track_id;
} MXFStructuralComponent;
typedef struct MXFSequence {
    UID uid;
    enum MXFMetadataSetType type;
    UID data_definition_ul;
    UID *structural_components_refs;
    int structural_components_count;
    int64_t duration;
    uint8_t origin;
} MXFSequence;
typedef struct MXFTrack {
    UID uid;
    enum MXFMetadataSetType type;
    int drop_frame;
    int start_frame;
    struct AVRational rate;
    AVTimecode tc;
} MXFTimecodeComponent;
typedef struct {
    UID uid;
    enum MXFMetadataSetType type;
    UID input_segment_ref;
} MXFPulldownComponent;
typedef struct {
    UID uid;
    enum MXFMetadataSetType type;
    UID *structural_components_refs;
    int structural_components_count;
    int64_t duration;
} MXFEssenceGroup;
typedef struct {
    UID uid;
    enum MXFMetadataSetType type;
    char *name;
    char *value;
} MXFTaggedValue;
typedef struct {
    UID uid;
    enum MXFMetadataSetType type;
    MXFSequence *sequence; /* mandatory, and only one */
    UID sequence_ref;
    int track_id;
    char *name;
    uint8_t track_number[4];
    AVRational edit_rate;
    int intra_only;
    uint64_t sample_count;
    int64_t original_duration; /* st->duration in SampleRate/EditRate units */
    int index_sid;
    int body_sid;
    MXFWrappingScheme wrapping;
    int edit_units_per_packet; /* how many edit units to read at a time (PCM, ClipWrapped) */
} MXFTrack;
typedef struct MXFDescriptor {
    UID uid;
    enum MXFMetadataSetType type;
    UID essence_container_ul;
    UID essence_codec_ul;
    UID codec_ul;
    AVRational sample_rate;
    AVRational aspect_ratio;
    int width;
    int height; /* Field height, not frame height */
    int frame_layout; /* See MXFFrameLayout enum */
    int video_line_map[2];
#define MXF_FIELD_DOMINANCE_DEFAULT 0
#define MXF_FIELD_DOMINANCE_FF 1 /* coded first, displayed first */
#define MXF_FIELD_DOMINANCE_FL 2 /* coded first, displayed last */
    int field_dominance;
    int channels;
    int bits_per_sample;
    int64_t duration; /* ContainerDuration optional property */
    unsigned int component_depth;
    unsigned int horiz_subsampling;
    unsigned int vert_subsampling;
    UID *sub_descriptors_refs;
    int sub_descriptors_count;
    int linked_track_id;
    uint8_t *extradata;
    int extradata_size;
    enum AVPixelFormat pix_fmt;
} MXFDescriptor;
typedef struct MXFIndexTableSegment {
    UID uid;
    enum MXFMetadataSetType type;
    int edit_unit_byte_count;
    int index_sid;
    int body_sid;
    AVRational index_edit_rate;
    uint64_t index_start_position;
    uint64_t index_duration;
    int8_t *temporal_offset_entries;
    int *flag_entries;
    uint64_t *stream_offset_entries;
    int nb_index_entries;
} MXFIndexTableSegment;
typedef struct MXFPackage {
    UID uid;
    enum MXFMetadataSetType type;
    UID package_uid;
    UID package_ul;
    UID *tracks_refs;
    int tracks_count;
    MXFDescriptor *descriptor; /* only one */
    UID descriptor_ref;
    char *name;
    UID *comment_refs;
    int comment_count;
} MXFPackage;
typedef struct MXFEssenceContainerData {
    UID uid;
    enum MXFMetadataSetType type;
    UID package_uid;
    UID package_ul;
    int index_sid;
    int body_sid;
} MXFEssenceContainerData;
typedef struct MXFMetadataSet {
    UID uid;
    enum MXFMetadataSetType type;
} MXFMetadataSet;
typedef struct MXFIndexTable {
    int index_sid;
    int body_sid;
    int nb_ptses;               /* number of PTSes or total duration of index */
    int64_t first_dts;          /* DTS = EditUnit + first_dts */
    int64_t *ptses;             /* maps EditUnit -> PTS */
    int nb_segments;
    MXFIndexTableSegment **segments;    /* sorted by IndexStartPosition */
    AVIndexEntry *fake_index;   /* used for calling ff_index_search_timestamp() */
    int8_t *offsets;            /* temporal offsets for display order to stored order conversion */
} MXFIndexTable;
typedef struct MXFContext {
    const AVClass *class;     /**< Class for private options. */
    MXFPartition *partitions;
    unsigned partitions_count;
    MXFOP op;
    UID *packages_refs;
    int packages_count;
    UID *essence_container_data_refs;
    int essence_container_data_count;
    MXFMetadataSet **metadata_sets;
    int metadata_sets_count;
    AVFormatContext *fc;
    struct AVAES *aesc;
    uint8_t *local_tags;
    int local_tags_count;
    uint64_t footer_partition;
    KLVPacket current_klv_data;
    int run_in;
    MXFPartition *current_partition;
    int parsing_backward;
    int64_t last_forward_tell;
    int last_forward_partition;
    int nb_index_tables;
    MXFIndexTable *index_tables;
    int eia608_extract;
} MXFContext;
typedef int MXFMetadataReadFunc(void *arg, AVIOContext *pb, int tag, int size, UID uid, int64_t klv_offset);

typedef struct MXFMetadataReadTableEntry {
    const UID key;
    MXFMetadataReadFunc *read;
    int ctx_size;
    enum MXFMetadataSetType type;
} MXFMetadataReadTableEntry;
#define IS_KLV_KEY(x, y) (!memcmp(x, y, sizeof(y)))
#define READ_STR16(type, big_endian)                                               \
#undef READ_STR16
#define SET_STR_METADATA(pb, name, str) do { \
#define SET_UID_METADATA(pb, name, var, str) do { \
#define SET_TS_METADATA(pb, name, var, str) do { \
