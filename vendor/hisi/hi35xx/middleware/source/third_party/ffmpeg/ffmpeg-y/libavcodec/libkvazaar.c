#include <kvazaar.h>
#include <stdint.h>
#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/dict.h"
#include "libavutil/error.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
typedef struct LibkvazaarContext {
    const AVClass *class;

    const kvz_api *api;
    kvz_encoder *encoder;
    kvz_config *config;

    char *kvz_params;
} LibkvazaarContext;
#define OFFSET(x) offsetof(LibkvazaarContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
