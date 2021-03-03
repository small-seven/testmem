#include <stdio.h>
#include "libavutil/common.h"
#include "libavutil/lfg.h"
#include "libavdevice/timefilter.h"
#define LFG_MAX ((1LL << 32) - 1)
#define SAMPLES 1000
