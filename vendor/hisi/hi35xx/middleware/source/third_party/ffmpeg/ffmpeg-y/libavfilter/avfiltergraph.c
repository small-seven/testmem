#include "config.h"
#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/channel_layout.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#define FF_INTERNAL_FIELDS 1
#include "framequeue.h"
#include "avfilter.h"
#include "buffersink.h"
#include "formats.h"
#include "internal.h"
#include "thread.h"
#define OFFSET(x) offsetof(AVFilterGraph, x)
#define F AV_OPT_FLAG_FILTERING_PARAM
#define V AV_OPT_FLAG_VIDEO_PARAM
#define A AV_OPT_FLAG_AUDIO_PARAM
#if !HAVE_THREADS
void ff_graph_thread_free(AVFilterGraph *graph)
{
}
#endif
void avfilter_graph_free(AVFilterGraph **graph)
{
    if (!*graph)
        return;

    while ((*graph)->nb_filters)
        avfilter_free((*graph)->filters[0]);

    ff_graph_thread_free(*graph);

    av_freep(&(*graph)->sink_links);

    av_freep(&(*graph)->scale_sws_opts);
    av_freep(&(*graph)->aresample_swr_opts);
#if FF_API_LAVR_OPTS
    av_freep(&(*graph)->resample_lavr_opts);
#endif
    av_freep(&(*graph)->filters);
    av_freep(&(*graph)->internal);
    av_freep(graph);
}
#define MERGE_DISPATCH(field, statement)                                     \
#undef MERGE_DISPATCH
#define REDUCE_FORMATS(fmt_type, list_type, list, var, nb, add_format, unref_format) \
#define CH_CENTER_PAIR (AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER)
#define CH_FRONT_PAIR  (AV_CH_FRONT_LEFT           | AV_CH_FRONT_RIGHT)
#define CH_STEREO_PAIR (AV_CH_STEREO_LEFT          | AV_CH_STEREO_RIGHT)
#define CH_WIDE_PAIR   (AV_CH_WIDE_LEFT            | AV_CH_WIDE_RIGHT)
#define CH_SIDE_PAIR   (AV_CH_SIDE_LEFT            | AV_CH_SIDE_RIGHT)
#define CH_DIRECT_PAIR (AV_CH_SURROUND_DIRECT_LEFT | AV_CH_SURROUND_DIRECT_RIGHT)
#define CH_BACK_PAIR   (AV_CH_BACK_LEFT            | AV_CH_BACK_RIGHT)
