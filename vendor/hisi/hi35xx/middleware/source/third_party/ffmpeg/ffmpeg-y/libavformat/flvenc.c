#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavutil/intfloat.h"
#include "libavutil/avassert.h"
#include "libavutil/mathematics.h"
#include "avio_internal.h"
#include "avio.h"
#include "avc.h"
#include "avformat.h"
#include "flv.h"
#include "internal.h"
#include "metadata.h"
#include "libavutil/opt.h"
#include "libavcodec/put_bits.h"
#include "libavcodec/aacenctab.h"
typedef enum {
    FLV_AAC_SEQ_HEADER_DETECT = (1 << 0),
    FLV_NO_SEQUENCE_END = (1 << 1),
    FLV_ADD_KEYFRAME_INDEX = (1 << 2),
    FLV_NO_METADATA = (1 << 3),
    FLV_NO_DURATION_FILESIZE = (1 << 4),
} FLVFlags;
typedef struct FLVFileposition {
    int64_t keyframe_position;
    double keyframe_timestamp;
    struct FLVFileposition *next;
} FLVFileposition;
typedef struct FLVContext {
    AVClass *av_class;
    int     reserved;
    int64_t duration_offset;
    int64_t filesize_offset;
    int64_t duration;
    int64_t delay;      ///< first dts delay (needed for AVC & Speex)

    int64_t datastart_offset;
    int64_t datasize_offset;
    int64_t datasize;
    int64_t videosize_offset;
    int64_t videosize;
    int64_t audiosize_offset;
    int64_t audiosize;

    int64_t metadata_size_pos;
    int64_t metadata_totalsize_pos;
    int64_t metadata_totalsize;
    int64_t keyframe_index_size;

    int64_t lasttimestamp_offset;
    double lasttimestamp;
    int64_t lastkeyframetimestamp_offset;
    double lastkeyframetimestamp;
    int64_t lastkeyframelocation_offset;
    int64_t lastkeyframelocation;

    int acurframeindex;
    int64_t keyframes_info_offset;

    int64_t filepositions_count;
    FLVFileposition *filepositions;
    FLVFileposition *head_filepositions;

    AVCodecParameters *audio_par;
    AVCodecParameters *video_par;
    double framerate;
    AVCodecParameters *data_par;

    int flags;
} FLVContext;
typedef struct FLVStreamContext {
    int64_t last_ts;    ///< last timestamp for each stream
} FLVStreamContext;
#define READ_BLOCK do {                                                             \
