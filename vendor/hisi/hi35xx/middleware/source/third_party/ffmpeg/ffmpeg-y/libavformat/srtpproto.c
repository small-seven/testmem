#include "libavutil/opt.h"
#include "avformat.h"
#include "avio_internal.h"
#include "url.h"
#include "internal.h"
#include "rtpdec.h"
#include "srtp.h"
typedef struct SRTPProtoContext {
    const AVClass *class;
    URLContext *rtp_hd;
    const char *out_suite, *out_params;
    const char *in_suite, *in_params;
    struct SRTPContext srtp_out, srtp_in;
    uint8_t encryptbuf[RTP_MAX_PACKET_LENGTH];
} SRTPProtoContext;
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
