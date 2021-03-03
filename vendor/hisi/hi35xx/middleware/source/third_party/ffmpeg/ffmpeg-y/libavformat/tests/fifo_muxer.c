#include <stdlib.h>
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/avassert.h"
#include "libavformat/avformat.h"
#include "libavformat/url.h"
#include "libavformat/network.h"
#define MAX_TST_PACKETS 128
#define SLEEPTIME_50_MS 50000
#define SLEEPTIME_10_MS 10000
typedef struct FailingMuxerPacketData {
    int ret;             /* return value of write_packet call*/
    int recover_after;   /* set ret to zero after this number of recovery attempts */
    unsigned sleep_time; /* sleep for this long in write_packet to simulate long I/O operation */
} FailingMuxerPacketData;
typedef struct TestCase {
    int (*test_func)(AVFormatContext *, AVDictionary **,const FailingMuxerPacketData *pkt_data);
    const char *test_name;
    const char *options;

    uint8_t print_summary_on_deinit;
    int write_header_ret;
    int write_trailer_ret;

    FailingMuxerPacketData pkt_data;
} TestCase;
#define BUFFER_SIZE 64
