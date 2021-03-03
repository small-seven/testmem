#include "ipcsem.h"
#ifdef _XLC_COMPILER
#define SEMUN_CAST
#else
#define SEMUN_CAST (union semun)
#endif
#ifdef _XLC_COMPILER
#define SEMUN_CAST
#else
#define SEMUN_CAST (union semun)
#endif
