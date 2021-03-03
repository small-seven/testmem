#include <stdio.h>
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "transpose.h"
typedef struct TransVtable {
    void (*transpose_8x8)(uint8_t *src, ptrdiff_t src_linesize,
                          uint8_t *dst, ptrdiff_t dst_linesize);
    void (*transpose_block)(uint8_t *src, ptrdiff_t src_linesize,
                            uint8_t *dst, ptrdiff_t dst_linesize,
                            int w, int h);
} TransVtable;
typedef struct TransContext {
    const AVClass *class;
    int hsub, vsub;
    int planes;
    int pixsteps[4];

    int passthrough;    ///< PassthroughType, landscape passthrough mode enabled
    int dir;            ///< TransposeDir

    TransVtable vtables[4];
} TransContext;
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
#define OFFSET(x) offsetof(TransContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
