#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
#define FLI_256_COLOR 4
#define FLI_DELTA     7
#define FLI_COLOR     11
#define FLI_LC        12
#define FLI_BLACK     13
#define FLI_BRUN      15
#define FLI_COPY      16
#define FLI_MINI      18
#define FLI_DTA_BRUN  25
#define FLI_DTA_COPY  26
#define FLI_DTA_LC    27
#define FLI_TYPE_CODE     (0xAF11)
#define FLC_FLX_TYPE_CODE (0xAF12)
#define FLC_DTA_TYPE_CODE (0xAF44) /* Marks an "Extended FLC" comes from Dave's Targa Animator (DTA) */
#define FLC_MAGIC_CARPET_SYNTHETIC_TYPE_CODE (0xAF13)
#define CHECK_PIXEL_PTR(n) \
typedef struct FlicDecodeContext {
    AVCodecContext *avctx;
    AVFrame *frame;

    unsigned int palette[256];
    int new_palette;
    int fli_type;  /* either 0xAF11 or 0xAF12, affects palette resolution */
} FlicDecodeContext;
#if HAVE_BIGENDIAN
#endif
