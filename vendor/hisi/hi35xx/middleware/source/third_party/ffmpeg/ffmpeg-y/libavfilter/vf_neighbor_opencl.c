#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avstring.h"
#include "avfilter.h"
#include "internal.h"
#include "opencl.h"
#include "opencl_source.h"
#include "video.h"
typedef struct NeighborOpenCLContext {
    OpenCLFilterContext ocf;

    int              initialised;
    cl_kernel        kernel;
    cl_command_queue command_queue;

    char *matrix_str[4];

    cl_float threshold[4];
    cl_int coordinates;
    cl_mem coord;

} NeighborOpenCLContext;
#define OFFSET(x) offsetof(NeighborOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
#if CONFIG_EROSION_OPENCL_FILTER
#endif /* CONFIG_EROSION_OPENCL_FILTER */
#if CONFIG_DILATION_OPENCL_FILTER
#endif /* CONFIG_DILATION_OPENCL_FILTER */
