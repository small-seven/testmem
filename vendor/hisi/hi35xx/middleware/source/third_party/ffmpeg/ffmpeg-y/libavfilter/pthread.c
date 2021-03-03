#include "config.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/thread.h"
#include "libavutil/slicethread.h"
#include "avfilter.h"
#include "internal.h"
#include "thread.h"
typedef struct ThreadContext {
    AVFilterGraph *graph;
    AVSliceThread *thread;
    avfilter_action_func *func;

    /* per-execute parameters */
    AVFilterContext *ctx;
    void *arg;
    int   *rets;
} ThreadContext;
void ff_graph_thread_free(AVFilterGraph *graph)
{
    if (graph->internal->thread)
        slice_thread_uninit(graph->internal->thread);
    av_freep(&graph->internal->thread);
}
