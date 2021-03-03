#include <math.h>
#include "jerryscript-ext/arg.h"
#include "jerryscript.h"
#define JERRYX_ARG_TRANSFORM_FUNC_FOR_INT_TEMPLATE(type, suffix, min, max) \
#define JERRYX_ARG_TRANSFORM_FUNC_FOR_INT(type, min, max) \
#undef JERRYX_ARG_TRANSFORM_FUNC_FOR_INT_TEMPLATE
#undef JERRYX_ARG_TRANSFORM_FUNC_FOR_INT
#define JERRYX_ARG_TRANSFORM_OPTIONAL(type) \
#undef JERRYX_ARG_TRANSFORM_OPTIONAL
