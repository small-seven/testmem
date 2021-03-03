#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "opencl.h"
#include "opencl_source.h"
#include "video.h"
typedef struct ColorkeyOpenCLContext {
    OpenCLFilterContext ocf;
    // Whether or not the above `OpenCLFilterContext` has been initialized
    int initialized;

    cl_command_queue command_queue;
    cl_kernel kernel_colorkey;

    // The color we are supposed to replace with transparency
    uint8_t colorkey_rgba[4];
    // Stored as a normalized float for passing to the OpenCL kernel
    cl_float4 colorkey_rgba_float;
    // Similarity percentage compared to `colorkey_rgba`, ranging from `0.01` to `1.0`
    // where `0.01` matches only the key color and `1.0` matches all colors
    float similarity;
    // Blending percentage where `0.0` results in fully transparent pixels, `1.0` results
    // in fully opaque pixels, and numbers in between result in transparency that varies
    // based on the similarity to the key color
    float blend;
} ColorkeyOpenCLContext;
#define OFFSET(x) offsetof(ColorkeyOpenCLContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
