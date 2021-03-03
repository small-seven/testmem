#include "libavutil/frame.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "idctdsp.h"
#include "internal.h"
#include "jpegtables.h"
#include "mjpegenc_common.h"
#include "mjpeg.h"
typedef struct LJpegEncContext {
    AVClass *class;
    IDCTDSPContext idsp;
    ScanTable scantable;
    uint16_t matrix[64];

    int vsample[4];
    int hsample[4];

    uint16_t huff_code_dc_luminance[12];
    uint16_t huff_code_dc_chrominance[12];
    uint8_t  huff_size_dc_luminance[12];
    uint8_t  huff_size_dc_chrominance[12];

    uint16_t (*scratch)[4];
    int pred;
} LJpegEncContext;
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(LJpegEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
