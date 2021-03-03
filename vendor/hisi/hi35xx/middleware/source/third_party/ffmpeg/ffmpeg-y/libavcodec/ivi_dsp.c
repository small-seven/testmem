#include "avcodec.h"
#include "ivi.h"
#include "ivi_dsp.h"
#define IVI_HAAR_BFLY(s1, s2, o1, o2, t) \
#define INV_HAAR8(s1, s5, s3, s7, s2, s4, s6, s8,\
#define INV_HAAR4(s1, s3, s5, s7, d1, d2, d3, d4, t0, t1, t2, t3, t4) {\
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define COMPENSATE(x) (x)
#undef  COMPENSATE
#define IVI_SLANT_BFLY(s1, s2, o1, o2, t) \
#define IVI_IREFLECT(s1, s2, o1, o2, t) \
#define IVI_SLANT_PART4(s1, s2, o1, o2, t) \
#define IVI_INV_SLANT8(s1, s4, s8, s5, s2, s6, s3, s7,\
#define IVI_INV_SLANT4(s1, s4, s2, s3, d1, d2, d3, d4, t0, t1, t2, t3, t4) {\
#define COMPENSATE(x) (x)
#undef COMPENSATE
#define COMPENSATE(x) (((x) + 1)>>1)
#undef COMPENSATE
#define COMPENSATE(x) (x)
#undef COMPENSATE
#define COMPENSATE(x) (((x) + 1)>>1)
#undef COMPENSATE
#define COMPENSATE(x) (((x) + 1)>>1)
#undef COMPENSATE
#define COMPENSATE(x) (((x) + 1)>>1)
#undef COMPENSATE
#define COMPENSATE(x) (((x) + 1)>>1)
#undef COMPENSATE
#define COMPENSATE(x) (((x) + 1)>>1)
#undef COMPENSATE
#define IVI_MC_TEMPLATE(size, suffix, OP) \
#define IVI_MC_AVG_TEMPLATE(size, suffix, OP) \
#define OP_PUT(a, b)  (a) = (b)
#define OP_ADD(a, b)  (a) += (b)
