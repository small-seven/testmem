#include "config.h"
#include "avcodec.h"
#include "internal.h"
#include "pthread_internal.h"
#include "thread.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/thread.h"
#include "libavutil/slicethread.h"
typedef int (action_func)(AVCodecContext *c, void *arg);
typedef int (action_func2)(AVCodecContext *c, void *arg, int jobnr, int threadnr);
typedef int (main_func)(AVCodecContext *c);

typedef struct SliceThreadContext {
    AVSliceThread *thread;
    action_func *func;
    action_func2 *func2;
    main_func *mainfunc;
    void *args;
    int *rets;
    int job_size;

    int *entries;
    int entries_count;
    int thread_count;
    pthread_cond_t *progress_cond;
    pthread_mutex_t *progress_mutex;
} SliceThreadContext;
void ff_slice_thread_free(AVCodecContext *avctx)
{
    SliceThreadContext *c = avctx->internal->thread_ctx;
    int i;

    avpriv_slicethread_free(&c->thread);

    for (i = 0; i < c->thread_count; i++) {
        pthread_mutex_destroy(&c->progress_mutex[i]);
        pthread_cond_destroy(&c->progress_cond[i]);
    }

    av_freep(&c->entries);
    av_freep(&c->progress_mutex);
    av_freep(&c->progress_cond);
    av_freep(&avctx->internal->thread_ctx);
}
