#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixfmt.h"
#include "avfilter.h"
#include "colorspacedsp.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "colorspace.h"
typedef struct ColorSpaceContext {
    const AVClass *class;

    ColorSpaceDSPContext dsp;

    enum Colorspace user_all, user_iall;
    enum AVColorSpace in_csp, out_csp, user_csp, user_icsp;
    enum AVColorRange in_rng, out_rng, user_rng, user_irng;
    enum AVColorTransferCharacteristic in_trc, out_trc, user_trc, user_itrc;
    enum AVColorPrimaries in_prm, out_prm, user_prm, user_iprm;
    enum AVPixelFormat in_format, user_format;
    int fast_mode;
    enum DitherMode dither;
    enum WhitepointAdaptation wp_adapt;

    int16_t *rgb[3];
    ptrdiff_t rgb_stride;
    unsigned rgb_sz;
    int *dither_scratch[3][2], *dither_scratch_base[3][2];

    const struct ColorPrimaries *in_primaries, *out_primaries;
    int lrgb2lrgb_passthrough;
    DECLARE_ALIGNED(16, int16_t, lrgb2lrgb_coeffs)[3][3][8];

    const struct TransferCharacteristics *in_txchr, *out_txchr;
    int rgb2rgb_passthrough;
    int16_t *lin_lut, *delin_lut;

    const struct LumaCoefficients *in_lumacoef, *out_lumacoef;
    int yuv2yuv_passthrough, yuv2yuv_fastmode;
    DECLARE_ALIGNED(16, int16_t, yuv2rgb_coeffs)[3][3][8];
    DECLARE_ALIGNED(16, int16_t, rgb2yuv_coeffs)[3][3][8];
    DECLARE_ALIGNED(16, int16_t, yuv2yuv_coeffs)[3][3][8];
    DECLARE_ALIGNED(16, int16_t, yuv_offset)[2 /* in, out */][8];
    yuv2rgb_fn yuv2rgb;
    rgb2yuv_fn rgb2yuv;
    rgb2yuv_fsb_fn rgb2yuv_fsb;
    yuv2yuv_fn yuv2yuv;
    double yuv2rgb_dbl_coeffs[3][3], rgb2yuv_dbl_coeffs[3][3];
    int in_y_rng, in_uv_rng, out_y_rng, out_uv_rng;

    int did_warn_range;
} ColorSpaceContext;
#define supported_depth(d) ((d) == 8 || (d) == 10 || (d) == 12)
#define supported_subsampling(lcw, lch) \
#define supported_format(d) \
#define OFFSET(x) offsetof(ColorSpaceContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#define ENUM(x, y, z) { x, "", 0, AV_OPT_TYPE_CONST, { .i64 = y }, INT_MIN, INT_MAX, FLAGS, z }
