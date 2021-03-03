#include <string.h>
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/rational.h"
#include "libavutil/stereo3d.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define LEFT  0
#define RIGHT 1
typedef struct FramepackContext {
    const AVClass *class;

    const AVPixFmtDescriptor *pix_desc; ///< agreed pixel format

    enum AVStereo3DType format;         ///< frame pack type output

    AVFrame *input_views[2];            ///< input frames

    int64_t double_pts;                 ///< new pts for frameseq mode
} FramepackContext;
#define OFFSET(x) offsetof(FramepackContext, x)
#define V AV_OPT_FLAG_VIDEO_PARAM
