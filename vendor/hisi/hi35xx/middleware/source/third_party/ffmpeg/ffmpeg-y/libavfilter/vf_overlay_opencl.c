#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "framesync.h"
#include "internal.h"
#include "opencl.h"
#include "opencl_source.h"
#include "video.h"
typedef struct OverlayOpenCLContext {
    OpenCLFilterContext ocf;

    int              initialised;
    cl_kernel        kernel;
    cl_command_queue command_queue;

    FFFrameSync      fs;

    int              nb_planes;
    int              x_subsample;
    int              y_subsample;
    int              alpha_separate;

    int              x_position;
    int              y_position;
} OverlayOpenCLContext;
#define OFFSET(x) offsetof(OverlayOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
