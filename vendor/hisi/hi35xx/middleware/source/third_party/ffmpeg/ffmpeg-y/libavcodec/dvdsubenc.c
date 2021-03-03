#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/bprint.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
typedef struct {
    AVClass *class;
    uint32_t global_palette[16];
    int even_rows_fix;
} DVDSubtitleContext;
#define PUTNIBBLE(val)\
#if FF_API_AVPICTURE
#endif
#define OFFSET(x) offsetof(DVDSubtitleContext, x)
#define SE AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_ENCODING_PARAM
