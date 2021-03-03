#include <math.h>
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "iirfilter.h"
typedef struct FFIIRFilterCoeffs {
    int   order;
    float gain;
    int   *cx;
    float *cy;
} FFIIRFilterCoeffs;
typedef struct FFIIRFilterState {
    float x[1];
} FFIIRFilterState;
#define MAXORDER 30
#define CONV_S16(dest, source) dest = av_clip_int16(lrintf(source));
#define CONV_FLT(dest, source) dest = source;
#define FILTER_BW_O4_1(i0, i1, i2, i3, fmt)             \
#define FILTER_BW_O4(type, fmt) {           \
#define FILTER_DIRECT_FORM_II(type, fmt) {                                  \
#define FILTER_O2(type, fmt) {                                              \
