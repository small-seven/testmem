#include "los_config.h"
#if (CMSIS_OS_VER == 1)
#include "1.0/cmsis_liteos1.c"
#elif (CMSIS_OS_VER == 2)
#include "2.0/cmsis_liteos2.c"
#endif
