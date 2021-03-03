#include "libavutil/avstring.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "framesync.h"
#include "internal.h"
#include "opencl.h"
#include "video.h"
typedef struct ProgramOpenCLContext {
    OpenCLFilterContext ocf;

    int                 loaded;
    cl_uint             index;
    cl_kernel           kernel;
    cl_command_queue    command_queue;

    FFFrameSync         fs;
    AVFrame           **frames;

    const char         *source_file;
    const char         *kernel_name;
    int                 nb_inputs;
    int                 width, height;
    enum AVPixelFormat  source_format;
    AVRational          source_rate;
} ProgramOpenCLContext;
#define OFFSET(x) offsetof(ProgramOpenCLContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
#if CONFIG_PROGRAM_OPENCL_FILTER
#endif
#if CONFIG_OPENCLSRC_FILTER
#endif
