#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include <openjpeg.h>
typedef struct LibOpenJPEGContext {
    AVClass *avclass;
    opj_cparameters_t enc_params;
    int format;
    int profile;
    int prog_order;
    int cinema_mode;
    int numresolution;
    int irreversible;
    int disto_alloc;
    int fixed_quality;
} LibOpenJPEGContext;
typedef struct PacketWriter {
    int pos;
    AVPacket *packet;
} PacketWriter;
#define OFFSET(x) offsetof(LibOpenJPEGContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
