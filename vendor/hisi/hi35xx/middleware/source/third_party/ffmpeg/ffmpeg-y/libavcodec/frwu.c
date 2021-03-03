#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "libavutil/opt.h"
typedef struct {
    AVClass *av_class;
    int change_field_order;
} FRWUContext;
