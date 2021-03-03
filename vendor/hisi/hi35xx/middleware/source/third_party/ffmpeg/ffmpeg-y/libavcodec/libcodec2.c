#include <codec2/codec2.h>
#include "avcodec.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "codec2utils.h"
typedef struct {
    const AVClass *class;
    struct CODEC2 *codec;
    int mode;
} LibCodec2Context;
