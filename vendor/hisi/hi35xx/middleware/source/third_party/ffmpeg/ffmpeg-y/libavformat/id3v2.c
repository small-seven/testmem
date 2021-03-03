#include "config.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#include "libavcodec/png.h"
#include "avio_internal.h"
#include "internal.h"
#include "id3v1.h"
#include "id3v2.h"
typedef struct ID3v2EMFunc {
    const char *tag3;
    const char *tag4;
    void (*read)(AVFormatContext *s, AVIOContext *pb, int taglen,
                 const char *tag, ID3v2ExtraMeta **extra_meta,
                 int isv34);
    void (*free)(void *obj);
} ID3v2EMFunc;
#if CONFIG_ZLIB
#endif
