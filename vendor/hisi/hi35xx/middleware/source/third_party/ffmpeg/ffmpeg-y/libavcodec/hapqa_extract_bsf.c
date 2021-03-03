#include "avcodec.h"
#include "bsf.h"
#include "bytestream.h"
#include "hap.h"
typedef struct HapqaExtractContext {
    const AVClass *class;
    int texture;/* index of the texture to keep (0 for rgb or 1 for alpha) */
} HapqaExtractContext;
#define OFFSET(x) offsetof(HapqaExtractContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_BSF_PARAM)
