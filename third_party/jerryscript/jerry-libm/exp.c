#include "jerry-libm-internal.h"
#define one          1.0
#define huge         1.0e+300
#define twom1000     9.33263618503218878990e-302 /* 2**-1000=0x01700000,0 */
#define o_threshold  7.09782712893383973096e+02 /* 0x40862E42, 0xFEFA39EF */
#define u_threshold -7.45133219101941108420e+02 /* 0xc0874910, 0xD52D3051 */
#define invln2       1.44269504088896338700e+00 /* 0x3ff71547, 0x652b82fe */
#define P1           1.66666666666666019037e-01 /* 0x3FC55555, 0x5555553E */
#define P2          -2.77777777770155933842e-03 /* 0xBF66C16C, 0x16BEBD93 */
#define P3           6.61375632143793436117e-05 /* 0x3F11566A, 0xAF25DE2C */
#define P4          -1.65339022054652515390e-06 /* 0xBEBBBD41, 0xC5D26BF1 */
#define P5           4.13813679705723846039e-08 /* 0x3E663769, 0x72BEA4D0 */
#undef one
#undef huge
#undef twom1000
#undef o_threshold
#undef u_threshold
#undef invln2
#undef P1
#undef P2
#undef P3
#undef P4
#undef P5
