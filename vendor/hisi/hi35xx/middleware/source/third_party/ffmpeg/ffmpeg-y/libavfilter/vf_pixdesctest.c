#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct PixdescTestContext {
    const AVPixFmtDescriptor *pix_desc;
    uint32_t *line;
} PixdescTestContext;
