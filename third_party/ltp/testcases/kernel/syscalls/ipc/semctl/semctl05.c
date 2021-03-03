#include "ipcsem.h"
#ifdef _XLC_COMPILER
#define SEMUN_CAST
#else
#define SEMUN_CAST (union semun)
#endif
#define BIGV	65535		/* a number ((2^16)-1) that should be larger */
#ifdef _XLC_COMPILER
#define SEMUN_CAST
#else
#define SEMUN_CAST (union semun)
#endif
