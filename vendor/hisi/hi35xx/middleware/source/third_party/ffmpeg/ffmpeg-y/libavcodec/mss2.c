#include "libavutil/avassert.h"
#include "error_resilience.h"
#include "internal.h"
#include "mpeg_er.h"
#include "msmpeg4.h"
#include "qpeldsp.h"
#include "vc1.h"
#include "wmv2data.h"
#include "mss12.h"
#include "mss2dsp.h"
typedef struct MSS2Context {
    VC1Context     v;
    int            split_position;
    AVFrame       *last_pic;
    MSS12Context   c;
    MSS2DSPContext dsp;
    QpelDSPContext qdsp;
    SliceContext   sc[2];
} MSS2Context;
#define READ_PAIR(a, b)                 \
#define MAX_WMV9_RECTANGLES 20
#define ARITH2_PADDING 2
