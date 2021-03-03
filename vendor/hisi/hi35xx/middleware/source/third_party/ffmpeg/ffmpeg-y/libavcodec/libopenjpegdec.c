#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixfmt.h"
#include "avcodec.h"
#include "internal.h"
#include "thread.h"
#include <openjpeg.h>
#define JP2_SIG_TYPE    0x6A502020
#define JP2_SIG_VALUE   0x0D0A870A
#define RGB_PIXEL_FORMATS  AV_PIX_FMT_RGB24, AV_PIX_FMT_RGBA,                 \
#define GRAY_PIXEL_FORMATS AV_PIX_FMT_GRAY8, AV_PIX_FMT_YA8,                  \
#define YUV_PIXEL_FORMATS  AV_PIX_FMT_YUV410P, AV_PIX_FMT_YUV411P, AV_PIX_FMT_YUVA420P, \
#define XYZ_PIXEL_FORMATS  AV_PIX_FMT_XYZ12
typedef struct LibOpenJPEGContext {
    AVClass *class;
    opj_dparameters_t dec_params;
    int lowqual;
} LibOpenJPEGContext;
typedef struct BufferReader {
    int pos;
    int size;
    const uint8_t *buffer;
} BufferReader;
#define OFFSET(x) offsetof(LibOpenJPEGContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
