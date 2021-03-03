#include <string.h>
#include <stdio.h>
#include "libavutil/avassert.h"
#include "libavutil/buffer.h"
#include "libavutil/hwcontext.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
#define BUFFER_ALIGN 32
