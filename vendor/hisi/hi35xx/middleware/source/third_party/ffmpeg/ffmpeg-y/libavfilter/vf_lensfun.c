#include <float.h>
#include <math.h>
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libswscale/swscale.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include <lensfun.h>
#define LANCZOS_RESOLUTION 256
typedef struct VignettingThreadData {
    int width, height;
    uint8_t *data_in;
    int linesize_in;
    int pixel_composition;
    lfModifier *modifier;
} VignettingThreadData;
typedef struct DistortionCorrectionThreadData {
    int width, height;
    const float *distortion_coords;
    const uint8_t *data_in;
    uint8_t *data_out;
    int linesize_in, linesize_out;
    const float *interpolation;
    int mode;
    int interpolation_type;
} DistortionCorrectionThreadData;
typedef struct LensfunContext {
    const AVClass *class;
    const char *make, *model, *lens_model;
    int mode;
    float focal_length;
    float aperture;
    float focus_distance;
    float scale;
    int target_geometry;
    int reverse;
    int interpolation_type;

    float *distortion_coords;
    float *interpolation;

    lfLens *lens;
    lfCamera *camera;
    lfModifier *modifier;
} LensfunContext;
#define OFFSET(x) offsetof(LensfunContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
