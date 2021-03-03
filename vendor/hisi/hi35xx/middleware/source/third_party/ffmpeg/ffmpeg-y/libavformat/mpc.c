#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
#include "apetag.h"
#include "id3v1.h"
#include "libavutil/dict.h"
#define MPC_FRAMESIZE  1152
#define DELAY_FRAMES   32
typedef struct MPCFrame {
    int64_t pos;
    int size, skip;
}MPCFrame;
typedef struct MPCContext {
    int ver;
    uint32_t curframe, lastframe;
    uint32_t fcount;
    MPCFrame *frames;
    int curbits;
    int frames_noted;
} MPCContext;
