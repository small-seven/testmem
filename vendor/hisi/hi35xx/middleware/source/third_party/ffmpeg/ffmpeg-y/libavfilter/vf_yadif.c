#include "libavutil/avassert.h"
#include "libavutil/cpu.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "yadif.h"
typedef struct ThreadData {
    AVFrame *frame;
    int plane;
    int w, h;
    int parity;
    int tff;
} ThreadData;
#define CHECK(j)\
#define FILTER(start, end, is_not_edge) \
#define MAX_ALIGN 8
