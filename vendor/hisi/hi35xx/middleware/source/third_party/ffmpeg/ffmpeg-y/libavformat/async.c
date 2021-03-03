#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/error.h"
#include "libavutil/fifo.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/thread.h"
#include "url.h"
#include <stdint.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#define BUFFER_CAPACITY         (4 * 1024 * 1024)
#define READ_BACK_CAPACITY      (4 * 1024 * 1024)
#define SHORT_SEEK_THRESHOLD    (256 * 1024)
typedef struct RingBuffer
{
    AVFifoBuffer *fifo;
    int           read_back_capacity;

    int           read_pos;
} RingBuffer;
typedef struct Context {
    AVClass        *class;
    URLContext     *inner;

    int             seek_request;
    int64_t         seek_pos;
    int             seek_whence;
    int             seek_completed;
    int64_t         seek_ret;

    int             inner_io_error;
    int             io_error;
    int             io_eof_reached;

    int64_t         logical_pos;
    int64_t         logical_size;
    RingBuffer      ring;

    pthread_cond_t  cond_wakeup_main;
    pthread_cond_t  cond_wakeup_background;
    pthread_mutex_t mutex;
    pthread_t       async_buffer_thread;

    int             abort_request;
    AVIOInterruptCB interrupt_callback;
} Context;
static void ring_destroy(RingBuffer *ring)
{
    av_fifo_freep(&ring->fifo);
}
#define OFFSET(x) offsetof(Context, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#undef D
#undef OFFSET
#if 0
#define TEST_SEEK_POS    (1536)
#define TEST_STREAM_SIZE (2048)
typedef struct TestContext {
    AVClass        *class;
    int64_t         logical_pos;
    int64_t         logical_size;

    /* options */
    int             opt_read_error;
} TestContext;
#define OFFSET(x) offsetof(TestContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#undef D
#undef OFFSET
#endif
