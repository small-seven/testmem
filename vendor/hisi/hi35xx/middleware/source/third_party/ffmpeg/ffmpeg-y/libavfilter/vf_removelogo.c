#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "bbox.h"
#include "lavfutils.h"
#include "lswsutils.h"
typedef struct RemovelogoContext {
    const AVClass *class;
    char *filename;
    /* Stores our collection of masks. The first is for an array of
       the second for the y axis, and the third for the x axis. */
    int ***mask;
    int max_mask_size;
    int mask_w, mask_h;

    uint8_t      *full_mask_data;
    FFBoundingBox full_mask_bbox;
    uint8_t      *half_mask_data;
    FFBoundingBox half_mask_bbox;
} RemovelogoContext;
#define OFFSET(x) offsetof(RemovelogoContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define apply_mask_fudge_factor(x) (((x) >> 2) + (x))
#define SHOW_LOGO_INFO(mask_type)                                       \
