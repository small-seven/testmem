#include "libavutil/attributes.h"
#include "bgmc.h"
#define FREQ_BITS  14                      // bits used by frequency counters
#define VALUE_BITS 18                      // bits used to represent the values
#define TOP_VALUE  ((1 << VALUE_BITS) - 1) // maximum value
#define FIRST_QTR  (TOP_VALUE / 4 + 1)     // first quarter of values maximum value
#define HALF       (2 * FIRST_QTR)         // first half of values maximum value
#define THIRD_QTR  (3 * FIRST_QTR)         // third quarter of values maximum value
#define LUT_BITS   (FREQ_BITS - 8)         // number of bits used to index lookup tables
#define LUT_SIZE   (1 << LUT_BITS)         // size of the lookup tables
#define LUT_BUFF   4                       // number of buffered lookup tables
