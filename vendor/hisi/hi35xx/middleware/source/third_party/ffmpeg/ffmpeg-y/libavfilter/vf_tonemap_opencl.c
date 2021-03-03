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
#include "colorspace.h"
#define DETECTION_FRAMES 63
typedef struct TonemapOpenCLContext {
    OpenCLFilterContext ocf;

    enum AVColorSpace colorspace, colorspace_in, colorspace_out;
    enum AVColorTransferCharacteristic trc, trc_in, trc_out;
    enum AVColorPrimaries primaries, primaries_in, primaries_out;
    enum AVColorRange range, range_in, range_out;
    enum AVChromaLocation chroma_loc;

    enum TonemapAlgorithm tonemap;
    enum AVPixelFormat    format;
    double                peak;
    double                param;
    double                desat_param;
    double                target_peak;
    double                scene_threshold;
    int                   initialised;
    cl_kernel             kernel;
    cl_command_queue      command_queue;
    cl_mem                util_mem;
} TonemapOpenCLContext;
#define OPENCL_SOURCE_NB 3
#ifndef NDEBUG
#endif
#define OFFSET(x) offsetof(TonemapOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
