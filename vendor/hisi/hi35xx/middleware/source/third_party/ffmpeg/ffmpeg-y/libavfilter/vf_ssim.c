#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "ssim.h"
#include "video.h"
typedef struct SSIMContext {
    const AVClass *class;
    FFFrameSync fs;
    FILE *stats_file;
    char *stats_file_str;
    int nb_components;
    int max;
    uint64_t nb_frames;
    double ssim[4], ssim_total;
    char comps[4];
    float coefs[4];
    uint8_t rgba_map[4];
    int planewidth[4];
    int planeheight[4];
    int *temp;
    int is_rgb;
    float (*ssim_plane)(SSIMDSPContext *dsp,
                        uint8_t *main, int main_stride,
                        uint8_t *ref, int ref_stride,
                        int width, int height, void *temp,
                        int max);
    SSIMDSPContext dsp;
} SSIMContext;
#define OFFSET(x) offsetof(SSIMContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define SUM_LEN(w) (((w) >> 2) + 3)
#define PF(suf) AV_PIX_FMT_YUV420##suf,  AV_PIX_FMT_YUV422##suf,  AV_PIX_FMT_YUV444##suf, AV_PIX_FMT_GBR##suf
