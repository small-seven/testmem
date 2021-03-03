#include "avformat.h"
#include "internal.h"
#include "libavutil/opt.h"
#include "libavcodec/internal.h"
#include <chromaprint.h>
#define CPR_VERSION_INT AV_VERSION_INT(CHROMAPRINT_VERSION_MAJOR, \
typedef enum FingerprintFormat {
    FINGERPRINT_RAW,
    FINGERPRINT_COMPRESSED,
    FINGERPRINT_BASE64,
} FingerprintFormat;
typedef struct ChromaprintMuxContext {
    const AVClass *class;
    int silence_threshold;
    int algorithm;
    FingerprintFormat fp_format;
#if CPR_VERSION_INT >= AV_VERSION_INT(1, 4, 0)
    ChromaprintContext *ctx;
#else
    ChromaprintContext ctx;
#endif
} ChromaprintMuxContext;
#if CPR_VERSION_INT >= AV_VERSION_INT(0, 7, 0)
#else
#endif
#define OFFSET(x) offsetof(ChromaprintMuxContext, x)
#define FLAGS AV_OPT_FLAG_ENCODING_PARAM
