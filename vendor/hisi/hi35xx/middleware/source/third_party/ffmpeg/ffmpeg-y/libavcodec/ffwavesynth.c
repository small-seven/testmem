#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "avcodec.h"
#include "internal.h"
#define SIN_BITS 14
#define WS_MAX_CHANNELS 32
#define INF_TS 0x7FFFFFFFFFFFFFFF
#define PINK_UNIT 128
#define LCG_A 1284865837
#define LCG_C 4150755663
#define LCG_AI 849225893 /* A*AI = 1 [mod 1<<32] */
