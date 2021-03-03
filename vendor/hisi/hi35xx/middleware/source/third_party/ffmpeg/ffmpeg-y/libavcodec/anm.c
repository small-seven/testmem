#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct AnmContext {
    AVFrame *frame;
    int palette[AVPALETTE_COUNT];
    GetByteContext gb;
    int x;  ///< x coordinate position
} AnmContext;
#define OP(gb, pixel, count) \
