#include "libavutil/attributes.h"
#include "libavcodec/hpeldsp.h"
#include "hpeldsp_alpha.h"
#include "asm.h"
#if 0
#endif
#define OP(LOAD, STORE)                         \
#define OP_X2(LOAD, STORE)                                      \
#define OP_Y2(LOAD, STORE)                      \
#define OP_XY2(LOAD, STORE)                                                 \
#define MAKE_OP(OPNAME, SUFF, OPKIND, STORE)                                \
#define PIXOP(OPNAME, STORE)                    \
#define AVG2 avg2
#define AVG4 avg4
#define AVG4_ROUNDER BYTE_VEC(0x02)
#define STORE(l, b) stq(l, b)
#undef STORE
#define STORE(l, b) stq(AVG2(l, ldq(b)), b);
#undef AVG2
#undef AVG4
#undef AVG4_ROUNDER
#undef STORE
#define AVG2 avg2_no_rnd
#define AVG4 avg4_no_rnd
#define AVG4_ROUNDER BYTE_VEC(0x01)
#define STORE(l, b) stq(l, b)
#undef STORE
#define STORE(l, b) stq(AVG2(l, ldq(b)), b);
