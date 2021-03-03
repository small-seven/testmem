#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
#include "libavutil/log.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avformat.h"
#include "internal.h"
#include "sauce.h"
typedef struct TtyDemuxContext {
    AVClass *class;
    int chars_per_frame;
    uint64_t fsize;  /**< file size less metadata buffer */
    int width, height; /**< Set by a private option. */
    AVRational framerate; /**< Set by a private option. */
} TtyDemuxContext;
#define GET_EFI_META(name,size) \
#define OFFSET(x) offsetof(TtyDemuxContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
