#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct C93DecoderContext {
    AVFrame *pictures[2];
    int currentpic;
} C93DecoderContext;
typedef enum {
    C93_8X8_FROM_PREV  = 0x02,
    C93_4X4_FROM_PREV  = 0x06,
    C93_4X4_FROM_CURR  = 0x07,
    C93_8X8_2COLOR     = 0x08,
    C93_4X4_2COLOR     = 0x0A,
    C93_4X4_4COLOR_GRP = 0x0B,
    C93_4X4_4COLOR     = 0x0D,
    C93_NOOP           = 0x0E,
    C93_8X8_INTRA      = 0x0F,
} C93BlockType;
#define WIDTH   320
#define HEIGHT  192
#define C93_HAS_PALETTE 0x01
#define C93_FIRST_FRAME 0x02
