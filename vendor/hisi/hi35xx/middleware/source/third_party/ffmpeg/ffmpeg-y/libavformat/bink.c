#include <inttypes.h>
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define BINK_EXTRADATA_SIZE     1
#define BINK_MAX_AUDIO_TRACKS   256
#define BINK_MAX_WIDTH          7680
#define BINK_MAX_HEIGHT         4800
#define SMUSH_BLOCK_SIZE        512
typedef struct BinkDemuxContext {
    uint32_t file_size;

    uint32_t num_audio_tracks;
    int current_track;      ///< audio track to return in next packet
    int64_t video_pts;
    int64_t audio_pts[BINK_MAX_AUDIO_TRACKS];

    uint32_t remain_packet_size;
    int smush_size;
} BinkDemuxContext;
