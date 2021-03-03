#include "avcodec.h"
#include "h264chroma.h"
#include "h264qpel.h"
#include "mathops.h"
#include "rv34dsp.h"
#define RV30_LOWPASS(OPNAME, OP) \
#define RV30_MC(OPNAME, SIZE) \
#define op_avg(a, b)  a = (((a)+cm[b]+1)>>1)
#define op_put(a, b)  a = cm[b]
