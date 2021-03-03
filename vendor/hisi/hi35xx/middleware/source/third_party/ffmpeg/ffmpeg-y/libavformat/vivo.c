#include "libavutil/parseutils.h"
#include "avformat.h"
#include "internal.h"
typedef struct VivoContext {
    int version;

    int type;
    int sequence;
    int length;

    uint8_t  text[1024 + 1];
} VivoContext;
