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
typedef struct QSVMJPEGEncContext {
    AVClass *class;
    QSVEncContext qsv;
} QSVMJPEGEncContext;
#define OFFSET(x) offsetof(QSVMJPEGEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
