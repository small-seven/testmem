#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavcodec/apng.h"
#include "libavcodec/png.h"
#include "libavcodec/bytestream.h"
#define DEFAULT_APNG_FPS 15
typedef struct APNGDemuxContext {
    const AVClass *class;

    int max_fps;
    int default_fps;

    int pkt_duration;

    int is_key_frame;

    /*
     * loop options
     */
    int ignore_loop;
    uint32_t num_frames;
    uint32_t num_play;
    uint32_t cur_loop;
} APNGDemuxContext;
