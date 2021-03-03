#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "opencl.h"
#include "opencl_source.h"
#include "video.h"
#include "boxblur.h"
typedef struct AverageBlurOpenCLContext {
    OpenCLFilterContext ocf;

    int              initialised;
    cl_kernel        kernel_horiz;
    cl_kernel        kernel_vert;
    cl_command_queue command_queue;

    int radiusH;
    int radiusV;
    int planes;

    FilterParam luma_param;
    FilterParam chroma_param;
    FilterParam alpha_param;
    int radius[4];
    int power[4];

} AverageBlurOpenCLContext;
#define OFFSET(x) offsetof(AverageBlurOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
#if CONFIG_AVGBLUR_OPENCL_FILTER
#endif /* CONFIG_AVGBLUR_OPENCL_FILTER */
#if CONFIG_BOXBLUR_OPENCL_FILTER
#endif /* CONFIG_BOXBLUR_OPENCL_FILTER */
