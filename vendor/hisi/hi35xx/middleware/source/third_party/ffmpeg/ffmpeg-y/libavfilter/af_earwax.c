#include "libavutil/channel_layout.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#define NUMTAPS 64
typedef struct EarwaxContext {
    int16_t taps[NUMTAPS * 2];
} EarwaxContext;
