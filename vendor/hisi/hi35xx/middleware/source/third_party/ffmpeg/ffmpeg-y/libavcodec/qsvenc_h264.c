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
typedef struct QSVH264EncContext {
    AVClass *class;
    QSVEncContext qsv;
} QSVH264EncContext;
#define OFFSET(x) offsetof(QSVH264EncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if QSV_HAVE_VCM
#endif
#if QSV_HAVE_LA
#endif
#if QSV_HAVE_LA_DS
#endif
#if QSV_HAVE_MF
#endif
#if FF_API_CODER_TYPE
#endif
#if FF_API_PRIVATE_OPT
#endif
