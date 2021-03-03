#include "hevcdsp.h"
#define BIT_DEPTH 8
#include "hevcdsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 9
#include "hevcdsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "hevcdsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "hevcdsp_template.c"
#undef BIT_DEPTH
#undef FUNC
#define FUNC(a, depth) a ## _ ## depth
#undef PEL_FUNC
#define PEL_FUNC(dst1, idx1, idx2, a, depth)                                   \
#undef EPEL_FUNCS
#define EPEL_FUNCS(depth)                                                     \
#undef EPEL_UNI_FUNCS
#define EPEL_UNI_FUNCS(depth)                                                 \
#undef EPEL_BI_FUNCS
#define EPEL_BI_FUNCS(depth)                                                \
#undef QPEL_FUNCS
#define QPEL_FUNCS(depth)                                                     \
#undef QPEL_UNI_FUNCS
#define QPEL_UNI_FUNCS(depth)                                                 \
#undef QPEL_BI_FUNCS
#define QPEL_BI_FUNCS(depth)                                                  \
#define HEVC_DSP(depth)                                                     \
