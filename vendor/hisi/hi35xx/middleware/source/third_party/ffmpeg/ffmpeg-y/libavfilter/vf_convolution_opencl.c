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
typedef struct ConvolutionOpenCLContext {
    OpenCLFilterContext ocf;

    int              initialised;
    cl_kernel        kernel;
    cl_command_queue command_queue;

    char *matrix_str[4];

    cl_mem matrix[4];
    cl_int matrix_sizes[4];
    cl_int dims[4];
    cl_float rdivs[4];
    cl_float biases[4];

    cl_int planes;
    cl_float scale;
    cl_float delta;

} ConvolutionOpenCLContext;
#define OFFSET(x) offsetof(ConvolutionOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
#if CONFIG_CONVOLUTION_OPENCL_FILTER
#endif /* CONFIG_CONVOLUTION_OPENCL_FILTER */
#if CONFIG_SOBEL_OPENCL_FILTER
#endif /* CONFIG_SOBEL_OPENCL_FILTER */
#if CONFIG_PREWITT_OPENCL_FILTER
#endif /* CONFIG_PREWITT_OPENCL_FILTER */
#if CONFIG_ROBERTS_OPENCL_FILTER
#endif /* CONFIG_ROBERTS_OPENCL_FILTER */
