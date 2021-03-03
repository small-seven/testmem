#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "mpeg.h"
#if CONFIG_VOBSUB_DEMUXER
# include "subtitles.h"
# include "libavutil/bprint.h"
# include "libavutil/opt.h"
#endif
#include "libavutil/avassert.h"
#define MAX_SYNC_SIZE 100000
typedef struct MpegDemuxContext {
    AVClass *class;
    int32_t header_state;
    unsigned char psm_es_type[256];
    int sofdec;
    int dvd;
    int imkh_cctv;
    int raw_ac3;
#if CONFIG_VOBSUB_DEMUXER
    AVFormatContext *sub_ctx;
    FFDemuxSubtitlesQueue q[32];
    char *sub_name;
#endif
} MpegDemuxContext;
#if CONFIG_VOBSUB_DEMUXER
#define REF_STRING "# VobSub index file,"
#define MAX_LINE_SIZE 2048
#endif
