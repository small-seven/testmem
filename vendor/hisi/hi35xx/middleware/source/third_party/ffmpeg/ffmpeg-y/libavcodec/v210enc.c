#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "v210enc.h"
#define CLIP(v) av_clip(v, 4, 1019)
#define CLIP8(v) av_clip(v, 1, 254)
#define WRITE_PIXELS(a, b, c)           \
#define WRITE_PIXELS8(a, b, c)          \
#if FF_API_CODED_FRAME
#endif
