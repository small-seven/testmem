#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "h264chroma.h"
#include "vp56.h"
#include "vp56data.h"
#define TRANSPOSE(x) (((x) >> 3) | (((x) & 7) << 3))
#undef TRANSPOSE
av_cold int ff_vp56_free(AVCodecContext *avctx)
{
    VP56Context *s = avctx->priv_data;
    return ff_vp56_free_context(s);
}
