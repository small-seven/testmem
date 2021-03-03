#include <stdint.h>
#include <sys/types.h>
#include <mfx/mfxvideo.h>
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "hevc.h"
#include "hevcdec.h"
#include "h2645_parse.h"
#include "internal.h"
#include "qsv.h"
#include "qsv_internal.h"
#include "qsvenc.h"
typedef struct QSVHEVCEncContext {
    AVClass *class;
    QSVEncContext qsv;
    int load_plugin;
} QSVHEVCEncContext;
#define OFFSET(x) offsetof(QSVHEVCEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_PRIVATE_OPT
#endif
