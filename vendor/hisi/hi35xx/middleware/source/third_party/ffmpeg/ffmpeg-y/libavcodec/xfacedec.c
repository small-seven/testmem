#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "xface.h"
typedef struct XFaceContext {
    uint8_t bitmap[XFACE_PIXELS]; ///< image used internally for decoding
} XFaceContext;
