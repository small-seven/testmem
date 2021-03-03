#include "libavutil/opt.h"
#include "avformat.h"
#define BOUNDARY_TAG "ffmpeg"
typedef struct MPJPEGContext {
    AVClass *class;
    char *boundary_tag;
} MPJPEGContext;
