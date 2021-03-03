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
#define MAX_DIAMETER 23
typedef struct UnsharpOpenCLContext {
    OpenCLFilterContext ocf;

    int              initialised;
    cl_kernel        kernel;
    cl_command_queue command_queue;

    float luma_size_x;
    float luma_size_y;
    float luma_amount;
    float chroma_size_x;
    float chroma_size_y;
    float chroma_amount;

    int global;

    int nb_planes;
    struct {
        float blur_x[MAX_DIAMETER];
        float blur_y[MAX_DIAMETER];

        cl_mem   matrix;
        cl_mem   coef_x;
        cl_mem   coef_y;

        cl_int   size_x;
        cl_int   size_y;
        cl_float amount;
        cl_float threshold;
    } plane[4];
#define OFFSET(x) offsetof(UnsharpOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
