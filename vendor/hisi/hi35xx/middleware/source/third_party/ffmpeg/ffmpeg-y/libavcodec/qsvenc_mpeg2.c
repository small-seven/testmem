#include <stdint.h>
#include <sys/types.h>
#include <mfx/mfxvideo.h>
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "qsv.h"
#include "qsv_internal.h"
#include "qsvenc.h"
typedef struct QSVMpeg2EncContext {
    AVClass *class;
    QSVEncContext qsv;
} QSVMpeg2EncContext;
#define OFFSET(x) offsetof(QSVMpeg2EncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_PRIVATE_OPT
#endif
