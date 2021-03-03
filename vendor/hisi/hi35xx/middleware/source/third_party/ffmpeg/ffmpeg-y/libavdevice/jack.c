#include "config.h"
#include <semaphore.h>
#include <jack/jack.h>
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/fifo.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
#include "timefilter.h"
#include "avdevice.h"
#define FIFO_PACKETS_NUM 16
typedef struct JackData {
    AVClass        *class;
    jack_client_t * client;
    int             activated;
    sem_t           packet_count;
    jack_nframes_t  sample_rate;
    jack_nframes_t  buffer_size;
    jack_port_t **  ports;
    int             nports;
    TimeFilter *    timefilter;
    AVFifoBuffer *  new_pkts;
    AVFifoBuffer *  filled_pkts;
    int             pkt_xrun;
    int             jack_xrun;
} JackData;
#if HAVE_BIGENDIAN
#else
#endif
#define OFFSET(x) offsetof(JackData, x)
