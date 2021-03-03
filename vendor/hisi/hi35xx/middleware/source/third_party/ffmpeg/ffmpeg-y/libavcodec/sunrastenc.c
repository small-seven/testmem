#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "sunrast.h"
typedef struct SUNRASTContext {
    AVClass *class;

    PutByteContext p;
    int depth;      ///< depth of pixel
    int length;     ///< length (bytes) of image
    int type;       ///< type of file
    int maptype;    ///< type of colormap
    int maplength;  ///< length (bytes) of colormap
    int size;
} SUNRASTContext;
#define GET_VALUE y >= avctx->height ? 0 : x >= len ? ptr[len-1] : ptr[x]
#if FF_API_CODER_TYPE
#endif
#define OFFSET(x) offsetof(SUNRASTContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_CODER_TYPE
#endif
#if FF_API_CODER_TYPE
#endif
