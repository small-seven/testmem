#include "libm.h"
#if FLT_EVAL_METHOD==2
#undef sqrtf
#define sqrtf sqrtl
#elif FLT_EVAL_METHOD==1
#undef sqrtf
#define sqrtf sqrt
#endif
