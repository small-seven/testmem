#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "put_bits.h"
#include "mathops.h"
#include "utvideo.h"
#include "huffman.h"
#if FF_API_PRIVATE_OPT
#endif
#undef A
#undef B
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(UtvideoContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
