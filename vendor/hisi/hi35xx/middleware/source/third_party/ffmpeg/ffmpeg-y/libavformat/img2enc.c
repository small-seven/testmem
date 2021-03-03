#include "libavutil/intreadwrite.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time_internal.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "img2.h"
typedef struct VideoMuxData {
    const AVClass *class;  /**< Class for private options. */
    int img_number;
    int is_pipe;
    int split_planes;       /**< use independent file for each Y, U, V plane */
    char path[1024];
    char tmp[4][1024];
    char target[4][1024];
    int update;
    int use_strftime;
    int frame_pts;
    const char *muxer;
    int use_rename;
} VideoMuxData;
#define OFFSET(x) offsetof(VideoMuxData, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
#if CONFIG_IMAGE2_MUXER
#endif
#if CONFIG_IMAGE2PIPE_MUXER
#endif
