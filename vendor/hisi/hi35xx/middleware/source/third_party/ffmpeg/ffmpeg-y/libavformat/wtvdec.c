#include <inttypes.h>
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "libavutil/time_internal.h"
#include "avformat.h"
#include "internal.h"
#include "wtv.h"
#include "mpegts.h"
#define PRI_PRETTY_GUID \
#define ARG_PRETTY_GUID(g) \
#define LEN_PRETTY_GUID 34
typedef struct WtvFile {
    AVIOContext *pb_filesystem;  /**< file system (AVFormatContext->pb) */

    int sector_bits;     /**< sector shift bits; used to convert sector number into pb_filesystem offset */
    uint32_t *sectors;   /**< file allocation table */
    int nb_sectors;      /**< number of sectors */

    int error;
    int64_t position;
    int64_t length;
} WtvFile;
#define wtvfile_open(s, buf, buf_size, filename) \
typedef struct WtvStream {
    int seen_data;
} WtvStream;
typedef struct WtvContext {
    AVIOContext *pb;       /**< timeline file */
    int64_t epoch;
    int64_t pts;             /**< pts for next data chunk */
    int64_t last_valid_pts;  /**< latest valid pts, used for interactive seeking */

    /* maintain private seek index, as the AVIndexEntry->pos is relative to the
       start of the 'timeline' file, not the file system (AVFormatContext->pb) */
    AVIndexEntry *index_entries;
    int nb_index_entries;
    unsigned int index_entries_allocated_size;
} WtvContext;
