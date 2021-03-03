#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "mathops.h"
typedef struct WNV1Context {
    int shift;
    GetBitContext gb;
} WNV1Context;
#define CODE_VLC_BITS 9
