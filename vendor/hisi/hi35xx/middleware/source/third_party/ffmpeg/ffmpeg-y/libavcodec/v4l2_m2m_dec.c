#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include "libavutil/pixfmt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/decode.h"
#include "v4l2_context.h"
#include "v4l2_m2m.h"
#include "v4l2_fmt.h"
#define OFFSET(x) offsetof(V4L2m2mPriv, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#define M2MDEC(NAME, LONGNAME, CODEC, bsf_name) \
