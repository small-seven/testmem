#include <stdint.h>
#include <float.h>
#include <math.h>
#include "atomic.h"
#define ASUINT64(x) ((union {double f; uint64_t i;}){x}).i
#define ZEROINFNAN (0x7ff-0x3ff-52-1)
