#include <stdint.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/x86/asm.h"
#include "inline_asm.h"
#define MAX_ABS (512 >> (SCALE_OFFSET>0 ? SCALE_OFFSET : 0))
