#include "jerry-libm-internal.h"
#define zero   0.0
#define ln2_hi 6.93147180369123816490e-01 /* 3fe62e42 fee00000 */
#define ln2_lo 1.90821492927058770002e-10 /* 3dea39ef 35793c76 */
#define two54  1.80143985094819840000e+16 /* 43500000 00000000 */
#define Lg1    6.666666666666735130e-01 /* 3FE55555 55555593 */
#define Lg2    3.999999999940941908e-01 /* 3FD99999 9997FA04 */
#define Lg3    2.857142874366239149e-01 /* 3FD24924 94229359 */
#define Lg4    2.222219843214978396e-01 /* 3FCC71C5 1D8E78AF */
#define Lg5    1.818357216161805012e-01 /* 3FC74664 96CB03DE */
#define Lg6    1.531383769920937332e-01 /* 3FC39A09 D078C69F */
#define Lg7    1.479819860511658591e-01 /* 3FC2F112 DF3E5244 */
#undef zero
#undef ln2_hi
#undef ln2_lo
#undef two54
#undef Lg1
#undef Lg2
#undef Lg3
#undef Lg4
#undef Lg5
#undef Lg6
#undef Lg7
