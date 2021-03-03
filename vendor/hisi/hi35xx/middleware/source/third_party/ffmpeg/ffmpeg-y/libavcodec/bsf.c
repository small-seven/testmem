#include <string.h>
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "avcodec.h"
#include "bsf.h"
void av_bsf_free(AVBSFContext **pctx)
{
    AVBSFContext *ctx;

    if (!pctx || !*pctx)
        return;
    ctx = *pctx;

    if (ctx->filter->close)
        ctx->filter->close(ctx);
    if (ctx->filter->priv_class && ctx->priv_data)
        av_opt_free(ctx->priv_data);

    av_opt_free(ctx);

    if (ctx->internal)
        av_packet_free(&ctx->internal->buffer_pkt);
    av_freep(&ctx->internal);
    av_freep(&ctx->priv_data);

    avcodec_parameters_free(&ctx->par_in);
    avcodec_parameters_free(&ctx->par_out);

    av_freep(pctx);
}
typedef struct BSFListContext {
    const AVClass *class;

    AVBSFContext **bsfs;
    int nb_bsfs;

    unsigned idx;           // index of currently processed BSF
    unsigned flushed_idx;   // index of BSF being flushed

    char * item_name;
} BSFListContext;
void av_bsf_list_free(AVBSFList **lst)
{
    int i;

    if (!*lst)
        return;

    for (i = 0; i < (*lst)->nb_bsfs; ++i)
        av_bsf_free(&(*lst)->bsfs[i]);
    av_free((*lst)->bsfs);
    av_freep(lst);
}
