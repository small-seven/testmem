#include <math.h>
#if defined(__HTM__) || __ARCH__ >= 9
#else
#include "../round.c"
#endif
