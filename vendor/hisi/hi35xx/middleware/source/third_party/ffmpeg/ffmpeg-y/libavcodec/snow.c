#include "libavutil/intmath.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "me_cmp.h"
#include "snow_dwt.h"
#include "internal.h"
#include "snow.h"
#include "snowdata.h"
#include "rangecoder.h"
#include "mathops.h"
#include "h263.h"
#define MC_STRIDE(x) (needs[x] ? 64 : stride)
#define mca(dx,dy,b_w)\
#define mcf(dx,dy)\
#define mcfh(dx,dy)\
#define USE_HALFPEL_PLANE 0
