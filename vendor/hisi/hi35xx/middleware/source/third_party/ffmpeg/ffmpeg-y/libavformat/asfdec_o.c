#include "libavutil/attributes.h"
#include "libavutil/avstring.h"
#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "libavutil/dict.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/time_internal.h"
#include "avformat.h"
#include "avio_internal.h"
#include "avlanguage.h"
#include "id3v2.h"
#include "internal.h"
#include "riff.h"
#include "asf.h"
#include "asfcrypt.h"
#define ASF_BOOL                              0x2
#define ASF_WORD                              0x5
#define ASF_GUID                              0x6
#define ASF_DWORD                             0x3
#define ASF_QWORD                             0x4
#define ASF_UNICODE                           0x0
#define ASF_FLAG_BROADCAST                    0x1
#define ASF_BYTE_ARRAY                        0x1
#define ASF_TYPE_AUDIO                        0x2
#define ASF_TYPE_VIDEO                        0x1
#define ASF_STREAM_NUM                        0x7F
#define ASF_MAX_STREAMS                       128
#define BMP_HEADER_SIZE                       40
#define ASF_NUM_OF_PAYLOADS                   0x3F
#define ASF_ERROR_CORRECTION_LENGTH_TYPE      0x60
#define ASF_PACKET_ERROR_CORRECTION_DATA_SIZE 0x2
typedef struct GUIDParseTable {
    const char *name;
    ff_asf_guid guid;
    int (*read_object)(AVFormatContext *, const struct GUIDParseTable *);
    int is_subobject;
} GUIDParseTable;
typedef struct ASFPacket {
    AVPacket avpkt;
    int64_t dts;
    uint32_t frame_num; // ASF payloads with the same number are parts of the same frame
    int flags;
    int data_size;
    int duration;
    int size_left;
    uint8_t stream_index;
} ASFPacket;
typedef struct ASFStream {
    uint8_t stream_index; // from packet header
    int index;  // stream index in AVFormatContext, set in asf_read_stream_properties
    int type;
    int indexed; // added index entries from the Simple Index Object or not
    int8_t span;   // for deinterleaving
    uint16_t virtual_pkt_len;
    uint16_t virtual_chunk_len;
    int16_t lang_idx;
    ASFPacket pkt;
} ASFStream;
typedef struct ASFStreamData{
    char langs[32];
    AVDictionary *asf_met; // for storing per-stream metadata
    AVRational aspect_ratio;
} ASFStreamData;
typedef struct ASFContext {
    int data_reached;
    int is_simple_index; // is simple index present or not 1/0
    int is_header;

    uint64_t preroll;
    uint64_t nb_packets; // ASF packets
    uint32_t packet_size;
    int64_t send_time;
    int duration;

    uint32_t b_flags;    // flags with broadcast flag
    uint32_t prop_flags; // file properties object flags

    uint64_t data_size; // data object size
    uint64_t unknown_size; // size of the unknown object

    int64_t offset; // offset of the current object

    int64_t data_offset;
    int64_t first_packet_offset; // packet offset
    int64_t unknown_offset;   // for top level header objects or subobjects without specified behavior

    // ASF file must not contain more than 128 streams according to the specification
    ASFStream *asf_st[ASF_MAX_STREAMS];
    ASFStreamData asf_sd[ASF_MAX_STREAMS];
    int nb_streams;

    int stream_index; // from packet header, for the subpayload case

    // packet parameters
    uint64_t sub_header_offset; // offset of subpayload header
    int64_t sub_dts;
    uint8_t dts_delta; // for subpayloads
    uint32_t packet_size_internal; // packet size stored inside ASFPacket, can be 0
    int64_t packet_offset; // offset of the current packet inside Data Object
    uint32_t pad_len; // padding after payload
    uint32_t rep_data_len;

    // packet state
    uint64_t sub_left;  // subpayloads left or not
    unsigned int nb_sub; // number of subpayloads read so far from the current ASF packet
    uint16_t mult_sub_len; // total length of subpayloads array inside multiple payload
    uint64_t nb_mult_left; // multiple payloads left
    int return_subpayload;
    enum {
        PARSE_PACKET_HEADER,
        READ_SINGLE,
        READ_MULTI,
        READ_MULTI_SUB
    } state;
#define READ_LEN(flag, name, len)            \
