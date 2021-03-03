#include "jerry-libm-internal.h"
#define tiny   1.0e-300
#define zero   0.0
#define pi_o_4 7.8539816339744827900E-01 /* 0x3FE921FB, 0x54442D18 */
#define pi_o_2 1.5707963267948965580E+00 /* 0x3FF921FB, 0x54442D18 */
#define pi     3.1415926535897931160E+00 /* 0x400921FB, 0x54442D18 */
#define pi_lo  1.2246467991473531772E-16 /* 0x3CA1A626, 0x33145C07 */
#undef tiny
#undef zero
#undef pi_o_4
#undef pi_o_2
#undef pi
#undef pi_lo
