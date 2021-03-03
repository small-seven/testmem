#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavfilter/threshold.h"
#define THRESHOLD_FUNC(depth, opt) \
