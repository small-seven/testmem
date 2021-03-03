#include "config.h"
#include <stdatomic.h>
#include <stdint.h>
#include "avcodec.h"
#include "hwaccel.h"
#include "internal.h"
#include "pthread_internal.h"
#include "thread.h"
#include "version.h"
#include "libavutil/avassert.h"
#include "libavutil/buffer.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/frame.h"
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/thread.h"
typedef struct PerThreadContext {
    struct FrameThreadContext *parent;

    pthread_t      thread;
    int            thread_init;
    pthread_cond_t input_cond;      ///< Used to wait for a new packet from the main thread.
    pthread_cond_t progress_cond;   ///< Used by child threads to wait for progress to change.
    pthread_cond_t output_cond;     ///< Used by the main thread to wait for frames to finish.

    pthread_mutex_t mutex;          ///< Mutex used to protect the contents of the PerThreadContext.
    pthread_mutex_t progress_mutex; ///< Mutex used to protect frame progress values and progress_cond.

    AVCodecContext *avctx;          ///< Context used to decode packets passed to this thread.

    AVPacket       avpkt;           ///< Input packet (for decoding) or output (for encoding).

    AVFrame *frame;                 ///< Output frame (for decoding) or input (for encoding).
    int     got_frame;              ///< The output of got_picture_ptr from the last avcodec_decode_video() call.
    int     result;                 ///< The result of the last codec decode/encode() call.

    atomic_int state;

    /**
     * Array of frames passed to ff_thread_release_buffer().
     * Frames are released after all threads referencing them are finished.
     */
    AVFrame *released_buffers;
    int  num_released_buffers;
    int      released_buffers_allocated;

    AVFrame *requested_frame;       ///< AVFrame the codec passed to get_buffer()
    int      requested_flags;       ///< flags passed to get_buffer() for requested_frame

    const enum AVPixelFormat *available_formats; ///< Format array for get_format()
    enum AVPixelFormat result_format;            ///< get_format() result

    int die;                        ///< Set when the thread should exit.

    int hwaccel_serializing;
    int async_serializing;

    atomic_int debug_threads;       ///< Set if the FF_DEBUG_THREADS option is set.
} PerThreadContext;
typedef struct FrameThreadContext {
    PerThreadContext *threads;     ///< The contexts for each thread.
    PerThreadContext *prev_thread; ///< The last thread submit_packet() was called on.

    pthread_mutex_t buffer_mutex;  ///< Mutex used to protect get/release_buffer().
    /**
     * This lock is used for ensuring threads run in serial when hwaccel
     * is used.
     */
    pthread_mutex_t hwaccel_mutex;
    pthread_mutex_t async_mutex;
    pthread_cond_t async_cond;
    int async_lock;

    int next_decoding;             ///< The next context to submit a packet to.
    int next_finished;             ///< The next context to return output from.

    int delaying;                  /**<
                                    * Set for the first N packets, where N is the number of threads.
                                    * While it is set, ff_thread_en/decode_frame won't return any results.
                                    */
} FrameThreadContext;
#define THREAD_SAFE_CALLBACKS(avctx) \
#if FF_API_CODED_FRAME
#endif
#define copy_fields(s, e) memcpy(&dst->s, &src->s, (char*)&dst->e - (char*)&dst->s);
#undef copy_fields
void ff_frame_thread_free(AVCodecContext *avctx, int thread_count)
{
    FrameThreadContext *fctx = avctx->internal->thread_ctx;
    const AVCodec *codec = avctx->codec;
    int i;

    park_frame_worker_threads(fctx, thread_count);

    if (fctx->prev_thread && fctx->prev_thread != fctx->threads)
        if (update_context_from_thread(fctx->threads->avctx, fctx->prev_thread->avctx, 0) < 0) {
            av_log(avctx, AV_LOG_ERROR, "Final thread update failed\n");
            fctx->prev_thread->avctx->internal->is_copy = fctx->threads->avctx->internal->is_copy;
            fctx->threads->avctx->internal->is_copy = 1;
        }

    for (i = 0; i < thread_count; i++) {
        PerThreadContext *p = &fctx->threads[i];

        pthread_mutex_lock(&p->mutex);
        p->die = 1;
        pthread_cond_signal(&p->input_cond);
        pthread_mutex_unlock(&p->mutex);

        if (p->thread_init)
            pthread_join(p->thread, NULL);
        p->thread_init=0;

        if (codec->close && p->avctx)
            codec->close(p->avctx);

        release_delayed_buffers(p);
        av_frame_free(&p->frame);
    }

    for (i = 0; i < thread_count; i++) {
        PerThreadContext *p = &fctx->threads[i];

        pthread_mutex_destroy(&p->mutex);
        pthread_mutex_destroy(&p->progress_mutex);
        pthread_cond_destroy(&p->input_cond);
        pthread_cond_destroy(&p->progress_cond);
        pthread_cond_destroy(&p->output_cond);
        av_packet_unref(&p->avpkt);
        av_freep(&p->released_buffers);

        if (i && p->avctx) {
            av_freep(&p->avctx->priv_data);
            av_freep(&p->avctx->slice_offset);
        }

        if (p->avctx) {
            av_freep(&p->avctx->internal);
            av_buffer_unref(&p->avctx->hw_frames_ctx);
        }

        av_freep(&p->avctx);
    }

    av_freep(&fctx->threads);
    pthread_mutex_destroy(&fctx->buffer_mutex);
    pthread_mutex_destroy(&fctx->hwaccel_mutex);
    pthread_mutex_destroy(&fctx->async_mutex);
    pthread_cond_destroy(&fctx->async_cond);

    av_freep(&avctx->internal->thread_ctx);

    if (avctx->priv_data && avctx->codec && avctx->codec->priv_class)
        av_opt_free(avctx->priv_data);
    avctx->codec = NULL;
}
#if FF_API_DEBUG_MV
#endif
