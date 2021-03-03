#include "libavutil/avassert.h"
#include "xface.h"
#define GEN(table) dst[h] ^= (table[k>>3]>>(7-(k&7)))&1
