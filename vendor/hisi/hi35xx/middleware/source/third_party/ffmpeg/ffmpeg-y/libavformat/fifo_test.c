#include <stdlib.h>
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/avassert.h"
#include "avformat.h"
#include "url.h"
#define MAX_TST_PACKETS 128
#define SLEEPTIME_50_MS 50000
#define SLEEPTIME_10_MS 10000
typedef struct FailingMuxerPacketData {
    int ret;             /* return value of write_packet call*/
    int recover_after;   /* set ret to zero after this number of recovery attempts */
    unsigned sleep_time; /* sleep for this long in write_packet to simulate long I/O operation */
} FailingMuxerPacketData;
typedef struct FailingMuxerContext {
    AVClass *class;
    int write_header_ret;
    int write_trailer_ret;
    /* If non-zero, summary of processed packets will be printed in deinit */
    int print_deinit_summary;

    int flush_count;
    int pts_written[MAX_TST_PACKETS];
    int pts_written_nr;
} FailingMuxerContext;
#define OFFSET(x) offsetof(FailingMuxerContext, x)
