#include "vp3dsp_mips.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mips/mmiutils.h"
#include "libavutil/common.h"
#include "libavcodec/rnd_avg.h"
#define LOAD_CONST(dst, value)                        \
