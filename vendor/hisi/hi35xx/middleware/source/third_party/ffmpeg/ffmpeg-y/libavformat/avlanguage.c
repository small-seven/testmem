#include "avlanguage.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct LangEntry {
    const char str[4];
    uint16_t next_equivalent;
} LangEntry;
#if LIBAVFORMAT_VERSION_MAJOR < 58
#endif
