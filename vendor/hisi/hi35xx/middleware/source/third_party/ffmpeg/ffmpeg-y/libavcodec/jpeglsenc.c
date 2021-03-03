#include "avcodec.h"
#include "get_bits.h"
#include "put_bits.h"
#include "golomb.h"
#include "internal.h"
#include "mathops.h"
#include "mjpeg.h"
#include "mjpegenc.h"
#include "jpegls.h"
typedef struct JPEGLSContext {
    AVClass *class;

    int pred;
} JPEGLSContext;
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(JPEGLSContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
