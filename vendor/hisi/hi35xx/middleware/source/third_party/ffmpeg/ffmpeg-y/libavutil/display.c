#include <stdint.h>
#include <string.h>
#include <math.h>
#include "display.h"
#include "mathematics.h"
#define CONV_FP(x) ((double) (x)) / (1 << 16)
#define CONV_DB(x) (int32_t) ((x) * (1 << 16))
