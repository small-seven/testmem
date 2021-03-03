#include "libavutil/avassert.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "libavutil/parseutils.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "avlanguage.h"
#include "avio_internal.h"
#include "internal.h"
#include "riff.h"
#include "asf.h"
#define ASF_INDEXED_INTERVAL    10000000
#define ASF_INDEX_BLOCK         (1<<9)
#define ASF_PAYLOADS_PER_PACKET 63
#define ASF_PACKET_ERROR_CORRECTION_DATA_SIZE 0x2
#define ASF_PACKET_ERROR_CORRECTION_FLAGS          \
#if (ASF_PACKET_ERROR_CORRECTION_FLAGS != 0)
#   define ASF_PACKET_ERROR_CORRECTION_FLAGS_FIELD_SIZE 1
#else
#   define ASF_PACKET_ERROR_CORRECTION_FLAGS_FIELD_SIZE 0
#endif
#define ASF_PPI_PROPERTY_FLAGS                                       \
#define ASF_PPI_LENGTH_TYPE_FLAGS 0
#define ASF_PAYLOAD_FLAGS ASF_PL_FLAG_PAYLOAD_LENGTH_FIELD_IS_WORD
#if (ASF_PPI_FLAG_SEQUENCE_FIELD_IS_BYTE == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_SEQUENCE_FIELD_SIZE))
#   define ASF_PPI_SEQUENCE_FIELD_SIZE 1
#endif
#if (ASF_PPI_FLAG_SEQUENCE_FIELD_IS_WORD == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_SEQUENCE_FIELD_SIZE))
#   define ASF_PPI_SEQUENCE_FIELD_SIZE 2
#endif
#if (ASF_PPI_FLAG_SEQUENCE_FIELD_IS_DWORD == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_SEQUENCE_FIELD_SIZE))
#   define ASF_PPI_SEQUENCE_FIELD_SIZE 4
#endif
#ifndef ASF_PPI_SEQUENCE_FIELD_SIZE
#   define ASF_PPI_SEQUENCE_FIELD_SIZE 0
#endif
#if (ASF_PPI_FLAG_PACKET_LENGTH_FIELD_IS_BYTE == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_PACKET_LENGTH_FIELD_SIZE))
#   define ASF_PPI_PACKET_LENGTH_FIELD_SIZE 1
#endif
#if (ASF_PPI_FLAG_PACKET_LENGTH_FIELD_IS_WORD == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_PACKET_LENGTH_FIELD_SIZE))
#   define ASF_PPI_PACKET_LENGTH_FIELD_SIZE 2
#endif
#if (ASF_PPI_FLAG_PACKET_LENGTH_FIELD_IS_DWORD == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_PACKET_LENGTH_FIELD_SIZE))
#   define ASF_PPI_PACKET_LENGTH_FIELD_SIZE 4
#endif
#ifndef ASF_PPI_PACKET_LENGTH_FIELD_SIZE
#   define ASF_PPI_PACKET_LENGTH_FIELD_SIZE 0
#endif
#if (ASF_PPI_FLAG_PADDING_LENGTH_FIELD_IS_BYTE == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_PADDING_LENGTH_FIELD_SIZE))
#   define ASF_PPI_PADDING_LENGTH_FIELD_SIZE 1
#endif
#if (ASF_PPI_FLAG_PADDING_LENGTH_FIELD_IS_WORD == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_PADDING_LENGTH_FIELD_SIZE))
#   define ASF_PPI_PADDING_LENGTH_FIELD_SIZE 2
#endif
#if (ASF_PPI_FLAG_PADDING_LENGTH_FIELD_IS_DWORD == (ASF_PPI_LENGTH_TYPE_FLAGS & ASF_PPI_MASK_PADDING_LENGTH_FIELD_SIZE))
#   define ASF_PPI_PADDING_LENGTH_FIELD_SIZE 4
#endif
#ifndef ASF_PPI_PADDING_LENGTH_FIELD_SIZE
#   define ASF_PPI_PADDING_LENGTH_FIELD_SIZE 0
#endif
#if (ASF_PL_FLAG_REPLICATED_DATA_LENGTH_FIELD_IS_BYTE == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_REPLICATED_DATA_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_REPLICATED_DATA_LENGTH_FIELD_SIZE 1
#endif
#if (ASF_PL_FLAG_REPLICATED_DATA_LENGTH_FIELD_IS_WORD == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_REPLICATED_DATA_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_REPLICATED_DATA_LENGTH_FIELD_SIZE 2
#endif
#if (ASF_PL_FLAG_REPLICATED_DATA_LENGTH_FIELD_IS_DWORD == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_REPLICATED_DATA_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_REPLICATED_DATA_LENGTH_FIELD_SIZE 4
#endif
#ifndef ASF_PAYLOAD_REPLICATED_DATA_LENGTH_FIELD_SIZE
#   define ASF_PAYLOAD_REPLICATED_DATA_LENGTH_FIELD_SIZE 0
#endif
#if (ASF_PL_FLAG_OFFSET_INTO_MEDIA_OBJECT_LENGTH_FIELD_IS_BYTE == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_OFFSET_INTO_MEDIA_OBJECT_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_OFFSET_INTO_MEDIA_OBJECT_FIELD_SIZE 1
#endif
#if (ASF_PL_FLAG_OFFSET_INTO_MEDIA_OBJECT_LENGTH_FIELD_IS_WORD == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_OFFSET_INTO_MEDIA_OBJECT_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_OFFSET_INTO_MEDIA_OBJECT_FIELD_SIZE 2
#endif
#if (ASF_PL_FLAG_OFFSET_INTO_MEDIA_OBJECT_LENGTH_FIELD_IS_DWORD == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_OFFSET_INTO_MEDIA_OBJECT_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_OFFSET_INTO_MEDIA_OBJECT_FIELD_SIZE 4
#endif
#ifndef ASF_PAYLOAD_OFFSET_INTO_MEDIA_OBJECT_FIELD_SIZE
#   define ASF_PAYLOAD_OFFSET_INTO_MEDIA_OBJECT_FIELD_SIZE 0
#endif
#if (ASF_PL_FLAG_MEDIA_OBJECT_NUMBER_LENGTH_FIELD_IS_BYTE == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_MEDIA_OBJECT_NUMBER_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_MEDIA_OBJECT_NUMBER_FIELD_SIZE 1
#endif
#if (ASF_PL_FLAG_MEDIA_OBJECT_NUMBER_LENGTH_FIELD_IS_WORD == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_MEDIA_OBJECT_NUMBER_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_MEDIA_OBJECT_NUMBER_FIELD_SIZE 2
#endif
#if (ASF_PL_FLAG_MEDIA_OBJECT_NUMBER_LENGTH_FIELD_IS_DWORD == (ASF_PPI_PROPERTY_FLAGS & ASF_PL_MASK_MEDIA_OBJECT_NUMBER_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_MEDIA_OBJECT_NUMBER_FIELD_SIZE 4
#endif
#ifndef ASF_PAYLOAD_MEDIA_OBJECT_NUMBER_FIELD_SIZE
#   define ASF_PAYLOAD_MEDIA_OBJECT_NUMBER_FIELD_SIZE 0
#endif
#if (ASF_PL_FLAG_PAYLOAD_LENGTH_FIELD_IS_BYTE == (ASF_PAYLOAD_FLAGS & ASF_PL_MASK_PAYLOAD_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_LENGTH_FIELD_SIZE 1
#endif
#if (ASF_PL_FLAG_PAYLOAD_LENGTH_FIELD_IS_WORD == (ASF_PAYLOAD_FLAGS & ASF_PL_MASK_PAYLOAD_LENGTH_FIELD_SIZE))
#   define ASF_PAYLOAD_LENGTH_FIELD_SIZE 2
#endif
#ifndef ASF_PAYLOAD_LENGTH_FIELD_SIZE
#   define ASF_PAYLOAD_LENGTH_FIELD_SIZE 0
#endif
#define PACKET_HEADER_MIN_SIZE \
#define ASF_PAYLOAD_REPLICATED_DATA_LENGTH 0x08
#define PAYLOAD_HEADER_SIZE_SINGLE_PAYLOAD                \
#define PAYLOAD_HEADER_SIZE_MULTIPLE_PAYLOADS             \
#define SINGLE_PAYLOAD_HEADERS                            \
#define MULTI_PAYLOAD_HEADERS                             \
#define DATA_HEADER_SIZE 50
#define PACKET_SIZE_MAX 65536
#define PACKET_SIZE_MIN 100
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
    AVClass *av_class;
    uint32_t seqno;
    int is_streamed;
    ASFStream streams[128];              ///< it's max number and it's not that big
    const char *languages[128];
    int nb_languages;
    int64_t creation_time;
    /* non-streamed additional info */
    uint64_t nb_packets;                 ///< how many packets are there in the file, invalid if broadcasting
    int64_t duration;                    ///< in 100ns units
    /* packet filling */
    unsigned char multi_payloads_present;
    int packet_size_left;
    int64_t packet_timestamp_start;
    int64_t packet_timestamp_end;
    unsigned int packet_nb_payloads;
    uint8_t packet_buf[PACKET_SIZE_MAX];
    AVIOContext pb;
    /* only for reading */
    uint64_t data_offset;                ///< beginning of the first data packet

    ASFIndex *index_ptr;
    uint32_t nb_index_memory_alloc;
    uint16_t maximum_packet;
    uint32_t next_packet_number;
    uint16_t next_packet_count;
    uint64_t next_packet_offset;
    int      next_start_sec;
    int      end_sec;
    int      packet_size;
} ASFContext;
#define PREROLL_TIME 3100
#if CONFIG_ASF_MUXER
#endif /* CONFIG_ASF_MUXER */
#if CONFIG_ASF_STREAM_MUXER
#endif /* CONFIG_ASF_STREAM_MUXER */
