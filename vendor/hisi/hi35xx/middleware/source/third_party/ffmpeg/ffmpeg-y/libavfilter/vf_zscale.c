#include <float.h>
#include <stdio.h>
#include <string.h>
#include <zimg.h>
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/avassert.h"
typedef struct ZScaleContext {
    const AVClass *class;

    /**
     * New dimensions. Special values are:
     *   0 = original width/height
     *  -1 = keep original aspect
     *  -N = try to keep aspect but make sure it is divisible by N
     */
    int w, h;
    int dither;
    int filter;
    int colorspace;
    int trc;
    int primaries;
    int range;
    int chromal;
    int colorspace_in;
    int trc_in;
    int primaries_in;
    int range_in;
    int chromal_in;
    char *size_str;
    double nominal_peak_luminance;
    int approximate_gamma;

    char *w_expr;               ///< width  expression string
    char *h_expr;               ///< height expression string

    int out_h_chr_pos;
    int out_v_chr_pos;
    int in_h_chr_pos;
    int in_v_chr_pos;

    int force_original_aspect_ratio;

    void *tmp;
    size_t tmp_size;

    zimg_image_format src_format, dst_format;
    zimg_image_format alpha_src_format, alpha_dst_format;
    zimg_graph_builder_params alpha_params, params;
    zimg_filter_graph *alpha_graph, *graph;

    enum AVColorSpace in_colorspace, out_colorspace;
    enum AVColorTransferCharacteristic in_trc, out_trc;
    enum AVColorPrimaries in_primaries, out_primaries;
    enum AVColorRange in_range, out_range;
    enum AVChromaLocation in_chromal, out_chromal;
} ZScaleContext;
#define OFFSET(x) offsetof(ZScaleContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
