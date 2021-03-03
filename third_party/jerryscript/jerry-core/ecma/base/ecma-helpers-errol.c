#include <math.h>
#include "ecma-helpers.h"
#define ECMA_NEXT_FLOAT(value) (nextafter ((value), INFINITY))
#define ECMA_PREV_FLOAT(value) (nextafter ((value), -INFINITY))
#define ERROL0_EPSILON 0.0000001
typedef struct
{
  double value; /**< value */
  double offset; /**< offset */
} ecma_high_prec_t;
