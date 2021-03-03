#include <stdlib.h>
#include "avcodec.h"
#include "get_bits.h"
#include "huffman.h"
#include "internal.h"
#include "vp56.h"
#include "vp56data.h"
#include "vp6data.h"
#define VP6_MAX_HUFF_SIZE 12
static av_cold int vp6_decode_free(AVCodecContext *avctx)
{
    VP56Context *s = avctx->priv_data;

    ff_vp56_free(avctx);
    vp6_decode_free_context(s);

    if (s->alpha_context) {
        ff_vp56_free_context(s->alpha_context);
        vp6_decode_free_context(s->alpha_context);
        av_freep(&s->alpha_context);
    }

    return 0;
}
