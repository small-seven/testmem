#include "libavcodec/elbg.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/random_seed.h"
#include "avfilter.h"
#include "drawutils.h"
#include "internal.h"
#include "video.h"
typedef struct ELBGContext {
    const AVClass *class;
    AVLFG lfg;
    unsigned int lfg_seed;
    int max_steps_nb;
    int *codeword;
    int codeword_length;
    int *codeword_closest_codebook_idxs;
    int *codebook;
    int codebook_length;
    const AVPixFmtDescriptor *pix_desc;
    uint8_t rgba_map[4];
    int pal8;
} ELBGContext;
#define OFFSET(x) offsetof(ELBGContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define NB_COMPONENTS 3
#define R 0
#define G 1
#define B 2
