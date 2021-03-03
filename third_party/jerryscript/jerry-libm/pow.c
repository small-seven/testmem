#include "jerry-libm-internal.h"
#define zero     0.0
#define one      1.0
#define two      2.0
#define two53    9007199254740992.0 /* 0x43400000, 0x00000000 */
#define huge     1.0e300
#define tiny     1.0e-300
#define L1       5.99999999999994648725e-01 /* 0x3FE33333, 0x33333303 */
#define L2       4.28571428578550184252e-01 /* 0x3FDB6DB6, 0xDB6FABFF */
#define L3       3.33333329818377432918e-01 /* 0x3FD55555, 0x518F264D */
#define L4       2.72728123808534006489e-01 /* 0x3FD17460, 0xA91D4101 */
#define L5       2.30660745775561754067e-01 /* 0x3FCD864A, 0x93C9DB65 */
#define L6       2.06975017800338417784e-01 /* 0x3FCA7E28, 0x4A454EEF */
#define P1       1.66666666666666019037e-01 /* 0x3FC55555, 0x5555553E */
#define P2      -2.77777777770155933842e-03 /* 0xBF66C16C, 0x16BEBD93 */
#define P3       6.61375632143793436117e-05 /* 0x3F11566A, 0xAF25DE2C */
#define P4      -1.65339022054652515390e-06 /* 0xBEBBBD41, 0xC5D26BF1 */
#define P5       4.13813679705723846039e-08 /* 0x3E663769, 0x72BEA4D0 */
#define lg2      6.93147180559945286227e-01 /* 0x3FE62E42, 0xFEFA39EF */
#define lg2_h    6.93147182464599609375e-01 /* 0x3FE62E43, 0x00000000 */
#define lg2_l   -1.90465429995776804525e-09 /* 0xBE205C61, 0x0CA86C39 */
#define ovt      8.0085662595372944372e-0017 /* -(1024-log2(ovfl+.5ulp)) */
#define cp       9.61796693925975554329e-01 /* 0x3FEEC709, 0xDC3A03FD = 2 / (3 ln2) */
#define cp_h     9.61796700954437255859e-01 /* 0x3FEEC709, 0xE0000000 = (float) cp */
#define cp_l    -7.02846165095275826516e-09 /* 0xBE3E2FE0, 0x145B01F5 = tail of cp_h */
#define ivln2    1.44269504088896338700e+00 /* 0x3FF71547, 0x652B82FE = 1 / ln2 */
#define ivln2_h  1.44269502162933349609e+00 /* 0x3FF71547, 0x60000000 = 24b 1 / ln2 */
#define ivln2_l  1.92596299112661746887e-08 /* 0x3E54AE0B, 0xF85DDF44 = 1 / ln2 tail */
#undef zero
#undef one
#undef two
#undef two53
#undef huge
#undef tiny
#undef L1
#undef L2
#undef L3
#undef L4
#undef L5
#undef L6
#undef P1
#undef P2
#undef P3
#undef P4
#undef P5
#undef lg2
#undef lg2_h
#undef lg2_l
#undef ovt
#undef cp
#undef cp_h
#undef cp_l
#undef ivln2
#undef ivln2_h
#undef ivln2_l
