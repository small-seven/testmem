#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/time_internal.h"
#include "avformat.h"
#include "internal.h"
#define SBG_SCALE (1 << 16)
#define DAY (24 * 60 * 60)
#define DAY_TS ((int64_t)DAY * AV_TIME_BASE)
#define FORWARD_ERROR(c) \
#undef time
#define ADD_EDATA32(v) do { AV_WL32(edata, (v)); edata += 4; } while(0)
#define ADD_EDATA64(v) do { AV_WL64(edata, (v)); edata += 8; } while(0)
