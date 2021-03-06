#include "jerry-libm-internal.h"
#define one      1.00000000000000000000e+00 /* 0x3FF00000, 0x00000000 */
#define pi       3.14159265358979311600e+00 /* 0x400921FB, 0x54442D18 */
#define pio2_hi  1.57079632679489655800e+00 /* 0x3FF921FB, 0x54442D18 */
#define pio2_lo  6.12323399573676603587e-17 /* 0x3C91A626, 0x33145C07 */
#define pS0      1.66666666666666657415e-01 /* 0x3FC55555, 0x55555555 */
#define pS1     -3.25565818622400915405e-01 /* 0xBFD4D612, 0x03EB6F7D */
#define pS2      2.01212532134862925881e-01 /* 0x3FC9C155, 0x0E884455 */
#define pS3     -4.00555345006794114027e-02 /* 0xBFA48228, 0xB5688F3B */
#define pS4      7.91534994289814532176e-04 /* 0x3F49EFE0, 0x7501B288 */
#define pS5      3.47933107596021167570e-05 /* 0x3F023DE1, 0x0DFDF709 */
#define qS1     -2.40339491173441421878e+00 /* 0xC0033A27, 0x1C8A2D4B */
#define qS2      2.02094576023350569471e+00 /* 0x40002AE5, 0x9C598AC8 */
#define qS3     -6.88283971605453293030e-01 /* 0xBFE6066C, 0x1B8D0159 */
#define qS4      7.70381505559019352791e-02 /* 0x3FB3B8C5, 0xB12E9282 */
#undef one
#undef pi
#undef pio2_hi
#undef pio2_lo
#undef pS0
#undef pS1
#undef pS2
#undef pS3
#undef pS4
#undef pS5
#undef qS1
#undef qS2
#undef qS3
#undef qS4
