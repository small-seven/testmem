#include "libm.h"
#if FLT_EVAL_METHOD==2
#undef sqrt
#define sqrt sqrtl
#endif
