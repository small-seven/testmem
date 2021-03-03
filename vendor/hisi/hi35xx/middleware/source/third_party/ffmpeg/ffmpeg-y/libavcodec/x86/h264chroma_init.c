#include <stdint.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/h264chroma.h"
#define CHROMA_MC(OP, NUM, DEPTH, OPT)                                  \
