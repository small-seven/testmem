#include "libavutil/intreadwrite.h"
#include "internal.h"
#include "libavutil/opt.h"
#include "libavcodec/fits.h"
#include "libavutil/bprint.h"
#define FITS_BLOCK_SIZE 2880
typedef struct FITSContext {
    const AVClass *class;
    AVRational framerate;
    int first_image;
    int64_t pts;
} FITSContext;
