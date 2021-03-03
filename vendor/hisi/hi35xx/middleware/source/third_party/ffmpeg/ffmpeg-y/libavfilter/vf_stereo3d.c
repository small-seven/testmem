#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "stereo3d.h"
typedef struct StereoComponent {
    int format;                 ///< StereoCode
    int width, height;
    int off_left, off_right;
    int off_lstep, off_rstep;
    int row_left, row_right;
    int row_step;
} StereoComponent;
typedef struct Stereo3DContext {
    const AVClass *class;
    StereoComponent in, out;
    int width, height;
    const int *ana_matrix[3];
    int nb_planes;
    int linesize[4];
    int pheight[4];
    int hsub, vsub;
    int pixstep[4];
    AVFrame *prev;
    int blanks;
    int in_off_left[4], in_off_right[4];
    AVRational aspect;
    Stereo3DDSPContext dsp;
} Stereo3DContext;
#define OFFSET(x) offsetof(Stereo3DContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    AVFrame *ileft, *iright;
    AVFrame *out;
} ThreadData;
