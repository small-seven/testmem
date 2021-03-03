#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#ifdef _SC_NPROCESSORS_ONLN
#else
#endif
#ifdef _SC_NPROCESSORS_CONF
#else
#endif
#define KERNEL_MAX "/sys/devices/system/cpu/kernel_max"
