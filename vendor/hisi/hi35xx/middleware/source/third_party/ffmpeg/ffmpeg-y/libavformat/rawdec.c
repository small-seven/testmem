#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#include "rawdec.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#define RAW_PACKET_SIZE 1024
#define OFFSET(x) offsetof(FFRawVideoDemuxerContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_DATA_DEMUXER
#endif
#if CONFIG_MJPEG_DEMUXER
#endif
