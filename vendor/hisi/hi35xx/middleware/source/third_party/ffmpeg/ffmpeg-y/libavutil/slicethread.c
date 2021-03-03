#include <stdatomic.h>
#include "slicethread.h"
#include "mem.h"
#include "thread.h"
#include "avassert.h"
#if HAVE_PTHREADS || HAVE_W32THREADS || HAVE_OS2THREADS
typedef struct WorkerContext {
    AVSliceThread   *ctx;
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    pthread_t       thread;
    int             done;
} WorkerContext;
void avpriv_slicethread_free(AVSliceThread **pctx)
{
    AVSliceThread *ctx;
    int nb_workers, i;

    if (!pctx || !*pctx)
        return;

    ctx = *pctx;
    nb_workers = ctx->nb_threads;
    if (!ctx->main_func)
        nb_workers--;

    ctx->finished = 1;
    for (i = 0; i < nb_workers; i++) {
        WorkerContext *w = &ctx->workers[i];
        pthread_mutex_lock(&w->mutex);
        w->done = 0;
        pthread_cond_signal(&w->cond);
        pthread_mutex_unlock(&w->mutex);
    }

    for (i = 0; i < nb_workers; i++) {
        WorkerContext *w = &ctx->workers[i];
        pthread_join(w->thread, NULL);
        pthread_cond_destroy(&w->cond);
        pthread_mutex_destroy(&w->mutex);
    }

    pthread_cond_destroy(&ctx->done_cond);
    pthread_mutex_destroy(&ctx->done_mutex);
    av_freep(&ctx->workers);
    av_freep(pctx);
}
#else /* HAVE_PTHREADS || HAVE_W32THREADS || HAVE_OS32THREADS */
void avpriv_slicethread_free(AVSliceThread **pctx)
{
    av_assert0(!pctx || !*pctx);
}
#endif /* HAVE_PTHREADS || HAVE_W32THREADS || HAVE_OS32THREADS */
