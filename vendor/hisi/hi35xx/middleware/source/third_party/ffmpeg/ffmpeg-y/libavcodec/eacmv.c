#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "internal.h"
typedef struct CmvContext {
    AVCodecContext *avctx;
    AVFrame *last_frame;   ///< last
    AVFrame *last2_frame;  ///< second-last
    int width, height;
    unsigned int palette[AVPALETTE_COUNT];
} CmvContext;
#define EA_PREAMBLE_SIZE 8
#define MVIh_TAG MKTAG('M', 'V', 'I', 'h')
