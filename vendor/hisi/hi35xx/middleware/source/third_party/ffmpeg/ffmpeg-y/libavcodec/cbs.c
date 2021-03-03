#include <string.h>
#include "config.h"
#include "libavutil/avassert.h"
#include "libavutil/buffer.h"
#include "libavutil/common.h"
#include "cbs.h"
#include "cbs_internal.h"
#if CONFIG_CBS_AV1
#endif
#if CONFIG_CBS_H264
#endif
#if CONFIG_CBS_H265
#endif
#if CONFIG_CBS_JPEG
#endif
#if CONFIG_CBS_MPEG2
#endif
#if CONFIG_CBS_VP9
#endif
#if CONFIG_CBS_AV1
#endif
#if CONFIG_CBS_H264
#endif
#if CONFIG_CBS_H265
#endif
#if CONFIG_CBS_JPEG
#endif
#if CONFIG_CBS_MPEG2
#endif
#if CONFIG_CBS_VP9
#endif
void ff_cbs_fragment_free(CodedBitstreamContext *ctx,
                          CodedBitstreamFragment *frag)
{
    ff_cbs_fragment_reset(ctx, frag);

    av_freep(&frag->units);
    frag->nb_units_allocated = 0;
}
