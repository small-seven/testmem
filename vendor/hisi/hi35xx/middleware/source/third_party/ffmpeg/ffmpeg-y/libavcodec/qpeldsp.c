#include <stddef.h>
#include <stdint.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "copy_block.h"
#include "qpeldsp.h"
#include "diracdsp.h"
#define BIT_DEPTH 8
#include "hpel_template.c"
#include "pel_template.c"
#include "qpel_template.c"
#define QPEL_MC(r, OPNAME, RND, OP)                                           \
#define op_avg(a, b)        a = (((a) + cm[((b) + 16) >> 5] + 1) >> 1)
#define op_put(a, b)        a = cm[((b) + 16) >> 5]
#define op_put_no_rnd(a, b) a = cm[((b) + 15) >> 5]
#undef op_avg
#undef op_put
#undef op_put_no_rnd
#define put_qpel8_mc00_c         ff_put_pixels8x8_c
#define avg_qpel8_mc00_c         ff_avg_pixels8x8_c
#define put_qpel16_mc00_c        ff_put_pixels16x16_c
#define avg_qpel16_mc00_c        ff_avg_pixels16x16_c
#define put_no_rnd_qpel8_mc00_c  ff_put_pixels8x8_c
#define put_no_rnd_qpel16_mc00_c ff_put_pixels16x16_c
#if CONFIG_DIRAC_DECODER
#define DIRAC_MC(OPNAME)\
#endif
#define dspfunc(PFX, IDX, NUM)                              \
