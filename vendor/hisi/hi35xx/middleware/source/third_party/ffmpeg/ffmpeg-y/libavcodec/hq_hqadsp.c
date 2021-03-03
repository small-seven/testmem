#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "hq_hqadsp.h"
#define FIX_1_082 17734
#define FIX_1_847 30274
#define FIX_1_414 23170
#define FIX_2_613 21407 // divided by two to fit the range
#define IDCTMUL(a, b) ((int)((a) * (unsigned)(b)) >> 16)
