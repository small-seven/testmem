#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "vf_nlmeans.h"
#include "video.h"
typedef struct NLMeansContext {
    const AVClass *class;
    int nb_planes;
    int chroma_w, chroma_h;
    double pdiff_scale;                         // invert of the filtering parameter (sigma*10) squared
    double sigma;                               // denoising strength
    int patch_size,    patch_hsize;             // patch size and half size
    int patch_size_uv, patch_hsize_uv;          // patch size and half size for chroma planes
    int research_size,    research_hsize;       // research size and half size
    int research_size_uv, research_hsize_uv;    // research size and half size for chroma planes
    uint32_t *ii_orig;                          // integral image
    uint32_t *ii;                               // integral image starting after the 0-line and 0-column
    int ii_w, ii_h;                             // width and height of the integral image
    ptrdiff_t ii_lz_32;                         // linesize in 32-bit units of the integral image
    struct weighted_avg *wa;                    // weighted average of every pixel
    ptrdiff_t wa_linesize;                      // linesize for wa in struct size unit
    float *weight_lut;                          // lookup table mapping (scaled) patch differences to their associated weights
    uint32_t max_meaningful_diff;               // maximum difference considered (if the patch difference is too high we ignore the pixel)
    NLMeansDSPContext dsp;
} NLMeansContext;
#define OFFSET(x) offsetof(NLMeansContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define CHECK_ODD_FIELD(field, name) do {                       \
