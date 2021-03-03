#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
typedef struct WebpContext{
    AVClass *class;
    int frame_count;
    AVPacket last_pkt;
    int loop;
    int wrote_webp_header;
    int using_webp_anim_encoder;
} WebpContext;
#define OFFSET(x) offsetof(WebpContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
