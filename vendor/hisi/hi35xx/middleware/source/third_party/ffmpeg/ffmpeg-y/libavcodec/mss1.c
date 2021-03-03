#include "avcodec.h"
#include "internal.h"
#include "mss12.h"
typedef struct MSS1Context {
    MSS12Context   ctx;
    AVFrame       *pic;
    SliceContext   sc;
} MSS1Context;
