#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "error_resilience.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "golomb.h"
#include "internal.h"
#include "mathops.h"
#include "mpeg_er.h"
#include "qpeldsp.h"
#include "rectangle.h"
#include "thread.h"
#include "rv34vlc.h"
#include "rv34data.h"
#include "rv34.h"
#define GET_PTS_DIFF(a, b) (((a) - (b) + 8192) & 0x1FFF)
static void rv34_decoder_free(RV34DecContext *r)
{
    av_freep(&r->intra_types_hist);
    r->intra_types = NULL;
    av_freep(&r->tmp_b_block_base);
    av_freep(&r->mb_type);
    av_freep(&r->cbp_luma);
    av_freep(&r->cbp_chroma);
    av_freep(&r->deblock_coefs);
}
static int rv34_decoder_realloc(RV34DecContext *r)
{
    rv34_decoder_free(r);
    return rv34_decoder_alloc(r);
}
#if CONFIG_RV30_DECODER
#endif
#if CONFIG_RV40_DECODER
#endif
