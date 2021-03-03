#include "movenccenc.h"
#include "libavutil/intreadwrite.h"
#include "avio_internal.h"
#include "movenc.h"
#include "avc.h"
void ff_mov_cenc_free(MOVMuxCencContext* ctx)
{
    av_aes_ctr_free(ctx->aes_ctr);
}
