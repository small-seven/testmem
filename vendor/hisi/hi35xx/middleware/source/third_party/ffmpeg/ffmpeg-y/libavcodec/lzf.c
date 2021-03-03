#include "libavutil/mem.h"
#include "bytestream.h"
#include "lzf.h"
#define LZF_LITERAL_MAX (1 << 5)
#define LZF_LONG_BACKREF 7 + 2
