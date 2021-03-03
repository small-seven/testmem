#include "libavutil/avstring.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avformat.h"
#if CONFIG_NETWORK
#include "network.h"
#endif
#include "url.h"
#include <librtmp/rtmp.h>
#include <librtmp/log.h>
typedef struct LibRTMPContext {
    const AVClass *class;
    RTMP rtmp;
    char *app;
    char *conn;
    char *subscribe;
    char *playpath;
    char *tcurl;
    char *flashver;
    char *swfurl;
    char *swfverify;
    char *pageurl;
    char *client_buffer_time;
    int live;
    char *temp_filename;
    int buffer_size;
} LibRTMPContext;
#if CONFIG_NETWORK
#endif
#define OFFSET(x) offsetof(LibRTMPContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
#define ENC AV_OPT_FLAG_ENCODING_PARAM
#if CONFIG_NETWORK
#endif
#define RTMP_CLASS(flavor)\
