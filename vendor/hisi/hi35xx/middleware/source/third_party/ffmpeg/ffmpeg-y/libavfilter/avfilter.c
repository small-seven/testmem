#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/buffer.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/hwcontext.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/rational.h"
#include "libavutil/samplefmt.h"
#include "libavutil/thread.h"
#define FF_INTERNAL_FIELDS 1
#include "framequeue.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "libavutil/ffversion.h"
#define LICENSE_PREFIX "libavfilter license: "
void avfilter_link_free(AVFilterLink **link)
{
    if (!*link)
        return;

    av_frame_free(&(*link)->partial_buf);
    ff_framequeue_free(&(*link)->fifo);
    ff_frame_pool_uninit((FFFramePool**)&(*link)->frame_pool);

    av_freep(link);
}
#if FF_API_FILTER_GET_SET
#endif
#define OFFSET(x) offsetof(AVFilterContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM
void avfilter_free(AVFilterContext *filter)
{
    int i;

    if (!filter)
        return;

    if (filter->graph)
        ff_filter_graph_remove_filter(filter->graph, filter);

    if (filter->filter->uninit)
        filter->filter->uninit(filter);

    for (i = 0; i < filter->nb_inputs; i++) {
        free_link(filter->inputs[i]);
    }
    for (i = 0; i < filter->nb_outputs; i++) {
        free_link(filter->outputs[i]);
    }

    if (filter->filter->priv_class)
        av_opt_free(filter->priv);

    av_buffer_unref(&filter->hw_device_ctx);

    av_freep(&filter->name);
    av_freep(&filter->input_pads);
    av_freep(&filter->output_pads);
    av_freep(&filter->inputs);
    av_freep(&filter->outputs);
    av_freep(&filter->priv);
    while(filter->command_queue){
        ff_command_queue_pop(filter);
    }
    av_opt_free(filter);
    av_expr_free(filter->enable);
    filter->enable = NULL;
    av_freep(&filter->var_values);
    av_freep(&filter->internal);
    av_free(filter);
}
#if FF_API_OLD_FILTER_OPTS_ERROR
#endif
