#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "opencl.h"
#include "opencl_source.h"
#include "video.h"
#include "transpose.h"
typedef struct TransposeOpenCLContext {
    OpenCLFilterContext ocf;
    int                   initialised;
    int passthrough;    ///< PassthroughType, landscape passthrough mode enabled
    int dir;            ///< TransposeDir
    cl_kernel             kernel;
    cl_command_queue      command_queue;
} TransposeOpenCLContext;
#define OFFSET(x) offsetof(TransposeOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
