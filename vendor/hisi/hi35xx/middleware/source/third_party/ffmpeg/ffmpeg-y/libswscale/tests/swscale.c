#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdarg.h>
#undef HAVE_AV_CONFIG_H
#include "libavutil/cpu.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#include "libavutil/avutil.h"
#include "libavutil/crc.h"
#include "libavutil/pixdesc.h"
#include "libavutil/lfg.h"
#include "libswscale/swscale.h"
#define isGray(x)                      \
#define hasChroma(x)                   \
#define isALPHA(x)                     \
#define W 96
#define H 96
