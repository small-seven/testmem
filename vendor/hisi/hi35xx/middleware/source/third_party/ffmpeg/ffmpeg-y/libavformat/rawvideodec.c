#include "libavutil/imgutils.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "avformat.h"
typedef struct RawVideoDemuxerContext {
    const AVClass *class;     /**< Class for private options. */
    int width, height;        /**< Integers describing video size, set by a private option. */
    char *pixel_format;       /**< Set by a private option. */
    AVRational framerate;     /**< AVRational describing framerate, set by a private option. */
} RawVideoDemuxerContext;
#define OFFSET(x) offsetof(RawVideoDemuxerContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
