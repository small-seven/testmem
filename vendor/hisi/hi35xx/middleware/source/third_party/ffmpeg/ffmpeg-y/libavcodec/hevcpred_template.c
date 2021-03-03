#include "libavutil/pixdesc.h"
#include "bit_depth_template.c"
#include "hevcpred.h"
#define POS(x, y) src[(x) + stride * (y)]
#define PU(x) \
#define MVF(x, y) \
#define MVF_PU(x, y) \
#define IS_INTRA(x, y) \
#define MIN_TB_ADDR_ZS(x, y) \
#define EXTEND(ptr, val, len)         \
#define EXTEND_RIGHT_CIP(ptr, start, length)                                   \
#define EXTEND_LEFT_CIP(ptr, start, length) \
#define EXTEND_UP_CIP(ptr, start, length)                                      \
#define EXTEND_DOWN_CIP(ptr, start, length)                                    \
#define INTRA_PRED(size)                                                            \
#undef INTRA_PRED
#define PRED_PLANAR(size)\
#undef PRED_PLANAR
#undef EXTEND_LEFT_CIP
#undef EXTEND_RIGHT_CIP
#undef EXTEND_UP_CIP
#undef EXTEND_DOWN_CIP
#undef IS_INTRA
#undef MVF_PU
#undef MVF
#undef PU
#undef EXTEND
#undef MIN_TB_ADDR_ZS
#undef POS
