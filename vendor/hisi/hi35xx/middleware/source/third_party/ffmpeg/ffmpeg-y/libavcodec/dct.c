#include <math.h>
#include <string.h>
#include "libavutil/mathematics.h"
#include "dct.h"
#include "dct32.h"
#define SIN(s, n, x) (s->costab[(n) - (x)])
#define COS(s, n, x) (s->costab[x])
