#include "libavutil/intreadwrite.h"
#include "libavutil/avassert.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "mpegts.h"
#include "wtv.h"
#define WTV_BIGSECTOR_SIZE (1 << WTV_BIGSECTOR_BITS)
#define INDEX_BASE 0x2
#define MAX_NB_INDEX 10
#define _ , 0,
#undef _
typedef struct {
    int64_t length;
    const void *header;
    int depth;
    int first_sector;
} WtvFile;
typedef struct {
    int64_t             pos;
    int64_t             serial;
    const ff_asf_guid * guid;
    int                 stream_id;
} WtvChunkEntry;
typedef struct {
    int64_t serial;
    int64_t value;
} WtvSyncEntry;
typedef struct {
    int64_t timeline_start_pos;
    WtvFile file[WTV_FILES];
    int64_t serial;         /**< chunk serial number */
    int64_t last_chunk_pos; /**< last chunk position */
    int64_t last_timestamp_pos; /**< last timestamp chunk position */
    int64_t first_index_pos;    /**< first index_chunk position */

    WtvChunkEntry index[MAX_NB_INDEX];
    int nb_index;
    int first_video_flag;

    WtvSyncEntry *st_pairs; /* (serial, timestamp) pairs */
    int nb_st_pairs;
    WtvSyncEntry *sp_pairs; /* (serial, position) pairs */
    int nb_sp_pairs;

    int64_t last_pts;
    int64_t last_serial;

    AVPacket thumbnail;
} WtvContext;
typedef int WTVHeaderWriteFunc(AVIOContext *pb);

typedef struct {
    const uint8_t *header;
    int header_size;
    WTVHeaderWriteFunc *write_header;
} WTVRootEntryTable;
#define write_pad(pb, size) ffio_fill(pb, 0, size)
