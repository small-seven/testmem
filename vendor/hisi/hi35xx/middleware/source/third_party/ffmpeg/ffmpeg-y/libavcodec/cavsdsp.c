#include <stdio.h>
#include "idctdsp.h"
#include "mathops.h"
#include "cavsdsp.h"
#include "libavutil/common.h"
#define P2 p0_p[-3*stride]
#define P1 p0_p[-2*stride]
#define P0 p0_p[-1*stride]
#define Q0 p0_p[ 0*stride]
#define Q1 p0_p[ 1*stride]
#define Q2 p0_p[ 2*stride]
#undef P0
#undef P1
#undef P2
#undef Q0
#undef Q1
#undef Q2
#define CAVS_SUBPIX(OPNAME, OP, NAME, A, B, C, D, E, F) \
#define CAVS_SUBPIX_HV(OPNAME, OP, NAME, AH, BH, CH, DH, EH, FH, AV, BV, CV, DV, EV, FV, FULL) \
#define CAVS_MC(OPNAME, SIZE) \
#define op_put1(a, b)  a = cm[((b)+4)>>3]
#define op_put2(a, b)  a = cm[((b)+64)>>7]
#define op_put3(a, b)  a = cm[((b)+32)>>6]
#define op_put4(a, b)  a = cm[((b)+512)>>10]
#define op_avg1(a, b)  a = ((a)+cm[((b)+4)>>3]   +1)>>1
#define op_avg2(a, b)  a = ((a)+cm[((b)+64)>>7]  +1)>>1
#define op_avg3(a, b)  a = ((a)+cm[((b)+32)>>6]  +1)>>1
#define op_avg4(a, b)  a = ((a)+cm[((b)+512)>>10]+1)>>1
#define put_cavs_qpel8_mc00_c  ff_put_pixels8x8_c
#define avg_cavs_qpel8_mc00_c  ff_avg_pixels8x8_c
#define put_cavs_qpel16_mc00_c ff_put_pixels16x16_c
#define avg_cavs_qpel16_mc00_c ff_avg_pixels16x16_c
#define dspfunc(PFX, IDX, NUM) \
