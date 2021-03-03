#include "libavcodec/snowenc.c"
#undef malloc
#undef free
#undef printf
#include "libavutil/lfg.h"
#include "libavutil/mathematics.h"
#define width  256
#define height 256
