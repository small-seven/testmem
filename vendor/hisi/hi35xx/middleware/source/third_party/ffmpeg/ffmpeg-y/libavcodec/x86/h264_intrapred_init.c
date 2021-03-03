#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/h264pred.h"
#define PRED4x4(TYPE, DEPTH, OPT) \
#define PRED8x8(TYPE, DEPTH, OPT) \
#define PRED8x8L(TYPE, DEPTH, OPT)\
#define PRED16x16(TYPE, DEPTH, OPT)\
