#include "avcodec.h"
#include "internal.h"
#include <float.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "fits.h"
typedef struct FITSContext {
    const AVClass *class;
    int blank_val;
} FITSContext;
#define CASE_N(a, t, rd) \
#define CASE_RGB(cas, dst, type, dref) \
#define CASE_GRAY(cas, dst, type, t, rd) \
