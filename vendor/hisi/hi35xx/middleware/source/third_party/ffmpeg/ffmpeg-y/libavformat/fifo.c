#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/thread.h"
#include "libavutil/threadmessage.h"
#include "avformat.h"
#include "internal.h"
#define FIFO_DEFAULT_QUEUE_SIZE              60
#define FIFO_DEFAULT_MAX_RECOVERY_ATTEMPTS   0
#define FIFO_DEFAULT_RECOVERY_WAIT_TIME_USEC 5000000 // 5 seconds
typedef struct FifoContext {
    const AVClass *class;
    AVFormatContext *avf;

    char *format;
    char *format_options_str;
    AVDictionary *format_options;

    int queue_size;
    AVThreadMessageQueue *queue;

    pthread_t writer_thread;

    /* Return value of last write_trailer_call */
    int write_trailer_ret;

    /* Time to wait before next recovery attempt
     * This can refer to the time in processed stream,
     * or real time. */
    int64_t recovery_wait_time;

    /* Maximal number of unsuccessful successive recovery attempts */
    int max_recovery_attempts;

    /* Whether to attempt recovery from failure */
    int attempt_recovery;

    /* If >0 stream time will be used when waiting
     * for the recovery attempt instead of real time */
    int recovery_wait_streamtime;

    /* If >0 recovery will be attempted regardless of error code
     * (except AVERROR_EXIT, so exit request is never ignored) */
    int recover_any_error;

    /* Whether to drop packets in case the queue is full. */
    int drop_pkts_on_overflow;

    /* Whether to wait for keyframe when recovering
     * from failure or queue overflow */
    int restart_with_keyframe;

    pthread_mutex_t overflow_flag_lock;
    int overflow_flag_lock_initialized;
    /* Value > 0 signals queue overflow */
    volatile uint8_t overflow_flag;

} FifoContext;
typedef struct FifoThreadContext {
    AVFormatContext *avf;

    /* Timestamp of last failure.
     * This is either pts in case stream time is used,
     * or microseconds as returned by av_getttime_relative() */
    int64_t last_recovery_ts;

    /* Number of current recovery process
     * Value > 0 means we are in recovery process */
    int recovery_nr;

    /* If > 0 all frames will be dropped until keyframe is received */
    uint8_t drop_until_keyframe;

    /* Value > 0 means that the previous write_header call was successful
     * so finalization by calling write_trailer and ff_io_close must be done
     * before exiting / reinitialization of underlying muxer */
    uint8_t header_written;
} FifoThreadContext;
typedef enum FifoMessageType {
    FIFO_WRITE_HEADER,
    FIFO_WRITE_PACKET,
    FIFO_FLUSH_OUTPUT
} FifoMessageType;
typedef struct FifoMessage {
    FifoMessageType type;
    AVPacket pkt;
} FifoMessage;
#define OFFSET(x) offsetof(FifoContext, x)
