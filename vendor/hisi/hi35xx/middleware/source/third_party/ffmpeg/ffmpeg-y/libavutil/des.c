#include <stdint.h>
#include "avutil.h"
#include "common.h"
#include "intreadwrite.h"
#include "mem.h"
#include "des.h"
#define T(a, b, c, d, e, f, g, h) 64 - a, 64 - b, 64 - c, 64 - d, 64 - e, 64 - f, 64 - g, 64 - h
#undef T
#if CONFIG_SMALL || defined(GENTABLES)
#define T(a, b, c, d) 32 - a, 32 - b, 32 - c, 32 - d
#undef T
#endif
#define T(a, b, c, d, e, f, g) 64 - a, 64 - b, 64 - c, 64 - d, 64 - e, 64 - f, 64 - g
#undef T
#define T(a, b, c, d, e, f) 56 - a, 56 - b, 56 - c, 56 - d, 56 - e, 56 - f
#undef T
#if CONFIG_SMALL
#else
#endif
#if CONFIG_SMALL
#else
#endif
#if CONFIG_SMALL
#endif
