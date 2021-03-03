#include "avcodec.h"
#include "bytestream.h"
#include "lzw.h"
#include "libavutil/mem.h"
#define LZW_MAXBITS                 12
#define LZW_SIZTABLE                (1<<LZW_MAXBITS)
