#include <string.h>
#include <stdint.h>
#include "securec.h"
#include "los_slab_pri.h"
#include "los_heap_pri.h"
#define LOW_BITS_MASK                     31
#define NUM_BITS_IN_ONE_BYTE              32
#define NUMBITS_TO_NUMBYTES(numBits)      (((numBits) + LOW_BITS_MASK) / 8)
