#include <common.h>
#include <cpu_func.h>
#if !(CONFIG_IS_ENABLED(SYS_ICACHE_OFF) && CONFIG_IS_ENABLED(SYS_DCACHE_OFF))
#endif
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#else
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#else
#endif
