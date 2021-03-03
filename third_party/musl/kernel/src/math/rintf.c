#include <float.h>
#include <math.h>
#include <stdint.h>
#if FLT_EVAL_METHOD==0
#define EPS FLT_EPSILON
#elif FLT_EVAL_METHOD==1
#define EPS DBL_EPSILON
#elif FLT_EVAL_METHOD==2
#define EPS LDBL_EPSILON
#endif
