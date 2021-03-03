#include <stdatomic.h>
#include "frame_thread_encoder.h"
#include "libavutil/fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/thread.h"
#include "avcodec.h"
#include "internal.h"
#include "thread.h"
#define MAX_THREADS 64
#define BUFFER_SIZE (2*MAX_THREADS)
typedef struct{
    void *indata;
    void *outdata;
    int64_t return_code;
    unsigned index;
} Task;
typedef struct{
    AVCodecContext *parent_avctx;
    pthread_mutex_t buffer_mutex;

    AVFifoBuffer *task_fifo;
    pthread_mutex_t task_fifo_mutex;
    pthread_cond_t task_fifo_cond;

    Task finished_tasks[BUFFER_SIZE];
    pthread_mutex_t finished_task_mutex;
    pthread_cond_t finished_task_cond;

    unsigned task_index;
    unsigned finished_task_index;

    pthread_t worker[MAX_THREADS];
    atomic_int exit;
} ThreadContext;
