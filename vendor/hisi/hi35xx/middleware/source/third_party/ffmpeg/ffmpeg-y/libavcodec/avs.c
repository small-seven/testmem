#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef struct AvsContext {
    AVFrame *frame;
} AvsContext;
typedef enum {
    AVS_VIDEO     = 0x01,
    AVS_AUDIO     = 0x02,
    AVS_PALETTE   = 0x03,
    AVS_GAME_DATA = 0x04,
} AvsBlockType;
typedef enum {
    AVS_I_FRAME     = 0x00,
    AVS_P_FRAME_3X3 = 0x01,
    AVS_P_FRAME_2X2 = 0x02,
    AVS_P_FRAME_2X3 = 0x03,
} AvsVideoSubType;
