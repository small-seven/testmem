#include "rtpdec_formats.h"
#include "internal.h"
#include "libavutil/attributes.h"
#include "libavutil/avstring.h"
#include "libavcodec/get_bits.h"
#define MAX_AAC_HBR_FRAME_SIZE 8191
typedef struct AttrNameMap {
    const char *str;
    uint16_t    type;
    uint32_t    offset;
} AttrNameMap;
#define ATTR_NAME_TYPE_INT 0
#define ATTR_NAME_TYPE_STR 1
