#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "internal.h"
#include "rle.h"
#include "targa.h"
typedef struct TargaContext {
    AVClass *class;

    int rle;
} TargaContext;
#if FF_API_CODER_TYPE
#endif
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(TargaContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
