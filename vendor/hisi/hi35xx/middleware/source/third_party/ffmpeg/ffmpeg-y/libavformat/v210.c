#include "libavutil/imgutils.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "avformat.h"
typedef struct V210DemuxerContext {
    const AVClass *class;     /**< Class for private options. */
    int width, height;        /**< Integers describing video size, set by a private option. */
    AVRational framerate;     /**< AVRational describing framerate, set by a private option. */
} V210DemuxerContext;
#define GET_PACKET_SIZE(w, h) (((w + 47) / 48) * 48 * h * 8 / 3)
#define OFFSET(x) offsetof(V210DemuxerContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_V210_DEMUXER
#endif // CONFIG_V210_DEMUXER
#if CONFIG_V210X_DEMUXER
#endif // CONFIG_V210X_DEMUXER
