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
typedef struct NLMeansOpenCLContext {
    OpenCLFilterContext   ocf;
    int                   initialised;
    cl_kernel             vert_kernel;
    cl_kernel             horiz_kernel;
    cl_kernel             accum_kernel;
    cl_kernel             average_kernel;
    cl_mem                integral_img;
    cl_mem                weight;
    cl_mem                sum;
    cl_mem                overflow; // overflow in integral image?
    double                sigma;
    float                 h;
    int                   chroma_w;
    int                   chroma_h;
    int                   patch_size;
    int                   patch_size_uv;
    int                   research_size;
    int                   research_size_uv;
    cl_command_queue      command_queue;
} NLMeansOpenCLContext;
#define OFFSET(x) offsetof(NLMeansOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
