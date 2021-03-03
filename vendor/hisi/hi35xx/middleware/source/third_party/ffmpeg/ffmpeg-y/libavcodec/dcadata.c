#include <stdint.h>
#include "libavutil/mem.h"
#include "dca.h"
#include "dcadata.h"
#define SCALE(c) ((c) / (256.0f * 32768.0f))
#undef SCALE
