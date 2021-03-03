#include <arm_neon.h>
#include "config.h"
#include "libavutil/cpu.h"
#if   ARCH_AARCH64
#   include "libavutil/aarch64/cpu.h"
#elif ARCH_ARM
#   include "libavutil/arm/cpu.h"
#endif
#include "libavcodec/mpegvideo.h"
