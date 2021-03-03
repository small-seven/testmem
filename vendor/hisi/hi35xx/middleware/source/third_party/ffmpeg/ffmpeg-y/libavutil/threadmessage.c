#include "fifo.h"
#include "threadmessage.h"
#include "thread.h"
#if HAVE_THREADS
#else
#endif
#if HAVE_THREADS
#else
#endif /* HAVE_THREADS */
#if HAVE_THREADS
#endif
void av_thread_message_queue_free(AVThreadMessageQueue **mq)
{
#if HAVE_THREADS
    if (*mq) {
        av_thread_message_flush(*mq);
        av_fifo_freep(&(*mq)->fifo);
        pthread_cond_destroy(&(*mq)->cond_send);
        pthread_cond_destroy(&(*mq)->cond_recv);
        pthread_mutex_destroy(&(*mq)->lock);
        av_freep(mq);
    }
#endif
}
#if HAVE_THREADS
#else
#endif
#if HAVE_THREADS
#endif /* HAVE_THREADS */
#if HAVE_THREADS
#else
#endif /* HAVE_THREADS */
#if HAVE_THREADS
#else
#endif /* HAVE_THREADS */
#if HAVE_THREADS
#endif /* HAVE_THREADS */
#if HAVE_THREADS
#endif /* HAVE_THREADS */
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif /* HAVE_THREADS */
